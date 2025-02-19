#include "EyeEntityHuman.h"

#include "GameFramework/CharacterMovementComponent.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	GetCharacterMovement()->GravityScale = 1.f;
}

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y) * NormalMovementSpeed * DeltaTime;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeEntityHuman::MakeJump()
{
	Super::MakeJump();

	if (JumpCount > MaxJumpCount)
		return;
	
	GetCharacterMovement()->AddImpulse(JumpDirection * JumpForce);
}

void AEyeEntityHuman::OnSpawned()
{
	Super::OnSpawned();
	
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->MaxWalkSpeed = NormalMovementSpeed;
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