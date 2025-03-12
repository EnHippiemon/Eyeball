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
		

	/* Danger */
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float MaxTimeInDanger = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Danger")
		float TimeDilationDanger = 0.2f;

	/* Jump */
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float HeldJumpThreshold = 1.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		FVector JumpDirection = FVector(0, 0, 1);
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		float JumpForce = 10000.f;
		UPROPERTY(EditDefaultsOnly, Category="Jump")
		int MaxJumpCount = 1;
			
		UPROPERTY(EditAnywhere, Category="Jump")
		float RadiusFloorCheck;
		UPROPERTY(EditAnywhere, Category="Jump")
		float LengthFloorCheck;
		UPROPERTY(EditAnywhere, Category="Jump")
		FVector OffsetFloorCheck;

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