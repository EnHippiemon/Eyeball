#pragma once

#include "CoreMinimal.h"
#include "Eyeball/PuzzleComponents/StaticObjects/EyeLaserDetector.h"
#include "EyeAttachedLaserDetector.generated.h"

UCLASS()
class EYEBALL_API AEyeAttachedLaserDetector : public AEyeLaserDetector
{
	GENERATED_BODY()

private:
	AEyeAttachedLaserDetector();

	FVector StartPoint;
	
	virtual void SearchForVictim() override;
	void FollowObject();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AEyeMoveableObject> ObjectToFollow;
};