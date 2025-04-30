#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EyeCharacterDataAsset.generated.h"

UCLASS()
class EYEBALL_API UEyeCharacterDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/* Interactions */
		// Decides if the character can interact with interactable objects. 
		UPROPERTY(EditDefaultsOnly, Category="Interaction")
		bool bCanInteract = false;
	
	/* Movement */
		// The movement speed the character is usually trying to maintain 
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float NormalMovementSpeed = 10.f;
	
		// Used in special cases when the character should have different movement speeds at different times
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float HighMovementSpeed = 200.f;

		// How fast the movement speed should increase or decay
		UPROPERTY(EditDefaultsOnly, Category="Movement|Speed")
		float MovementAcceleration = 0.5f;

		// How much each artificial input instantiation should be multiplied with. 
		UPROPERTY(EditDefaultsOnly, Category="Movement|Artificial")
		float InputMultiplier = 1.f;
	
		// How fast the artificial input should decay 
		UPROPERTY(EditDefaultsOnly, Category="Movement|Artificial")
		float DecaySpeed = 1.f;

		// The rotation speed of the souls
		UPROPERTY(EditDefaultsOnly, Category="Movement|Rotation")
		FRotator MeshRotationRate = FRotator(0, 0, 200);

	/* Danger */
		// The velocity of the player in order to take fall damage
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
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float DashCooldown = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float DashDuration = 0.5f;

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

	/* Wall tracing */
		UPROPERTY(EditDefaultsOnly, Category="WallTraces|Sliding")
		bool bShouldSlideDownWall;
		UPROPERTY(EditDefaultsOnly, Category="WallTraces|Sliding")
		float SlidingSpeed = 3.f;
	
		UPROPERTY(EditDefaultsOnly, Category="WallTraces")
		int SlidingTraceAmount = 4;
		UPROPERTY(EditDefaultsOnly, Category="WallTraces")
		float SlidingTraceLength = 3.f;
		UPROPERTY(EditDefaultsOnly, Category="WallTraces")
		float SlidingTraceHeight;
		UPROPERTY(EditDefaultsOnly, Category="WallTraces")
		FVector SlidingTraceOffset;
		UPROPERTY(EditDefaultsOnly, Category="WallTraces")
		FVector SlidingLineDirection = FVector(0, 0, 1);
		UPROPERTY(EditDefaultsOnly, Category="WallTraces")
		FVector SlidingTraceDirection = FVector(0, 1, 0);

	/* Entity tracing */
		UPROPERTY(EditDefaultsOnly, Category="EntityTrace")
		FVector SwitchEntityTraceOffset = FVector(150, 0, 0);
		UPROPERTY(EditDefaultsOnly, Category="EntityTrace")
		float SwitchEntityTraceLength = 20.f;

	/* Positioning */
		UPROPERTY(EditDefaultsOnly, Category="Positioning")
		FVector OffsetActorPlacement = FVector(0, 0, 0);
		UPROPERTY(EditDefaultsOnly, Category="Positioning")
		FVector OffsetUnpossessedActorPlacement = FVector(0, 0, 0);

	/* Collisions */
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> SafeZone;
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> EntityBody;
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> Floor;
		UPROPERTY(EditDefaultsOnly, Category="Collision")
		TEnumAsByte<ECollisionChannel> InteractableCollision;
};