// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Pawn.h"
#include "Projectile.h"
#include "Tank.generated.h"

UCLASS()
class UNREALBATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Called by engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmmount, struct FDamageEvent const &DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// Returns current health as a percentage of starting health between 0 and 1 
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private: 
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;

	// Sets default values for this pawn's properties
	ATank();
};
