#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeDanger.generated.h"

class AEyeCharacter;
class AEyeGameMode;
class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeDanger : public AActor
{
	GENERATED_BODY()
	
private:
	AEyeDanger();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void CheckOverlaps();
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* DangerBox;
	UPROPERTY()
	AEyeGameMode* GameMode;
	UPROPERTY()
	AEyeCharacter* PlayerCharacter;

	FTimerHandle DangerTimer;
};