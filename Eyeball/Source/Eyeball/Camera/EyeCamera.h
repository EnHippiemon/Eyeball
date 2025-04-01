#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "EyeCamera.generated.h"

class USpotLightComponent;
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

	float CameraFOVCompensation = 1.f;
	
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
	UPROPERTY(EditDefaultsOnly)
	USpotLightComponent* SpotLight;
	
#pragma endregion 
#pragma region -- FUNCTIONS --

public:
	void OnSpawned();
	// If TimerDelay is 0 or less, focus will stay until RemoveActorFromFocus is called. 
	void AddActorToFocus(AActor* ActorToAdd, float const TimerDelay);
	void RemoveActorFromFocus(AActor* ActorToRemove);
	
private:
	FTimerHandle TimerHandle;

	void MoveTowardsTarget(float const DeltaTime);
	float FindDistanceBetweenActors();
	UFUNCTION()
	void GetNewPlayerReference(AEyeCharacter* NewCharacter);

	void SetRotation();
	void CameraOffsetCompensationForFOV();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
#pragma endregion
};