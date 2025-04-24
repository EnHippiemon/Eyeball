#include "EyeCharacter.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
#include "Eyeball/GameState/EyeGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Eyeball/StaticFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

AEyeCharacter::AEyeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsUnPossessed = true;
}

void AEyeCharacter::HandleUpwardsInput(const float Value)
{
	bInputIsAllowed ? MovementInput.Y = Value : MovementInput.Y = 0;
}

void AEyeCharacter::HandleSidewaysInput(const float Value)
{
	bInputIsAllowed ? MovementInput.X = Value : MovementInput.X = 0;
	
	if (bFoundLeftWall && MovementInput.X < 0)
		MovementInput.X = 0;
	if (bFoundRightWall && MovementInput.X > 0)
		MovementInput.X = 0;
}

void AEyeCharacter::SmoothenMovementDirection(const float DeltaTime)
{
	const FVector VectorTranslation = FVector(0, GetMovementInput().X, GetMovementInput().Y);
	MovementDirection = FMath::Lerp(MovementDirection, VectorTranslation, DeltaTime * Data->MovementAcceleration);
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

void AEyeCharacter::SlideDownWall()
{
	if (!Data->bShouldSlideDownWall || !bFoundLeftWall && !bFoundRightWall || GetVelocity().Z >= 0.f)
		return;
	
	RootComponent->SetRelativeLocation(
		GetActorLocation() - FVector(0, 0, Data->SlidingSpeed) * GetWorld()->DeltaTimeSeconds);
}

void AEyeCharacter::CalculateTraceDistances()
{
	FloorTraceDistance = Data->RadiusFloorCheck / Data->FloorTraceAmount;
	WallTraceDistance = Data->SlidingTraceHeight / Data->SlidingTraceAmount;
}

void AEyeCharacter::HandlePauseInput()
{
	OnPaused.Broadcast();
}

void AEyeCharacter::UnPossessed()
{
	Super::UnPossessed();

	bIsUnPossessed = true;
	SetActorLocation(FVector(Data->OffsetUnpossessedActorPlacement.X, GetActorLocation().Y, GetActorLocation().Z));
}

void AEyeCharacter::HandleEntityChanged(AEyeCharacter* NewEntity)
{
	PossessedCharacter = NewEntity;
	if (NewEntity == this)
		return;

	PossessedCharacter->OnInteractableFound.AddUniqueDynamic(this, &AEyeCharacter::HandleCanBePossessed);
}

bool AEyeCharacter::CheckIsJumpHeld(const float Threshold)
{
	return GetJumpHeldTime() > Threshold;
}

void AEyeCharacter::SearchForSwitchableEntity()
{
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	const FVector TraceStart = GetActorLocation() + Data->SwitchEntityTraceOffset;
	const FVector TraceEnd = TraceStart + FVector(Data->SwitchEntityTraceLength, 0, 0);
	
	auto Trace = GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, Data->EntityBody, Params, FCollisionResponseParams());
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Blue, false);
	// if (Trace)
	// 	FoundEntity = Cast<AEyeCharacter>(HitResult.GetActor());
	//
	const auto SwitchableEntity = Hit.GetActor();

	OnInteractableFound.Broadcast(SwitchableEntity);
}

void AEyeCharacter::PossessNewEntity(AEyeCharacter* EntityToPossess)
{
	OnCharacterChanged.Broadcast(EntityToPossess);
	MovementDirection = FVector(0, 0, 0);
}

void AEyeCharacter::ChangeState(EGameState NewState)
{
	bInputIsAllowed = NewState == Egs_Playing;
}

void AEyeCharacter::HandleCanBePossessed(AActor* FoundActor)
{
	if (!MeshComponent)
		return;
	
	MeshComponent->SetOverlayMaterial(FoundActor == this ? PossessableMaterial : EmptyMaterial);
}

void AEyeCharacter::OnSpawned()
{
	if (GameMode)
		GameMode->OnChangedState.AddUniqueDynamic(this, &AEyeCharacter::ChangeState);
	if (MeshComponent)
		MeshComponent->SetOverlayMaterial(EmptyMaterial);
	
	bIsUnPossessed = false;
	CalculateTraceDistances();
}

