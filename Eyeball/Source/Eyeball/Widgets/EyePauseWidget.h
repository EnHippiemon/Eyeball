#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyePauseWidget.generated.h"

class UButton;
class UOverlay;

UCLASS()
class EYEBALL_API UEyePauseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetVisible(bool ShouldBeVisible) const;

private:
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UOverlay* WidgetOverlay;

	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* ContinueButton;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* RestartButton;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UButton* QuitButton;
	
	virtual void NativeConstruct() override;
};
