#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyeGrasshopperJumpWidget.generated.h"

class UImage;

UCLASS()
class EYEBALL_API UEyeGrasshopperJumpWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void RenderJumpBar(float Value) const;

private:
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UImage* JumpMeter;
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UImage* Frame;
};