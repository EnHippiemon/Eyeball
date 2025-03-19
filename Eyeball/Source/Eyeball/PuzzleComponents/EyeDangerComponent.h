#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EyeDangerComponent.generated.h"

class UBoxComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EYEBALL_API UEyeDangerComponent : public USceneComponent
{
	GENERATED_BODY()

private:
	UEyeDangerComponent();

	// UFUNCTION()
	// void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//
	// UPROPERTY(EditAnywhere)
	// UBoxComponent* DangerBox;
};