#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeLever.generated.h"

class AEyeCamera;
class AEyeMoveableObject;

UCLASS()
class EYEBALL_API AEyeLever : public AActor
{
	GENERATED_BODY()
	
public:	
	AEyeLever();

	virtual void InteractWith();

protected:
	UPROPERTY(EditAnywhere)
	float TimeToFocusCameraOnActor = 2.f;
	
	virtual void StartEvent(TObjectPtr<AEyeMoveableObject> ObjectToMove);

private:
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AEyeMoveableObject> MoveableObject;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AEyeCamera> CameraClass;
	TObjectPtr<AEyeCamera> CameraRef;
};