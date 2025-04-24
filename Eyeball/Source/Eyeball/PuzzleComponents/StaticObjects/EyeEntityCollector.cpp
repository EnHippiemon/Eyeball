#include "EyeEntityCollector.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"


AEyeEntityCollector::AEyeEntityCollector()
{
	CollisionBox2 = CreateDefaultSubobject<UBoxComponent>("CollisionBox2");
	CollisionBox2->SetupAttachment(RootComponent);
	CollisionBox2->OnComponentBeginOverlap.AddDynamic(this, &AEyeEntityCollector::HandleBeginOverlap);
	CollisionBox2->OnComponentEndOverlap.AddDynamic(this, &AEyeEntityCollector::HandleEndOverlap);
}

void AEyeEntityCollector::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEyeEntityCollector::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OverlappedComponent == CollisionBox)
	{
		if (OtherActor->StaticClass() == WantedEntity)
			bLeftOverlapping = true;
	}
	if (OverlappedComponent == CollisionBox2)
	{
		if (OtherActor->StaticClass() == WantedEntity)
			bRightOverlapping = true;
	}
	// Add check to see all overlapping components. 
}

void AEyeEntityCollector::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OverlappedComponent == CollisionBox)
	{
		if (OtherActor->StaticClass() == WantedEntity)
			bLeftOverlapping = false;
	}
	if (OverlappedComponent == CollisionBox2)
	{
		if (OtherActor->StaticClass() == WantedEntity)
			bRightOverlapping = false;
	}
}