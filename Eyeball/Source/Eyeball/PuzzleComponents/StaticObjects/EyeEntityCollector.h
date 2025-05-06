#pragma once

#include "CoreMinimal.h"
#include "EyeCollisionDetector.h"
#include "EyeEntityCollector.generated.h"

class AEyeCharacter;

UCLASS()
class EYEBALL_API AEyeEntityCollector : public AEyeInteractableObject
{
	GENERATED_BODY()

private:
	bool bLeftOverlapping = false;
	bool bRightOverlapping = false;
	
	AEyeEntityCollector();

	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void CheckOverlaps();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox;
	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox2;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AEyeCharacter> WantedEntity;
};