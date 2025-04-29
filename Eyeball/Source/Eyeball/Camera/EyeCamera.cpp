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
	StopRetractingCamera();
}

void AEyeCamera::AddActorToFocus(AActor* ActorToAdd, float const TimerDelay)
{
	RetractingCamera = false;
	
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
	StartRetractingCamera();
	FocusedActors.Remove(ActorToRemove);
}

void AEyeCamera::SetCameraOnStart()
{
	const FVector NewLocation = FVector(GetActorLocation().X, FocusedActors[0]->GetActorLocation().Y,
	                              FocusedActors[0]->GetActorLocation().Z);
	SetActorLocation(NewLocation);
	StopRetractingCamera();
}

void AEyeCamera::RemoveAllFocus()
{
	StartRetractingCamera();
	
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

void AEyeCamera::IncrementCameraSpeed(float const DeltaTime)
{
	if (!RetractingCamera)
		return;

	CurrentSpeed += DeltaTime * Data->SpeedIncrementationMultiplier;
	if (CurrentSpeed >= Data->NormalMoveSpeed)
		StopRetractingCamera();
}

void AEyeCamera::StartRetractingCamera()
{
	CurrentSpeed = Data->RetractCameraSpeed;
	RetractingCamera = true;
}

void AEyeCamera::StopRetractingCamera()
{
	CurrentSpeed = Data->NormalMoveSpeed;
	RetractingCamera = false;
}

void AEyeCamera::GetBackToTarget()
{
	if (FocusedActors.Num() > 1)
		return;
	if (Data->LimitDistanceToPlayerSpeed < CurrentSpeed)
		return;

	const FVector CameraPosition = FVector(0, GetActorLocation().Y, GetActorLocation().Z);
	const FVector PlayerPosition = FVector(0, FocusedActors[0]->GetActorLocation().Y, FocusedActors[0]->GetActorLocation().Z);

	const float CurrentDistance = (CameraPosition - PlayerPosition).Length();
	if (CurrentDistance > Data->AllowedDistanceToPlayer)
		CurrentSpeed = Data->LimitDistanceToPlayerSpeed;
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
	NewLocation = UKismetMathLibrary::VLerp(NewLocation, TargetLocation, CurrentSpeed * DeltaTime);

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

	// Calculate the camera's final position on Y and Z
	const float Y = DistanceY * CameraFOVCompensation * Data->YDistanceMultiplier;
	const float Z = DistanceZ * CameraFOVCompensation * Data->ZDistanceMultiplier;

	// Return the greatest distance of Y and Z
	// Aspect ratio is 16:9 (9/16)
	constexpr float AspectRatio = 0.5625;
	const float AspectRatioY = DistanceY * AspectRatio;
	return AspectRatioY > DistanceZ ? Y : Z;
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
	IncrementCameraSpeed(DeltaTime);
	GetBackToTarget();
}