#include "EyeEntityEyeball.h"

#include "Components/SphereComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"

AEyeEntityEyeball::AEyeEntityEyeball()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Eyeball_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComponent;
	
	SphereComponent->SetEnableGravity(false);
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
	OnDangerChanged.Broadcast(bIsInDanger, EntityData->TimeDilationDanger, EntityData->MaxTimeInDanger);
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
}

void AEyeEntityEyeball::MakeJump()
{
	CurrentMovementSpeed = EntityData->JumpForce;
}

void AEyeEntityEyeball::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	CurrentMovementSpeed = EntityData->NormalMovementSpeed;
}

void AEyeEntityEyeball::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y);
	OutputMovement.Normalize();
	
	auto NewLocation = GetActorLocation() + OutputMovement * CurrentMovementSpeed * DeltaTime;
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
}