#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityEyeball.generated.h"

class USphereComponent;

UCLASS()
class EYEBALL_API AEyeEntityEyeball : public AEyeCharacter
{
	GENERATED_BODY()

public:
	virtual void OnSpawned() override;
	virtual void DamagePlayer() override {}

private:
	AEyeEntityEyeball();
	
	float PlayerRadius;
	
	bool bCanChangeEntity = false;
	
	bool bIsInDanger = false;
	float TimeInDanger = 0.f;
	float MaxTimeInDanger = 2.f;

	UPROPERTY()
	AActor* FoundActor;
	UPROPERTY()
	AEyeCharacter* FoundEntity;

	void FindOverlap();
	
	virtual void HandleActionInput() override;
	virtual void HandleEjectInput() override;

	virtual void MakeJump() override;
	virtual void MakeReleaseJump() override;
	virtual void ResetJumpCount() override { }

	virtual void MakeMovement(const float DeltaTime) override;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;
};
