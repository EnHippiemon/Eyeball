#include "EyeEntityEyeball.h"

#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"

AEyeEntityEyeball::AEyeEntityEyeball()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(
		TEXT("/Game/Characters/Player/DataAssets/Eyeball_DataAsset"));
	if (EntityDataAsset.Object)
		Data = EntityDataAsset.Object;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComponent;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	SoulPart1 = CreateDefaultSubobject<UStaticMeshComponent>("SoulPart1");
	SoulPart1->SetupAttachment(MeshComponent);
	SoulPart2 = CreateDefaultSubobject<UStaticMeshComponent>("SoulPart2");
	SoulPart2->SetupAttachment(MeshComponent);

	SphereComponent->SetEnableGravity(false);

	bIsUnPossessed = false;
}

FVector AEyeEntityEyeball::Dash(const float DeltaTime)
{
	const auto NewLocation = GetActorLocation() + DashDirection * Data->JumpForce * DeltaTime;
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
	SoulPart1->SetMaterial(0, bIsInDanger ? EyeballMaterialDanger : EyeballMaterialNormal);
	SoulPart2->SetMaterial(0, bIsInDanger ? EyeballMaterialDanger : EyeballMaterialNormal);
	OnDangerFound.Broadcast(bIsInDanger);
	OnEntityFound.Broadcast(bCanChangeEntity ? FoundEntity : this);
}

void AEyeEntityEyeball::SetOverlayMaterial()
{
	if (MeshComponent)
		MeshComponent->SetOverlayMaterial(EmptyMaterial);
}

void AEyeEntityEyeball::RotateMesh(float const DeltaTime)
{
	MeshComponent->AddLocalRotation(DeltaTime * MeshRotationRate);
}

void AEyeEntityEyeball::HandleEjectInput()
{
	if (!bCanChangeEntity || !IsValid(FoundEntity))
		return;

	bIsDashing = false;
	PossessNewEntity(FoundEntity);
	ArtificialInput = FVector(0, 0, 0);	
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
	if (TimeSinceDashed >= Data->DashCooldown)
	{
		AddJumpCount(-1);
		TimeSinceDashed = 0.f;
	}

	if (!bIsDashing)
		return;

	bIsDashing = TimeSinceDashed < Data->DashDuration;
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

	CurrentMovementSpeed = Data->NormalMovementSpeed;
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
	RotateMesh(DeltaTime);
}