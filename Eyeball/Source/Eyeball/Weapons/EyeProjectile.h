#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeProjectile.generated.h"

class UCapsuleComponent;
class UEyeProjectileDataAsset;
class USphereComponent;

UCLASS()
class EYEBALL_API AEyeProjectile : public AActor
{
	GENERATED_BODY()

public:
	AEyeProjectile();

	void OnSpawned();
	void SetTarget(const FVector& NewTarget);
	void SetShootingActor(const TObjectPtr<AActor>& NewActor);

private:
	FVector TargetLocation;
	FVector TargetOffset;
	FVector TargetDirection;

	UPROPERTY()
	TObjectPtr<AActor> ShootingActor;
	
	bool bCanMove = true;
	
	void MoveToTargetLocation(float const DeltaTime);
	void DestroyProjectile();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	UEyeProjectileDataAsset* Data;
	
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* RootSphere;
	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* DangerCapsule;
};