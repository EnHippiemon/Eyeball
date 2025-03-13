#include "EyeGameMode.h"
#include "Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"

AEyeGameMode::AEyeGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
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

void AEyeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CountTimeInDanger(DeltaTime);
	
}
