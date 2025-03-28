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
	// const auto Target = PlayerCharacter->GetActorLocation();
	// auto NewLocation = GetActorLocation();
	// NewLocation = UKismetMathLibrary::VLerp(NewLocation, FVector(/*NewLocation.X + */Data->CameraOffset.X, Target.Y, Target.Z), Data->MoveSpeed * DeltaTime);
	// SetActorLocation(NewLocation);


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
	NewLocation = UKismetMathLibrary::VLerp(NewLocation, FVector(Data->CameraOffset.X, MiddleLocation.Y, MiddleLocation.Z), Data->MoveSpeed * DeltaTime);
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
	// FocusedActors.Insert(NewCharacter, 0);
	FocusedActors[0] = NewCharacter;
	// PlayerCharacter = NewCharacter;
}

void AEyeCamera::OnSpawned()
{
	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
		{ UE_LOG(LogTemp, Error, TEXT("AEyeCamera.cpp: GameMode is null")); }
	else
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeCamera::GetNewPlayerReference);

	// ChangeFocus({PlayerCharacter/*, Data->Target1/*, Data->Target2/*, Data->Target3, Data->Target4*/});
}

void AEyeCamera::AddActorToFocus(AActor* ActorToAdd)
{
	if (FocusedActors.Find(ActorToAdd))
		FocusedActors.Remove(ActorToAdd);
	
	FocusedActors.Add(ActorToAdd);
	// ChangeFocus({PlayerCharacter/*, Data->Target1/*, Data->Target2/*, Data->Target3, Data->Target4*/});

	// GetWorldTimerManager().SetTimer(TimerHandle, this, &AEyeCamera::RemoveActorFromFocus, 2.f, false, 2.f);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEyeCamera::OnTimerActivated, 2.f, false, 2.f);
}

void AEyeCamera::RemoveActorFromFocus(AActor* ActorToRemove)
{
	
}

void AEyeCamera::OnTimerActivated()
{
	FocusedActors.RemoveAt(FocusedActors.Num() - 1);
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