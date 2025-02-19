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
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACharacter> EntityEyeball;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACharacter> EntityHuman;

	UPROPERTY()
	AEyeCharacter* PlayerCharacter;
	UPROPERTY()
	AController* Controller;

	UFUNCTION()
	void ChangeEntity(AEyeCharacter* Character);

	UFUNCTION()
	void EjectCurrentEntity();

	void GetNewPlayerReference();
	
	virtual void BeginPlay() override;
};