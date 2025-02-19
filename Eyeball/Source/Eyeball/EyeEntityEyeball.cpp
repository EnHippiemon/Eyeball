#include "EyeEntityEyeball.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AEyeEntityEyeball::AEyeEntityEyeball()
{
	GetCharacterMovement()->GravityScale = 0.f;
	PlayerRadius = GetCapsuleComponent()->GetScaledCapsuleRadius();
}

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
		FVector TraceStart = TraceOffset + PlayerRadius * GetActorUpVector().RotateAngleAxis(
			360.f / TraceAmount * i + 1, FVector(1, 0, 0));
		FVector TraceEnd = TraceStart + FVector(500, 0, 0);;
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red);

		// Look for safe zone 
		if (!SafetyTraces.IsValidIndex(i))
			SafetyTraces.Add(true);

		const auto SafetyTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, GetSafeZone(),
		                                                              Params, FCollisionResponseParams());
		SafetyTraces[i] = SafetyTrace;

		// Look for possessable entities 
		if (!EntityTraces.IsValidIndex(i))
			EntityTraces.Add(false);

		const auto EntityTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, GetEntityBody(),
		                                                              Params, FCollisionResponseParams());
		EntityTraces[i] = EntityTrace;
		if (EntityTrace)
			FoundEntity = Cast<AEyeCharacter>(HitResult.GetActor());
	}

	bIsInDanger = SafetyTraces.Contains(false);
	bCanChangeEntity = EntityTraces.Contains(true);
}

void AEyeEntityEyeball::HandleDanger(float DeltaTime)
{
	if (!bIsInDanger)
	{
		TimeInDanger = 0.f;
		return;
	}

	TimeInDanger += DeltaTime;
	UE_LOG(LogTemp, Log, TEXT("Time in danger: %f"), TimeInDanger);

	if (TimeInDanger < MaxTimeInDanger)
		return;

	OnDeath.Broadcast();
}

void AEyeEntityEyeball::HandleActionInput()
{
	Super::HandleActionInput();

	if (!bCanChangeEntity || !IsValid(FoundEntity))
		return;

	PossessNewEntity(FoundEntity);
}

void AEyeEntityEyeball::HandleEjectInput()
{
	UE_LOG(LogTemp, Log, TEXT("Don't eject."));
}

void AEyeEntityEyeball::MakeJump()
{
	GetCharacterMovement()->MaxFlySpeed = JumpForce;
}

void AEyeEntityEyeball::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	GetCharacterMovement()->MaxFlySpeed = NormalMovementSpeed;
	UE_LOG(LogTemp, Log, TEXT("Don't jump"));

	// CheckIsJumpHeld(JumpHoldTime);
	UE_LOG(LogTemp, Log, TEXT("Long jump: %hhd"), CheckIsJumpHeld(HeldJumpThreshold));
}

void AEyeEntityEyeball::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y) * NormalMovementSpeed * DeltaTime;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeEntityEyeball::OnSpawned()
{
	Super::OnSpawned();

	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	GetCharacterMovement()->MaxFlySpeed = NormalMovementSpeed;
}

void AEyeEntityEyeball::BeginPlay()
{
	Super::BeginPlay();

	OnSpawned();
}

void AEyeEntityEyeball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindOverlap();
	MakeMovement(DeltaTime);
	HandleDanger(DeltaTime);
}