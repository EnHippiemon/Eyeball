#include "EyeControlsWidget.h"

#include "Components/TextBlock.h"
#include "Eyeball/Entities/EyeEntityBalloon.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"
#include "Eyeball/Entities/EyeEntityGrasshopper.h"
#include "Eyeball/Entities/EyeEntityHuman.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"

void UEyeControlsWidget::SetDisplayWidget(EGameState NewState)
{
	SetRenderOpacity(NewState == Egs_Playing);
}

void UEyeControlsWidget::ChangeText(AEyeCharacter* NewEntity)
{
	if (Cast<AEyeEntityEyeball>(NewEntity))
	{
		SpaceText->SetText(FText::FromString("Dash"));
		LMBText->SetText(FText::FromString("Possess entity"));
		RMBText->SetText(FText::FromString(""));
		return;
	}
	if (Cast<AEyeEntityHuman>(NewEntity))
	{
		SpaceText->SetText(FText::FromString("Jump"));
		LMBText->SetText(FText::FromString("Interact"));
		RMBText->SetText(FText::FromString("Eject entity"));
		return;
	}
	if (Cast<AEyeEntityGrasshopper>(NewEntity)
		|| Cast<AEyeEntityBalloon>(NewEntity))
	{
		SpaceText->SetText(FText::FromString("Jump"));
		LMBText->SetText(FText::FromString(""));
		RMBText->SetText(FText::FromString("Eject entity"));
		return;
	}

	SpaceText->SetText(FText::FromString("Jump"));
	LMBText->SetText(FText::FromString("Action button"));
	RMBText->SetText(FText::FromString("Secondary action"));
}

void UEyeControlsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->OnChangedState.AddUniqueDynamic(this, &UEyeControlsWidget::SetDisplayWidget);
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &UEyeControlsWidget::ChangeText);
	}
}