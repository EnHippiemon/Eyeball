#include "EyeEntityBalloon.h"

#include "Components/SphereComponent.h"

AEyeEntityBalloon::AEyeEntityBalloon()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Balloon_DataAsset"));
	if (EntityDataAsset.Object)
		Data = EntityDataAsset.Object;
	
	Sphere = CreateDefaultSubobject<USphereComponent>("RootSphere");
	RootComponent = Sphere;
	Sphere->SetEnableGravity(true);
	Sphere->SetSimulatePhysics(true);
	
	// MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	// MeshComponent->SetupAttachment(RootComponent);
	
	bIsUnPossessed = true;
}

void AEyeEntityBalloon::MakeMovement(const float DeltaTime)
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

void AEyeEntityBalloon::MakeJump()
{
	Super::MakeJump();
	
	if (!GetCanJump())
		return;

	AddJumpCount(1);
	Sphere->AddImpulse(Data->JumpDirection * Data->JumpForce);
}

void AEyeEntityBalloon::OnSpawned()
{
	Super::OnSpawned();
}

void AEyeEntityBalloon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEyeEntityBalloon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsUnPossessed)
		return;

	MakeMovement(DeltaTime);
}