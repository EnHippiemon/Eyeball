#include "EyeCamera.h"

#include "Eyeball/DataAssets/CameraDataAssets/EyeMainCameraDataAsset.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AEyeCamera::AEyeCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeCamera::MoveTowardsTarget(float const DeltaTime)
{
	FVector MiddleLocation;
	int ValidActors = 0;
	for (int i = 0; i < FocusedActors.Num(); ++i)
	{
		if (!FocusedActors[i])
			continue;

		MiddleLocation += FocusedActors[i]->GetActorLocation();
		++ValidActors;
	}
	MiddleLocation /= ValidActors;

	auto NewLocation = GetActorLocation();
	NewLocation = UKismetMathLibrary::VLerp(NewLocation,
	                                        FVector(Data->CameraOffset.X, MiddleLocation.Y, MiddleLocation.Z),
	                                        Data->MoveSpeed * DeltaTime);
	SetActorLocation(NewLocation);
}

void AEyeCamera::ChangeFocus(const TArray<AActor*>& NewActors)
{
	FocusedActors.Empty();
	FocusedActors = NewActors;
}

void AEyeCamera::GetNewPlayerReference(AEyeCharacter* NewCharacter)
{
	if (!FocusedActors.IsValidIndex(0))
	{
		FocusedActors.Add(NewCharacter);
		return;
	}
	FocusedActors[0] = NewCharacter;
}

void AEyeCamera::OnSpawned()
{
	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("AEyeCamera.cpp: GameMode is null"));
	}
	else
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeCamera::GetNewPlayerReference);
}

void AEyeCamera::AddActorToFocus(AActor* ActorToAdd, float const TimerDelay)
{
	for (int i = 0; i < FocusedActors.Num(); ++i)
	{
		if (FocusedActors[i]->GetName() == ActorToAdd->GetName())
			FocusedActors.RemoveAt(i);
	}
	FocusedActors.Add(ActorToAdd);

	// Remove all focused actors except player (which is at index 0)
	FTimerDelegate Delegate;
	Delegate.BindLambda([&]()
	{
		int NumberOfActors = FocusedActors.Num();
		for (int i = 1; i < NumberOfActors; ++i)
		{
			if (FocusedActors.IsValidIndex(i))
			{
				FocusedActors.RemoveAt(i);
				--i;
				--NumberOfActors;
			}
		}
	});

	GetWorldTimerManager().SetTimer(TimerHandle, Delegate, TimerDelay, false, TimerDelay);
}

void AEyeCamera::BeginPlay()
{
	Super::BeginPlay();

	OnSpawned();
}

void AEyeCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveTowardsTarget(DeltaTime);
}