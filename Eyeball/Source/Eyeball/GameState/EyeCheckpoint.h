#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeCheckpoint.generated.h"

class AEyeCharacter;
class UBoxComponent;

UCLASS()
class EYEBALL_API AEyeCheckpoint : public AActor
{
	GENERATED_BODY()
	
protected:
	AEyeCheckpoint();
	
	UFUNCTION()
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnOverlapSuccess(AEyeCharacter* EyeCharacter);
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxComponent;
	UPROPERTY(EditInstanceOnly)
	TArray<TSubclassOf<AEyeCharacter>> IgnoredCharacters;
	
};
