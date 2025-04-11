#include "../StaticObjects/EyeDanger.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeDanger::AEyeDanger()
{
	PrimaryActorTick.bCanEverTick = false;

	DangerBox = CreateDefaultSubobject<UBoxComponent>("DangerBox");
	RootComponent = DangerBox;

	DangerBox->OnComponentBeginOverlap.AddDynamic(this, &AEyeDanger::HandleBeginOverlap);
}

void AEyeDanger::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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