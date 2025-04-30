#include "EyeWinBox.h"

#include "Eyeball/Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"

void AEyeWinBox::OnOverlapSuccess(AEyeCharacter* EyeCharacter)
{
	GameMode->SetGameWon(PlayerHasWon);
}

void AEyeWinBox::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}
