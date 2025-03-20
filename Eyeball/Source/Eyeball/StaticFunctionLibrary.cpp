#include "StaticFunctionLibrary.h"

bool UStaticFunctionLibrary::TracesAlongLine(AActor* Actor, FVector TraceOffset, int TraceAmount, float DistanceBetweenTraces, float TraceLength, ECollisionChannel TraceChannel, bool ShowDebugLines)
{
	const UWorld* World = Actor->GetWorld();
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Actor);
	TArray<bool> RightTraces;
	TArray<bool> LeftTraces;
	
	// Calculate set trace offset.
	FVector FinalTraceOffset = Actor->GetActorLocation() + TraceOffset;

	int HalfTraceAmount = TraceAmount * 0.5;
	for (int i = 0; i < HalfTraceAmount; ++i)
	{
		// Decide right side trace transform
		FVector RightTraceStart = FinalTraceOffset - FVector( 0, DistanceBetweenTraces, 0) + FVector(0, DistanceBetweenTraces * i, 0);
		FVector RightTraceEnd = RightTraceStart + FVector(0, 0, TraceLength);

		// Look for floor on right side 
		if (!RightTraces.IsValidIndex(i))
			RightTraces.Add(true);
		
		auto FloorTrace = World->LineTraceSingleByChannel(HitResult, RightTraceStart, RightTraceEnd, TraceChannel, Params, FCollisionResponseParams());
		RightTraces[i] = FloorTrace;
		
		// Decide left side trace transform
		FVector LeftTraceStart = FinalTraceOffset + FVector( 0, DistanceBetweenTraces, 0) - FVector(0, DistanceBetweenTraces * i, 0);
		FVector LeftTraceEnd = LeftTraceStart + FVector(0, 0, TraceLength);
		
		// Look for floor on left side
		if (!LeftTraces.IsValidIndex(i))
			LeftTraces.Add(true);
		
		FloorTrace = World->LineTraceSingleByChannel(HitResult, LeftTraceStart, LeftTraceEnd, TraceChannel, Params, FCollisionResponseParams());
		LeftTraces[i] = FloorTrace;
		
		if (ShowDebugLines)
		{
			DrawDebugLine(World, RightTraceStart, RightTraceEnd, FColor::Blue);
			DrawDebugLine(World, LeftTraceStart, LeftTraceEnd, FColor::Cyan);
		}
	}
	
	return RightTraces.Contains(true) || LeftTraces.Contains(true);
}