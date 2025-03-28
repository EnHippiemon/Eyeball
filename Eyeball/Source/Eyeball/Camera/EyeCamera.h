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
	AActor* Target1;
	UPROPERTY()
	AActor* Target2;
	
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
	void AddActorToFocus(AActor* ActorToAdd);
	void RemoveActorFromFocus(AActor* ActorToRemove);

private:
	void MoveTowardsTarget(float const DeltaTime);
	void ChangeFocus(const TArray<AActor*>& NewActors);
	UFUNCTION()
	void GetNewPlayerReference(AEyeCharacter* NewCharacter);

	FTimerHandle TimerHandle;
	void OnTimerActivated();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
#pragma endregion
};