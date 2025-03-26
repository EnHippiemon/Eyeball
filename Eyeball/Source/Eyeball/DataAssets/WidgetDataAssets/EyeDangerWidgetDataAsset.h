#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeDangerWidgetDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeDangerWidgetDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float TransitionSpeed;
	
	UPROPERTY(EditAnywhere)
	FVector2D Box1Offset;
	UPROPERTY(EditAnywhere)
	FVector2D Box2Offset;
	
	UPROPERTY(EditAnywhere)
	FVector2D Box1StartTransform;
	UPROPERTY(EditAnywhere)
	FVector2D Box2StartTransform;
};
