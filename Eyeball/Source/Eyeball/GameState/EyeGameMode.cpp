#include "EyeGameMode.h"
#include "../Entities/EyeCharacter.h"
#include "Components/SphereComponent.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"
#include "Eyeball/Widgets/EyeRestartWidget.h"
#include "Eyeball/Widgets/EyeDangerWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// void AEyeGameMode::InitGameState()
// {
// 	Super::InitGameState();
// }

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
	
	bEyeballHiddenAtCheckpoint = Eyeball->IsHidden();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EyeCharacter, CharacterArray);
	SaveLocations();
}

void AEyeGameMode::SaveLocations()
{
	if (CurrentGameState == Egs_GameOver)
		return;
	
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
	
	CurrentGameState = Egs_StartingGame;
}

void AEyeGameMode::ChangeEntity(AEyeCharacter* Character)
{
	const auto CurrentVelocity = PlayerCharacter->GetMovementDirection();
	Eyeball->SetActorHiddenInGame(true);
	Controller->Possess(Character);
	GetNewPlayerReference();
	HandleDangerFound(false);
	Character->AddArtificialInput(CurrentVelocity);
}

void AEyeGameMode::EjectCurrentEntity()
{
	const auto CurrentVelocity = FVector(0, PlayerCharacter->GetVelocity().Y, PlayerCharacter->GetVelocity().Z);
	Eyeball->AddArtificialInput(CurrentVelocity);
	Eyeball->SetActorLocation(PlayerCharacter->GetActorLocation());
	Eyeball->SetActorHiddenInGame(false);
	Controller->Possess(Eyeball);
	GetNewPlayerReference();
}

void AEyeGameMode::HandlePlayerDeath()
{
	CurrentGameState = Egs_GameOver;
	OnChangedState.Broadcast(CurrentGameState);
}

void AEyeGameMode::HandleDangerFound(bool IsInDanger)
{
	if (bIsInDanger == IsInDanger)
		return;
	
	bIsInDanger = IsInDanger;
	TargetTimeDilation = IsInDanger ? TimeDilationDanger : 1;
	OnDangerChanged.Broadcast(IsInDanger);
}

void AEyeGameMode::CountTimeInDanger(float const DeltaTime)
{
	if (!bIsInDanger || CurrentGameState != Egs_Playing)
	{
		TimeInDanger = 0;
		return;
	}

	TimeInDanger += DeltaTime;
	
	if (TimeInDanger > MaxDangerTime)
		HandlePlayerDeath();
}

void AEyeGameMode::SetTimeDilation(float DeltaTime)
{
	float CurrentTimeDilation = UGameplayStatics::GetGlobalTimeDilation(GetWorld());
	CurrentTimeDilation = FMath::Lerp(CurrentTimeDilation, TargetTimeDilation, TimeDilationTransitionSpeed * DeltaTime);
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), CurrentTimeDilation);
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
		PlayerCharacter->OnDangerFound.AddUniqueDynamic(this, &AEyeGameMode::HandleDangerFound);
		PlayerCharacter->OnDeath.AddUniqueDynamic(this, &AEyeGameMode::HandlePlayerDeath);
		PlayerCharacter->OnCheckpointReached.AddUniqueDynamic(this, &AEyeGameMode::HandleCheckpointReached);
	}

	PlayerCharacter->OnSpawned();
}

void AEyeGameMode::SetNewState(const bool bScreenIsBlack)
{
	if (bScreenIsBlack)
		ResetLocations();
	else
		CurrentGameState = Egs_Playing;
	
	OnChangedState.Broadcast(CurrentGameState);
}

void AEyeGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	Controller = GetWorld()->GetFirstPlayerController();
	if (!IsValid(Controller))
		UE_LOG(LogTemp, Error, TEXT("EyeGameMode.cpp: No valid player controller."));
	
	RestartWidgetRef = CreateWidget<UEyeRestartWidget>(GetWorld(), RestartWidget);
	if (RestartWidgetRef)
	{
		RestartWidgetRef->AddToViewport();
		RestartWidgetRef->OnTransitionCompleted.AddUniqueDynamic(this, &AEyeGameMode::SetNewState);
	}
	
	DangerWidgetRef = CreateWidget<UEyeDangerWidget>(GetWorld(), DangerWidget);
	if (DangerWidgetRef)
	{
		DangerWidgetRef->AddToViewport();
	}
	
	CurrentGameState = Egs_StartingGame;
	OnChangedState.Broadcast(CurrentGameState);
	
	GetNewPlayerReference();
	FindAllReferences();
}

void AEyeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CountTimeInDanger(DeltaTime);
	SetTimeDilation(DeltaTime);
}