#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyeWonWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS()
class EYEBALL_API UEyeWonWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UImage* BackgroundImage;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UTextBlock* Text;
};
