#include "EyeEntityHuman.h"
#include "Components/CapsuleComponent.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"

AEyeEntityHuman::AEyeEntityHuman()
{
	static ConstructorHelpers::FObjectFinder<UEyeCharacterDataAsset> EntityDataAsset(TEXT("/Game/Characters/Player/DataAssets/Human_DataAsset"));
	if (EntityDataAsset.Object)
		EntityData = EntityDataAsset.Object;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Capsule;

	Capsule->SetEnableGravity(true);
	Capsule->SetSimulatePhysics(true);
}

void AEyeEntityHuman::MakeMovement(const float DeltaTime)
{
	Super::MakeMovement(DeltaTime);

	auto OutputMovement = FVector(0, GetMovementInput().X, 0) * DeltaTime;
	OutputMovement.Normalize();
	
	auto NewLocation = GetActorLocation() + OutputMovement * EntityData->NormalMovementSpeed;
	RootComponent->SetRelativeLocation(NewLocation);
}

void AEyeEntityHuman::MakeJump()
{
	Super::MakeJump();

	if (!GetIsOnFloor() || GetJumpCount() > EntityData->MaxJumpCount)
		return;

	Capsule->AddImpulse(EntityData->JumpDirection * EntityData->JumpForce);
}

void AEyeEntityHuman::OnSpawned()
{
	Super::OnSpawned();
}

void AEyeEntityHuman::BeginPlay()
{
	Super::BeginPlay();
	
	OnSpawned();	
}

void AEyeEntityHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MakeMovement(DeltaTime);
}