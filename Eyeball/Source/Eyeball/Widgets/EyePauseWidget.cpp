#include "EyePauseWidget.h"

#include "Components/Overlay.h"

void UEyePauseWidget::SetVisible(const bool ShouldBeVisible) const
{
	WidgetOverlay->SetRenderOpacity(ShouldBeVisible);
}

void UEyePauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	WidgetOverlay->SetRenderOpacity(0);
}
