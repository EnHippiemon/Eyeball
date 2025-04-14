#include "EyeNPC.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AEyeNPC::AEyeNPC()
{
	PrimaryActorTick.bCanEverTick = true;

	RootCapsule = CreateDefaultSubobject<UCapsuleComponent>("RootCapsule");
	RootComponent = RootCapsule;

	SearchBox = CreateDefaultSubobject<UBoxComponent>("SearchBox");
	SearchBox->SetupAttachment(RootCapsule);
	SearchBox->OnComponentBeginOverlap.AddDynamic(this, &AEyeNPC::HandleBeginOverlap);
	SearchBox->OnComponentEndOverlap.AddDynamic(this, &AEyeNPC::HandleEndOverlap);
	
	WithinReachCollider = CreateDefaultSubobject<UBoxComponent>("WithinReachCollider");
	WithinReachCollider->SetupAttachment(RootCapsule);
	WithinReachCollider->OnComponentBeginOverlap.AddDynamic(this, &AEyeNPC::HandleBeginOverlap);
}

void AEyeNPC::StopMoving()
{
	FLatentActionManager LatentActionManager = GetWorld()->GetLatentActionManager();
	LatentActionManager.RemoveActionsForObject(this);
}

void AEyeNPC::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OverlappedComponent == WithinReachCollider)
	{
		for (int i = 0; i < Friends.Num(); ++i)
		{
			if (Friends[i] != OtherActor)
				continue;

			StopMoving();
			InteractWith();
		}
	}
	else if (OverlappedComponent == SearchBox)
	{
		for (int i = 0; i < Friends.Num(); ++i)
		{
			if (Friends[i] != OtherActor)
				continue;

			UKismetSystemLibrary::MoveComponentTo(
				RootCapsule,
				Friends[i]->GetActorLocation(),
				GetActorRotation(),
				true,
				true,
				2,
				false,
				EMoveComponentAction::Move,
				LatentInfo
				);
		}
	}
}

void AEyeNPC::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
							   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OverlappedComponent != SearchBox)
		return;
	
	for (int i = 0; i < Friends.Num(); ++i)
	{
		if (Friends[i] != OtherActor)
			continue;

		StopMoving();
	}
}