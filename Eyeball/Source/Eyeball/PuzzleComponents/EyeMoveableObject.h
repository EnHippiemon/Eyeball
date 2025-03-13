#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeMoveableObject.generated.h"

class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeMoveableObject : public AActor
{
	GENERATED_BODY()

public:
	AEyeMoveableObject();
	
	void Activate();
	FVector GetTargetLocation() const { return TargetLocation; }

private:	
	UPROPERTY(EditAnywhere)
	FVector MoveDirection;
	UPROPERTY(EditAnywhere)
	float MoveSpeed;
	UPROPERTY(EditAnywhere)
	FVector TargetOffset;
	UPROPERTY(EditAnywhere)
	bool ReturnToStartLocation;
	
	bool bIsActivated = false;
	bool bHasReachedTarget = false;
	
	FVector StartLocation;
	FVector TargetLocation;
	
	void MoveToTarget();
	void MoveToStart();
	
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* Box;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* CollisionBox;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};