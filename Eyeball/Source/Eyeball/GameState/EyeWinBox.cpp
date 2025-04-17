#include "EyeWinBox.h"

#include "Eyeball/Entities/EyeCharacter.h"
#include "Kismet/GameplayStatics.h"

void AEyeWinBox::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::HandleBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	const auto FoundActor = Cast<AEyeCharacter>(OtherActor);
	if (!FoundActor)
		return;
	if (!FoundActor->GetIsPossessed())
		return;

	GameMode->SetGameWon(PlayerHasWon);
}

void AEyeWinBox::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}