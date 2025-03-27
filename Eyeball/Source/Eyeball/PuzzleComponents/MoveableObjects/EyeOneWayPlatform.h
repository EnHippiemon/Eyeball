#pragma once

#include "CoreMinimal.h"
#include "EyeMoveableObject.h"
#include "EyeOneWayPlatform.generated.h"

UCLASS()
class EYEBALL_API AEyeOneWayPlatform : public AEyeMoveableObject
{
	GENERATED_BODY()

private:
	AEyeOneWayPlatform();
	
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BlockingCollision;
};