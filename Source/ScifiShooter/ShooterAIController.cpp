// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if(aiBehavior != nullptr)
    {
        RunBehaviorTree(aiBehavior);
    }

}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);


    /*APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if(LineOfSightTo(playerPawn))
    {
        SetFocus(playerPawn);
        MoveToActor(playerPawn, distFromPlayer);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }*/
}

