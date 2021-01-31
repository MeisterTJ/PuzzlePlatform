// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

	UPROPERTY(EditAnywhere)
	float Speed = 1000;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;		// ÇÃ·§ÆûÀÌ ¿òÁ÷ÀÏ ¹æÇâ


private:
	FVector GlobalTargetLocation;	// Platform end position
	FVector GlobalStartLocation;	// Platform start position


	
	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
};
