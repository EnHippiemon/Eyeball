#include "EyeLeverTwo.h"

#include "Eyeball/Camera/EyeCamera.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"

void AEyeLeverTwo::InteractWith()
{
	Super::InteractWith();

	StartEvent(MoveableObjectTwo);
}