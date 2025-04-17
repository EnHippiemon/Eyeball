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

	// Setters 
	void SetActivated(const bool Value) { bIsActivated = Value; }
	void SetReachedTarget(const bool Value) { bHasReachedTarget = Value; }

	// Getters 
	FVector GetTargetLocation() const { return TargetLocation; }
	bool GetIsActivated() const { return bIsActivated; }
	bool GetHasReachedTarget() const { return bHasReachedTarget; }
	bool GetShouldReturnToStart() const { return ReturnToStartLocation; }
	bool GetShouldLoop() const { return bShouldLoop; }

protected:
	UFUNCTION()
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	bool bShouldTick;
	UPROPERTY(EditAnywhere)
	bool bStartActivated;
	UPROPERTY(EditAnywhere)
	bool bShouldLoop;
	UPROPERTY(EditAnywhere)
	FVector MoveDirection;
	UPROPERTY(EditAnywhere)
	float MoveSpeed;
	UPROPERTY(EditAnywhere)
	FVector TargetOffset;
	UPROPERTY(EditAnywhere)
	bool ReturnToStartLocation;
	
private:	
	bool bIsActivated = false;
	bool bHasReachedTarget = false;
	bool bIsHindered = false;
	
	FVector StartLocation;
	FVector TargetLocation;
	
	void MoveToTarget();
	void MoveToStart();
	
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* Box;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* OverlapCollision;
};