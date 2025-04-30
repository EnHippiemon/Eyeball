#include "EyeGameMode.h"

#include "NiagaraFunctionLibrary.h"
#include "../Entities/EyeCharacter.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Eyeball/Camera/EyeCamera.h"
#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"
#include "Eyeball/Widgets/EyeRestartWidget.h"
#include "Eyeball/Widgets/EyeDeathCountWidget.h"
#include "Eyeball/Widgets/EyeDangerWidget.h"
#include "Eyeball/Widgets/EyeWonWidget.h"
#include "Eyeball/Widgets/EyePauseWidget.h"
#include "Kismet/GameplayStatics.h"

void AEyeGameMode::SetGameWon(const bool HasWon)
{
	CurrentGameState = HasWon ? Egs_GameWon : Egs_StartingGame;

	if (!HasWon)
		return;
	
	WonWidgetRef = CreateWidget<UEyeWonWidget>(GetWorld(), Data->WonWidget);
	if (WonWidgetRef)
		WonWidgetRef->AddToViewport();
}

AEyeGameMode::AEyeGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEyeGameMode::HandleEasyMode(bool const ShouldBeEasy)
{
	for (int i = 0; i < CharacterArray.Num(); ++i)
	{
		const AEyeCharacter* CurrentCharacter = Cast<AEyeCharacter>(CharacterArray[i]);
		if (CurrentCharacter)
			CurrentCharacter->SetEasyModeMesh(ShouldBeEasy);

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Data->SmokeEffect,
											   FVector(50, CharacterArray[i]->GetActorLocation().Y,
													   CharacterArray[i]->GetActorLocation().Z),
											   FRotator::ZeroRotator, FVector(1, 1, 1), true,
											   true);
	}
}

void AEyeGameMode::HandleCheckpointReached()
{
	if (CurrentGameState != Egs_Playing)
		return;

	FindAllReferences();

	const bool bIsEasyMode = DeathCountSinceCheckpoint >= Data->DeathCountForDecreasedDifficulty;
	if (bIsEasyMode)
		HandleEasyMode(false);
	
	DeathCountSinceCheckpoint = 0;
	CurrentMaxTimeInDanger = Data->MaxTimeInDanger;
}

void AEyeGameMode::FindAllReferences()
{
	if (!Eyeball)
		Eyeball = Cast<AEyeEntityEyeball>(UGameplayStatics::GetActorOfClass(GetWorld(), Data->EntityEyeball));
	
	bEyeballHiddenAtCheckpoint = Eyeball->IsHidden();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Data->EyeCharacter, CharacterArray);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Data->EnemyCharacter, EnemyArray);

	// Find all MoveableObjects in the scene 
	TArray<AActor*> Objects;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Data->MoveableObject, Objects);
	for (int i = 0; i < Objects.Num(); ++i)
	{
		if (!MoveableObjectArray.IsValidIndex(i))
			MoveableObjectArray.Insert(Cast<AEyeMoveableObject>(Objects[i]), i);
		else
			MoveableObjectArray[i] = Cast<AEyeMoveableObject>(Objects[i]);
	}
	
	SaveStates();
}

void AEyeGameMode::SaveStates()
{
	if (CurrentGameState == Egs_GameOver)
		return;
	
	PossessedAtCheckpoint = PlayerCharacter;

	SaveLocationsOfActors(CharacterArray, CharacterLocations);
	SaveLocationsOfActors(EnemyArray, EnemyLocations);
	SaveMoveableObjectStates();

	SaveEnemyHealth(EnemyArray, EnemyHealths);

	if (CharacterLocations.Num() > CharacterArray.Num())
		UE_LOG(LogTemp, Warning, TEXT("Potential memory leak: EyeGameMode.cpp | CharacterLocations Array Size: %d"), CharacterLocations.Num());
}

void AEyeGameMode::ResetStates()
{
	// Reset MoveableObjects
	ResetMoveableObjects();
	
	// Reset entity locations
	if (bEyeballHiddenAtCheckpoint)
		ChangeEntity(PossessedAtCheckpoint);
	else
		EjectCurrentEntity();
	
	ResetActorLocations(CharacterArray, CharacterLocations);

	// Reset enemies
	ResetActorLocations(EnemyArray, EnemyLocations);
	ResetEnemyHealth(EnemyArray, EnemyHealths);
	
	// Delete objects 
	RemoveObjects(Data->Projectile);

	const bool bIsEasyMode = DeathCountSinceCheckpoint >= Data->DeathCountForDecreasedDifficulty;
	if (bIsEasyMode)
		HandleEasyMode(true);
	
	CurrentGameState = Egs_StartingGame;
}

void AEyeGameMode::SaveLocationsOfActors(TArray<AActor*> ArrayOfActors, TArray<FVector>& ArrayOfLocations)
{
	for (int i = 0; i < ArrayOfActors.Num(); ++i)
	{
		if (!ArrayOfLocations.IsValidIndex(i))
			ArrayOfLocations.Insert(ArrayOfActors[i]->GetActorLocation(), i);
		else
			ArrayOfLocations[i] = ArrayOfActors[i]->GetActorLocation();
	}
}

