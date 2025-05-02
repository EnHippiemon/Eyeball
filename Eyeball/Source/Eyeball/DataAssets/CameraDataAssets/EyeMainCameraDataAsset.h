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
	
	// The movement speed of the camera on the X-axis after losing focus on more actors than the player. 
	UPROPERTY(EditDefaultsOnly)
	float RetractCameraStartSpeedX = 0.f;
	
	// How fast the retraction speed should increase to reach normal speed on the X-axis
	UPROPERTY(EditDefaultsOnly)
	float RetractCameraSpeedXIncrementation = 1.f;
	
	// The movement speed of the camera after losing focus on more actors than the player. 
	UPROPERTY(EditDefaultsOnly)
	float RetractCameraSpeedYZ = 1.f;

	// The movement speed of the camera when focusing on more actors than the player.
	UPROPERTY(EditDefaultsOnly)
	float SeveralFocusesCameraSpeed = 3.f;
	
	// How the camera should be placed in relation to the player character
	UPROPERTY(EditDefaultsOnly)
	FVector CameraOffset = FVector(-200, 0, 0);
	
	// Allowed distance between center of camera and possessed entity
	UPROPERTY(EditDefaultsOnly)
	float AllowedDistanceToPlayer = 100.f;

	// Set speed if distance to player is too far
	UPROPERTY(EditDefaultsOnly)
	float LimitDistanceToPlayerSpeed = 2.f;
	
	UPROPERTY(EditDefaultsOnly)
	float YDistanceMultiplier = 1.5f;
	
	UPROPERTY(EditDefaultsOnly)
	float ZDistanceMultiplier = 1.5f;
};