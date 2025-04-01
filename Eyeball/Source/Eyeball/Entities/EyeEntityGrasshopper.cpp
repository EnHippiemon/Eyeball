#include "Eyeball/Entities/EyeEntityGrasshopper.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AEyeEntityGrasshopper::AEyeEntityGrasshopper()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Grasshopper_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	RootComponent = Box;

	Box->SetEnableGravity(true);
	Box->SetSimulatePhysics(true);
}

void AEyeEntityGrasshopper::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);
	
	auto OutputMovement = FVector(0, GetMovementInput().X, 0) ;
	OutputMovement.Normalize();
	
	auto NewLocation = GetActorLocation() + OutputMovement * CurrentMovementSpeed * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityGrasshopper::DecideMovementSpeed()
{
	float MovementSpeed;
	if (!GetIsOnFloor())
		MovementSpeed = EntityData->HighMovementSpeed;
	else if (GetJumpDepressed())
		MovementSpeed = 0.f;
	else
		MovementSpeed = EntityData->NormalMovementSpeed;

	CurrentMovementSpeed = MovementSpeed;
}

void AEyeEntityGrasshopper::DecideJumpHeight(float const DeltaTime)
{
	if (!GetJumpDepressed() || !GetIsOnFloor() || !GetCanJump())
		return;

	JumpHeight += DeltaTime * JumpTimeDirection;
	if (JumpHeight <= 0 || JumpHeight >= TimerInterval)
		JumpTimeDirection *= -1;
	JumpHeight = FMath::Clamp(JumpHeight, 0.f, TimerInterval);

	UE_LOG(LogTemp, Log, TEXT("Jump height: %f"), JumpHeight);
}

void AEyeEntityGrasshopper::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	if (!GetIsOnFloor() || !GetCanJump())
		return;
	
	const auto Impulse = JumpHeight * EntityData->JumpForce;
	Box->AddImpulse(EntityData->JumpDirection * Impulse);

	AddJumpCount(1);
	JumpHeight = 0.f;
}

void AEyeEntityGrasshopper::OnSpawned()
{
	Super::OnSpawned();
}

void AEyeEntityGrasshopper::BeginPlay()
{
	Super::BeginPlay();

	OnSpawned();
}

void AEyeEntityGrasshopper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsUnPossessed)
		return;
	
	MakeMovement(DeltaTime);
	DecideMovementSpeed();
	DecideJumpHeight(DeltaTime);
}