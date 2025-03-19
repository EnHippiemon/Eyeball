#include "EyeDangerComponent.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"

UEyeDangerComponent::UEyeDangerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// DangerBox = CreateDefaultSubobject<UBoxComponent>("DangerBox");
	//
	// // DangerBox->SetupAttachment(GetOwner()->GetRootComponent());
	// // DangerBox->SetupAttachment(GetOwner()->GetRootComponent());
	// // if (DangerBox)
	// // 	DangerBox->SetupAttachment(GetOwner()->GetRootComponent(), "DangerBoxComponent");
	// // RootComponent = DangerBox;
	// // DangerBox->SetWorldLocation()
	//
	// DangerBox->OnComponentBeginOverlap.AddDynamic(this, &UEyeDangerComponent::HandleBeginOverlap);
}

// void UEyeDangerComponent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// 	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
// 	if (!FoundActor)
// 		return;
//
// 	FoundActor->DamagePlayer();
// }