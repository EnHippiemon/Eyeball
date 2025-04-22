#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyePauseWidget.generated.h"

class UButton;
class UOverlay;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClicked, FString, ButtonName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRestartFromCheckpoint);

UCLASS()
class EYEBALL_API UEyePauseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetVisible(bool ShouldBeVisible) const;

	UPROPERTY()
	FOnButtonClicked OnButtonClicked;

private:
	UFUNCTION()
	void OnContinue();
	UFUNCTION()
	void OnRestartFromCheckpoint();
	UFUNCTION()
	void OnRestartLevel();
	UFUNCTION()
	void OnQuit();
	
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UOverlay* WidgetOverlay;
	
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* ContinueButton;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* RestartFromCheckpointButton;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* RestartLevelButton;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* QuitButton;
};
