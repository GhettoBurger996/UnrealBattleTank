// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force, and to apply forces.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UNREALBATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets a throttles between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000; // Assume 40 ton tank, and 1g accelleration
	
};
