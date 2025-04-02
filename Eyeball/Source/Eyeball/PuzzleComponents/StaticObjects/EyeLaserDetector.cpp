#include "EyeLaserDetector.h"
#include "Eyeball/StaticFunctionLibrary.h"
#include "Eyeball/DataAssets/PuzzleComponentsDataAssets/EyeLaserDetectorDataAsset.h"

AEyeLaserDetector::AEyeLaserDetector()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeLaserDetector::SearchForVictim()
{
	const auto FoundVictim = UStaticFunctionLibrary::TracesAlongLine(this, Data->LineDirection, Data->TraceDirection,
	                                                                 Data->TraceOffset, Data->TraceAmount,
	                                                                 Data->DistanceBetweenTraces, TraceLength,
	                                                                 Data->VictimCollisionChannel, true);
	if (FoundVictim)
		InteractWith();
}

void AEyeLaserDetector::FollowObject()
{
	if (!ObjectToFollow)
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
	
	StartPoint = ObjectToFollow->GetActorLocation();
}

void AEyeLaserDetector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SearchForVictim();
	FollowObject();
}