#pragma once

#include "CoreMinimal.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "EyeCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDangerChanged, bool, IsInDanger, float, TimeDilationAmount, float, MaxDangerTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

class UEyeCharacterDataAsset;
class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeCharacter : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnCharacterChanged OnCharacterChanged;
	UPROPERTY()
	FOnEject OnEject;
	UPROPERTY()
	FOnDangerChanged OnDangerChanged;
	UPROPERTY()
	FOnDeath OnDeath;

	virtual void OnSpawned();
	virtual void DamagePlayer();
	
protected:
	AEyeCharacter();

	/* Getters */
		FVector GetMovementInput() const { return MovementInput; }
		bool GetJumpDepressed() const { return bJumpDepressed; }
		float GetJumpHeldTime() const { return JumpHeldTime; }
		int GetJumpCount() const { return JumpCount; }
		bool GetIsOnFloor() const { return bIsOnFloor; }
		ECollisionChannel GetSafeZone() const { return EntityData->SafeZone; }
		ECollisionChannel GetEntityBody() const { return EntityData->EntityBody; }

	float CurrentMovementSpeed;
	bool bIsUnPossessed;
	
	virtual void MakeMovement(const float DeltaTime) {}
	virtual void Force2DMovement();

	virtual void MakeJump();
	virtual void MakeReleaseJump() {}
	virtual void ResetJumpCount();

	virtual void HandleActionInput();
	virtual void HandleEjectInput();
	
	virtual bool CheckIsJumpHeld(float Threshold);

	virtual void PossessNewEntity(AEyeCharacter* EntityToPossess);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataAsset, meta = (AllowPrivateAccess = "true"))
	UEyeCharacterDataAsset* EntityData;

private:
	FVector MovementInput;

	bool bIsDead = false;
	
	bool bJumpDepressed = false;
	bool bJumpHeld = false;
	float JumpHeldTime = 0.f;
	int JumpCount = 0;
	bool bIsOnFloor = false;

	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void HandleJumpInput();
	void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);

	virtual void UnPossessed() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};