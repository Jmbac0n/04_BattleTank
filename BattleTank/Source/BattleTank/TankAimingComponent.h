// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM(BlueprintType)
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel; // Forward Declaration
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

};
