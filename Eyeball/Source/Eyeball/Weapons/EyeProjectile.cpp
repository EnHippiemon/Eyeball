#include "EyeProjectile.h"

#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EnemyDataAssets/EyeProjectileDataAsset.h"
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

void AEyeProjectile::MoveToTargetLocation(float const DeltaTime)
{
	auto NewPosition = GetActorLocation() + TargetOffset * TargetDirection * Data->Speed * DeltaTime;
	SetActorRelativeLocation(NewPosition);

	if ((NewPosition - TargetLocation).Length() < Data->MarginToTargetReached)
		DestroyProjectile();
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
	AEyeCharacter* FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;
	if (!FoundActor->GetIsPossessed())
		return;
	FoundActor->TakeDamage();

	DestroyProjectile();
}

void AEyeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToTargetLocation(DeltaTime);
}
