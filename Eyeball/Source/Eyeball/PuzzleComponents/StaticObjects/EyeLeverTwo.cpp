#include "EyeLeverTwo.h"

#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"

void AEyeLeverTwo::InteractWith() const
{
	Super::InteractWith();

	if ((MoveableObjectTwo->GetActorLocation() - MoveableObjectTwo->GetTargetLocation()).Length() < 10.f)
		return;
	
	MoveableObjectTwo->Activate();
}