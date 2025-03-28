#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeLever.generated.h"

class AEyeMoveableObject;

UCLASS()
class EYEBALL_API AEyeLever : public AActor
{
	GENERATED_BODY()
	
public:	
	AEyeLever();

	virtual void InteractWith() const;

protected:
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AEyeMoveableObject> MoveableObject;
};