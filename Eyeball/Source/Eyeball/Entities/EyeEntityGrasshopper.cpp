#include "Eyeball/Entities/EyeEntityGrasshopper.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AEyeEntityGrasshopper::AEyeEntityGrasshopper()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Grasshopper_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	RootComponent = Box;

	Box->SetEnableGravity(true);
	Box->SetSimulatePhysics(true);
}

void AEyeEntityGrasshopper::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);
	
	auto OutputMovement = FVector(0, GetMovementInput().X, 0) ;
	OutputMovement.Normalize();
	
	auto NewLocation = GetActorLocation() + OutputMovement * CurrentMovementSpeed * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityGrasshopper::DecideMovementSpeed()
{
	float MovementSpeed;
	if (!GetIsOnFloor())
		MovementSpeed = EntityData->HighMovementSpeed;
	else if (GetJumpDepressed())
		MovementSpeed = 0.f;
	else
		MovementSpeed = EntityData->NormalMovementSpeed;

	CurrentMovementSpeed = MovementSpeed;
}

void AEyeEntityGrasshopper::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	if (!GetIsOnFloor() || GetJumpCount() > EntityData->MaxJumpCount)
		return;

	auto Impulse = CheckIsJumpHeld(EntityData->HeldJumpThreshold) ? EntityData->JumpForce : EntityData->JumpForce * 0.25f;
	Box->AddImpulse(EntityData->JumpDirection * Impulse);
}

void AEyeEntityGrasshopper::OnSpawned()
{
	Super::OnSpawned();
}

void AEyeEntityGrasshopper::BeginPlay()
{
	Super::BeginPlay();

	OnSpawned();
}

void AEyeEntityGrasshopper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;
	
	MakeMovement(DeltaTime);
	DecideMovementSpeed();
}