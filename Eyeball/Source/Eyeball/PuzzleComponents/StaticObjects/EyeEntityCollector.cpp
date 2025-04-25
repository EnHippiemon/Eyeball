#include "EyeEntityCollector.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeEntityCollector::AEyeEntityCollector()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	MeshComponent->SetupAttachment(CollisionBox);

	CollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &AEyeEntityCollector::HandleEndOverlap);
	
	CollisionBox2 = CreateDefaultSubobject<UBoxComponent>("CollisionBox2");
	CollisionBox2->SetupAttachment(CollisionBox);
}

void AEyeEntityCollector::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CheckOverlaps();
	
	if (OverlappedComponent == CollisionBox)
	{
		if (OtherActor->GetClass() == WantedEntity)
			bLeftOverlapping = true;
	}
	if (OverlappedComponent == CollisionBox2)
	{
		if (OtherActor->GetClass() == WantedEntity)
			bRightOverlapping = true;
	}
}

void AEyeEntityCollector::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OverlappedComponent == CollisionBox)
	{
		if (OtherActor->GetClass() == WantedEntity)
			bLeftOverlapping = false;
	}
	if (OverlappedComponent == CollisionBox2)
	{
		if (OtherActor->GetClass() == WantedEntity)
			bRightOverlapping = false;
	}
	CheckOverlaps();
}

void AEyeEntityCollector::CheckOverlaps()
{
	TArray<AActor*> LeftOverlappingActors;
	CollisionBox->GetOverlappingActors(LeftOverlappingActors);
	for (int i = 0; i < LeftOverlappingActors.Num(); ++i)
	{
		if (LeftOverlappingActors[i]->GetClass() == WantedEntity)
		{
			bLeftOverlapping = true;
			break;
		}
		if (i == LeftOverlappingActors.Num())
			bLeftOverlapping = false;
	}
	TArray<AActor*> RightOverlappingActors;
	CollisionBox2->GetOverlappingActors(RightOverlappingActors);
	for (int i = 0; i < RightOverlappingActors.Num(); ++i)
	{
		if (RightOverlappingActors[i]->GetClass() == WantedEntity)
		{
			bRightOverlapping = true;
			break;
		}
		if (i == RightOverlappingActors.Num())
			bRightOverlapping = false;
	}

	if (bLeftOverlapping && bRightOverlapping)
		InteractWith();
}
