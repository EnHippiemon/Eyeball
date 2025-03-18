#include "EyeCharacter.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"

AEyeCharacter::AEyeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeCharacter::HandleUpwardsInput(const float Value)
{
	bInputIsAllowed ? MovementInput.Y = Value : MovementInput.Y = 0;
}

void AEyeCharacter::HandleSidewaysInput(const float Value)
{
	bInputIsAllowed ? MovementInput.X = Value : MovementInput.X = 0;
}

void AEyeCharacter::HandleJumpInput()
{
	if (!bInputIsAllowed)
		return;
	
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

	bIsUnPossessed = true;
}

bool AEyeCharacter::CheckIsJumpHeld(const float Threshold)
{
	return GetJumpHeldTime() > Threshold;
}

void AEyeCharacter::PossessNewEntity(AEyeCharacter* EntityToPossess)
{
	OnCharacterChanged.Broadcast(EntityToPossess);
}

void AEyeCharacter::ChangeState(EGameState NewState)
{
	bInputIsAllowed = NewState == Egs_Playing;
}

void AEyeCharacter::OnSpawned()
{
	bIsUnPossessed = false;
}

void AEyeCharacter::DamagePlayer()
{
	OnDeath.Broadcast();
}

void AEyeCharacter::Force2DMovement()
{
	SetActorLocation(FVector(EntityData->OffsetActorPlacement.X, GetActorLocation().Y, GetActorLocation().Z));
}

void AEyeCharacter::MakeJump()
{
	if (JumpCount > EntityData->MaxJumpCount)
		return;
	
	++JumpCount;
}

void AEyeCharacter::ResetJumpCount()
{
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	TArray<bool> FloorTraces;

	const FVector TraceOffset = GetActorLocation() + EntityData->OffsetFloorCheck;
	
	constexpr int TraceAmount = 10;
	for (int i = 0; i < TraceAmount; ++i)
	{
		// Decide trace transform 
		FVector TraceStart = TraceOffset + EntityData->RadiusFloorCheck * GetActorForwardVector().RotateAngleAxis(360.f / TraceAmount * i + 1, FVector(0, 0, 1));
		FVector TraceEnd = TraceStart + FVector(0, 0, EntityData->LengthFloorCheck);
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Blue);

		// Look for floor 
		if (!FloorTraces.IsValidIndex(i))
			FloorTraces.Add(true);
		
		const auto FloorTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, EntityData->Floor, Params, FCollisionResponseParams());
		FloorTraces[i] = FloorTrace;
	}

	const auto TraceResult = FloorTraces.Contains(true);
	
	if (TraceResult && GetVelocity().Z < EntityData->ThresholdFallDamageVelocity)
		TakeFallDamage();
	
	JumpCount = TraceResult ? 0 : JumpCount;
	bIsOnFloor = TraceResult;
}

void AEyeCharacter::TakeFallDamage()
{
	// UE_LOG(LogTemp, Display, TEXT("TakeFallDamage | Velocity: %s"), *GetVelocity().ToString());
	DamagePlayer();
}

void AEyeCharacter::HandleActionInput()
{
}

void AEyeCharacter::HandleEjectInput()
{
	if (!bInputIsAllowed)
		return;
	
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

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
		GameMode->OnChangedState.AddUniqueDynamic(this, &AEyeCharacter::ChangeState);
	
	// GetCharacterMovement()->bRunPhysicsWithNoController = true;
}

void AEyeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;
	
	JumpHeldTimer(DeltaTime);
	Force2DMovement();
	ResetJumpCount();
}