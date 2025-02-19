#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EyeCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

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
	FOnDeath OnDeath;

	virtual void OnSpawned();
	
protected:
	AEyeCharacter();

	FVector GetMovementInput() const { return MovementInput; }
	float GetJumpHeldTime() const { return JumpHeldTime; }
	ECollisionChannel GetSafeZone() const { return SafeZone; }
	ECollisionChannel GetEntityBody() const { return EntityBody; }

#pragma region Move to data asset
	UPROPERTY(EditDefaultsOnly)
	float NormalMovementSpeed = 10.f;
	UPROPERTY(EditDefaultsOnly)
	float MaxTimeInDanger = 1.f;
	UPROPERTY(EditDefaultsOnly)
	float HeldJumpThreshold = 1.f;

	UPROPERTY(EditDefaultsOnly)
	FVector JumpDirection = FVector(0, 0, 1);
	UPROPERTY(EditDefaultsOnly)
	float JumpForce = 10000.f;
#pragma endregion 

	int JumpCount = 0;
	int MaxJumpCount = 1;

	UPROPERTY(EditAnywhere)
	float RadiusFloorCheck;
	UPROPERTY(EditAnywhere)
	float LengthFloorCheck;
	UPROPERTY(EditAnywhere)
	FVector OffsetFloorCheck;
	
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
	
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> SafeZone;
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> EntityBody;
	// Would be cool to make a character that can walk on other surfaces.
	// If so, make it protected. 
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> Floor;
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void HandleJumpInput();
	void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);

	virtual void UnPossessed() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};