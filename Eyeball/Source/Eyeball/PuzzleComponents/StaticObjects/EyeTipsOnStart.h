#pragma once

#include "CoreMinimal.h"
#include "EyeTips.h"
#include "EyeTipsOnStart.generated.h"

UCLASS()
class EYEBALL_API AEyeTipsOnStart : public AEyeTips
{
	GENERATED_BODY()

private:
	void CheckOverlaps();

	virtual void BeginPlay() override;

	FTimerHandle TimerHandle;

};
