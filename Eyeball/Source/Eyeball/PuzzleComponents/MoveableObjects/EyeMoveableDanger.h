#pragma once

#include "CoreMinimal.h"
#include "../MoveableObjects/EyeMoveableObject.h"
#include "EyeMoveableDanger.generated.h"

class AEyeGameMode;
class UEyeDangerComponent;

UCLASS()
class EYEBALL_API AEyeMoveableDanger : public AEyeMoveableObject
{
	GENERATED_BODY()
	
private:
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	void CheckOverlaps() const;
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* DangerBox;
	UPROPERTY()
	AEyeGameMode* GameMode;

	FTimerHandle DangerTimer;
};