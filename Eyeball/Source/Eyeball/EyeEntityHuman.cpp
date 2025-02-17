#include "EyeEntityHuman.h"

#include "GameFramework/CharacterMovementComponent.h"

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	FVector OutputMovement = FVector(0, GetMovementInput().X, 0) * MovementSpeed * DeltaTime;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeEntityHuman::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}

void AEyeEntityHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MakeMovement(DeltaTime);
}
