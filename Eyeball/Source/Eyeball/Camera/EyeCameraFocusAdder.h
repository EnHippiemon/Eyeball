#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeCameraFocusAdder.generated.h"

class AEyeCamera;
class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeCameraFocusAdder : public AActor
{
	GENERATED_BODY()

private:
	AEyeCameraFocusAdder();

	UPROPERTY(EditInstanceOnly)
	TArray<TObjectPtr<AActor>> ObjectsToFocusOn;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AEyeCamera> CameraClass;
	
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxComponent;
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
