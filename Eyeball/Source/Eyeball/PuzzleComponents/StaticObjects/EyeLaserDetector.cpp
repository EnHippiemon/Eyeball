#include "EyeLaserDetector.h"
#include "Eyeball/StaticFunctionLibrary.h"
#include "Eyeball/DataAssets/PuzzleComponentsDataAssets/EyeLaserDetectorDataAsset.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"

AEyeLaserDetector::AEyeLaserDetector()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeLaserDetector::SearchForVictim()
{
	if (ObjectToFollow->GetIsActivated())
		return;
	
	const auto FoundVictim = UStaticFunctionLibrary::TracesAlongLine(this, Data->LineDirection, Data->TraceDirection,
	                                                                 Data->TraceOffset, Data->TraceAmount,
	                                                                 Data->DistanceBetweenTraces, TraceLength,
	                                                                 Data->VictimCollisionChannel, true);
	if (FoundVictim)
		InteractWith();
}

void AEyeLaserDetector::FollowObject()
{
	if (!ObjectToFollow || !ObjectToFollow->GetHasReachedTarget() && !ObjectToFollow->GetIsActivated())
		return;
	
	SetActorLocation(ObjectToFollow->GetActorLocation());
	const float LengthDifference = (StartPoint - ObjectToFollow->GetActorLocation()).Length();
	TraceLength = Data->TraceLength + LengthDifference;
}

void AEyeLaserDetector::BeginPlay()
{
	Super::BeginPlay();

	TraceLength = Data->TraceLength;

	if (!ObjectToFollow)
		return;

	SetActorLocation(ObjectToFollow->GetActorLocation());
	StartPoint = GetActorLocation();
}

void AEyeLaserDetector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SearchForVictim();
	FollowObject();
}