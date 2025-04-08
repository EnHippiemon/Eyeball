#include "EyeEnemy.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EnemyDataAssets/EyeEnemyDataAsset.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Eyeball/Weapons/EyeProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AEyeEnemy::AEyeEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	RootCollider = CreateDefaultSubobject<UCapsuleComponent>("RootCollider");
	RootComponent = RootCollider;

	DamageBox = CreateDefaultSubobject<UBoxComponent>("DamageBox");
	DamageBox->SetupAttachment(RootCollider);

	DetectionSphere = CreateDefaultSubobject<USphereComponent>("DetectionSphere");
	DetectionSphere->SetupAttachment(RootCollider);
	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeEnemy::HandleBeginOverlap);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &AEyeEnemy::HandleEndOverlap);

	EvasionSphere = CreateDefaultSubobject<USphereComponent>("EvasionSphere");
	EvasionSphere->SetupAttachment(RootCollider);
	EvasionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeEnemy::HandleBeginOverlap);
	EvasionSphere->OnComponentEndOverlap.AddDynamic(this, &AEyeEnemy::HandleEndOverlap);
}

void AEyeEnemy::SetHealth(int const NewHealth)
{
	Health = NewHealth;
	DetermineDeath();
}

void AEyeEnemy::ChangeHealth(int const HealthToAdd)
{
	Health += HealthToAdd;
	DetermineDeath();
}

void AEyeEnemy::PrepareAttack(float const DeltaTime)
{
	if (CurrentState != Ees_PreparingAttack)
		return;

	if (Cast<AEyeEntityEyeball>(CharacterRef))
	{
		CurrentState = Ees_Idle;
		return;
	}

	AttackPreparationTime += DeltaTime;
	if (AttackPreparationTime >= Data->AttackDelay)
		CurrentState = Ees_Attacking;
}

void AEyeEnemy::Attack()
{
	if (CurrentState != Ees_Attacking)
		return;

	for (int i = 0; i < Data->ProjectilesPerAttack; ++i)
	{
		const auto AccuracyOffset = FVector(0, FMath::FRandRange(-Data->AttackAccuracy.Y, Data->AttackAccuracy.Y),
		                                    FMath::FRandRange(-Data->AttackAccuracy.Z, Data->AttackAccuracy.Z));
		const auto Target = AccuracyOffset + CharacterRef->GetActorLocation();

		const auto ThisProjectile = GetWorld()->SpawnActor<AEyeProjectile>(Data->Projectile, GetTransform());
		ThisProjectile->SetShootingActor(this);
		ThisProjectile->SetActorScale3D(FVector(1, 1, 1));
		ThisProjectile->OnSpawned();
		ThisProjectile->SetTarget(Target);
	}

	AttackPreparationTime = 0;
	CurrentState = Ees_PreparingAttack;
}

void AEyeEnemy::Move(float const DeltaTime)
{
	if (CurrentState != Ees_Moving)
		return;

	auto NewLocation = GetActorLocation() + TargetMoveOffset * MoveDirection * Data->MovementSpeed * DeltaTime;
	SetActorRelativeLocation(NewLocation);

	const auto CurrentLocation = FVector(0, NewLocation.Y, Data->bCanFly ? NewLocation.Z : 0);
	const auto TargetLocation = FVector(0, TargetMoveLocation.Y, Data->bCanFly ? TargetMoveLocation.Z : 0);

	if ((CurrentLocation - TargetLocation).Length() > Data->MarginForReachingTarget)
		return;
	
	if (bIsThreatened)
		SetNewMoveTarget();
	else
		CurrentState = Ees_PreparingAttack;
}

void AEyeEnemy::SetNewMoveTarget()
{
	const int DirectionY = CharacterRef->GetActorLocation().Y < GetActorLocation().Y ? 1 : -1;
	const int DirectionZ = CharacterRef->GetActorLocation().Z < GetActorLocation().Z ? 1 : -1;
	MoveDirection = FVector(0, DirectionY, Data->bCanFly ? DirectionZ : 0);
	
	TargetMoveLocation = GetActorLocation() + Data->DistanceForEvasion * MoveDirection;
	
	TargetMoveOffset = FVector(0, FMath::Abs(TargetMoveLocation.Y - GetActorLocation().Y),
	                           FMath::Abs(TargetMoveLocation.Z - GetActorLocation().Z));
	TargetMoveOffset.Normalize();
	
	CurrentState = Ees_Moving;
}

