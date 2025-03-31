#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeMainCameraDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeMainCameraDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float MoveSpeed = 15.f;
	UPROPERTY(EditDefaultsOnly)
	FVector CameraOffset = FVector(-200, 0, 0);
};