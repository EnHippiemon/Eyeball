#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EyeCharacter.generated.h"


// Create line traces all around the sphere, going in on X-axis. If any of them
// finds danger zone, start bool that determines timer.
// If none of them finds danger zone, reset bool and timer.

class UBoxComponent;
UCLASS()
class EYEBALL_API AEyeCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	AEyeCharacter();

	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed = 10.f;

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> SafeZone;
	
	FVector Movement;

	float PlayerRadius;
	
	void HandleUpwardsInput(float Value);
	void HandleSidewaysInput(float Value);

	void HandleJumpInput();
	void HandleActionInput();

	void MakeMovement();
	void FindOverlap();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};


