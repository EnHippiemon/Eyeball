#include "EyeCamera.h"

#include "Eyeball/DataAssets/CameraDataAssets/EyeMainCameraDataAsset.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


AEyeCamera::AEyeCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeCamera::MoveTowardsTarget(const float DeltaTime)
{
	if (!PlayerCharacter)
		return;
	
	const auto Target = PlayerCharacter->GetActorLocation();
	auto NewLocation = GetActorLocation();
	NewLocation = UKismetMathLibrary::VLerp(NewLocation, FVector(/*NewLocation.X + */Data->CameraOffset.X, Target.Y, Target.Z), Data->MoveSpeed * DeltaTime);
	SetActorLocation(NewLocation);
}

void AEyeCamera::ChangePrimaryFocus()
{
}

void AEyeCamera::GetNewPlayerReference(AEyeCharacter* NewCharacter)
{
	PlayerCharacter = NewCharacter;
}

void AEyeCamera::OnSpawned()
{
	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
	{ UE_LOG(LogTemp, Error, TEXT("AEyeCamera.cpp: GameMode is null")); }
	else
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeCamera::GetNewPlayerReference);
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