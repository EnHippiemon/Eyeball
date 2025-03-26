#include "EyeCharacter.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Eyeball/StaticFunctionLibrary.h"

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

void AEyeCharacter::SetMovementDirection(const float DeltaTime)
{
	FVector VectorTranslation = FVector(0, GetMovementInput().X, GetMovementInput().Y);
	MovementDirection = FMath::Lerp(MovementDirection, VectorTranslation, DeltaTime * EntityData->MovementAcceleration);
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

void AEyeCharacter::CalculateTraceDistances()
{
	FloorTraceDistance = EntityData->RadiusFloorCheck / EntityData->FloorTraceAmount;
	SlideTraceDistance = EntityData->SlidingTraceHeight / EntityData->SlidingTraceAmount;
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
	MovementDirection = FVector(0, 0, 0);
	OnCharacterChanged.Broadcast(EntityToPossess);
}

void AEyeCharacter::ChangeState(EGameState NewState)
{
	bInputIsAllowed = NewState == Egs_Playing;
}

void AEyeCharacter::OnSpawned()
{
	bIsUnPossessed = false;
	//
	// if (bInputIsAllowed)
		// MovementDirection = FVector(0, 0, 0);
	
	CalculateTraceDistances();
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
}

void AEyeCharacter::ResetJumpCount()
{
	const bool FoundFloor = UStaticFunctionLibrary::TracesAlongLine(this, EntityData->FloorLineDirection,
	                                                                EntityData->FloorTraceDirection,
	                                                                EntityData->OffsetFloorCheck,
	                                                                EntityData->FloorTraceAmount, FloorTraceDistance,
	                                                                EntityData->LengthFloorCheck, EntityData->Floor,
	                                                                true);
	
	if (FoundFloor && GetVelocity().Z < EntityData->ThresholdFallDamageVelocity)
		TakeFallDamage();
	
	JumpCount = FoundFloor ? 0 : JumpCount;
	bIsOnFloor = FoundFloor;
}

void AEyeCharacter::TakeFallDamage()
{
	// UE_LOG(LogTemp, Display, TEXT("TakeFallDamage | Velocity: %s"), *GetVelocity().ToString());
	DamagePlayer();
}

void AEyeCharacter::SlideDownWall()
{
	if (!GetMovementInput().X)
		return;
	
	const bool FoundWall = UStaticFunctionLibrary::TracesAlongLine(this, EntityData->SlidingLineDirection,
	                                                               EntityData->SlidingTraceDirection,
	                                                               EntityData->SlidingTraceOffset,
	                                                               EntityData->SlidingTraceAmount, SlideTraceDistance,
	                                                               EntityData->SlidingTraceLength, EntityData->Floor,
	                                                               true);
	
	if (FoundWall)
		RootComponent->SetRelativeLocation(
			GetActorLocation() - FVector(0, 0, EntityData->SlidingSpeed) * GetWorld()->DeltaTimeSeconds);
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

	OnSpawned();
}

void AEyeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;
	
	JumpHeldTimer(DeltaTime);
	Force2DMovement();
	ResetJumpCount();
	SlideDownWall();
	SetMovementDirection(DeltaTime);
}