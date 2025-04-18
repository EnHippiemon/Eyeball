#pragma once

#include "CoreMinimal.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "EyeCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEject);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDangerFound, bool, IsInDanger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCheckpointReached);

class UEyeCharacterDataAsset;
class UBoxComponent;
class AEyeGameMode;

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
	FOnDangerChanged OnDangerFound;
	UPROPERTY()
	FOnDeath OnDeath;
	UPROPERTY()
	FOnCheckpointReached OnCheckpointReached;

	virtual void OnSpawned();
	virtual void TakeDamage();

	/* Setters */
		void SetArtificialInput(const FVector& Direction);
		void SetMoveDirection(const FVector& NewDirection) { MovementDirection = NewDirection; }
		void ResetPosition();

	/* Getters */
		FVector GetMovementDirection() const { return MovementDirection; }
		bool GetIsPossessed() const { return !bIsUnPossessed; }
	
protected:
	AEyeCharacter();

	/* Setters */
		void AddJumpCount(const int Value) { JumpCount += Value; }

	/* Getters */
		FVector GetMovementInput() const { return MovementInput; }
		bool GetJumpDepressed() const { return bJumpDepressed; }
		float GetJumpHeldTime() const { return JumpHeldTime; }
		bool GetCanJump() const { return JumpCount < EntityData->MaxJumpCount;}
		int GetJumpCount() const { return JumpCount; }
		bool GetIsOnFloor() const { return bIsOnFloor; }
		ECollisionChannel GetSafeZone() const { return EntityData->SafeZone; }
		ECollisionChannel GetEntityBody() const { return EntityData->EntityBody; }

	float CurrentMovementSpeed;
	bool bIsUnPossessed = true;
	
	virtual void MakeMovement(const float DeltaTime) {}
	virtual void Force2DMovement();
	
	FVector ArtificialInput;
	void MakeArtificialInput(float const DeltaTime);

	virtual void MakeJump();
	virtual void MakeReleaseJump() {}
	virtual void ResetJumpCount();
	virtual void TakeFallDamage();

	virtual void DetectWall();

	virtual void HandleActionInput();
	virtual void HandleEjectInput();
	
	virtual bool CheckIsJumpHeld(float Threshold);

	virtual void PossessNewEntity(AEyeCharacter* EntityToPossess);

	UFUNCTION()
	virtual void ChangeState(EGameState NewState);

	virtual void UnPossessed() override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataAsset, meta = (AllowPrivateAccess = "true"))
	UEyeCharacterDataAsset* EntityData;
	
	UPROPERTY()
	AEyeGameMode* GameMode;

private:
	FVector MovementInput;
	FVector MovementDirection;

	bool bInputIsAllowed = true;
	
	bool bJumpDepressed = false;
	bool bJumpHeld = false;
	float JumpHeldTime = 0.f;
	int JumpCount = 0;
	bool bIsOnFloor = false;
	float FloorTraceDistance;

	bool bFoundLeftWall;
	bool bFoundRightWall;
	float WallTraceDistance;

	FVector StartPosition;
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void SmoothenMovementDirection(float DeltaTime);

	void HandleJumpInput();
	void HandleJumpReleased();
	void JumpHeldTimer(float DeltaTime);

	void SlideDownWall();

	void CalculateTraceDistances();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};