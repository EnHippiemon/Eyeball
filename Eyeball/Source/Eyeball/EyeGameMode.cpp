#include "EyeGameMode.h"
#include "EyeCharacter.h"
#include "EyeEntityEyeball.h"

void AEyeGameMode::ChangeEntity(AEyeCharacter* Character)
{
	Controller->Possess(Character);
	GetWorld()->DestroyActor(PlayerCharacter);
	GetNewPlayerReference();
}

void AEyeGameMode::EjectCurrentEntity()
{
	auto SpawnEyeBall = GetWorld()->SpawnActor<ACharacter>(EntityEyeball, PlayerCharacter->GetTransform());
	Controller->Possess(SpawnEyeBall);
	GetNewPlayerReference();
}

void AEyeGameMode::GetNewPlayerReference()
{
	PlayerCharacter = Cast<AEyeCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!IsValid(PlayerCharacter))
		{ UE_LOG(LogTemp, Error, TEXT("EyeGameMode.cpp: No valid player character.")); }
	else
	{
		PlayerCharacter->OnCharacterChanged.AddUniqueDynamic(this, &AEyeGameMode::ChangeEntity);
		PlayerCharacter->OnEject.AddUniqueDynamic(this, &AEyeGameMode::EjectCurrentEntity);
	}

	PlayerCharacter->OnSpawned();
}

void AEyeGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	Controller = GetWorld()->GetFirstPlayerController();
	if (!IsValid(Controller))
		UE_LOG(LogTemp, Error, TEXT("EyeGameMode.cpp: No valid player controller."));

	GetNewPlayerReference();
}