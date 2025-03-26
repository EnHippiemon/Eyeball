#include "EyeEntityEyeball.h"

#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Kismet/KismetMathLibrary.h"

void AEyeEntityEyeball::AddArtificialInput(FVector Direction)
{
	ArtificialInput = Direction * EntityData->InputMultiplier;
}

void AEyeEntityEyeball::MakeArtificialInput(float const DeltaTime)
{
	if (ArtificialInput.Size() <= 0)
		return;

	// Decrease input over time
	ArtificialInput = UKismetMathLibrary::VLerp(ArtificialInput, FVector(0, 0, 0), EntityData->DecaySpeed * DeltaTime);

	// Movement speed and set location
	const auto NewLocation = GetActorLocation() + ArtificialInput * EntityData->ArtificialMovementSpeed * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

AEyeEntityEyeball::AEyeEntityEyeball()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(
		TEXT("/Game/Characters/Player/DataAssets/Eyeball_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComponent;

	SphereComponent->SetEnableGravity(false);
}

FVector AEyeEntityEyeball::Dash(const float DeltaTime)
{
	const auto NewLocation = GetActorLocation() + DashDirection * EntityData->JumpForce * DeltaTime;
	return NewLocation;
}

FVector AEyeEntityEyeball::Move(const float DeltaTime)
{
	// Movement direction
	FVector OutputMovement = GetMovementDirection();
	OutputMovement.Normalize();

	// Accelerate movement
	OutputMovement *= FVector(0, FMath::Abs(GetMovementDirection().Y), FMath::Abs(GetMovementDirection().Z));

	// Movement speed and set location
	const auto NewLocation = GetActorLocation() + OutputMovement * CurrentMovementSpeed * DeltaTime;
	return NewLocation;
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
	OnDangerFound.Broadcast(bIsInDanger);
}

void AEyeEntityEyeball::HandleActionInput()
{
	Super::HandleActionInput();

	if (!bCanChangeEntity || !IsValid(FoundEntity))
		return;

	bIsDashing = false;
	ArtificialInput = FVector(0, 0, 0);
	PossessNewEntity(FoundEntity);
}

void AEyeEntityEyeball::MakeJump()
{
	Super::MakeJump();

	if (!GetCanJump() || GetMovementInput().Length() == 0)
		return;
	
	DashDirection = FVector(0, GetMovementInput().X, GetMovementInput().Y);
	DashDirection.Normalize();

	SetMoveDirection(DashDirection);
	
	AddJumpCount(1);
	bIsDashing = true;
}

void AEyeEntityEyeball::MakeReleaseJump()
{
	Super::MakeReleaseJump();
}

void AEyeEntityEyeball::ResetJumpCount()
{
	if (GetCanJump())
		return;

	TimeSinceDashed += GetWorld()->DeltaTimeSeconds;
	if (TimeSinceDashed >= EntityData->DashCooldown)
	{
		AddJumpCount(-1);
		TimeSinceDashed = 0.f;
	}

	if (!bIsDashing)
		return;

	bIsDashing = TimeSinceDashed < EntityData->DashDuration;
}

void AEyeEntityEyeball::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	auto const NewLocation = bIsDashing ? Dash(DeltaTime) : Move(DeltaTime);
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityEyeball::OnSpawned()
{
	Super::OnSpawned();

	CurrentMovementSpeed = EntityData->NormalMovementSpeed;
	PlayerRadius = SphereComponent->GetScaledSphereRadius();
}

void AEyeEntityEyeball::BeginPlay()
{
	Super::BeginPlay();

	OnSpawned();
}

void AEyeEntityEyeball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;

	FindOverlap();
	MakeMovement(DeltaTime);
	ResetJumpCount();
	MakeArtificialInput(DeltaTime);
}