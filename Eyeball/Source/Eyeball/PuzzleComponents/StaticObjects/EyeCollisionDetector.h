#pragma once

#include "CoreMinimal.h"
#include "EyeLever.h"
#include "EyeCollisionDetector.generated.h"

class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeCollisionDetector : public AEyeLever
{
	GENERATED_BODY()

private:
	AEyeCollisionDetector();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox;
};