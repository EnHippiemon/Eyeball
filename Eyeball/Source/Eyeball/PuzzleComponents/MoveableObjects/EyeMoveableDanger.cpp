#include "../MoveableObjects/EyeMoveableDanger.h"

#include "Eyeball/Enemies/EyeEnemy.h"
#include "Eyeball/Entities/EyeCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

void AEyeMoveableDanger::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEyeCharacter* FoundActor = Cast<AEyeCharacter>(OtherActor))
	{
		if (FoundActor->GetIsPossessed())
		{
			if (GameMode && GameMode->GetDeathCountSinceCheckpoint() >= GameMode->GetDeathCountForDecreasedDifficulty())
			{
				GetWorldTimerManager().SetTimer(DangerTimer, this, &AEyeMoveableDanger::CheckOverlaps,
												GameMode->GetLeewayForBeingHit(), false,
												GameMode->GetLeewayForBeingHit());
				return;
			}

			FoundActor->TakeDamage();
			return;
		}

		FoundActor->ResetPosition();
		return;
	}
	if (const auto FoundActor = Cast<AEyeEnemy>(OtherActor))
	{
		if (OtherComp == Cast<UPrimitiveComponent>(FoundActor->GetDamageComponent()))
			FoundActor->ChangeHealth(-1);
		return;
	}
}

void AEyeMoveableDanger::CheckOverlaps() const
{
	TArray<AActor*> OverlappingActors;
	OverlapCollision->GetOverlappingActors(OverlappingActors, AEyeCharacter::StaticClass());
	for (int i = 0; i < OverlappingActors.Num(); ++i)
	{
		AEyeCharacter* CurrentActor = Cast<AEyeCharacter>(OverlappingActors[i]);
		if (!CurrentActor)
			continue;
		if (CurrentActor->GetIsPossessed())
		{
			CurrentActor->TakeDamage();
			break;
		}
	}
}

void AEyeMoveableDanger::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AEyeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}