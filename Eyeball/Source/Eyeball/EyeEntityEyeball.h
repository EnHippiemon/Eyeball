#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityEyeball.generated.h"

UCLASS()
class EYEBALL_API AEyeEntityEyeball : public AEyeCharacter
{
	GENERATED_BODY()


private:
	float PlayerRadius;
	float TimeInDanger = 0.f;

	bool bCanChangeEntity = false;
	bool bIsInDanger = false;

	UPROPERTY()
	AActor* FoundEntity;
	
	void FindOverlap();

	virtual void HandleActionInput();

	virtual void MakeJump() override;
	virtual void MakeReleaseJump() override;

	virtual void MakeMovement(const float DeltaTime) override;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
