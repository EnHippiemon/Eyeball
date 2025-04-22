#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyeWonWidget.generated.h"

class UOverlay;
class UTextBlock;
class UImage;

UCLASS()
class EYEBALL_API UEyeWonWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	float CreditsDelay = 5.f;
	float TimeSinceWon = 0.f;

	UPROPERTY(EditDefaultsOnly)
	float BackgroundOpacitySpeed = 1.f;
	float WidgetOpacity = 0.f;

	UPROPERTY(EditDefaultsOnly)
	float TimeUntilOpenLevel = 5.f;
	float TimeSinceCreditsOpened = 0.f;

	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UOverlay* BackgroundOverlay;
	
	UPROPERTY(EditDefaultsOnly)
	FName MainLevelPath;

	void CreditsCountdown(float const DeltaTime);
	void OpenCredits(float const DeltaTime);
	void OpenNextLevel(float const DeltaTime);
	
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
