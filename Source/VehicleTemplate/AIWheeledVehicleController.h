// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIWheeledVehicleController.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLETEMPLATE_API AAIWheeledVehicleController : public AAIController
{
	GENERATED_BODY()
	
public:

	// A cached BT component
	class UBehaviorTreeComponent* BehaviorTreeComp;
	
	// A cached Blackboard component
	class UBlackboardComponent* BlackboardComp;

	// A cached vehicle movement component
	class UWheeledVehicleMovementComponent* VehicleMovementComp;

	AAIWheeledVehicleController();

	//override Possess to handle additional setup
	virtual void OnPossess(APawn* InPawn) override;

	//override Tick to create some autonomous behaviours
	virtual void Tick(float DeltaSeconds) override;

};
