#include "EyeArcher.h"


AEyeArcher::AEyeArcher()
{
	PrimaryActorTick.bCanEverTick = true;
		
	// EvasionSphere = CreateDefaultSubobject<USphereComponent>("EvasionSphere");
	// EvasionSphere->SetupAttachment(RootCollider);
	// EvasionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEyeEnemy::HandleBeginOverlap);
	// EvasionSphere->OnComponentEndOverlap.AddDynamic(this, &AEyeEnemy::HandleEndOverlap);
}

void AEyeArcher::AvoidPlayer()
{
	
}

void AEyeArcher::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEyeArcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}