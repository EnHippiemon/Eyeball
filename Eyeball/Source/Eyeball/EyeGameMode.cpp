#include "EyeGameMode.h"
#include "EyeCharacter.h"
#include "EyeEntityEyeball.h"

void AEyeGameMode::ChangeEntity(AEyeCharacter* Character)
{
	Controller->Possess(Character);
}

void AEyeGameMode::EjectCurrentEntity()
{
	FActorSpawnParameters SpawnParameters;
	auto SpawnedEntity = GetWorld()->SpawnActor<AEyeEntityEyeball>(
		PlayerCharacter->GetActorLocation(), PlayerCharacter->GetActorRotation(), SpawnParameters);
	Controller->Possess(SpawnedEntity);
}

void AEyeGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	Controller = GetWorld()->GetFirstPlayerController();
	if (!IsValid(Controller))
		UE_LOG(LogTemp, Error, TEXT("EyeGameMode.cpp: No valid player controller."));
	
	PlayerCharacter = Cast<AEyeCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!IsValid(PlayerCharacter))
		UE_LOG(LogTemp, Error, TEXT("EyeGameMode.cpp: No valid player character."));
	if (IsValid(PlayerCharacter))
		PlayerCharacter->OnCharacterChanged.AddUniqueDynamic(this, &AEyeGameMode::ChangeEntity);
}
