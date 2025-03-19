#pragma once

#include "CoreMinimal.h"
#include "../PuzzleComponents/EyeMoveableObject.h"
#include "EyeMoveableDanger.generated.h"

class UEyeDangerComponent;

UCLASS()
class EYEBALL_API AEyeMoveableDanger : public AEyeMoveableObject
{
	GENERATED_BODY()

private:
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};