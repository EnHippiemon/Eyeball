#include "EyeEntityEyeball.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


void AEyeEntityEyeball::FindOverlap()
{
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	TArray<bool> SafetyTraces;
	TArray<bool> EntityTraces;

	const FVector TraceOffset = GetActorLocation() - FVector(PlayerRadius, 0, 0);
	
	constexpr int TraceAmount = 10;
	for (int i = 0; i < TraceAmount; ++i)
	{
		// Decide trace transform 
		FVector TraceStart = TraceOffset + PlayerRadius * GetActorUpVector().RotateAngleAxis(360.f / TraceAmount * i + 1, FVector(1, 0, 0));
		FVector TraceEnd = TraceStart + FVector(500, 0, 0);;
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red);

		// Look for safe zone 
		if (!SafetyTraces.IsValidIndex(i))
			SafetyTraces.Add(true);
		
		const auto SafetyTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, GetSafeZone(), Params, FCollisionResponseParams());
		SafetyTraces[i] = SafetyTrace;

		// Look for possessable entities 
		if (!EntityTraces.IsValidIndex(i))
			EntityTraces.Add(false);
		
		const auto EntityTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, GetEntityBody(), Params, FCollisionResponseParams());
		EntityTraces[i] = EntityTrace;
		if (EntityTrace)
			FoundEntity = Cast<AEyeCharacter>(HitResult.GetActor());
	}

	bIsInDanger = SafetyTraces.Contains(false);
	bCanChangeEntity = EntityTraces.Contains(true);
}

void AEyeEntityEyeball::HandleActionInput()
{
	Super::HandleActionInput();
	
	if (!bCanChangeEntity || !IsValid(FoundEntity))
		return;

	PossessNewEntity(FoundEntity);
}

void AEyeEntityEyeball::MakeJump()
{
	Super::MakeJump();

	UE_LOG(LogTemp, Log, TEXT("Jump"));
}

void AEyeEntityEyeball::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	UE_LOG(LogTemp, Log, TEXT("Don't jump"));

	// CheckIsJumpHeld(JumpHoldTime);
	UE_LOG(LogTemp, Log, TEXT("Long jump: %hhd"), CheckIsJumpHeld(HeldJumpThreshold));
}

void AEyeEntityEyeball::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y) * MovementSpeed * DeltaTime;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeEntityEyeball::BeginPlay()
{
	Super::BeginPlay();

	PlayerRadius = GetCapsuleComponent()->GetScaledCapsuleRadius();

	SetActorLocation(FVector(0, GetActorLocation().Y, GetActorLocation().Z));
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}

void AEyeEntityEyeball::Tick(float DeltaTime)
{
	if (GetEntityState() != Ees_Eyeball)
		return;
	
	Super::Tick(DeltaTime);

	FindOverlap();
	MakeMovement(DeltaTime);
}
