#include "../MoveableObjects/EyeMoveableObject.h"

#include "Components/BoxComponent.h"
#include "Eyeball/DataAssets/EyeMoveableObjectDataAsset.h"
#include "Eyeball/Entities/EyeCharacter.h"

AEyeMoveableObject::AEyeMoveableObject()
{
	Box = CreateDefaultSubobject<UBoxComponent>("RootComponent");
	RootComponent = Box;
	
	OverlapCollision = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");
	OverlapCollision->SetupAttachment(Box);
	OverlapCollision->OnComponentBeginOverlap.AddDynamic(this, &AEyeMoveableObject::HandleBeginOverlap);
	OverlapCollision->OnComponentEndOverlap.AddDynamic(this, &AEyeMoveableObject::HandleEndOverlap);

	PrimaryActorTick.bCanEverTick = true;
}

void AEyeMoveableObject::Activate()
{
	bIsActivated = true;
	bHasReachedTarget = false;
}

void AEyeMoveableObject::ResetLocation()
{
	if (!ObjectData->bStartActivated)
		bIsActivated = false;
	bHasReachedTarget = true;
	SetActorLocation(StartLocation);
}

void AEyeMoveableObject::MoveToTarget()
{
	if (!bIsActivated)
		return;

	if ((GetActorLocation() - TargetLocation).Length() < 5.f)
	{
		bIsActivated = false;
		bHasReachedTarget = true;
	}

	const auto NewLocation = GetActorLocation() + ObjectData->MoveDirection * ObjectData->MoveSpeed * GetWorld()->DeltaTimeSeconds;
	SetActorRelativeLocation(NewLocation);
}

void AEyeMoveableObject::MoveToStart()
{
	if (!ObjectData->ReturnToStartLocation || !bHasReachedTarget || bIsHindered)
		return;

	if ((GetActorLocation() - StartLocation).Length() < 5.f)
	{
		bHasReachedTarget = false;

		if (ObjectData->bShouldLoop)
			bIsActivated = true;
	}
	
	const auto NewLocation = GetActorLocation() - ObjectData->MoveDirection * ObjectData->MoveSpeed * GetWorld()->DeltaTimeSeconds;
	SetActorRelativeLocation(NewLocation);
}

void AEyeMoveableObject::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		bIsHindered = true;
	}
}

void AEyeMoveableObject::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA<AEyeCharacter>())
	{
		bIsHindered = false;
	}
}

void AEyeMoveableObject::BeginPlay()
{
	Super::BeginPlay();

	if (!ObjectData)
	{
		UE_LOG(LogTemp, Error, TEXT("No Object data in: %s"), *GetActorNameOrLabel())
		return;
	}
	
	StartLocation = GetActorLocation();
	TargetLocation = GetActorLocation() + ObjectData->TargetOffset;
	bIsActivated = ObjectData->bStartActivated;
}

void AEyeMoveableObject::Tick(float DeltaTime)
{
	if (!ObjectData->bShouldTick)
		return;
	
	Super::Tick(DeltaTime);

	if (!ObjectData)
		return;
	
	MoveToTarget();
	MoveToStart();
}