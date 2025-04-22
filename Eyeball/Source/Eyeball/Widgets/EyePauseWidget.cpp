#include "EyePauseWidget.h"

#include "Components/Button.h"
#include "Components/Overlay.h"

void UEyePauseWidget::SetVisible(const bool ShouldBeVisible) const
{
	WidgetOverlay->SetRenderOpacity(ShouldBeVisible);
}

void UEyePauseWidget::OnContinue()
{
	OnButtonClicked.Broadcast("Continue");
}

void UEyePauseWidget::OnRestartFromCheckpoint()
{
	OnButtonClicked.Broadcast("RestartCheckpoint");
}

void UEyePauseWidget::OnRestartLevel()
{
	OnButtonClicked.Broadcast("RestartLevel");
}

void UEyePauseWidget::OnQuit()
{
	OnButtonClicked.Broadcast("Quit");
}

void UEyePauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	WidgetOverlay->SetRenderOpacity(0);

	ContinueButton->OnClicked.AddUniqueDynamic(this, &UEyePauseWidget::OnContinue);
	RestartFromCheckpointButton->OnClicked.AddUniqueDynamic(this, &UEyePauseWidget::OnRestartFromCheckpoint);
	RestartLevelButton->OnClicked.AddUniqueDynamic(this, &UEyePauseWidget::OnRestartLevel);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UEyePauseWidget::OnQuit);
}
