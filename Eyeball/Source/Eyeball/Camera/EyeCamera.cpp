#include "EyeCamera.h"

#include "Camera/CameraComponent.h"
#include "Components/SpotLightComponent.h"
#include "Eyeball/DataAssets/CameraDataAssets/EyeMainCameraDataAsset.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AEyeCamera::AEyeCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>("SpotLight");
	SpotLight->SetupAttachment(GetRootComponent());
}

void AEyeCamera::OnSpawned()
{
	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
		{ UE_LOG(LogTemp, Error, TEXT("AEyeCamera.cpp: GameMode is null")); }
	else
	{
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeCamera::GetNewPlayerReference);
		GameMode->OnChangedState.AddUniqueDynamic(this, &AEyeCamera::OnNewGameState);
	}

	SetRotation();
	CameraOffsetCompensationForFOV();
	RetractingCamera = false;
}

void AEyeCamera::AddActorToFocus(AActor* ActorToAdd, float const TimerDelay)
{
	for (int i = 0; i < FocusedActors.Num(); ++i)
	{
		if (FocusedActors[i]->GetName() == ActorToAdd->GetName())
			FocusedActors.RemoveAt(i);
	}
	FocusedActors.Add(ActorToAdd);

	if (TimerDelay <= 0)
		return;

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEyeCamera::RemoveAllFocus, TimerDelay, false, TimerDelay);
}

void AEyeCamera::RemoveActorFromFocus(AActor* ActorToRemove)
{
	RetractingCamera = true;
	FocusedActors.Remove(ActorToRemove);
}

void AEyeCamera::SetCameraOnStart()
{
	const FVector NewLocation = FVector(GetActorLocation().X, FocusedActors[0]->GetActorLocation().Y,
	                              FocusedActors[0]->GetActorLocation().Z);
	SetActorLocation(NewLocation);
	RetractingCamera = false;
}

void AEyeCamera::RemoveAllFocus()
{
	// Remove all focused actors except player (which is at index 0)
	int NumberOfActors = FocusedActors.Num();
	for (int i = 1; i < NumberOfActors; ++i)
	{
		if (!FocusedActors.IsValidIndex(i))
			continue;

		FocusedActors.RemoveAt(i);
		--i;
		--NumberOfActors;
	}
}

void AEyeCamera::CheckIfRetractingCameraReachedTarget()
{
	if (!RetractingCamera)
		return;

	if (FMath::IsNearlyEqual(GetActorLocation().X, TargetLocation.X, Data->ResetCameraRetractionTolerance))
		RetractingCamera = false;
}

void AEyeCamera::MoveTowardsTarget(float const DeltaTime)
{
	// Calculate the mean value of all focused actors
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

	// Move towards the mean value 
	TargetLocation = FVector(-FindDistanceBetweenActors(), MiddleLocation.Y, MiddleLocation.Z);
	auto NewLocation = GetActorLocation();
	NewLocation = UKismetMathLibrary::VLerp(NewLocation, TargetLocation,
	                                        RetractingCamera
		                                        ? Data->RetractCameraSpeed * DeltaTime
		                                        : Data->NormalMoveSpeed * DeltaTime);
	SetActorLocation(NewLocation);
}

float AEyeCamera::FindDistanceBetweenActors()
{
	// If player character is the only actor in focus, return
	if (FocusedActors.Num() <= 1)
		return (GetActorLocation().X + Data->CameraOffset.X) * CameraFOVCompensation;

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
		return (GetActorLocation().X + Data->CameraOffset.X) * CameraFOVCompensation;

	// Return the greatest distance of Y and Z
	return DistanceY > DistanceZ ? DistanceY * CameraFOVCompensation : DistanceZ * CameraFOVCompensation;
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

void AEyeCamera::OnNewGameState(EGameState NewState)
{
	if (NewState == Egs_GameOver)
		RemoveAllFocus();
	else if (NewState == Egs_StartingGame)
		SetCameraOnStart();
}

void AEyeCamera::SetRotation()
{
	SetActorRotation(FRotator(0, 0, 0));
}

void AEyeCamera::CameraOffsetCompensationForFOV()
{
	// 90 is original FOV. This makes sure that any FOV used, all actors in focus will still be visible.
	CameraFOVCompensation = 90 / GetCameraComponent()->FieldOfView;
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
	CheckIfRetractingCameraReachedTarget();
}
