#pragma once

#include "CoreMinimal.h"
#include "EyeInteractableObject.h"
#include "GameFramework/Actor.h"
#include "EyeLaserDetector.generated.h"

class UEyeLaserDetectorDataAsset;
class AEyeMoveableObject;

UCLASS()
class EYEBALL_API AEyeLaserDetector : public AEyeInteractableObject
{
	GENERATED_BODY()

protected:
	AEyeLaserDetector();

	float TraceLength;

	virtual void SearchForVictim();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditInstanceOnly)
	UEyeLaserDetectorDataAsset* Data;
};