#include "EyeTipsOnStart.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"


void AEyeTipsOnStart::CheckOverlaps()
{
	TArray<AActor*> OverlappingActors;
	EnterBox->GetOverlappingActors(OverlappingActors, AEyeCharacter::StaticClass());
	for (int i = 0; i < OverlappingActors.Num(); ++i)
	{
		const auto CurrentActor = Cast<AEyeCharacter>(OverlappingActors[i]);
		if (!Cast<AEyeCharacter>(OverlappingActors[i]))
			continue;
		if (!CurrentActor->GetIsPossessed())
			return;

		bPlayerHasEntered = true;
		bPlayerHasLeft = false;
		break;
	}
}

void AEyeTipsOnStart::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEyeTipsOnStart::CheckOverlaps, TimeBeforeTips, false, TimeBeforeTips);
}
