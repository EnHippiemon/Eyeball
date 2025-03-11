#include "EyeEntityHuman.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Human_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	GetCharacterMovement()->GravityScale = 1.f;
}

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y) * EntityData->NormalMovementSpeed * DeltaTime;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeEntityHuman::MakeJump()
{
	Super::MakeJump();

	if (!GetIsOnFloor() || GetJumpCount() > EntityData->MaxJumpCount)
		return;
	
	GetCharacterMovement()->AddImpulse(EntityData->JumpDirection * EntityData->JumpForce);
}

void AEyeEntityHuman::OnSpawned()
{
	Super::OnSpawned();
	
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->MaxWalkSpeed = EntityData->NormalMovementSpeed;
}

void AEyeEntityHuman::BeginPlay()
{
	Super::BeginPlay();
	
	OnSpawned();	
}

void AEyeEntityHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MakeMovement(DeltaTime);
}