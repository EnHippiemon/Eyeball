#include "Eyeball/Entities/EyeEntityGrasshopper.h"

#include "Blueprint/UserWidget.h"
#include "Components/BoxComponent.h"
#include "Eyeball/Widgets/EyeGrasshopperJumpWidget.h"

AEyeEntityGrasshopper::AEyeEntityGrasshopper()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(
		TEXT("/Game/Characters/Player/DataAssets/Grasshopper_DataAsset"));
	if (EntityDataAsset.Object)
		Data = EntityDataAsset.Object;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	RootComponent = Box;
	Box->SetEnableGravity(true);
	Box->SetSimulatePhysics(true);
	
	MeshComponent->SetupAttachment(Box);
	RotatingSoulMesh->SetupAttachment(Box);

	bIsUnPossessed = true;
}

void AEyeEntityGrasshopper::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	auto OutputMovement = FVector(0, GetMovementInput().X, 0);
	OutputMovement.Normalize();

	auto NewLocation = GetActorLocation() + OutputMovement * CurrentMovementSpeed * DeltaTime;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityGrasshopper::DecideMovementSpeed()
{
	float MovementSpeed;
	if (!GetIsOnFloor())
		MovementSpeed = Data->HighMovementSpeed;
	else if (GetJumpDepressed())
		MovementSpeed = 0.f;
	else
		MovementSpeed = Data->NormalMovementSpeed;

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
	
	if (JumpWidgetRef)
		JumpWidgetRef->RenderJumpBar(JumpHeight);
}

void AEyeEntityGrasshopper::MakeReleaseJump()
{
	Super::MakeReleaseJump();

	if (JumpWidgetRef)
		JumpWidgetRef->RenderJumpBar(0);
	
	if (!GetIsOnFloor() || !GetCanJump())
		return;

	const auto Impulse = JumpHeight * Data->JumpForce;
	Box->AddImpulse(Data->JumpDirection * Impulse);
	AddJumpCount(1);
	JumpHeight = 0.f;
}

void AEyeEntityGrasshopper::TakeDamage()
{
	Super::TakeDamage();

	JumpHeight = 0.f;
	if (JumpWidgetRef)
		JumpWidgetRef->RenderJumpBar(0);
}

void AEyeEntityGrasshopper::HandleEjectInput()
{
	Super::HandleEjectInput();

	if (JumpWidgetRef)
	{
		JumpWidgetRef->RemoveFromParent();
		JumpWidgetRef = nullptr;
	}
	
	JumpHeight = 0.f;
	SetJumpDepressed(false);
}

void AEyeEntityGrasshopper::OnSpawned()
{
	Super::OnSpawned();

	if (bIsUnPossessed)
		return;

	if (!JumpWidgetRef)
	{
		JumpWidgetRef = CreateWidget<UEyeGrasshopperJumpWidget>(GetWorld(), JumpWidget);
		if (JumpWidgetRef)
		{
			JumpWidgetRef->AddToViewport();
			JumpWidgetRef->RenderJumpBar(0);
		}
	}
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