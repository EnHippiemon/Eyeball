#pragma once

#include "CoreMinimal.h"
#include "Eyeball/DataAssets/EyeGameModeDataAsset.h"
#include "GameFramework/GameModeBase.h"
#include "EyeGameMode.generated.h"

class UEyeGameModeDataAsset;
class UEyePauseWidget;
class UEyeWonWidget;
class UEyeDeathCountWidget;
class UNiagaraSystem;
class AEyeEnemy;
class AEyeProjectile;
class AEyeMoveableDanger;
class AEyeMoveableObject;
class AEyeCamera;
class UEyeDangerWidget;
class UEyeRestartWidget;
class AEyeEntityEyeball;
class AEyeCharacter;

UENUM(BlueprintType)
enum EGameState
{
	Egs_Playing,
	Egs_GameOver,
	Egs_StartingGame,
	Egs_GameWon,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedState, EGameState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDangerChanged, bool, IsInDanger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEntityChanged, AEyeCharacter*, NewEntity);
UCLASS()
class EYEBALL_API AEyeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Delegates 
		UPROPERTY()
		FOnChangedState OnChangedState;
		UPROPERTY()
		FOnDangerChanged OnDangerChanged;
		UPROPERTY()
		FOnEntityChanged OnEntityChanged;

	// Setters
		void SetGameWon(bool HasWon);
	
	// Getters
		int GetDeathCount() const { return DeathCount; }
		int GetDeathCountSinceCheckpoint() const { return DeathCountSinceCheckpoint; }
		int GetDeathCountForDecreasedDifficulty() const { return Data->DeathCountForDecreasedDifficulty; }
		float GetLeewayForBeingHit() const { return Data->LeewayForBeingHit; }
		EGameState GetGameState() const { return CurrentGameState;}
	
private:
	AEyeGameMode();
	
	EGameState CurrentGameState;
	EGameState SavedState;
	
	float SavedTimeDilation;
	
	bool bIsInDanger = true;
	float TimeInDanger = 0.f;
	float CurrentMaxTimeInDanger = 0.6f;
	float TargetTimeDilation = 1.f;

	int DeathCount = 0;
	int DeathCountSinceCheckpoint = 0;

	UPROPERTY(EditDefaultsOnly)
	UEyeGameModeDataAsset* Data;
	
	UPROPERTY()
	AEyeCharacter* PlayerCharacter;
	UPROPERTY()
	AController* Controller;

	
#pragma region --- Widgets ---
	/* Widgets */
		/* Game over */
			TObjectPtr<UEyeRestartWidget> RestartWidgetRef;
			TObjectPtr<UEyeDeathCountWidget> DeathCountWidgetRef;
			TObjectPtr<UEyeWonWidget> WonWidgetRef;
	
		/* Danger */
			TObjectPtr<UEyeDangerWidget> DangerWidgetRef;

		/* Pause */
			TObjectPtr<UEyePauseWidget> PauseWidgetRef;
	
#pragma endregion

#pragma region --- Checkpoint ---
	/* Checkpoint */
		/* Player characters */
			UPROPERTY()
			AEyeEntityEyeball* Eyeball;
			UPROPERTY()
			TArray<AActor*> CharacterArray;
			UPROPERTY()
			AEyeCharacter* PossessedAtCheckpoint;
			TArray<FVector> CharacterLocations;

		/* Enemy characters */
			UPROPERTY()
			TArray<AActor*> EnemyArray;
			TArray<FVector> EnemyLocations;
			TArray<int> EnemyHealths;

		/* Actors to handle on death and checkpoint objects */
			UPROPERTY()
			TArray<AEyeMoveableObject*> MoveableObjectArray;
			TArray<FVector> MoveableObjectLocations;
			TArray<bool> MoveableObjectsActivated;
			TArray<bool> MoveableObjectsReachedTarget;
	
		bool bEyeballHiddenAtCheckpoint = false;

		void HandleEasyMode(bool const ShouldBeEasy);
	
		UFUNCTION()
		void HandleCheckpointReached();
	
		void FindAllReferences();
		void SaveStates();
		void ResetStates();

		// Save logic
			void SaveLocationsOfActors(TArray<AActor*> ArrayOfActors, TArray<FVector>& ArrayOfLocations);
			void SaveEnemyHealth(TArray<AActor*> ArrayOfActors, TArray<int>& ArrayOfHealth);
			void SaveMoveableObjectStates();
	
		// Reset logic
			void ResetActorLocations(TArray<AActor*> ArrayOfActors, TArray<FVector>& ArrayOfLocations);
			void ResetEnemyHealth(TArray<AActor*> ArrayOfActors, TArray<int>& ArrayOfHealth);
			void ResetMoveableObjects() const;
	
		// Remove logic 
			void RemoveObjects(const TSubclassOf<AActor>& ObjectClassToDelete) const;
#pragma endregion
	
	UFUNCTION()
	void ChangeEntity(AEyeCharacter* Character);

	UFUNCTION()
	void EjectCurrentEntity();

	UFUNCTION()
	void HandlePlayerDeath();
	UFUNCTION()
	void HandleDangerFound(bool IsInDanger);
	void CountTimeInDanger(float DeltaTime);
	void SetTimeDilation(float DeltaTime);
	
	void GetNewPlayerReference();

	void SpawnCamera() const;

	UFUNCTION()
	void SetNewState(bool bScreenIsBlack);

	UFUNCTION()
	void PauseGame();

	UFUNCTION()
	void HandleMenuButtonPressed(FString ButtonName);

	void DebugWidgetAmount();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};