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
	AEyeCharacter* PlayerCharacter;
	UPROPERTY()
	AEyeGameMode* GameMode;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataAsset, meta = (AllowPrivateAccess = "true"))
	UEyeMainCameraDataAsset* Data;
	
#pragma endregion 
#pragma region -- FUNCTIONS --

public:
	void OnSpawned();

private:
	void MoveTowardsTarget(const float DeltaTime);
	void ChangePrimaryFocus();
	UFUNCTION()
	void GetNewPlayerReference(AEyeCharacter* NewCharacter);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
#pragma endregion
};