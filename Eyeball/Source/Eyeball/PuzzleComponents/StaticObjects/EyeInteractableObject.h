#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeInteractableObject.generated.h"

class AEyeCamera;
class AEyeMoveableObject;

UCLASS()
class EYEBALL_API AEyeInteractableObject : public AActor
{
	GENERATED_BODY()

public:	
	AEyeInteractableObject();

	virtual void InteractWith();

protected:
	UPROPERTY(EditAnywhere)
	float TimeToFocusCameraOnActor = 2.f;
	
	virtual void StartEvent(TObjectPtr<AEyeMoveableObject> ObjectToMove);

	UPROPERTY(EditInstanceOnly)
	TArray<TObjectPtr<AEyeMoveableObject>> MoveableObject;

	// If no camera hint is wanted, leave empty
	UPROPERTY(EditAnywhere)
	TSubclassOf<AEyeCamera> CameraClass;
	TObjectPtr<AEyeCamera> CameraRef;
};