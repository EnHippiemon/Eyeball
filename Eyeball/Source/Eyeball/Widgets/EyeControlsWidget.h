#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "EyeControlsWidget.generated.h"

class UTextBlock;
class AEyeGameMode;

UCLASS()
class EYEBALL_API UEyeControlsWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UTextBlock* SpaceText;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UTextBlock* LMBText;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UTextBlock* RMBText;
	
	UPROPERTY()
	AEyeGameMode* GameMode;

	UFUNCTION()
	void SetDisplayWidget(EGameState NewState);

	UFUNCTION()
	void ChangeText(AEyeCharacter* NewEntity);
	virtual void NativeConstruct() override;
};