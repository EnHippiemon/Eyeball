#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityBalloon.generated.h"

class USphereComponent;

UCLASS()
class EYEBALL_API AEyeEntityBalloon : public AEyeCharacter
{
	GENERATED_BODY()

private:
	AEyeEntityBalloon();

	
	virtual void HandleActionInput() override {}
	virtual void MakeMovement(const float DeltaTime) override;

	virtual void MakeJump() override;
	virtual void TakeFallDamage() override {}
	
	virtual void OnSpawned() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
};