void AEyeGameMode::ResetActorLocations(TArray<AActor*> ArrayOfActors, TArray<FVector>& ArrayOfLocations)
{
	for (int i = 0; i < ArrayOfActors.Num(); ++i)
	{
		ArrayOfActors[i]->SetActorLocation(ArrayOfLocations[i]);
	}
}

void AEyeGameMode::ResetMoveableObjects() const
{
	for (int i = 0; i < MoveableObjectArray.Num(); ++i)
	{
		MoveableObjectArray[i]->SetActorLocation(MoveableObjectLocations[i]);
		MoveableObjectArray[i]->SetActivated(MoveableObjectsActivated[i]);
		MoveableObjectArray[i]->SetReachedTarget(MoveableObjectsReachedTarget[i]);
	}
}

void AEyeGameMode::RemoveObjects(const TSubclassOf<AActor>& ObjectClassToDelete) const
{
	TArray<AActor*> ObjectsToDelete;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ObjectClassToDelete, ObjectsToDelete);
	for (int i = 0; i < ObjectsToDelete.Num(); ++i)
	{
		ObjectsToDelete[i]->Destroy();
	}
}

void AEyeGameMode::SaveEnemyHealth(TArray<AActor*> ArrayOfActors, TArray<int>& ArrayOfHealth)
{
	for (int i = 0; i < ArrayOfActors.Num(); ++i)
	{
		const auto Actor = Cast<AEyeEnemy>(ArrayOfActors[i]);
		if (!Actor)
			continue;
		
		if (!ArrayOfHealth.IsValidIndex(i))
			ArrayOfHealth.Add(Actor->GetHealth());
		else
			ArrayOfHealth[i] = Actor->GetHealth();
	}
}

void AEyeGameMode::SaveMoveableObjectStates()
{
	for (int i = 0; i < MoveableObjectArray.Num(); ++i)
	{
		// Location 
		if (!MoveableObjectLocations.IsValidIndex(i))
			MoveableObjectLocations.Insert(MoveableObjectArray[i]->GetActorLocation(), i);
		else
			MoveableObjectLocations[i] = MoveableObjectArray[i]->GetActorLocation();

		// Activation state 
		if (!MoveableObjectsActivated.IsValidIndex(i))
			MoveableObjectsActivated.Add(MoveableObjectArray[i]->GetIsActivated());
		else
			MoveableObjectsActivated[i] = MoveableObjectArray[i]->GetIsActivated();

		// Has reached end position state
		if (!MoveableObjectsReachedTarget.IsValidIndex(i))
			MoveableObjectsReachedTarget.Add(MoveableObjectArray[i]->GetHasReachedTarget());
		else
			MoveableObjectsReachedTarget[i] = MoveableObjectArray[i]->GetHasReachedTarget();
	}
}

void AEyeGameMode::ResetEnemyHealth(TArray<AActor*> ArrayOfActors, TArray<int>& ArrayOfHealth)
{
	for (int i = 0; i < ArrayOfActors.Num(); ++i)
	{
		const auto Actor = Cast<AEyeEnemy>(ArrayOfActors[i]);
		if (!Actor)
			continue;
		
		Actor->SetHealth(ArrayOfHealth[i]);
	}
}

void AEyeGameMode::ChangeEntity(AEyeCharacter* Character)
{
	const auto CurrentVelocity = PlayerCharacter->GetMovementDirection();
	Eyeball->SetActorHiddenInGame(true);
	Controller->Possess(Character);
	GetNewPlayerReference();
	HandleDangerFound(false);
	Character->SetArtificialInput(CurrentVelocity);
}

void AEyeGameMode::EjectCurrentEntity()
{
	const auto CurrentVelocity = FVector(0, PlayerCharacter->GetVelocity().Y, PlayerCharacter->GetVelocity().Z);
	Eyeball->SetArtificialInput(CurrentVelocity);
	Eyeball->SetActorLocation(PlayerCharacter->GetActorLocation());
	Eyeball->SetActorHiddenInGame(false);
	Controller->Possess(Eyeball);
	GetNewPlayerReference();
}

void AEyeGameMode::HandlePlayerDeath()
{
	if (CurrentGameState != Egs_Playing)
		return;
	
	++DeathCount;
	++DeathCountSinceCheckpoint;
	if (DeathCountSinceCheckpoint >= Data->DeathCountForDecreasedDifficulty)
		CurrentMaxTimeInDanger = Data->ExtendedMaxTimeInDanger;
	
	CurrentGameState = Egs_GameOver;
	OnChangedState.Broadcast(CurrentGameState);
}

void AEyeGameMode::HandleDangerFound(bool IsInDanger)
{
	if (bIsInDanger == IsInDanger)
		return;
	
	bIsInDanger = IsInDanger;
	TargetTimeDilation = IsInDanger ? Data->TimeDilationDanger : 1;
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
	
	if (TimeInDanger > CurrentMaxTimeInDanger)
		HandlePlayerDeath();
}

