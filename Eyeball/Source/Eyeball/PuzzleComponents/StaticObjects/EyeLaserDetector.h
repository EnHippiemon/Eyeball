#pragma once

#include "CoreMinimal.h"
#include "EyeLever.h"
#include "GameFramework/Actor.h"
#include "EyeLaserDetector.generated.h"

class UEyeLaserDetectorDataAsset;
class AEyeMoveableObject;

UCLASS()
class EYEBALL_API AEyeLaserDetector : public AEyeLever
{
	GENERATED_BODY()

private:
	AEyeLaserDetector();

	FVector StartPoint;
	float TraceLength;
	
	void SearchForVictim();
	void FollowObject();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AActor> ObjectToFollow;
	UPROPERTY(EditInstanceOnly)
	UEyeLaserDetectorDataAsset* Data;
};