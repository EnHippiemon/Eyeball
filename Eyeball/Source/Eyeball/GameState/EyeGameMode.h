#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EyeGameMode.generated.h"

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
UCLASS()
class EYEBALL_API AEyeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnChangedState OnChangedState;
	UPROPERTY()
	FOnDangerChanged OnDangerChanged;
	
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
	
	
	/* Checkpoint */
		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AEyeCharacter> EyeCharacter;
		UPROPERTY()
		AEyeEntityEyeball* Eyeball;
		UPROPERTY()
		TArray<AActor*> CharacterArray;
		UPROPERTY()
		AEyeCharacter* PossessedAtCheckpoint;

		TArray<FVector> CharacterLocations;
	
		bool bEyeballHiddenAtCheckpoint = false;
	
		UFUNCTION()
		void HandleCheckpointReached();
	
		void FindAllReferences();
		void SaveLocations();
		void ResetLocations();
	
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

	UFUNCTION()
	void SetNewState(bool bScreenIsBlack);
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};