void AEyeCharacter::TakeDamage()
{
	OnDeath.Broadcast();
	SetArtificialInput(FVector(0, 0, 0));
	SetMoveDirection(FVector(0, 0, 0));
}

void AEyeCharacter::Force2DMovement()
{
	SetActorLocation(FVector(Data->OffsetActorPlacement.X, GetActorLocation().Y, GetActorLocation().Z));
}

void AEyeCharacter::SetArtificialInput(const FVector& Direction)
{
	ArtificialInput = Direction * Data->InputMultiplier;
}

void AEyeCharacter::ResetPosition()
{
	SetActorLocation(StartPosition);
}

void AEyeCharacter::DecayMovementSpeed(float const DeltaTime)
{
	if (ArtificialInput.Size() <= 0)
		return;

	// Decrease input over time
	ArtificialInput = UKismetMathLibrary::VLerp(ArtificialInput, FVector(0, 0, 0), Data->DecaySpeed * DeltaTime);

	// Movement speed and set location
	const auto NewLocation = GetActorLocation() + ArtificialInput * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeCharacter::MakeJump()
{
}

void AEyeCharacter::ResetJumpCount()
{
	const bool FoundFloor = UStaticFunctionLibrary::TracesAlongLine(this, Data->FloorLineDirection,
	                                                                Data->FloorTraceDirection,
	                                                                Data->OffsetFloorCheck,
	                                                                Data->FloorTraceAmount, FloorTraceDistance,
	                                                                Data->LengthFloorCheck, Data->Floor,
	                                                                false);
	
	if (FoundFloor && GetVelocity().Z < Data->ThresholdFallDamageVelocity)
		TakeFallDamage();
	
	JumpCount = FoundFloor ? 0 : JumpCount;
	bIsOnFloor = FoundFloor;
}

void AEyeCharacter::TakeFallDamage()
{
	TakeDamage();
}

void AEyeCharacter::DetectWall()
{
	const bool RightFoundWall = UStaticFunctionLibrary::TracesAlongLine(this, Data->SlidingLineDirection,
	                                                                    Data->SlidingTraceDirection,
	                                                                    Data->SlidingTraceOffset,
	                                                                    Data->SlidingTraceAmount,
	                                                                    WallTraceDistance,
	                                                                    Data->SlidingTraceLength,
	                                                                    Data->Floor,
	                                                                    false);
	const bool LeftFoundWall = UStaticFunctionLibrary::TracesAlongLine(this, Data->SlidingLineDirection,
	                                                                   -Data->SlidingTraceDirection,
	                                                                   FVector(Data->SlidingTraceOffset.X,
	                                                                           -Data->SlidingTraceOffset.Y,
	                                                                           Data->SlidingTraceOffset.Z),
	                                                                   Data->SlidingTraceAmount,
	                                                                   WallTraceDistance,
	                                                                   Data->SlidingTraceLength,
	                                                                   Data->Floor,
	                                                                   false);

	bFoundLeftWall = LeftFoundWall;
	bFoundRightWall = RightFoundWall;
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

	FInputActionBinding& TogglePause = PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &AEyeCharacter::HandlePauseInput);
	TogglePause.bExecuteWhenPaused = true;
}

void AEyeCharacter::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
		GameMode->OnEntityChanged.AddUniqueDynamic(this, &AEyeCharacter::HandleEntityChanged);

	HandleEntityChanged(Cast<AEyeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)));
	
	if (bIsUnPossessed)
		UnPossessed();
	else
		OnSpawned();

	StartPosition = GetActorLocation();
}

void AEyeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed || GameMode->GetGameState() == Egs_GameWon)
		return;
	
	JumpHeldTimer(DeltaTime);
	Force2DMovement();
	ResetJumpCount();
	DetectWall();
	SlideDownWall();
	SmoothenMovementDirection(DeltaTime);
	DecayMovementSpeed(DeltaTime);
	SearchForSwitchableEntity();
}