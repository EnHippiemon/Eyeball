#include "EyeTips.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Eyeball/Widgets/EyeTipsWidget.h"
#include "Kismet/GameplayStatics.h"


void AEyeTips::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		bPlayerHasEntered = true;
		bPlayerHasLeft = false;
	}
}

void AEyeTips::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		bPlayerHasEntered = false;
		bPlayerHasLeft = true;
		TimeSincePlayerEntered = 0;

		if (EyeTipsWidgetRef)
			EyeTipsWidgetRef->ShouldFadeOut(true);
	}
}

void AEyeTips::CountTimeSincePlayerEntered(float const DeltaTime)
{
	if (!bPlayerHasEntered)
		return;

	TimeSincePlayerEntered += DeltaTime;

	if (TimeSincePlayerEntered < TimeBeforeTips)
		return;

	if (EyeTipsWidgetRef)
		return;
	EyeTipsWidgetRef = CreateWidget<UEyeTipsWidget>(GetWorld(), EyeTipsWidget);
	if (EyeTipsWidgetRef)
		EyeTipsWidgetRef->AddToViewport();
}

void AEyeTips::HandlePlayerHasLeft()
{
	if (!EyeTipsWidgetRef)
		return;
	
	if (EyeTipsWidgetRef->GetOpacity() < 0)
	{
		EyeTipsWidgetRef->RemoveFromParent();
		EyeTipsWidgetRef->MarkAsGarbage();
		EyeTipsWidgetRef = nullptr;
		bPlayerHasLeft = false;
		CollectGarbage(EObjectFlags::RF_NoFlags);
	}
}

AEyeTips::AEyeTips()
{
	PrimaryActorTick.bCanEverTick = true;

	EnterBox = CreateDefaultSubobject<UBoxComponent>("EnterBox");
	RootComponent = EnterBox;
	EnterBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &AEyeTips::OnBeginOverlap);

	ExitBox = CreateDefaultSubobject<UBoxComponent>("ExitBox");
	ExitBox->SetupAttachment(EnterBox);
	ExitBox->OnComponentEndOverlap.AddUniqueDynamic(this, &AEyeTips::OnEndOverlap);

	bPlayerHasEntered = false;
	bPlayerHasLeft = false;
}

void AEyeTips::BeginPlay()
{
	Super::BeginPlay();

}

void AEyeTips::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CountTimeSincePlayerEntered(DeltaTime);
	HandlePlayerHasLeft();
}