#include "../Widgets/EyeRestartWidget.h"

#include "Components/Image.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"

void UEyeRestartWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->OnChangedState.AddUniqueDynamic(this, &UEyeRestartWidget::HandleChangedState);
	}

	OpacityValue = 1.f;
}

void UEyeRestartWidget::HandleChangedState(EGameState NewState)
{
	CurrentGameState = NewState;
}

void UEyeRestartWidget::SetOpacity(const float DeltaTime)
{
	if (CurrentGameState != Egs_StartingGame && CurrentGameState != Egs_GameOver)
		return;
	
	switch (CurrentGameState)
	{
		case Egs_GameOver:
			OpacityValue += DeltaTime * TransitionSpeed;
			if (OpacityValue >= 1.f)
				OnTransitionCompleted.Broadcast(true);
			break;
		case Egs_StartingGame:
			OpacityValue -= DeltaTime * TransitionSpeed;
			if (OpacityValue <= 0.0f)
				OnTransitionCompleted.Broadcast(false);
			break;
		default:
			break;
	}
	
	BlackImage->SetOpacity(OpacityValue);
}

void UEyeRestartWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	SetOpacity(InDeltaTime);
}