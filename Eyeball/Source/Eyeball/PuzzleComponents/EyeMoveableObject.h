#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeMoveableObject.generated.h"

class UEyeMoveableObjectDataAsset;
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
	UPROPERTY(EditInstanceOnly)
	UEyeMoveableObjectDataAsset* ObjectData;
	
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