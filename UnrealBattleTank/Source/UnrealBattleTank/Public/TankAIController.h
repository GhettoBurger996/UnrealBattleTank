// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALBATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;

	void BeginPlay() override;

	ATank* GetPlayerTank() const;

	
};
