#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EyeGameMode.generated.h"

class AEyeProjectile;
class UEyeControlsWidget;
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
	Egs_StartingGame
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedState, EGameState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDangerChanged, bool, IsInDanger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEntityChanged, AEyeCharacter*, NewEntity);
UCLASS()
class EYEBALL_API AEyeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnChangedState OnChangedState;
	UPROPERTY()
	FOnDangerChanged OnDangerChanged;
	UPROPERTY()
	FOnEntityChanged OnEntityChanged;
	
private:
	EGameState CurrentGameState;
	
	AEyeGameMode();
	
	UPROPERTY(EditDefaultsOnly)
	float TimeDilationDanger = 0.2f;
	UPROPERTY(EditDefaultsOnly)
	float MaxDangerTime = 2.f;
	UPROPERTY(EditDefaultsOnly)
	float TimeDilationTransitionSpeed = 25.f;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> EntityEyeball;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> EntityHuman;

	bool bIsInDanger = true;
	float TimeInDanger = 0.f;
	float MaxTimeInDanger = 2.f;
	float TargetTimeDilation = 1.f;

	UPROPERTY()
	AEyeCharacter* PlayerCharacter;
	UPROPERTY()
	AController* Controller;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AEyeCamera> MainCamera;

	/* Widgets */
		/* Game over */
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<UEyeRestartWidget> RestartWidget;
			TObjectPtr<UEyeRestartWidget> RestartWidgetRef;
	
		/* Danger */
			UPROPERTY(EditDefaultsOnly)
			// TSubclassOf<UDangerWidget> DangerWidget;
			TSubclassOf<UEyeDangerWidget> DangerWidget;
			TObjectPtr<UEyeDangerWidget> DangerWidgetRef;

		/* Controls */
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<UEyeControlsWidget> ControlsWidget;
			TObjectPtr<UEyeControlsWidget> ControlsWidgetRef;
	
	/* Checkpoint */
		/* Player characters */
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<AEyeCharacter> EyeCharacter;
			UPROPERTY()
			AEyeEntityEyeball* Eyeball;
			UPROPERTY()
			TArray<AActor*> CharacterArray;
			UPROPERTY()
			AEyeCharacter* PossessedAtCheckpoint;
			TArray<FVector> CharacterLocations;

		/* Enemy characters */
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<AActor> EnemyCharacter;
			UPROPERTY()
			TArray<AActor*> EnemyArray;
			TArray<FVector> EnemyLocations;

		/* Actors to handle on death and checkpoint objects */
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<AActor> MoveableObject;
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<AActor> MoveableDanger;
			UPROPERTY(EditDefaultsOnly)
			TSubclassOf<AActor> Projectile;
	
		bool bEyeballHiddenAtCheckpoint = false;
	
		UFUNCTION()
		void HandleCheckpointReached();
	
		void FindAllReferences();
		void SaveLocations();
		void ResetLocations();
	
		void SaveArrayOfActors(TArray<AActor*> ArrayOfActors, TArray<FVector>& ArrayOfLocations);
		void ResetActorLocations(TArray<AActor*> ArrayOfActors, TArray<FVector>& ArrayOfLocations);
		void ResetMoveableObjects(const TSubclassOf<AActor>& MoveableObjectClass) const;
		void RemoveObjects(const TSubclassOf<AActor>& ObjectClassToDelete) const;
	
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
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};