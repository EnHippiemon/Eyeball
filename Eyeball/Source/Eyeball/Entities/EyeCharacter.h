#pragma once

#include "CoreMinimal.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "EyeCharacter.generated.h"

class UNiagaraComponent;
class AEyeInteractableObject;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterChanged, AEyeCharacter*, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEject);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDangerFound, bool, IsInDanger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCheckpointReached);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPaused);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEntityFound, AActor*, FoundActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractableFound, AActor*, FoundActor);

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
	UPROPERTY()
	FOnPaused OnPaused;
	UPROPERTY()
	FOnEntityFound OnEntityFound;
	UPROPERTY()
	FOnInteractableFound OnInteractableFound;

	virtual void OnSpawned();
	virtual void TakeDamage();

	/* Setters */
		void SetArtificialInput(const FVector& Direction);
		void SetMoveDirection(const FVector& NewDirection) { MovementDirection = NewDirection; }
		void ResetPosition();
		void SetEasyModeMesh(bool bIsEasyMode) const { MeshComponent->SetMaterial(0, bIsEasyMode ? EasyModeMeshMaterial : DefaultMeshMaterial); }
	
	/* Getters */
		FVector GetMovementDirection() const { return MovementDirection; }
		bool GetIsPossessed() const { return !bIsUnPossessed; }
		
protected:
	AEyeCharacter();

	/* Setters */
		void AddJumpCount(const int Value) { JumpCount += Value; }
		void SetJumpDepressed(const bool Value) { bJumpDepressed = Value; }
	/* Getters */
		FVector GetMovementInput() const { return MovementInput; }
		bool GetJumpDepressed() const { return bJumpDepressed; }
		float GetJumpHeldTime() const { return JumpHeldTime; }
		bool GetCanJump() const { return JumpCount < Data->MaxJumpCount;}
		int GetJumpCount() const { return JumpCount; }
		bool GetIsOnFloor() const { return bIsOnFloor; }
		ECollisionChannel GetSafeZone() const { return Data->SafeZone; }
		ECollisionChannel GetEntityBody() const { return Data->EntityBody; }

	float CurrentMovementSpeed;
	bool bIsUnPossessed = true;

	bool bCanChangeEntity = false;
	
	virtual void MakeMovement(const float DeltaTime) {}
	virtual void Force2DMovement();
	
	FVector ArtificialInput;
	void DecayMovementSpeed(float const DeltaTime);

	virtual void MakeJump();
	virtual void MakeReleaseJump() {}
	virtual void ResetJumpCount();
	virtual void TakeFallDamage();

	virtual void DetectWall();

	virtual void HandleActionInput();
	virtual void HandleEjectInput();
	
	virtual bool CheckIsJumpHeld(float Threshold);

	virtual void SearchForSwitchableEntity();
	virtual void PossessNewEntity(AEyeCharacter* EntityToPossess);

	virtual void FindInteractableObject();
	
	UFUNCTION()
	virtual void ChangeState(EGameState NewState);

	UFUNCTION()
	virtual void HandleCanBePossessed(AActor* FoundActor);
	
	virtual void UnPossessed() override;
	virtual void SetSoulVisibility(bool Value);

	UFUNCTION()
	void HandleEntityChanged(AEyeCharacter* NewEntity);
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataAsset, meta = (AllowPrivateAccess = "true"))
	UEyeCharacterDataAsset* Data;
	
	UPROPERTY()
	AEyeGameMode* GameMode;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MeshComponent;

	// Soul components 
		UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* RotatingSoulMesh;
		UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* SoulPart1;
		UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* SoulPart2;
		UPROPERTY(EditDefaultsOnly)
		UMaterialInstance* EyeballMaterialNormal;
		UPROPERTY(EditDefaultsOnly)
		UNiagaraComponent* SoulNiagara1;
		UPROPERTY(EditDefaultsOnly)
		UNiagaraComponent* SoulNiagara2;
		
	
	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* PossessableMaterial;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* EmptyMaterial;
	
private:
	UPROPERTY()
	AEyeCharacter* PossessedCharacter;
	UPROPERTY()
	AEyeCharacter* SwitchableEntity;
	
	UPROPERTY()
	AEyeInteractableObject* InteractableObject;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* NiagaraLightning;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* DefaultMeshMaterial;
	UPROPERTY(EditDefaultsOnly)
	UMaterial* EasyModeMeshMaterial;
	
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

	void HandlePauseInput();

	void RotateMesh(float const DeltaTime);
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};