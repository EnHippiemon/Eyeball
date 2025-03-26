#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyeDangerWidget.generated.h"

class UEyeDangerWidgetDataAsset;
class AEyeGameMode;
class UImage;

UCLASS()
class EYEBALL_API UEyeDangerWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UImage* Box1Image;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UImage* Box2Image;
	
	FVector2D Box1Target;
	FVector2D Box2Target;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataAsset, meta = (AllowPrivateAccess = "true"))
	UEyeDangerWidgetDataAsset* WidgetData;
	
	UPROPERTY()
	AEyeGameMode* GameMode;

	UFUNCTION()
	void SetDanger(bool IsInDanger);
	
	void MoveUIBoxes(float const DeltaTime) const;

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};