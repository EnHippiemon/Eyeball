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

	USphereComponent* GetSphereComponent() const { return SphereComponent; }

private:
	AEyeEntityEyeball();
	
	float PlayerRadius;
	
	bool bIsInDanger = false;
	float TimeInDanger = 0.f;
	float MaxTimeInDanger = 2.f;

	bool bIsDashing = false;
	bool bCanDash = true;
	float TimeSinceDashed = 0.f;
	FVector DashDirection;
	FVector Dash(const float DeltaTime);
	FVector Move(const float DeltaTime);
	
	UPROPERTY()
	AActor* FoundActor;
	UPROPERTY()
	AEyeCharacter* FoundEntity;

	void FindOverlap();
	void SetOverlayMaterial();
	
	virtual void HandleActionInput() override {}
	virtual void HandleEjectInput() override;

	virtual void MakeJump() override;
	virtual void MakeReleaseJump() override;
	virtual void ResetJumpCount() override;

	virtual void DetectWall() override {}

	virtual void MakeMovement(const float DeltaTime) override;

	virtual void HandleCanBePossessed(AActor* Actor) override {}
	virtual void SearchForSwitchableEntity() override {}

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* EyeballMaterialDanger;
};