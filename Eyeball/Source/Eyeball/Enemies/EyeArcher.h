#pragma once

#include "CoreMinimal.h"
#include "EyeEnemy.h"
#include "EyeArcher.generated.h"

UCLASS()
class EYEBALL_API AEyeArcher : public AEyeEnemy
{
	GENERATED_BODY()

private:
	AEyeArcher(); 

	void AvoidPlayer();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};