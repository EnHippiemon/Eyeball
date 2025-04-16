#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityHuman.generated.h"

class AEyeInteractableObject;
class UCapsuleComponent;

UCLASS()
class EYEBALL_API AEyeEntityHuman : public AEyeCharacter
{
	GENERATED_BODY()

public:
	virtual void OnSpawned() override;
	
private:
	AEyeEntityHuman();

	bool FoundInteractableObject();

	UPROPERTY()
	AEyeInteractableObject* InteractableObject;
	
	virtual void HandleActionInput() override;
	virtual void MakeMovement(const float DeltaTime) override;

	virtual void MakeJump() override;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> InteractableCollision;
	
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
};