#include "EyeCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AEyeCharacter::AEyeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	// PlayerRadius = GetCapsuleComponent()->GetScaledCapsuleRadius();
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

void AEyeCharacter::UnPossessed()
{
	Super::UnPossessed();

	
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

void AEyeCharacter::Force2DMovement()
{
	SetActorLocation(FVector(0, GetActorLocation().Y, GetActorLocation().Z));
}

void AEyeCharacter::MakeJump()
{
	if (JumpCount > MaxJumpCount)
		return;
	
	++JumpCount;
}

void AEyeCharacter::ResetJumpCount()
{
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	TArray<bool> FloorTraces;

	const FVector TraceOffset = GetActorLocation() + OffsetFloorCheck/*- FVector(0, 0, PlayerRadius)*/;
	
	constexpr int TraceAmount = 10;
	for (int i = 0; i < TraceAmount; ++i)
	{
		// Decide trace transform 
		FVector TraceStart = TraceOffset + RadiusFloorCheck * GetActorForwardVector().RotateAngleAxis(360.f / TraceAmount * i + 1, FVector(0, 0, 1));
		FVector TraceEnd = TraceStart + FVector(0, 0, LengthFloorCheck);
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Blue);

		// Look for floor 
		if (!FloorTraces.IsValidIndex(i))
			FloorTraces.Add(true);
		
		const auto FloorTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, Floor, Params, FCollisionResponseParams());
		FloorTraces[i] = FloorTrace;
	}

	JumpCount = FloorTraces.Contains(true) ? 0 : JumpCount;
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
	Force2DMovement();
	ResetJumpCount();
}