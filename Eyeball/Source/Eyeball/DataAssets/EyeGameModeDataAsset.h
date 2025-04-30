#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeGameModeDataAsset.generated.h"

class AEyeMoveableObject;
class AEyeCharacter;
class UEyePauseWidget;
class UEyeDangerWidget;
class UEyeWonWidget;
class UEyeDeathCountWidget;
class UEyeRestartWidget;
class UNiagaraSystem;
class AEyeCamera;

UCLASS()
class EYEBALL_API UEyeGameModeDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/* Danger */
		UPROPERTY(EditDefaultsOnly, Category = "Danger|DangerZone")
		float MaxTimeInDanger = 0.6f;
		UPROPERTY(EditDefaultsOnly, Category = "Danger|DangerZone")
		float ExtendedMaxTimeInDanger = 1.0f;
		UPROPERTY(EditDefaultsOnly, Category = "Danger|DangerZone")
		float TimeDilationDanger = 0.3f;
		UPROPERTY(EditDefaultsOnly, Category = "Danger|DangerZone")
		float TimeDilationTransitionSpeed = 5.f;
		
		// Amount of time allowed to be hit by danger when difficulty is decreased.
		UPROPERTY(EditDefaultsOnly, Category = "Danger|DangerBox")
		float LeewayForBeingHit = 0.1f;

		UPROPERTY(EditDefaultsOnly, Category = "Danger|Difficulty")
		int DeathCountForDecreasedDifficulty = 7;

	/* Classes */
		UPROPERTY(EditDefaultsOnly, Category = "Classes")
		TSubclassOf<APawn> EntityEyeball;
		UPROPERTY(EditDefaultsOnly, Category = "Classes")
		TSubclassOf<AEyeCamera> MainCamera;
		UPROPERTY(EditDefaultsOnly, Category = "Classes")
		TSubclassOf<AEyeCharacter> EyeCharacter;
		UPROPERTY(EditDefaultsOnly, Category = "Classes")
		TSubclassOf<AActor> EnemyCharacter;
		UPROPERTY(EditDefaultsOnly, Category = "Classes")
		TSubclassOf<AEyeMoveableObject> MoveableObject;
		UPROPERTY(EditDefaultsOnly, Category = "Classes")
		TSubclassOf<AActor> Projectile;

	/* FX */
		UPROPERTY(EditDefaultsOnly, Category = "FX")
		UNiagaraSystem* SmokeEffect;
	
	/* Level */
		UPROPERTY(EditDefaultsOnly, Category = "LevelPaths")
		FName MainLevelPath;

	/* Widgets */
		UPROPERTY(EditDefaultsOnly, Category = "Widgets|GameOver")
		TSubclassOf<UEyeRestartWidget> RestartWidget;
		UPROPERTY(EditDefaultsOnly, Category = "Widgets|GameOver")
		TSubclassOf<UEyeDeathCountWidget> DeathCountWidget;
		UPROPERTY(EditDefaultsOnly, Category = "Widgets|GameOver")
		TSubclassOf<UEyeWonWidget> WonWidget;
	
		UPROPERTY(EditDefaultsOnly, Category = "Widgets|Danger")
		TSubclassOf<UEyeDangerWidget> DangerWidget;

		UPROPERTY(EditDefaultsOnly, Category = "Widgets|Pause")
		TSubclassOf<UEyePauseWidget> PauseWidget;
};