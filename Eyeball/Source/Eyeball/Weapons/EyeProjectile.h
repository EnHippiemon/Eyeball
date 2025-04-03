#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeProjectile.generated.h"

class USphereComponent;

UCLASS()
class EYEBALL_API AEyeProjectile : public AActor
{
	GENERATED_BODY()

public:
	AEyeProjectile();

	void SetTarget(const FVector& NewTarget);

private:
	UPROPERTY(EditDefaultsOnly)
	float Speed;
	
	FVector TargetLocation;
	// float Speed;

	void MoveToTargetLocation(float const DeltaTime);
	void DestroyProjectile();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* DangerSphere;
};