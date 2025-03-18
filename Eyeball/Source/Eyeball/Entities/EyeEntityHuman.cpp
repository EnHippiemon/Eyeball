#include "EyeEntityHuman.h"
#include "Components/CapsuleComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Eyeball/PuzzleComponents/EyeLever.h"
#include "Kismet/GameplayStatics.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Human_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Capsule;

	Capsule->SetEnableGravity(true);
	Capsule->SetSimulatePhysics(true);
}

bool AEyeEntityHuman::FoundInteractableObject()
{
	FHitResult HitResult;
	FCollisionQueryParams Params;

	const auto TraceStart = GetActorLocation() + FVector(0, 20, 0);
	const auto TraceEnd = TraceStart - FVector(0, 40, 0);

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, true, 1, 0, 20);
	const auto Trace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, InteractableCollision, Params);
	if (!Trace)
		return false;

	const auto Lever = Cast<AEyeLever>(HitResult.GetActor());
	if (!Lever)
		return false;

	InteractableObject = Lever;
	return true;
}

void AEyeEntityHuman::HandleActionInput()
{
	Super::HandleActionInput();

	if (!FoundInteractableObject())
		return;

	InteractableObject->InteractWith();
}

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	auto OutputMovement = FVector(0, GetMovementInput().X, 0);
	OutputMovement.Normalize();
	
	auto NewLocation = GetActorLocation() + OutputMovement * EntityData->NormalMovementSpeed * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityHuman::MakeJump()
{
	Super::MakeJump();

	if (!GetIsOnFloor() || GetJumpCount() > EntityData->MaxJumpCount)
		return;

	Capsule->AddImpulse(EntityData->JumpDirection * EntityData->JumpForce);
}

void AEyeEntityHuman::OnSpawned()
{
	Super::OnSpawned();
}

void AEyeEntityHuman::BeginPlay()
{
	Super::BeginPlay();
	
	OnSpawned();
}

void AEyeEntityHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;
	
	MakeMovement(DeltaTime);
}