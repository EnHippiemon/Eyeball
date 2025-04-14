#include "EyeProjectile.h"

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Eyeball/Camera/EyeCameraFocusAdder.h"
#include "Eyeball/DataAssets/EnemyDataAssets/EyeProjectileDataAsset.h"
#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Eyeball/GameState/EyeCheckpoint.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"
#include "Eyeball/PuzzleComponents/StaticObjects/EyeLaserDetector.h"

AEyeProjectile::AEyeProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSphere = CreateDefaultSubobject<USphereComponent>("DangerSphere");
	RootSphere->SetupAttachment(GetRootComponent());

	DangerCapsule = CreateDefaultSubobject<UCapsuleComponent>("DangerCapsule");
	DangerCapsule->SetupAttachment(RootSphere);
	DangerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AEyeProjectile::HandleBeginOverlap);
}

void AEyeProjectile::OnSpawned()
{
	SetActorLocation(FVector(Data->PositioningOffset.X, GetActorLocation().Y + Data->PositioningOffset.Y,
	                         GetActorLocation().Z + Data->PositioningOffset.Z));
}

void AEyeProjectile::SetTarget(const FVector& NewTarget)
{
	TargetLocation = FVector(Data->PositioningOffset.X, NewTarget.Y, NewTarget.Z);

	TargetOffset = FVector(0, FMath::Abs(TargetLocation.Y - GetActorLocation().Y),
	                       FMath::Abs(TargetLocation.Z - GetActorLocation().Z));
	TargetOffset.Normalize();
	
	const int DirectionY = TargetLocation.Y > GetActorLocation().Y ? 1 : -1;
	const int DirectionZ = TargetLocation.Z > GetActorLocation().Z ? 1 : -1;
	TargetDirection = FVector(0, DirectionY, DirectionZ);
}

void AEyeProjectile::SetShootingActor(const TObjectPtr<AActor>& NewActor)
{
	ShootingActor = NewActor;
}

void AEyeProjectile::DestructionCountdown(float const DeltaTime)
{
	TimeSinceSpawned += DeltaTime;
	if (TimeSinceSpawned >= Data->LifeSpan)
		Destroy();
}

void AEyeProjectile::MoveToTargetLocation(float const DeltaTime)
{
	auto NewPosition = GetActorLocation() + TargetOffset * TargetDirection * Data->Speed * DeltaTime;
	SetActorRelativeLocation(NewPosition);
}

void AEyeProjectile::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	if (!bCanMove)
		return;
	if (OverlappedComponent != DangerCapsule)
		return;
	if (OtherActor == ShootingActor || !ShootingActor)
		return;
	if (Cast<AEyeProjectile>(OtherActor)
		|| Cast<AEyeCheckpoint>(OtherActor)
		|| Cast<AEyeCameraFocusAdder>(OtherActor)
		|| Cast<AEyeLaserDetector>(OtherActor))
		return;
	
	if (AEyeEnemy* FoundActor = Cast<AEyeEnemy>(OtherActor))
	{
		FoundActor->ChangeHealth(-1);
		return;
	}
	
	if (AEyeCharacter* FoundActor = Cast<AEyeCharacter>(OtherActor))
	{
		if (!FoundActor->GetIsPossessed())
			return;
		FoundActor->TakeDamage();
		return;
	}

	if (Cast<AEyeMoveableObject>(OtherActor))
	{
		Destroy();
		return;
	}
	
	bCanMove = false;
}

void AEyeProjectile::Tick(float DeltaTime)
{
	if (!bCanMove)
		return;
	
	Super::Tick(DeltaTime);

	DestructionCountdown(DeltaTime);
	MoveToTargetLocation(DeltaTime);
}