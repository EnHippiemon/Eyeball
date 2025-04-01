#include "EyeCameraFocusAdder.h"

#include "EyeCamera.h"
#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"


AEyeCameraFocusAdder::AEyeCameraFocusAdder()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("OverlapBox");
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AEyeCameraFocusAdder::HandleBeginOverlap);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AEyeCameraFocusAdder::HandleEndOverlap);
}

void AEyeCameraFocusAdder::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		auto CameraRef = Cast<AEyeCamera>(UGameplayStatics::GetActorOfClass(GetWorld(), CameraClass));
		if (!CameraRef)
			return;

		for (int i = 0; i < ObjectsToFocusOn.Num(); ++i)
		{
			CameraRef->AddActorToFocus(ObjectsToFocusOn[i], 0);
		}
	}
}

void AEyeCameraFocusAdder::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		auto CameraRef = Cast<AEyeCamera>(UGameplayStatics::GetActorOfClass(GetWorld(), CameraClass));
		if (!CameraRef)
			return;

		for (int i = 0; i < ObjectsToFocusOn.Num(); ++i)
		{
			CameraRef->RemoveActorFromFocus(ObjectsToFocusOn[i]);
		}
	}
}