void AEyeGameMode::SetTimeDilation(float DeltaTime)
{
	float CurrentTimeDilation = UGameplayStatics::GetGlobalTimeDilation(GetWorld());
	CurrentTimeDilation = FMath::Lerp(CurrentTimeDilation, TargetTimeDilation, Data->TimeDilationTransitionSpeed * DeltaTime);
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
		PlayerCharacter->OnPaused.AddUniqueDynamic(this, &AEyeGameMode::PauseGame);
	}
	
	PlayerCharacter->OnSpawned();
	OnEntityChanged.Broadcast(PlayerCharacter);

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Data->SmokeEffect,
	                                               FVector(50, PlayerCharacter->GetActorLocation().Y,
	                                                       PlayerCharacter->GetActorLocation().Z),
	                                               FRotator::ZeroRotator, FVector(1, 1, 1), true,
	                                               true);
}

void AEyeGameMode::SpawnCamera() const
{
	const auto Camera = GetWorld()->SpawnActor<AEyeCamera>(Data->MainCamera, PlayerCharacter->GetTransform());
	Camera->OnSpawned();
	OnEntityChanged.Broadcast(PlayerCharacter);
}

void AEyeGameMode::SetNewState(const bool bScreenIsBlack)
{
	if (bScreenIsBlack)
	{
		ResetStates();
		PlayerCharacter->SetArtificialInput(FVector(0, 0, 0));
		PlayerCharacter->SetMoveDirection(FVector(0, 0, 0));
	}
	else
		CurrentGameState = Egs_Playing;

	OnChangedState.Broadcast(CurrentGameState);
}

void AEyeGameMode::PauseGame()
{
	if (!PauseWidgetRef)
		return;

	const bool ShouldPause = !UGameplayStatics::IsGamePaused(GetWorld());
	PauseWidgetRef->SetVisible(ShouldPause);
	UGameplayStatics::SetGamePaused(GetWorld(), ShouldPause);
	UGameplayStatics::SetViewportMouseCaptureMode(GetWorld(), ShouldPause ? EMouseCaptureMode::CapturePermanently : EMouseCaptureMode::NoCapture);
	APlayerController* PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = ShouldPause;
		PlayerController->bEnableClickEvents = ShouldPause;
		PlayerController->bEnableMouseOverEvents = ShouldPause;
		ShouldPause ? UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController) : UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	}
}

void AEyeGameMode::HandleMenuButtonPressed(FString ButtonName)
{
	if (ButtonName == "Continue")
		PauseGame();
	else if (ButtonName == "RestartCheckpoint")
	{
		HandlePlayerDeath();
		PauseGame();
	}
	else if (ButtonName == "RestartLevel")
	{
		APlayerController* PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		UGameplayStatics::OpenLevel(this, Data->MainLevelPath, true);
	}
	else if (ButtonName == "Quit")
		FGenericPlatformMisc::RequestExit(false);
}

void AEyeGameMode::DebugWidgetAmount()
{
	// // Debugging widget count
	// TArray<UUserWidget*> FoundWidgets;
	// UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UUserWidget::StaticClass());
	// UE_LOG(LogTemp, Display, TEXT("Amount of widgets: %i"), FoundWidgets.Num());
}

void AEyeGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	Controller = GetWorld()->GetFirstPlayerController();
	if (!IsValid(Controller))
		UE_LOG(LogTemp, Error, TEXT("EyeGameMode.cpp: No valid player controller."));

	RestartWidgetRef = CreateWidget<UEyeRestartWidget>(GetWorld(), Data->RestartWidget);
	if (RestartWidgetRef)
	{
		RestartWidgetRef->AddToViewport();
		RestartWidgetRef->OnTransitionCompleted.AddUniqueDynamic(this, &AEyeGameMode::SetNewState);
	}
	
	DangerWidgetRef = CreateWidget<UEyeDangerWidget>(GetWorld(), Data->DangerWidget);
	if (DangerWidgetRef)
		DangerWidgetRef->AddToViewport();

	PauseWidgetRef = CreateWidget<UEyePauseWidget>(GetWorld(), Data->PauseWidget);
	if (PauseWidgetRef)
	{
		PauseWidgetRef->AddToViewport();
		PauseWidgetRef->OnButtonClicked.AddUniqueDynamic(this, &AEyeGameMode::HandleMenuButtonPressed);
	}

	// Create last, so it's above other widgets in the hierarchy and always visible. 
	DeathCountWidgetRef = CreateWidget<UEyeDeathCountWidget>(GetWorld(), Data->DeathCountWidget);
	if (DeathCountWidgetRef)
		DeathCountWidgetRef->AddToViewport();
	
	GetNewPlayerReference();
	FindAllReferences();

	SpawnCamera();
	
	CurrentGameState = Egs_StartingGame;
	OnChangedState.Broadcast(CurrentGameState);
}

void AEyeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CountTimeInDanger(DeltaTime);
	SetTimeDilation(DeltaTime);
	
	DebugWidgetAmount();
}