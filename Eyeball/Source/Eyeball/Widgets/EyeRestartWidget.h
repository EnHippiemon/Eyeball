#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EyeRestartWidget.generated.h"

// class FCanvasItem;
class UImage;
class AEyeGameMode;
enum EGameState : int;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransitionCompleted, bool, bScreenIsBlack);

UCLASS()
class EYEBALL_API UEyeRestartWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnTransitionCompleted OnTransitionCompleted;

protected:
	UPROPERTY(meta = (BindWidget), EditDefaultsOnly)
	UImage* BlackImage;
		
private:
	UPROPERTY(EditDefaultsOnly)
	float TransitionSpeed = 1.f;
	
	float OpacityValue;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* BlackTexture;

	virtual void NativeConstruct() override;

	UPROPERTY()
	AEyeGameMode* GameMode;

	UFUNCTION()
	void HandleChangedState(EGameState NewState);

	void SetOpacity(const float DeltaTime);
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	EGameState CurrentGameState;
};