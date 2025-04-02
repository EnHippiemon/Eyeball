#pragma once

#include "CoreMinimal.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "EyeEntityGrasshopper.generated.h"

class UEyeGrasshopperJumpWidget;

UCLASS()
class EYEBALL_API AEyeEntityGrasshopper : public AEyeCharacter
{
	GENERATED_BODY()

private:
	AEyeEntityGrasshopper();

	float TimerInterval = 1.f;
	int JumpTimeDirection = 1;
	float JumpHeight = 0.f;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UEyeGrasshopperJumpWidget> JumpWidget;
	UPROPERTY()
	TObjectPtr<UEyeGrasshopperJumpWidget> JumpWidgetRef;
	
	virtual void MakeMovement(const float DeltaTime) override;
	void DecideMovementSpeed();

	void DecideJumpHeight(float const DeltaTime);
	virtual void MakeReleaseJump() override;
	virtual void TakeFallDamage() override {}

	virtual void HandleEjectInput() override;

public:
	virtual void OnSpawned() override;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Box;
};