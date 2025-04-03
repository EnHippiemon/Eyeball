#include "EyeEnemy.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EnemyDataAssets/EyeEnemyDataAsset.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Eyeball/Weapons/EyeProjectile.h"
#include "Kismet/GameplayStatics.h"

AEyeEnemy::AEyeEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	RootCollider = CreateDefaultSubobject<UCapsuleComponent>("RootCollider");
	RootComponent = RootCollider;
	
	DetectionSphere = CreateDefaultSubobject<USphereComponent>("DetectionSphere");
	DetectionSphere->SetupAttachment(RootCollider);
	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeEnemy::HandleBeginOverlap);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &AEyeEnemy::HandleEndOverlap);
	
	EvasionSphere = CreateDefaultSubobject<USphereComponent>("EvasionSphere");
	EvasionSphere->SetupAttachment(RootCollider);
	EvasionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeEnemy::HandleBeginOverlap);
	EvasionSphere->OnComponentEndOverlap.AddDynamic(this, &AEyeEnemy::HandleEndOverlap);
}

void AEyeEnemy::KillThisActor()
{
	Destroy();
}

void AEyeEnemy::PrepareAttack(float const DeltaTime)
{
	if (CurrentState != Ees_PreparingAttack)
		return;

	// UE_LOG(LogTemp, Log, TEXT("Preparing attack"));
	
	AttackPreparationTime += DeltaTime;
	if (AttackPreparationTime >= Data->AttackDelay)
		CurrentState = Ees_Attacking;
}

void AEyeEnemy::Attack()
{
	if (CurrentState != Ees_Attacking)
		return;
	
	// UE_LOG(LogTemp, Log, TEXT("Attacking"));
	
	// for (int i = 0; i < Data->ProjectilesPerAttack; ++i)
	// {
	// 	const auto AccuracyOffset = FVector(0, FMath::FRandRange(-Data->AttackAccuracy.Y, Data->AttackAccuracy.Y),
	// 	                                    FMath::FRandRange(-Data->AttackAccuracy.Z, Data->AttackAccuracy.Z));
	// 	const auto Target = AccuracyOffset + CharacterRef->GetActorLocation();
	// 	
	// 	auto ThisProjectile = Cast<AEyeProjectile>(GetWorld()->SpawnActor(Data->Projectile));
	// 	ThisProjectile->SetTarget(Target);
	// }
	
	AttackPreparationTime = 0;
	CurrentState = Ees_PreparingAttack;
}

void AEyeEnemy::Move(float const DeltaTime)
{
	if (CurrentState != Ees_Moving)
		return;

	// UE_LOG(LogTemp, Log, TEXT("Moving"));


	// FVector MoveOffsetY = FMath::Abs(GetActorLocation() + Data->DistanceForEvasion);
	
	const FVector TargetLocation = FVector(TargetMoveOffset.X, TargetMoveOffset.Y, Data->bCanFly ? TargetMoveOffset.Z : GetActorLocation().Z);

	UE_LOG(LogTemp, Log, TEXT("Final Target Location: %s"), *TargetLocation.ToString());
	
	auto NewLocation = GetActorLocation();
	NewLocation = FMath::Lerp(NewLocation, TargetLocation, DeltaTime * Data->MovementSpeed);
	SetActorLocation(NewLocation);

	DrawDebugLine(GetWorld(), NewLocation, TargetLocation, FColor::Purple, false, -1, 0, 5);

	if (!FMath::IsNearlyZero((TargetLocation - NewLocation).Length()))
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
	
	TargetMoveOffset = GetActorLocation() + FVector(Data->DistanceForEvasion.X, Data->DistanceForEvasion.Y * DirectionY, Data->DistanceForEvasion.Z * DirectionZ);
	UE_LOG(LogTemp, Log, TEXT("Setting New Move Target: %s"), *TargetMoveOffset.ToString());
	CurrentState = Ees_Moving;
}

void AEyeEnemy::SetIsThreatened(bool const IsThreatened)
{
	bIsThreatened = IsThreatened;
}

void AEyeEnemy::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != CharacterRef)
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
	if (OtherActor != CharacterRef)
		return;
	if (OverlappedComponent == DetectionSphere)
	{
		CurrentState = Ees_Idle;
		AttackPreparationTime = 0;
		UE_LOG(LogTemp, Log, TEXT("Idle"));
	}
	else if (OverlappedComponent == EvasionSphere)
	{
		SetIsThreatened(false);
		CurrentState = Ees_PreparingAttack;
	}
}

void AEyeEnemy::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeEnemy::UpdateTarget);

	CurrentState = Ees_Idle;
}

void AEyeEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	PrepareAttack(DeltaTime);
	Attack();
	Move(DeltaTime);
	
}

void AEyeEnemy::UpdateTarget(AEyeCharacter* NewEntity)
{
	CharacterRef = NewEntity;
}