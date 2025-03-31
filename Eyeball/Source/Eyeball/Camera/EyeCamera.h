#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "EyeCamera.generated.h"

class UEyeMainCameraDataAsset;
class AEyeGameMode;
class AEyeCharacter;

UCLASS()
class EYEBALL_API AEyeCamera : public ACameraActor
{
	GENERATED_BODY()

private:
	AEyeCamera();

#pragma region -- Variables --

	
#pragma endregion 

#pragma region -- REFERENCES --
	
	UPROPERTY()
	TArray<AActor*> FocusedActors;
	UPROPERTY()
	AEyeCharacter* PlayerCharacter;
	UPROPERTY()
	AEyeGameMode* GameMode;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataAsset, meta = (AllowPrivateAccess = "true"))
	UEyeMainCameraDataAsset* Data;
	
#pragma endregion 
#pragma region -- FUNCTIONS --

public:
	void OnSpawned();
	void AddActorToFocus(AActor* ActorToAdd, float const TimerDelay);

private:
	FTimerHandle TimerHandle;

	void MoveTowardsTarget(float const DeltaTime);
	float FindDistanceBetweenActors();
	void ChangeFocus(const TArray<AActor*>& NewActors);
	UFUNCTION()
	void GetNewPlayerReference(AEyeCharacter* NewCharacter);
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
#pragma endregion
};