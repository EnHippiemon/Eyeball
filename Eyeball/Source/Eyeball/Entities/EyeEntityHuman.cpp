#include "EyeEntityHuman.h"
#include "Components/CapsuleComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Human_DataAsset"));
	if (EntityDataAsset.Object)
		Data = EntityDataAsset.Object;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Capsule;
	Capsule->SetEnableGravity(true);
	Capsule->SetSimulatePhysics(true);

	MeshComponent->SetupAttachment(Capsule);
	RotatingSoulMesh->SetupAttachment(Capsule);

	bIsUnPossessed = true;
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