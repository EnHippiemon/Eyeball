#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EyeCharacter.generated.h"


// Create line traces all around the sphere, going in on X-axis. If any of them
// finds danger zone, start bool that determines timer.
// If none of them finds danger zone, reset bool and timer.

// Make a changed state delegate

enum EEntityState
{
	Ees_Eyeball,
	Ees_Human
};

class UBoxComponent;
UCLASS()
class EYEBALL_API AEyeCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	AEyeCharacter();

	FVector GetMovementInput() const { return MovementInput; }
	EEntityState GetEntityState() const { return CurrentEntityState; }
	float GetJumpHeldTime() const { return JumpHeldTime; }
	ECollisionChannel GetSafeZone() const { return SafeZone; }
	ECollisionChannel GetEntityBody() const { return EntityBody; }
	
	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed = 10.f;
	UPROPERTY(EditDefaultsOnly)
	float MaxTimeInDanger = 1.f;
	UPROPERTY(EditDefaultsOnly)
	float HeldJumpThreshold = 1.f;
	
	virtual void MakeMovement(const float DeltaTime) {}

	virtual void MakeJump() {}
	virtual void MakeReleaseJump() {}
	
	virtual bool CheckIsJumpHeld(float Threshold);

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
	
	EEntityState CurrentEntityState;
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	virtual void HandleJumpInput();
	virtual void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);
	
	void HandleActionInput();
	void HandleEjectInput();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};


