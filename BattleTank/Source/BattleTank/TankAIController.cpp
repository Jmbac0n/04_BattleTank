// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move Towards Player
		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);

		// Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO Don't fire every frame
	}
}


