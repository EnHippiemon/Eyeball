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
	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;
	if (!FoundActor->GetIsPossessed())
		return;

	BlockingCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEyeOneWayPlatform::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;
	if (!FoundActor->GetIsPossessed())
		return;

	BlockingCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
