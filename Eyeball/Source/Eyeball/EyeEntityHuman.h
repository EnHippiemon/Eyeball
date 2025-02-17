#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityHuman.generated.h"

UCLASS()
class EYEBALL_API AEyeEntityHuman : public AEyeCharacter
{
	GENERATED_BODY()

private:
	virtual void MakeMovement(const float DeltaTime) override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
