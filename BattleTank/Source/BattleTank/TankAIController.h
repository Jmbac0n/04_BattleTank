// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private: //public is planning to inherit from a class

	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};
