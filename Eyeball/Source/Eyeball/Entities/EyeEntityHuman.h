#pragma once

#include "CoreMinimal.h"
#include "EyeCharacter.h"
#include "EyeEntityHuman.generated.h"

class UCapsuleComponent;

UCLASS()
class EYEBALL_API AEyeEntityHuman : public AEyeCharacter
{
	GENERATED_BODY()

public:
	
private:
	AEyeEntityHuman();
	
	virtual void MakeMovement(const float DeltaTime) override;
	virtual void MakeJump() override;
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
};