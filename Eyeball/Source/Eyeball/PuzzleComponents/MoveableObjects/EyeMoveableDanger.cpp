#include "../MoveableObjects/EyeMoveableDanger.h"

#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Components/BoxComponent.h"

void AEyeMoveableDanger::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const auto FoundActor = Cast<AEyeCharacter>(OtherActor))
	{
		if (FoundActor->GetIsPossessed())
		{
			FoundActor->TakeDamage();
			return;
		}

		FoundActor->ResetPosition();
		return;
	}
	if (const auto FoundActor = Cast<AEyeEnemy>(OtherActor))
	{
		if (OtherComp == Cast<UPrimitiveComponent>(FoundActor->GetDamageComponent()))
			FoundActor->ChangeHealth(-1);
		return;
	}
}
