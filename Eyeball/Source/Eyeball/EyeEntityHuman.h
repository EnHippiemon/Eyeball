#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityHuman.generated.h"

UCLASS()
class EYEBALL_API AEyeEntityHuman : public AEyeCharacter
{
	GENERATED_BODY()

public:
	virtual void OnSpawned() override;
	
private:
	AEyeEntityHuman();
	
	virtual void MakeMovement(const float DeltaTime) override;

	virtual void MakeJump() override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};