#pragma once

#include "CoreMinimal.h"
#include "Eyeball/EyeCharacter.h"
#include "EyeEntityGrasshopper.generated.h"

UCLASS()
class EYEBALL_API AEyeEntityGrasshopper : public AEyeCharacter
{
	GENERATED_BODY()

private:
	AEyeEntityGrasshopper();
	
	virtual void MakeMovement(const float DeltaTime) override;

	// virtual void MakeJump() override;
	virtual void MakeReleaseJump() override;

public:
	virtual void OnSpawned() override;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
