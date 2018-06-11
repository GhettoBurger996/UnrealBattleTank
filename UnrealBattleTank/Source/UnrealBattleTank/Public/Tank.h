// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // forward declaration
class UTankTurret;
class AProjectile;

UCLASS()
class UNREALBATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable)
	void Fire();


private:
	
	// TODO remove once 


	UPROPERTY(EditDefaultsOnly, Category = "Setup") // EdieDfaultsOnly edits as a whole and not individual tanks
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	// local barrel reference for spawning projectiles 
	UTankBarrel* Barrel = nullptr; 

	double LastFireTime = 0;

	virtual void BeginPlay() override;
};
