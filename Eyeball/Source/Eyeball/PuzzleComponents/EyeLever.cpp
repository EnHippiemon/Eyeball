#include "EyeLever.h"
#include "EyeMoveableObject.h"

AEyeLever::AEyeLever()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEyeLever::InteractWith() const
{
	if ((MoveableObject->GetActorLocation() - MoveableObject->GetTargetLocation()).Length() < 10.f)
		return;
	
	MoveableObject->Activate();
}