#pragma once

#include "CoreMinimal.h"
#include "EyeCollisionDetector.h"
#include "EyeEntityCollector.generated.h"

class AEyeCharacter;

UCLASS()
class EYEBALL_API AEyeEntityCollector : public AEyeCollisionDetector
{
	GENERATED_BODY()

private:
	bool bLeftOverlapping = false;
	bool bRightOverlapping = false;
	
	AEyeEntityCollector();
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox2;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AEyeCharacter> WantedEntity;
};
