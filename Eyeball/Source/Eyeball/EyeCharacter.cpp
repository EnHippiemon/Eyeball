#include "EyeCharacter.h"

#include "EyeEntityEyeball.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AEyeCharacter::AEyeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->GravityScale = 0;
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
	
	// GetController()->UnPossess();

	
	// GetController()->Possess(EntityToPossess->GetInstigator());
	/*
	switch (EntityToPossess)
	{
	case EntityHuman:
		GetController()->Possess(EntityHuman);
		break;
	default:
		GetController()->Possess(EntityEyeball);
	}
	*/
}

void AEyeCharacter::HandleActionInput()
{
	// UE_LOG(LogTemp, Log, TEXT("HandleActionInput"));
}

void AEyeCharacter::HandleEjectInput()
{
	UE_LOG(LogTemp, Log, TEXT("HandleEjectInput"));
	// if (GetEntityState() == Ees_Eyeball)
	// 	return;

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;

	auto SpawnedEntity = GetWorld()->SpawnActor<AEyeEntityEyeball>(GetActorLocation(), GetActorRotation());
	// auto SpawnedEye = GetWorld()->SpawnActor
	// GetController()->UnPossess();
	GetController()->Possess(SpawnedEntity);
	// GetController()->Possess
	// CurrentEntityState = Ees_Eyeball;
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

	CurrentEntityState = Ees_Eyeball;
}

void AEyeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	JumpHeldTimer(DeltaTime);
}