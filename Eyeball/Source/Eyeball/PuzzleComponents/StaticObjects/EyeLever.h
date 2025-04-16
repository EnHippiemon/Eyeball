#pragma once

#include "CoreMinimal.h"
#include "EyeInteractableObject.h"
#include "EyeLever.generated.h"

enum ELeverHandleState
{
	Elhs_Activated,
	Elhs_Deactivated,
	Elhs_Moving
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
	FRotator BaseRotation = FRotator(50, 0, 0);
	UPROPERTY(EditDefaultsOnly)
	FRotator MaxRotation = FRotator(0, 0, 310);

	bool bShouldDeactivate = false;
	
	ELeverHandleState CurrentState;
	
	void MoveHandle(float const DeltaTime);
	void Deactivate();

	void CheckShouldDeactivate();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* LeverBase;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* LeverHandle;
};