#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "EyeDeathCountWidget.generated.h"

class UTextBlock;
class AEyeGameMode;

UCLASS()
class EYEBALL_API UEyeDeathCountWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void UpdateDeathCount(EGameState NewState);
	
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UTextBlock* DeathCountText;
	
	UPROPERTY()
	AEyeGameMode* GameMode;
};
