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

	void InteractWith() const;

private:
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AEyeMoveableObject> MoveableObject;
};