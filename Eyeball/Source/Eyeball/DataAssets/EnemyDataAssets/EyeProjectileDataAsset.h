#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeProjectileDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeProjectileDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Move")
	float Speed;
	UPROPERTY(EditDefaultsOnly, Category = "Move")
	float MarginToTargetReached;
	UPROPERTY(EditDefaultsOnly, Category = "Move|Positioning")
	FVector PositioningOffset;
	
	UPROPERTY(EditDefaultsOnly, Category = "")
	float LifeSpan;
};