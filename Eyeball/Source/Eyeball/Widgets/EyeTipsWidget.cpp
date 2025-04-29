#include "EyeTipsWidget.h"

#include "Components/Overlay.h"

void UEyeTipsWidget::FadeOverlay(float const DeltaTime)
{
	float const TimeDirection = bShouldFadeOut ? DeltaTime * -1 : DeltaTime;
	CurrentOpacity += TimeDirection * FadeSpeed;
	CurrentOpacity = CurrentOpacity > 1.f ? 1.f : CurrentOpacity;
	WidgetOverlay->SetRenderOpacity(CurrentOpacity);
}

void UEyeTipsWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	FadeOverlay(InDeltaTime);
}