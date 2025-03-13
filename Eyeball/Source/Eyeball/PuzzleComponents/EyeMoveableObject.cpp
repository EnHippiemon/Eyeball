#include "../PuzzleComponents/EyeMoveableObject.h"

#include "Components/BoxComponent.h"
#include "Eyeball/DataAssets/EyeMoveableObjectDataAsset.h"

AEyeMoveableObject::AEyeMoveableObject()
{
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>("RootComponent");
	RootComponent = Box;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");
	CollisionBox->SetupAttachment(Box);
}

void AEyeMoveableObject::Activate()
{
	bIsActivated = true;
	bHasReachedTarget = false;
}

void AEyeMoveableObject::MoveToTarget()
{
	if (!bIsActivated)
		return;

	if ((GetActorLocation() - TargetLocation).Length() < 10.f)
	{
		bIsActivated = false;
		bHasReachedTarget = true;
	}

	const auto NewLocation = GetActorLocation() + ObjectData->MoveDirection * ObjectData->MoveSpeed * GetWorld()->DeltaTimeSeconds;
	SetActorRelativeLocation(NewLocation);
}

void AEyeMoveableObject::MoveToStart()
{
	if (!ObjectData->ReturnToStartLocation || !bHasReachedTarget)
		return;

	if ((GetActorLocation() - StartLocation).Length() < 10.f)
		bHasReachedTarget = false;
	
	const auto NewLocation = GetActorLocation() - ObjectData->MoveDirection * ObjectData->MoveSpeed * GetWorld()->DeltaTimeSeconds;
	SetActorRelativeLocation(NewLocation);
}

void AEyeMoveableObject::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	TargetLocation = GetActorLocation() + ObjectData->TargetOffset;
}

void AEyeMoveableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToTarget();
	MoveToStart();
}