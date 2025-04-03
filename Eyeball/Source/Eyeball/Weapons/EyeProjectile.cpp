#include "EyeProjectile.h"

#include "Components/SphereComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeProjectile::AEyeProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	DangerSphere = CreateDefaultSubobject<USphereComponent>("DangerSphere");
	DangerSphere->SetupAttachment(GetRootComponent());
	DangerSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeProjectile::HandleBeginOverlap);
}

void AEyeProjectile::SetTarget(const FVector& NewTarget)
{
	TargetLocation = NewTarget;
	// Speed = ProjectileSpeed;
}

void AEyeProjectile::MoveToTargetLocation(float const DeltaTime)
{
	auto NewPosition = GetActorLocation();
	NewPosition = FMath::Lerp(NewPosition, TargetLocation, Speed * DeltaTime);
	SetActorLocation(NewPosition);

	if (FMath::IsNearlyZero((NewPosition - TargetLocation).Length()))
		DestroyProjectile();
}

void AEyeProjectile::DestroyProjectile()
{
	Destroy();
}

void AEyeProjectile::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEyeCharacter* FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (FoundActor)
		FoundActor->DamagePlayer();
	
	DestroyProjectile();
}

void AEyeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToTargetLocation(DeltaTime);
}