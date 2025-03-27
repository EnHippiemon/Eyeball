#include "EyeOneWayPlatform.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeOneWayPlatform::AEyeOneWayPlatform()
{
	BlockingCollision = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	BlockingCollision->SetupAttachment(RootComponent);
	BlockingCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AEyeOneWayPlatform::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		const auto ActorLocationZ = OtherActor->GetActorLocation().Z;
		const auto ComponentLocationZ = OverlappedComponent->GetComponentLocation().Z;
		if (ActorLocationZ < ComponentLocationZ)
			BlockingCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		else
			BlockingCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
}

void AEyeOneWayPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEyeOneWayPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}