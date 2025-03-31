#include "../MoveableObjects/EyeMoveableDanger.h"
#include "Eyeball/Entities/EyeCharacter.h"

void AEyeMoveableDanger::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::HandleBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;

	FoundActor->DamagePlayer();
}
