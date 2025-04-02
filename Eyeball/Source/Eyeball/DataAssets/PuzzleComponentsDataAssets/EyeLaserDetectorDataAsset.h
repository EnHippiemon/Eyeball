#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeLaserDetectorDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeLaserDetectorDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FVector LineDirection;
	UPROPERTY(EditDefaultsOnly)
	FVector TraceDirection;
	UPROPERTY(EditDefaultsOnly)
	FVector TraceOffset;
	UPROPERTY(EditDefaultsOnly)
	int TraceAmount;
	UPROPERTY(EditDefaultsOnly)
	float DistanceBetweenTraces;
	UPROPERTY(EditDefaultsOnly)
	float TraceLength;
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> VictimCollisionChannel;
};
