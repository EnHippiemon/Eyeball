#include "EyeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AEyeCharacter::AEyeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeCharacter::HandleUpwardsInput(const float Value)
{
	MovementInput.Y = Value;
}

void AEyeCharacter::HandleSidewaysInput(const float Value)
{
	MovementInput.X = Value;
}

void AEyeCharacter::HandleJumpInput()
{
	bJumpDepressed = true;
	MakeJump();
}

void AEyeCharacter::HandleJumpReleased()
{
	bJumpDepressed = false;
	MakeReleaseJump();

	FLatentActionInfo LatentActionInfo;
	UKismetSystemLibrary::DelayUntilNextTick(GetWorld(), LatentActionInfo);

	JumpHeldTime = 0.f;
}

void AEyeCharacter::JumpHeldTimer(float DeltaTime)
{
	if (!bJumpDepressed)
		return;

	JumpHeldTime += DeltaTime;
}

bool AEyeCharacter::CheckIsJumpHeld(const float Threshold)
{
	return GetJumpHeldTime() > Threshold;
}

void AEyeCharacter::PossessNewEntity(AEyeCharacter* EntityToPossess)
{
	UE_LOG(LogTemp, Log, TEXT("Possessing %s"), *EntityToPossess->GetName())

	OnCharacterChanged.Broadcast(EntityToPossess);
}

void AEyeCharacter::OnSpawned()
{
	UE_LOG(LogTemp, Log, TEXT("OnSpawned"));
}

void AEyeCharacter::HandleActionInput()
{
	// UE_LOG(LogTemp, Log, TEXT("HandleActionInput"));
}

void AEyeCharacter::HandleEjectInput()
{
	UE_LOG(LogTemp, Log, TEXT("HandleEjectInput"));

	OnEject.Broadcast();
}

void AEyeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Upwards", this, &AEyeCharacter::HandleUpwardsInput);
	PlayerInputComponent->BindAxis("Sideways", this, &AEyeCharacter::HandleSidewaysInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AEyeCharacter::HandleJumpInput);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AEyeCharacter::HandleJumpReleased);
	
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AEyeCharacter::HandleActionInput);
	PlayerInputComponent->BindAction("Eject", IE_Pressed, this, &AEyeCharacter::HandleEjectInput);
}

void AEyeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEyeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	JumpHeldTimer(DeltaTime);
}