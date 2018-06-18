// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMesh.h"
#include "kismet/GamePlayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;


UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

// Hold barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALBATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

	

private:

	UTankAimingComponent();
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // EdieDfaultsOnly edits as a whole and not individual tanks
	float ReloadTimeInSeconds = 3;
	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	double LastFireTime = 0;

	int RoundsLeft = 3;
	
	FVector AimDirection;
};

