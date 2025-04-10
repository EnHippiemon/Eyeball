#include "EyeAttachedLaserDetector.h"

#include "EyeMoveableObject.h"
#include "Eyeball/DataAssets/PuzzleComponentsDataAssets/EyeLaserDetectorDataAsset.h"


AEyeAttachedLaserDetector::AEyeAttachedLaserDetector()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeAttachedLaserDetector::SearchForVictim()
{
	if (!ObjectToFollow)
	{
		UE_LOG(LogTemp, Log, TEXT("%s: No object interact with"), *GetName());
		return;
	}
	
	if (ObjectToFollow->GetIsActivated())
		return;
	
	Super::SearchForVictim();
}

void AEyeAttachedLaserDetector::FollowObject()
{
	if (!ObjectToFollow)
	{
		UE_LOG(LogTemp, Log, TEXT("%s: No object interact with"), *GetName());
		return;
	}
	
	if (ObjectToFollow->GetActorLocation() == GetActorLocation())
		return;
	
	SetActorLocation(ObjectToFollow->GetActorLocation());
	const float LengthDifference = (StartPoint - ObjectToFollow->GetActorLocation()).Length();
	TraceLength = Data->TraceLength + LengthDifference;
}

void AEyeAttachedLaserDetector::BeginPlay()
{
	Super::BeginPlay();

	if (!ObjectToFollow)
	{
		UE_LOG(LogTemp, Log, TEXT("%s: No object interact with"), *GetName());
		return;
	}

	SetActorLocation(ObjectToFollow->GetActorLocation());
	StartPoint = GetActorLocation();
}

void AEyeAttachedLaserDetector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FollowObject();
}