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

protected:
	UFUNCTION()
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:	
	UPROPERTY(EditInstanceOnly)
	UEyeMoveableObjectDataAsset* ObjectData;
	
	bool bIsActivated = false;
	bool bHasReachedTarget = false;
	bool bIsHindered = false;
	
	FVector StartLocation;
	FVector TargetLocation;
	
	void MoveToTarget();
	void MoveToStart();

	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* Box;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* CollisionBox;
};