void AEyeEnemy::SetIsThreatened(bool const IsThreatened)
{
	if (CurrentState == Ees_IsDead)
		return;

	bIsThreatened = IsThreatened;
}

void AEyeEnemy::DetermineDeath()
{
	const bool ShouldBeDead = Health <= 0;
	SetActorHiddenInGame(ShouldBeDead);
	DamageBox->SetActive(!ShouldBeDead);
	DetectionSphere->SetActive(!ShouldBeDead);
	EvasionSphere->SetActive(!ShouldBeDead);
	bIsThreatened = ShouldBeDead ? false : bIsThreatened;
	CurrentState = ShouldBeDead ? Ees_IsDead : CurrentState;
	SetActorEnableCollision(!ShouldBeDead);
	RootCollider->SetSimulatePhysics(ShouldBeDead);
}

void AEyeEnemy::CheckOverlaps()
{
	if (CurrentState == Ees_IsDead)
		return;

	TArray<AActor*> OverlappingActors;
	DetectionSphere->GetOverlappingActors(OverlappingActors);
	for (int i = 0; i < OverlappingActors.Num(); ++i)
	{
		const auto Actor = Cast<AEyeCharacter>(OverlappingActors[i]);
		if (!Actor)
			continue;
		if (!Actor->GetIsPossessed())
			continue;

		CurrentState = Ees_PreparingAttack;
	}

	EvasionSphere->GetOverlappingActors(OverlappingActors);
	for (int i = 0; i < OverlappingActors.Num(); ++i)
	{
		const auto Actor = Cast<AEyeCharacter>(OverlappingActors[i]);
		if (!Actor)
			continue;
		if (!Actor->GetIsPossessed())
			continue;

		SetIsThreatened(true);
		SetNewMoveTarget();
	}
}

void AEyeEnemy::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                   const FHitResult& SweepResult)
{
	if (CurrentState == Ees_IsDead)
		return;
	if (OtherActor != CharacterRef || Cast<AEyeEntityEyeball>(OtherActor))
		return;
	if (OverlappedComponent == DetectionSphere)
		CurrentState = Ees_PreparingAttack;
	else if (OverlappedComponent == EvasionSphere && !bIsThreatened)
	{
		SetIsThreatened(true);
		SetNewMoveTarget();
	}
}

void AEyeEnemy::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (CurrentState == Ees_IsDead)
		return;
	if (OtherActor != CharacterRef || Cast<AEyeEntityEyeball>(OtherActor))
		return;
	if (OverlappedComponent == DetectionSphere)
	{
		CurrentState = Ees_Idle;
		AttackPreparationTime = 0;
	}
	else if (OverlappedComponent == EvasionSphere)
		SetIsThreatened(false);
}

void AEyeEnemy::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeEnemy::UpdateTarget);
		GameMode->OnChangedState.AddUniqueDynamic(this, &AEyeEnemy::OnPlayerDeath);
	}

	CurrentState = Ees_Idle;
}

void AEyeEnemy::Tick(float DeltaTime)
{
	if (CurrentState == Ees_IsDead)
		return;

	Super::Tick(DeltaTime);

	PrepareAttack(DeltaTime);
	Attack();
	Move(DeltaTime);
}

void AEyeEnemy::ForceSetLocation(FVector const& NewLocation)
{
	SetActorLocation(NewLocation);
}

void AEyeEnemy::UpdateTarget(AEyeCharacter* NewEntity)
{
	if (CurrentState == Ees_IsDead)
		return;

	CharacterRef = NewEntity;

	if (Cast<AEyeEntityEyeball>(CharacterRef))
	{
		SetIsThreatened(false);
		return;
	}

	CheckOverlaps();
}

void AEyeEnemy::OnPlayerDeath(const EGameState NewState)
{
	if (NewState == Egs_StartingGame)
		CurrentState = Ees_Idle;
}