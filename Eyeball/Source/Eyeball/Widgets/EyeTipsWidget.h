#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyeTipsWidget.generated.h"

class UOverlay;

UCLASS()
class EYEBALL_API UEyeTipsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void ShouldFadeOut(const bool Value) { bShouldFadeOut = Value; }
	float GetOpacity() const { return CurrentOpacity; }

private:
	UPROPERTY(EditAnywhere)
	float FadeSpeed = 1.f;
	bool bShouldFadeOut = false;
	float CurrentOpacity = 0.f;
	
	void FadeOverlay(float const DeltaTime);
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UOverlay* WidgetOverlay;
};
