#pragma once

#include "CoreMinimal.h"
#include "Eyeball/PuzzleComponents/StaticObjects/EyeInteractableObject.h"
#include "GameFramework/Actor.h"
#include "EyeNPC.generated.h"

class AEyeMoveableObject;
class UCapsuleComponent;
class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeNPC : public AEyeInteractableObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly)
	TArray<AActor*> Friends;

	FLatentActionInfo LatentInfo;

	AEyeNPC();

	void StopMoving();
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* RootCapsule;
	UPROPERTY(EditAnywhere)
	UBoxComponent* SearchBox;
	UPROPERTY(EditAnywhere)
	UBoxComponent* WithinReachCollider;
};