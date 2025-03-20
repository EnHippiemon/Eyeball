#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StaticFunctionLibrary.generated.h"

UCLASS()
class EYEBALL_API UStaticFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static bool TracesAlongLine(AActor* Actor, FVector LineDirection, FVector TraceDirection, FVector TraceOffset, int TraceAmount, float DistanceBetweenTraces, float TraceLength, ECollisionChannel TraceChannel, bool ShowDebugLines);
};
