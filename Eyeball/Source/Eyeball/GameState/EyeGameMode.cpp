#include "EyeGameMode.h"
#include "../Entities/EyeCharacter.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"
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
	if (!Eyeball)
		Eyeball = Cast<AEyeEntityEyeball>(UGameplayStatics::GetActorOfClass(GetWorld(), EntityEyeball));
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EyeCharacter, CharacterArray);

	auto FoundEyeball = UGameplayStatics::GetActorOfClass(GetWorld(), EntityEyeball);
	bEyeballHiddenAtCheckpoint = FoundEyeball->IsHidden();
	
	SaveLocations();
}

void AEyeGameMode::SaveLocations()
{
	PossessedAtCheckpoint = PlayerCharacter;
	
	for (int i = 0; i < CharacterArray.Num(); ++i)
	{
		if (!CharacterLocations.IsValidIndex(i))
			CharacterLocations.Insert(CharacterArray[i]->GetActorLocation(), i);
		else
			CharacterLocations[i] = CharacterArray[i]->GetActorLocation();
	}

	if (CharacterLocations.Num() > CharacterArray.Num())
		UE_LOG(LogTemp, Warning, TEXT("Potential memory leak: EyeGameMode.cpp | CharacterLocations Array Size: %d"), CharacterLocations.Num());
}

void AEyeGameMode::ResetLocations()
{
	if (bEyeballHiddenAtCheckpoint)
		ChangeEntity(PossessedAtCheckpoint);
	else
		EjectCurrentEntity();
	
	for (int i = 0; i < CharacterArray.Num(); ++i)
	{
		CharacterArray[i]->SetActorLocation(CharacterLocations[i]);
	}
}

void AEyeGameMode::ChangeEntity(AEyeCharacter* Character)
{
	Eyeball->SetActorHiddenInGame(true);
	Controller->Possess(Character);
	GetNewPlayerReference();
	HandleDangerChange(false, 1, 1);
}

void AEyeGameMode::EjectCurrentEntity()
{
	Eyeball->SetActorLocation(PlayerCharacter->GetActorLocation());
	Eyeball->SetActorHiddenInGame(false);
	Controller->Possess(Eyeball);
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