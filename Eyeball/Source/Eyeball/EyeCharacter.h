#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EyeCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEject);

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

	virtual void OnSpawned();
	
protected:
	AEyeCharacter();

	FVector GetMovementInput() const { return MovementInput; }
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
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void HandleJumpInput();
	void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};