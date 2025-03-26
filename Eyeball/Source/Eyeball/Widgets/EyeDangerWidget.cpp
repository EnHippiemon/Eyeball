#include "EyeDangerWidget.h"
#include "Components/Image.h"
#include "Eyeball/DataAssets/WidgetDataAssets/EyeDangerWidgetDataAsset.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"

void UEyeDangerWidget::SetDanger(bool IsInDanger)
{
	if (IsInDanger)
	{
		Box1Target = WidgetData->Box1Offset;
		Box2Target = WidgetData->Box2Offset;
	}
	else
	{
		Box1Target = WidgetData->Box1StartTransform;
		Box2Target = WidgetData->Box2StartTransform;
	}
}

void UEyeDangerWidget::MoveUIBoxes(float const DeltaTime) const
{
	auto Box1Transform = Box1Image->GetRenderTransform().Translation.Y;
	auto Box2Transform = Box2Image->GetRenderTransform().Translation.Y;
	if (Box1Transform == Box1Target.Y && Box2Transform == Box2Target.Y)
		return;
	
	Box1Transform = FMath::Lerp(Box1Transform, Box1Target.Y, WidgetData->TransitionSpeed * DeltaTime);
	Box2Transform = FMath::Lerp(Box2Transform, Box2Target.Y, WidgetData->TransitionSpeed * DeltaTime);

	Box1Image->SetRenderTranslation(FVector2D(Box1Target.X, Box1Transform));
	Box2Image->SetRenderTranslation(FVector2D(Box2Target.X, Box2Transform));
}

void UEyeDangerWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
		GameMode->OnDangerChanged.AddUniqueDynamic(this, &UEyeDangerWidget::SetDanger);

	if (!WidgetData)
		UE_LOG(LogTemp, Error, TEXT("No Data Asset in UEyeDangerWidget!"));
}

void UEyeDangerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	MoveUIBoxes(InDeltaTime);
}