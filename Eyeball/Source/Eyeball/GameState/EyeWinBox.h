#pragma once

#include "CoreMinimal.h"
#include "EyeCheckpoint.h"
#include "EyeWinBox.generated.h"

class AEyeGameMode;

UCLASS()
class EYEBALL_API AEyeWinBox : public AEyeCheckpoint
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	bool PlayerHasWon = true;
	
	// virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnOverlapSuccess(AEyeCharacter* EyeCharacter) override;
	virtual void BeginPlay() override;

	UPROPERTY()
	AEyeGameMode* GameMode;
};
