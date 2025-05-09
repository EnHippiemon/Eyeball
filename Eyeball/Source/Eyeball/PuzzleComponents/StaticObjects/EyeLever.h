#pragma once

#include "CoreMinimal.h"
#include "EyeInteractableObject.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "EyeLever.generated.h"

class AEyeGameMode;

enum ELeverHandleState
{
	Elhs_Activated,
	Elhs_Deactivated,
	Elhs_Moving,
	Elhs_Disabled
};

UCLASS()
class EYEBALL_API AEyeLever : public AEyeInteractableObject
{
	GENERATED_BODY()

public:
	AEyeLever();

	virtual void InteractWith() override;

private:
	UPROPERTY(EditDefaultsOnly)
	float RotationSpeed;

	FRotator TargetRotation; 
	UPROPERTY(EditDefaultsOnly)
	FRotator BaseRotation;
	UPROPERTY(EditDefaultsOnly)
	FRotator MaxRotation;

	bool bShouldDeactivate = false;
	
	ELeverHandleState CurrentState;
	
	void MoveHandle(float const DeltaTime);
	void Deactivate();

	void CheckShouldDeactivate();

	UFUNCTION()
	void ResetState(EGameState NewState);

	UFUNCTION()
	void EntityChanged(AEyeCharacter* NewEntity);
	UFUNCTION()
	void HandleCanBeInteractedWith(AActor* FoundActor);
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* LeverBase;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* LeverHandle;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* InteractableMaterial;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* EmptyMaterial;
	
	UPROPERTY()
	AEyeGameMode* GameMode;
	UPROPERTY()
	AEyeCharacter* PlayerCharacter;
};