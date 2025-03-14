#include "EyeGameMode.h"
#include "../Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"

AEyeGameMode::AEyeGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeGameMode::HandleCheckpointReached()
{
	FindAllReferences();
}

void AEyeGameMode::FindAllReferences()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EyeCharacter, CharacterArray);

	SaveLocations();
}

void AEyeGameMode::SaveLocations()
{
	PossessedAtCheckpoint = PlayerCharacter;
	
	for (int i = 0; i < CharacterArray.Num(); ++i)
	{
		if (!CharacterLocations.IsValidIndex(i))
			CharacterLocations.Add(CharacterArray[i]->GetActorLocation());
		else
			CharacterLocations[i] = CharacterArray[i]->GetActorLocation();
	}
}

void AEyeGameMode::ResetLocations()
{
	TArray<AActor*> CurrentArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EyeCharacter, CurrentArray);
	if (CurrentArray.Num() < CharacterArray.Num())
		EjectCurrentEntity();
	else if (CurrentArray.Num() > CharacterArray.Num())
		ChangeEntity(PossessedAtCheckpoint);
	
	for (int i = 0; i < CharacterArray.Num(); ++i)
	{
		CharacterArray[i]->SetActorLocation(CharacterLocations[i]);
	}
}

void AEyeGameMode::ChangeEntity(AEyeCharacter* Character)
{
	Controller->Possess(Character);
	GetWorld()->DestroyActor(PlayerCharacter);
	GetNewPlayerReference();
	HandleDangerChange(false, 1, 1);
}

void AEyeGameMode::EjectCurrentEntity()
{
	auto SpawnEyeBall = GetWorld()->SpawnActor<APawn>(EntityEyeball, PlayerCharacter->GetTransform());
	Controller->Possess(SpawnEyeBall);
	GetNewPlayerReference();
}

void AEyeGameMode::HandlePlayerDeath()
{
	ResetLocations();
	UE_LOG(LogTemp, Log, TEXT("DEATH IS UPON YOU"));
}

void AEyeGameMode::HandleDangerChange(bool IsInDanger, float TimeDilationAmount, float MaxDangerTime)
{
	if (bIsInDanger == IsInDanger)
		return;
	
	bIsInDanger = IsInDanger;
	MaxTimeInDanger = MaxDangerTime;
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), IsInDanger ? TimeDilationAmount : 1);
}

void AEyeGameMode::CountTimeInDanger(float const DeltaTime)
{
	if (!bIsInDanger)
	{
		TimeInDanger = 0;
		return;
	}

	TimeInDanger += DeltaTime;
	
	if (TimeInDanger > MaxTimeInDanger)
		HandlePlayerDeath();
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
		PlayerCharacter->OnDangerChanged.AddUniqueDynamic(this, &AEyeGameMode::HandleDangerChange);
		PlayerCharacter->OnDeath.AddUniqueDynamic(this, &AEyeGameMode::HandlePlayerDeath);
		PlayerCharacter->OnCheckpointReached.AddUniqueDynamic(this, &AEyeGameMode::HandleCheckpointReached);
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
	FindAllReferences();
}

void AEyeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CountTimeInDanger(DeltaTime);
}