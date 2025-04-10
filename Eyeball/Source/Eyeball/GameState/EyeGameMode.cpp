#include "EyeGameMode.h"
#include "../Entities/EyeCharacter.h"
#include "Eyeball/Camera/EyeCamera.h"
#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeEntityEyeball.h"
#include "Eyeball/PuzzleComponents/MoveableObjects/EyeMoveableObject.h"
#include "Eyeball/Widgets/EyeRestartWidget.h"
#include "Eyeball/Widgets/EyeDangerWidget.h"
#include "Eyeball/Widgets/EyeControlsWidget.h"
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
	
	bEyeballHiddenAtCheckpoint = Eyeball->IsHidden();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EyeCharacter, CharacterArray);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EnemyCharacter, EnemyArray);

	// Find all MoveableObjects in the scene 
	TArray<AActor*> Objects;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), MoveableObject, Objects);
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
	RemoveObjects(Projectile);
	
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
		MoveableObjectArray[i]->ResetLocation();
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
	OnEntityChanged.Broadcast(PlayerCharacter);
}

void AEyeGameMode::SpawnCamera() const
{
	const auto Camera = GetWorld()->SpawnActor<AEyeCamera>(MainCamera, PlayerCharacter->GetTransform());
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
		DangerWidgetRef->AddToViewport();

	ControlsWidgetRef = CreateWidget<UEyeControlsWidget>(GetWorld(), ControlsWidget);
	if (ControlsWidgetRef)
		ControlsWidgetRef->AddToViewport();
	
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
}