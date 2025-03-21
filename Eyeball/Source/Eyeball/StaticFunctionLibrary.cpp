#include "StaticFunctionLibrary.h"

bool UStaticFunctionLibrary::TracesAlongLine(AActor* Actor, FVector LineDirection, FVector TraceDirection, FVector TraceOffset, int TraceAmount, float DistanceBetweenTraces, float TraceLength, ECollisionChannel TraceChannel, bool ShowDebugLines)
{
	const UWorld* World = Actor->GetWorld();
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Actor);
	TArray<bool> LeftTraces;
	TArray<bool> RightTraces;
	
	// Calculate set trace offset.
	FVector FinalTraceOffset = Actor->GetActorLocation() + TraceOffset;

	int HalfTraceAmount = TraceAmount * 0.5;
	for (int i = 0; i < HalfTraceAmount; ++i)
	{
		// Decide left side trace transform
		FVector LeftTraceStart = FinalTraceOffset + LineDirection * DistanceBetweenTraces - LineDirection * DistanceBetweenTraces * i;
		FVector LeftTraceEnd = LeftTraceStart + TraceDirection * TraceLength;
		
		// Look for collision on left side
		if (!LeftTraces.IsValidIndex(i))
			LeftTraces.Add(true);
		
		auto FloorTrace = World->LineTraceSingleByChannel(HitResult, LeftTraceStart, LeftTraceEnd, TraceChannel, Params, FCollisionResponseParams());
		LeftTraces[i] = FloorTrace;
		
		// Decide right side trace transform
		FVector RightTraceStart = FinalTraceOffset - LineDirection * DistanceBetweenTraces + LineDirection * DistanceBetweenTraces * i;
		FVector RightTraceEnd = RightTraceStart + TraceDirection * TraceLength;

		// Look for collision on right side 
		if (!RightTraces.IsValidIndex(i))
			RightTraces.Add(true);
		
		FloorTrace = World->LineTraceSingleByChannel(HitResult, RightTraceStart, RightTraceEnd, TraceChannel, Params, FCollisionResponseParams());
		RightTraces[i] = FloorTrace;

		if (ShowDebugLines)
		{
			DrawDebugLine(World, RightTraceStart, RightTraceEnd, FColor::Blue);
			DrawDebugLine(World, LeftTraceStart, LeftTraceEnd, FColor::Cyan);
		}
	}
	
	return RightTraces.Contains(true) || LeftTraces.Contains(true);
}