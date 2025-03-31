#include "EyeLeverTwo.h"

#include "Eyeball/Camera/EyeCamera.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"

void AEyeLeverTwo::InteractWith()
{
	Super::InteractWith();

	StartEvent(MoveableObjectTwo);
	// if ((MoveableObjectTwo->GetActorLocation() - MoveableObjectTwo->GetTargetLocation()).Length() < 10.f
	// 	|| MoveableObjectTwo->GetIsActivated())
	// 	return;
	//
	// MoveableObjectTwo->Activate();
	//
	// if (GetCamera())
	// 	GetCamera()->AddActorToFocus(MoveableObjectTwo, TimeToFocusCameraOnActor);
}