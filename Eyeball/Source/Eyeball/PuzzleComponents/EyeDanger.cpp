#include "../PuzzleComponents/EyeDanger.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeDanger::AEyeDanger()
{
	PrimaryActorTick.bCanEverTick = false;

	DangerBox = CreateDefaultSubobject<UBoxComponent>("DangerBox");
	RootComponent = DangerBox;

	DangerBox->OnComponentBeginOverlap.AddDynamic(this, &AEyeDanger::HandleBeginOverlap);
}

void AEyeDanger::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;

	FoundActor->DamagePlayer();
}