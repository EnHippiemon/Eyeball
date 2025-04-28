#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeMainCameraDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeMainCameraDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// The normal movement speed of the camera
	UPROPERTY(EditDefaultsOnly)
	float NormalMoveSpeed = 15.f;
	// The movement speed of the camera after losing focus on more actors than the player. 
	UPROPERTY(EditDefaultsOnly)
	float RetractCameraSpeed = 1.f;
	// How close to target the camera must be before the normal move speed kicks in. 
	UPROPERTY(EditDefaultsOnly)
	float ResetCameraRetractionTolerance;
	// How the camera should be placed in relation to the player character
	UPROPERTY(EditDefaultsOnly)
	FVector CameraOffset = FVector(-200, 0, 0);
};