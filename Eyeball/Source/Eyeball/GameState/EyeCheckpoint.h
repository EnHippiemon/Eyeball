#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeCheckpoint.generated.h"

class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeCheckpoint : public AActor
{
	GENERATED_BODY()
	
private:
	AEyeCheckpoint();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxComponent;
};
