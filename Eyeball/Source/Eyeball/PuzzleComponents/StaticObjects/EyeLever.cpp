#include "EyeLever.h"
#include "../MoveableObjects/EyeMoveableObject.h"
#include "Eyeball/Camera/EyeCamera.h"
#include "Kismet/GameplayStatics.h"

AEyeLever::AEyeLever()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEyeLever::InteractWith() const
{
	if ((MoveableObject->GetActorLocation() - MoveableObject->GetTargetLocation()).Length() < 10.f
		|| MoveableObject->GetIsActivated())
		return;
	
	MoveableObject->Activate();
	
	const auto Camera = Cast<AEyeCamera>(UGameplayStatics::GetActorOfClass(GetWorld(), CameraClass));
	if (Camera)
		Camera->AddActorToFocus(MoveableObject);
}