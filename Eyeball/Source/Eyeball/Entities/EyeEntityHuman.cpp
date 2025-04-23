#include "EyeEntityHuman.h"
#include "Components/CapsuleComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "../PuzzleComponents/StaticObjects/EyeInteractableObject.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Human_DataAsset"));
	if (EntityDataAsset.Object)
		Data = EntityDataAsset.Object;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Capsule;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	Capsule->SetEnableGravity(true);
	Capsule->SetSimulatePhysics(true);
}

void AEyeEntityHuman::FindInteractableObject()
{
	// FHitResult HitResult;
	// FCollisionQueryParams Params;
	//
	// const auto TraceStart = GetActorLocation() + FVector(0, 20, 0);
	// const auto TraceEnd = TraceStart - FVector(0, 40, 0);
	//
	// const auto Trace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, InteractableCollision, Params);
	// if (!Trace)
	// {
	// 	InteractableObject = nullptr;
	// 	OnInteractableFound.Broadcast(InteractableObject);
	// 	return;
	// }
	//
	// const auto Lever = Cast<AEyeInteractableObject>(HitResult.GetActor());
	// InteractableObject = Lever;
	// OnInteractableFound.Broadcast(Lever);
}

void AEyeEntityHuman::HandleActionInput()
{
	Super::HandleActionInput();

	if (!InteractableObject)
		return;

	InteractableObject->InteractWith();
}

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	// Movement direction
	FVector OutputMovement = FVector(0, GetMovementDirection().Y, 0);
	OutputMovement.Normalize();
	
	// Accelerate movement
	OutputMovement *= FVector(0, FMath::Abs(GetMovementDirection().Y), 0);

	// Movement speed and set location
	auto NewLocation = GetActorLocation() + OutputMovement * Data->NormalMovementSpeed * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityHuman::MakeJump()
{
	Super::MakeJump();

	if (!GetIsOnFloor() || !GetCanJump())
		return;

	AddJumpCount(1);
	Capsule->AddImpulse(Data->JumpDirection * Data->JumpForce);
}

void AEyeEntityHuman::OnSpawned()
{
	Super::OnSpawned();
}

void AEyeEntityHuman::BeginPlay()
{
	Super::BeginPlay();
}

void AEyeEntityHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;
	
	MakeMovement(DeltaTime);
	FindInteractableObject();
}