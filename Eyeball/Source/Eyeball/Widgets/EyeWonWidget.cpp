#include "EyeWonWidget.h"

#include "Components/Overlay.h"
#include "Kismet/GameplayStatics.h"

void UEyeWonWidget::CreditsCountdown(float const DeltaTime)
{
	if (TimeSinceWon >= CreditsDelay)
		return;

	TimeSinceWon += DeltaTime;
}

void UEyeWonWidget::OpenCredits(float const DeltaTime)
{
	if (TimeSinceWon < CreditsDelay || WidgetOpacity >= 1.f)
		return;
	
	BackgroundOverlay->SetRenderOpacity(WidgetOpacity);
	WidgetOpacity += DeltaTime * BackgroundOpacitySpeed;
}

void UEyeWonWidget::OpenNextLevel(float const DeltaTime)
{
	if (WidgetOpacity < 1.f)
		return;

	TimeSinceCreditsOpened += DeltaTime;
	if (TimeSinceCreditsOpened >= TimeUntilOpenLevel)
		UGameplayStatics::OpenLevel(this, MainLevelPath, true);
}

void UEyeWonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TimeSinceWon = 0.f;
	WidgetOpacity = 0.f;
	TimeSinceCreditsOpened = 0.f;
	BackgroundOverlay->SetRenderOpacity(WidgetOpacity);
}

void UEyeWonWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	CreditsCountdown(InDeltaTime);
	OpenCredits(InDeltaTime);
	OpenNextLevel(InDeltaTime);
}