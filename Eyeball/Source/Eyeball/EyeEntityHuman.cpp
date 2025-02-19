#include "EyeEntityHuman.h"

#include "GameFramework/CharacterMovementComponent.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	GetCharacterMovement()->GravityScale = 0.f;
}

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, GetMovementInput().Y) * MovementSpeed * DeltaTime;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeEntityHuman::OnSpawned()
{
	Super::OnSpawned();
	
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
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