#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EyeCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDangerChanged, bool, IsInDanger, float, TimeDilationAmount, float, MaxDangerTime);

class UBoxComponent;
UCLASS()
class EYEBALL_API AEyeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnCharacterChanged OnCharacterChanged;
	UPROPERTY()
	FOnEject OnEject;
	UPROPERTY()
	FOnDangerChanged OnDangerChanged;

	virtual void OnSpawned();
	
protected:
	AEyeCharacter();

	/* Getters */
		FVector GetMovementInput() const { return MovementInput; }
		float GetJumpHeldTime() const { return JumpHeldTime; }
		ECollisionChannel GetSafeZone() const { return SafeZone; }
		ECollisionChannel GetEntityBody() const { return EntityBody; }
		int GetJumpCount() const { return JumpCount; }
		bool GetIsOnFloor() const { return bIsOnFloor; }

	/* Movement */
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float NormalMovementSpeed = 10.f;

	/* Danger */
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float MaxTimeInDanger = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float TimeDilationDanger = 0.2f;

	/* Jump */
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float HeldJumpThreshold = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		FVector JumpDirection = FVector(0, 0, 1);
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float JumpForce = 10000.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		int MaxJumpCount = 1;
		
		UPROPERTY(EditAnywhere, Category="Jump")
		float RadiusFloorCheck;
		UPROPERTY(EditAnywhere, Category="Jump")
		float LengthFloorCheck;
		UPROPERTY(EditAnywhere, Category="Jump")
		FVector OffsetFloorCheck;

	/* Positioning */
		UPROPERTY(EditDefaultsOnly, Category="Positioning")
		FVector OffsetActorPlacement = FVector(0, 0, 0);
	
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

private:
	FVector MovementInput;
	
	bool bJumpDepressed = false;
	bool bJumpHeld = false;
	float JumpHeldTime = 0.f;
	int JumpCount = 0;
	bool bIsOnFloor = false;
	
	UPROPERTY(EditDefaultsOnly, Category="Collision")
	TEnumAsByte<ECollisionChannel> SafeZone;
	UPROPERTY(EditDefaultsOnly, Category="Collision")
	TEnumAsByte<ECollisionChannel> EntityBody;
	// Would be cool to make a character that can walk on other surfaces.
	// If so, make it protected. 
	UPROPERTY(EditDefaultsOnly, Category="Collision")
	TEnumAsByte<ECollisionChannel> Floor;
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void HandleJumpInput();
	void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);

	virtual void UnPossessed() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};