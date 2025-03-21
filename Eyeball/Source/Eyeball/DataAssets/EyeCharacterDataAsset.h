#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeCharacterDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeCharacterDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/* Movement */
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float NormalMovementSpeed = 10.f;
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float HighMovementSpeed = 200.f;
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float MovementAcceleration = 0.5f;

	/* Danger */
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float MaxTimeInDanger = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float TimeDilationDanger = 0.2f;
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float ThresholdFallDamageVelocity = -90.f;

	/* Jump */
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float HeldJumpThreshold = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		FVector JumpDirection = FVector(0, 0, 1);
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float JumpForce = 10000.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		int MaxJumpCount = 1;

	/* Floor traces */
		UPROPERTY(EditDefaultsOnly, Category="Positioning")
		int FloorTraceAmount = 10;
		UPROPERTY(EditAnywhere, Category="FloorTrace")
		float RadiusFloorCheck;
		UPROPERTY(EditAnywhere, Category="FloorTrace")
		float LengthFloorCheck;
		UPROPERTY(EditAnywhere, Category="FloorTrace")
		FVector OffsetFloorCheck;
		UPROPERTY(EditAnywhere, Category="FloorTrace")
		FVector FloorLineDirection = FVector(0, 1, 0);
		UPROPERTY(EditAnywhere, Category="FloorTrace")
		FVector FloorTraceDirection = FVector(0, 0, 1);

	/* Sliding */
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Speed")
		float SlidingSpeed = 3.f;
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Traces")
		int SlidingTraceAmount = 4;
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Traces")
		float SlidingTraceLength = 3.f;
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Traces")
		float SlidingTraceHeight;
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Traces")
		FVector SlidingTraceOffset;
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Traces")
		FVector SlidingLineDirection = FVector(0, 0, 1);
		UPROPERTY(EditDefaultsOnly, Category="Sliding|Traces")
		FVector SlidingTraceDirection = FVector(0, 1, 0);

	/* Positioning */
		UPROPERTY(EditDefaultsOnly, Category="Positioning")
		FVector OffsetActorPlacement = FVector(0, 0, 0);

	/* Collisions */
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> SafeZone;
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> EntityBody;
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> Floor;
};