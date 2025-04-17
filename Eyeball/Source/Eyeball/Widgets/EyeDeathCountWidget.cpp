#include "EyeDeathCountWidget.h"
#include "Components/TextBlock.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"

void UEyeDeathCountWidget::UpdateDeathCount(EGameState NewState)
{
	if (NewState != Egs_GameOver)
		return;
	
	DeathCountText->SetText(FText::FromString(FString::FromInt(GameMode->GetDeathCount())));
}

void UEyeDeathCountWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->OnChangedState.AddUniqueDynamic(this, &UEyeDeathCountWidget::UpdateDeathCount);
	}
}
