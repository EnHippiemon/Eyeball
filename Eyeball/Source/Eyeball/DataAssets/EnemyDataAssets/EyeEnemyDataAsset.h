#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeEnemyDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeEnemyDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	// Set the max offset to the target of the attacks.
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	FVector AttackAccuracy;
	
	// How many projectiles will be fired at once.
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	int ProjectilesPerAttack;
	
	// How many times the enemy will attack per attack sequence.
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	int SeriesOfAttacks;
	
	// The delayed time between each series of attack in a sequence. 
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	float AttackDelay;

	// The type of projectile this enemy uses.
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	TSubclassOf<AActor> Projectile;

	// How far the enemy will move after player gets too close. 
	UPROPERTY(EditDefaultsOnly, Category = "Move | Evade")
	FVector DistanceForEvasion;

	// The speed the enemy moves at. 
	UPROPERTY(EditDefaultsOnly, Category = "Move")
	float MovementSpeed;

	// Decides if this actor can move upward. 
	UPROPERTY(EditDefaultsOnly, Category = "Move")
	bool bCanFly;

	// The permanent offset position of the enemy in the level. 
	UPROPERTY(EditDefaultsOnly, Category = "Move | Positioning")
	FVector PositionOffset;
};