#include "Eyeball/Entities/EyeEntityGrasshopper.h"
#include "GameFramework/CharacterMovementComponent.h"

AEyeEntityGrasshopper::AEyeEntityGrasshopper()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Grasshopper_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	GetCharacterMovement()->GravityScale = 1.f;
}

void AEyeEntityGrasshopper::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y) * EntityData->NormalMovementSpeed * DeltaTime;
	OutputMovement.Normalize();
	
	AddMovementInput(OutputMovement);
}

void AEyeEntityGrasshopper::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	if (!GetIsOnFloor() || GetJumpCount() > EntityData->MaxJumpCount)
		return;

	auto Impulse = CheckIsJumpHeld(EntityData->HeldJumpThreshold) ? EntityData->JumpForce : EntityData->JumpForce * 0.25f;
 	GetCharacterMovement()->AddImpulse(EntityData->JumpDirection * Impulse);
}

void AEyeEntityGrasshopper::OnSpawned()
{
	Super::OnSpawned();

	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->MaxWalkSpeed = EntityData->NormalMovementSpeed;
}

void AEyeEntityGrasshopper::BeginPlay()
{
	Super::BeginPlay();

	OnSpawned();
}

void AEyeEntityGrasshopper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MakeMovement(DeltaTime);
}
