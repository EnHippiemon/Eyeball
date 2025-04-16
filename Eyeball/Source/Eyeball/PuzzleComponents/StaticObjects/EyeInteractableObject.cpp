#include "EyeInteractableObject.h"
#include "../MoveableObjects/EyeMoveableObject.h"
#include "Eyeball/Camera/EyeCamera.h"
#include "Kismet/GameplayStatics.h"

AEyeInteractableObject::AEyeInteractableObject()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEyeInteractableObject::InteractWith() 
{
	for (int i = 0; i < MoveableObject.Num(); ++i)
	{
		StartEvent(MoveableObject[i]);
	}
}

void AEyeInteractableObject::StartEvent(TObjectPtr<AEyeMoveableObject> ObjectToMove)
{
	if ((ObjectToMove->GetActorLocation() - ObjectToMove->GetTargetLocation()).Length() < 10.f
	|| ObjectToMove->GetIsActivated())
		return;
	
	ObjectToMove->Activate();

	CameraRef = Cast<AEyeCamera>(UGameplayStatics::GetActorOfClass(GetWorld(), CameraClass));
	if (CameraRef)
		CameraRef->AddActorToFocus(ObjectToMove, TimeToFocusCameraOnActor);
}