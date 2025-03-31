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
		if (!FocusedActors.IsValidIndex(i))
			continue;

		MiddleLocation += FocusedActors[i]->GetActorLocation();
		++ValidActors;
	}
	MiddleLocation /= ValidActors;

	auto NewLocation = GetActorLocation();
	NewLocation = UKismetMathLibrary::VLerp(NewLocation,
	                                        FVector(-FindDistanceBetweenActors(), MiddleLocation.Y, MiddleLocation.Z),
	                                        Data->MoveSpeed * DeltaTime);
	SetActorLocation(NewLocation);
}

float AEyeCamera::FindDistanceBetweenActors()
{
	// If player character is the only actor in focus, return
	if (FocusedActors.Num() <= 1)
		return GetActorLocation().X + Data->CameraOffset.X;

	// Find the smallest and largest values of Y and Z among the actor locations 
	FVector FurthestUpRight = FVector(0, FLT_MIN, FLT_MIN);
	FVector FurthestLeftDown = FVector(0, FLT_MAX, FLT_MAX);
	for (int i = 0; i < FocusedActors.Num(); ++i)
	{
		const auto ActorLocation = FocusedActors[i]->GetActorLocation();
		// Finding top right vectors
		if (ActorLocation.Y > FurthestUpRight.Y)
			FurthestUpRight.Y = ActorLocation.Y;
		if (ActorLocation.Z > FurthestUpRight.Z)
			FurthestUpRight.Z = ActorLocation.Z;
		
		// Finding down left vectors
		if (ActorLocation.Y < FurthestLeftDown.Y)
			FurthestLeftDown.Y = ActorLocation.Y;
		if (ActorLocation.Z < FurthestLeftDown.Z)
			FurthestLeftDown.Z = ActorLocation.Z;
	}

	// Make sure the distance is a positive number
	const float DistanceY = abs(FurthestUpRight.Y - FurthestLeftDown.Y);
	const float DistanceZ = abs(FurthestUpRight.Z - FurthestLeftDown.Z);

	// If the actor distance is too small, return the regular offset
	if (DistanceY < GetActorLocation().X + Data->CameraOffset.X
		&& DistanceZ < GetActorLocation().X + Data->CameraOffset.X)
		return GetActorLocation().X + Data->CameraOffset.X;

	// Return the greatest distance of Y and Z
	return DistanceY > DistanceZ ? DistanceY : DistanceZ;
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
		{ UE_LOG(LogTemp, Error, TEXT("AEyeCamera.cpp: GameMode is null")); }
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
			if (!FocusedActors.IsValidIndex(i))
				continue;
			
			FocusedActors.RemoveAt(i);
			--i;
			--NumberOfActors;
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