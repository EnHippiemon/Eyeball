#include "../GameState/EyeCheckpoint.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeCheckpoint::AEyeCheckpoint()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box");
	RootComponent = BoxComponent;

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AEyeCheckpoint::HandleBeginOverlap);
}

void AEyeCheckpoint::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;

	if (!FoundActor->GetIsPossessed())
		return;
	
	FoundActor->OnCheckpointReached.Broadcast();
}