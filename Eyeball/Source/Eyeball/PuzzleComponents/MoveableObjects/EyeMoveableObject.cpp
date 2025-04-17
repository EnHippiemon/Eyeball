#include "../MoveableObjects/EyeMoveableObject.h"

#include "Components/BoxComponent.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"

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

void AEyeMoveableObject::MoveToTarget()
{
	if (!bIsActivated)
		return;

	if ((GetActorLocation() - TargetLocation).Length() < 5.f)
	{
		bIsActivated = false;
		bHasReachedTarget = true;
		if (!ReturnToStartLocation)
			PrimaryActorTick.bCanEverTick = false;
	}

	const auto NewLocation = GetActorLocation() + MoveDirection * MoveSpeed * GetWorld()->DeltaTimeSeconds;
	SetActorRelativeLocation(NewLocation);
}

void AEyeMoveableObject::MoveToStart()
{
	if (!ReturnToStartLocation || !bHasReachedTarget || bIsHindered)
		return;

	if ((GetActorLocation() - StartLocation).Length() < 5.f)
	{
		bHasReachedTarget = false;

		if (bShouldLoop)
			bIsActivated = true;
	}
	
	const auto NewLocation = GetActorLocation() - MoveDirection * MoveSpeed * GetWorld()->DeltaTimeSeconds;
	SetActorRelativeLocation(NewLocation);
}

void AEyeMoveableObject::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AEyeEntityEyeball>())
		return;
	if (OtherActor->IsA<AEyeCharacter>())
		bIsHindered = true;
}

void AEyeMoveableObject::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA<AEyeEntityEyeball>())
		return;
	if (OtherActor->IsA<AEyeCharacter>())
		bIsHindered = false;
}

void AEyeMoveableObject::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	TargetLocation = GetActorLocation() + TargetOffset;
	bIsActivated = bStartActivated;
}

void AEyeMoveableObject::Tick(float DeltaTime)
{
	if (!bShouldTick)
		return;
	
	Super::Tick(DeltaTime);
	
	MoveToTarget();
	MoveToStart();
}