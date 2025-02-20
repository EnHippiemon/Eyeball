#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EyeGameMode.generated.h"

class AEyeCharacter;

UCLASS()
class EYEBALL_API AEyeGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	AEyeGameMode();
	
	UPROPERTY(EditDefaultsOnly)
	float TimeDilationDanger = 0.2f;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACharacter> EntityEyeball;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACharacter> EntityHuman;

	bool bIsInDanger = false;
	float TimeInDanger = 0.f;
	float MaxTimeInDanger = 2.f;
	
	UPROPERTY()
	AEyeCharacter* PlayerCharacter;
	UPROPERTY()
	AController* Controller;

	UFUNCTION()
	void ChangeEntity(AEyeCharacter* Character);

	UFUNCTION()
	void EjectCurrentEntity();

	UFUNCTION()
	void HandlePlayerDeath();
	UFUNCTION()
	void HandleDangerChange(bool bIsInDanger, float TimeDilationAmount, float MaxDangerTime);
	void CountTimeInDanger(float DeltaTime);
	
	void GetNewPlayerReference();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};