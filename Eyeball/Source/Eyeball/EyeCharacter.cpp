#include "EyeCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AEyeCharacter::AEyeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->GravityScale = 0;
}

void AEyeCharacter::HandleUpwardsInput(float Value)
{
	Movement.Y = Value ;
}

void AEyeCharacter::HandleSidewaysInput(float Value)
{
	Movement.X = Value;
}

void AEyeCharacter::HandleJumpInput()
{
	UE_LOG(LogTemp, Log, TEXT("HandleJumpInput"));
}

void AEyeCharacter::HandleActionInput()
{
	UE_LOG(LogTemp, Log, TEXT("HandleActionInput"));
}


void AEyeCharacter::MakeMovement()
{
	FVector OutputMovement = FVector(0, Movement.X, Movement.Y) * MovementSpeed * GetWorld()->DeltaTimeSeconds;
	OutputMovement.Normalize();

	AddMovementInput(OutputMovement);
}

void AEyeCharacter::FindOverlap()
{
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	TArray<bool> LineTraceResults;

	const FVector TraceOffset = GetActorLocation() - FVector(PlayerRadius, 0, 0);
	
	constexpr int TraceAmount = 10;
	for (int i = 0; i < TraceAmount; ++i)
	{
		if (!LineTraceResults.IsValidIndex(i))
			LineTraceResults.Add(true);
		
		FVector TraceStart = TraceOffset + PlayerRadius * GetActorUpVector().RotateAngleAxis(360.f / TraceAmount * i + 1, FVector(1, 0, 0));
		FVector TraceEnd = TraceStart + FVector(500, 0, 0);;
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red);

		const auto LineTrace = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, SafeZone, Params, FCollisionResponseParams());
		LineTraceResults[i] = LineTrace;
		
		if (!LineTrace)
			UE_LOG(LogTemp, Log, TEXT("Inside danger zone %i"), i);
	}

	if (LineTraceResults.Contains(false))
		return;

	UE_LOG(LogTemp, Log, TEXT("Not in danger"));
}

void AEyeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Upwards", this, &AEyeCharacter::HandleUpwardsInput);
	PlayerInputComponent->BindAxis("Sideways", this, &AEyeCharacter::HandleSidewaysInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AEyeCharacter::HandleJumpInput);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AEyeCharacter::HandleActionInput);
}

void AEyeCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	this->SetActorLocation(FVector(0, GetActorLocation().Y, GetActorLocation().Z));

	PlayerRadius = GetCapsuleComponent()->GetScaledCapsuleRadius();
}

void AEyeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MakeMovement();
	FindOverlap();
}