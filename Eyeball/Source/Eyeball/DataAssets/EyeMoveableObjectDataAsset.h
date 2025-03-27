#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeMoveableObjectDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeMoveableObjectDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	bool bShouldTick;
	UPROPERTY(EditAnywhere)
	bool bStartActivated;
	UPROPERTY(EditAnywhere)
	bool bShouldLoop;
	UPROPERTY(EditAnywhere)
	FVector MoveDirection;
	UPROPERTY(EditAnywhere)
	float MoveSpeed;
	UPROPERTY(EditAnywhere)
	FVector TargetOffset;
	UPROPERTY(EditAnywhere)
	bool ReturnToStartLocation;
};
