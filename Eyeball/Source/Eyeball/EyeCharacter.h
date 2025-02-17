#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EyeCharacter.generated.h"


// Add delegate for ejection. Figure spawning. 
//
//
// .
// Working on possessing. Do I need an actor, pawn or charadcter?
// 
// Create line traces all around the sphere, going in on X-axis. If any of them
// finds danger zone, start bool that determines timer.
// If none of them finds danger zone, reset bool and timer.

// Make a changed state delegate

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);

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

public:
	UPROPERTY()
	FOnCharacterChanged OnCharacterChanged;
	
protected:
	AEyeCharacter();

	FVector GetMovementInput() const { return MovementInput; }
	EEntityState GetEntityState() const { return CurrentEntityState; }
	float GetJumpHeldTime() const { return JumpHeldTime; }
	ECollisionChannel GetSafeZone() const { return SafeZone; }
	ECollisionChannel GetEntityBody() const { return EntityBody; }

	// UPROPERTY(EditDefaultsOnly)
	// TArray<AActor*> PossessableEntities;
	
	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed = 10.f;
	UPROPERTY(EditDefaultsOnly)
	float MaxTimeInDanger = 1.f;
	UPROPERTY(EditDefaultsOnly)
	float HeldJumpThreshold = 1.f;
	
	virtual void MakeMovement(const float DeltaTime) {}

	virtual void MakeJump() {}
	virtual void MakeReleaseJump() {}

	virtual void HandleActionInput();
	
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
	
	EEntityState CurrentEntityState;
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void HandleJumpInput();
	void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);
	
	void HandleEjectInput();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};