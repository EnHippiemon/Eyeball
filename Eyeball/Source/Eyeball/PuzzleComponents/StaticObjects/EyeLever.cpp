#include "EyeLever.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"


AEyeLever::AEyeLever()
{
	PrimaryActorTick.bCanEverTick = true;

	LeverBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverBase"));
	LeverBase->SetupAttachment(GetRootComponent());

	LeverHandle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverHandle"));
	LeverHandle->SetupAttachment(LeverBase);
}

void AEyeLever::InteractWith()
{
	if (CurrentState == Elhs_Activated)
		Super::InteractWith();
	else if (CurrentState == Elhs_Deactivated)
	{
		TargetRotation = MaxRotation;
		CurrentState = Elhs_Moving;
	}
}

void AEyeLever::MoveHandle(float const DeltaTime)
{
	if (CurrentState == Elhs_Activated)
		return;

	const float RotationalDifference = TargetRotation.Pitch - LeverHandle->GetRelativeRotation().Pitch;
	if (CurrentState == Elhs_Deactivated && RotationalDifference < 5.f)
		return;
	if (CurrentState == Elhs_Moving && RotationalDifference > 5.f)
		return;

	auto NewRotation = LeverHandle->GetRelativeRotation() + TargetRotation * RotationSpeed * DeltaTime;
	LeverHandle->SetRelativeRotation(NewRotation);

	if (LeverHandle->GetRelativeRotation().Pitch - TargetRotation.Pitch < 5.f
		&& CurrentState == Elhs_Moving)
	{
		CurrentState = Elhs_Activated;
		InteractWith();
	}
}

void AEyeLever::Deactivate()
{
	if (!bShouldDeactivate || CurrentState != Elhs_Activated)
		return;

	for (int i = 0; i < MoveableObject.Num(); ++i)
	{
		if (!MoveableObject[i]->GetHasReachedTarget())
			continue;

		TargetRotation = BaseRotation;
		CurrentState = Elhs_Deactivated;
		break;
	}
}

void AEyeLever::CheckShouldDeactivate()
{
	for (int i = 0; i < MoveableObject.Num(); ++i)
	{
		if (!MoveableObject[i]->GetShouldReturnToStart()
			|| MoveableObject[i]->GetShouldLoop())
			continue;
		
		bShouldDeactivate = true;
		break;
	}
}

void AEyeLever::BeginPlay()
{
	Super::BeginPlay();

	TargetRotation = BaseRotation;
	LeverHandle->SetRelativeRotation(BaseRotation);
	CurrentState = Elhs_Deactivated;
	CheckShouldDeactivate();
}

void AEyeLever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveHandle(DeltaTime);
	Deactivate();
}