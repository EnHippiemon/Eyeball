#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeDanger.generated.h"

class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeDanger : public AActor
{
	GENERATED_BODY()
	
private:
	AEyeDanger();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* DangerBox;
};