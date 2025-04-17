#include "EyeCollisionDetector.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"


AEyeCollisionDetector::AEyeCollisionDetector()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AEyeCollisionDetector::HandleBeginOverlap);
}

void AEyeCollisionDetector::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;
	if (!FoundActor->GetIsPossessed())
		return;
	
	InteractWith();
}