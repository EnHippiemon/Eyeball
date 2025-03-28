#pragma once

#include "CoreMinimal.h"
#include "EyeLever.h"
#include "EyeLeverTwo.generated.h"

UCLASS()
class EYEBALL_API AEyeLeverTwo : public AEyeLever
{
	GENERATED_BODY()

public:
	virtual void InteractWith() const override;
	
protected:
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AEyeMoveableObject> MoveableObjectTwo;
};
