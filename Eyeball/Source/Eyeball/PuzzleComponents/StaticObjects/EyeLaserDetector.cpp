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
	const auto FoundVictim = UStaticFunctionLibrary::TracesAlongLine(this, Data->LineDirection, Data->TraceDirection,
	                                                                 Data->TraceOffset, Data->TraceAmount,
	                                                                 Data->DistanceBetweenTraces, TraceLength,
	                                                                 Data->VictimCollisionChannel, true);
	if (FoundVictim)
		InteractWith();
}

void AEyeLaserDetector::BeginPlay()
{
	Super::BeginPlay();

	TraceLength = Data->TraceLength;
}

void AEyeLaserDetector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SearchForVictim();
}