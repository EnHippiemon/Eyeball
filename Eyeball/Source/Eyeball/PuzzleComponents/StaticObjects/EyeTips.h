#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeTips.generated.h"

class UEyeTipsWidget;
class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeTips : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	int TimeBeforeTips = 2;
	
	bool bPlayerHasEntered = false;
	float TimeSincePlayerEntered = 0;
	
	bool bPlayerHasLeft = false;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void CountTimeSincePlayerEntered(float const DeltaTime);
	void HandlePlayerHasLeft();
	
	AEyeTips();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UBoxComponent* EnterBox;
	UPROPERTY(EditAnywhere)
	UBoxComponent* ExitBox;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UEyeTipsWidget> EyeTipsWidget;
	TObjectPtr<UEyeTipsWidget> EyeTipsWidgetRef;
};