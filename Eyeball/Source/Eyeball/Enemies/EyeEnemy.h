#pragma once

#include "CoreMinimal.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "GameFramework/Actor.h"
#include "EyeEnemy.generated.h"

class AEyeGameMode;
class AEyeCharacter;
class AEyeProjectile;
class UEyeEnemyDataAsset;
class UCapsuleComponent;
class USphereComponent;

enum EEnemyState
{
	Ees_Idle,
	Ees_PreparingAttack,
	Ees_Attacking,
	Ees_Moving
};

UCLASS()
class EYEBALL_API AEyeEnemy : public AActor
{
	GENERATED_BODY()

public:
	void TakeDamage();
	USphereComponent* GetDamageComponent() { return EvasionSphere; }
	
protected:
	AEyeEnemy();

	void PrepareAttack(float const DeltaTime);
	void Attack();
	void Move(float const DeltaTime);

	void SetNewMoveTarget();
	void SetIsThreatened(bool IsThreatened);

	void CheckOverlaps();

	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	FVector TargetMoveOffset;
	bool bIsThreatened;
	float AttackPreparationTime = 0;

	EEnemyState CurrentState;

	UPROPERTY()
	AEyeGameMode* GameMode;
	TObjectPtr<AEyeCharacter> CharacterRef;
	
	UPROPERTY(EditAnywhere)
	UEyeEnemyDataAsset* Data;
	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* RootCollider;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* DetectionSphere;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* EvasionSphere;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void UpdateTarget(AEyeCharacter* NewEntity);
	UFUNCTION()
	void OnPlayerDeath(EGameState NewState);
};