// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmmount, struct FDamageEvent const &DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmmount);
	int32 DamageToApply = FMath::Clamp<int32>(DamageAmmount, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	UE_LOG(LogTemp, Warning, TEXT("FUCK"))
	return DamageToApply;
}

float ATank::GetHealthPercent() const 
{

	return (float)CurrentHealth / (float)StartingHealth;
}