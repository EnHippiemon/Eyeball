#include "EyeProjectile.h"

#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EnemyDataAssets/EyeProjectileDataAsset.h"
#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeProjectile::AEyeProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	DangerSphere = CreateDefaultSubobject<USphereComponent>("DangerSphere");
	DangerSphere->SetupAttachment(GetRootComponent());
	DangerSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeProjectile::HandleBeginOverlap);
}

void AEyeProjectile::OnSpawned()
{
	SetActorLocation(FVector(Data->PositioningOffset.X, GetActorLocation().Y + Data->PositioningOffset.Y,
	                         GetActorLocation().Z + Data->PositioningOffset.Z));

	FTimerDelegate Delegate;
	Delegate.BindLambda([&]() { DestroyProjectile(); });
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, Delegate, Data->LifeSpan, false, Data->LifeSpan);
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

void AEyeProjectile::MoveToTargetLocation(float const DeltaTime)
{
	auto NewPosition = GetActorLocation() + TargetOffset * TargetDirection * Data->Speed * DeltaTime;
	SetActorRelativeLocation(NewPosition);
}

void AEyeProjectile::DestroyProjectile()
{
	// Got a crash once because it tried to destroy when it was already destroyed.
	if (this)
		Destroy();
}

void AEyeProjectile::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	if (OtherActor == ShootingActor || !ShootingActor)
		return;
	
	if (AEyeEnemy* FoundActor = Cast<AEyeEnemy>(OtherActor))
	{
		FoundActor->ChangeHealth(-1);
	}
	
	if (AEyeCharacter* FoundActor = Cast<AEyeCharacter>(OtherActor))
	{
		if (!FoundActor->GetIsPossessed())
			return;
		FoundActor->TakeDamage();
	}
}

void AEyeProjectile::Tick(float DeltaTime)
{
	if (!bCanMove)
		return;
	
	Super::Tick(DeltaTime);
	MoveToTargetLocation(DeltaTime);
}
