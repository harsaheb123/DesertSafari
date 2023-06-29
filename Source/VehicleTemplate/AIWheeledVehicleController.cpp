// Fill out your copyright notice in the Description page of Project Settings.

#include "AIWheeledVehicleController.h"
#include "AIWheeledVehicle.h"
#include "WheeledVehicleMovementComponent4W.h"
#include <BehaviorTree/BehaviorTreeComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/BehaviorTree.h>

AAIWheeledVehicleController::AAIWheeledVehicleController()
{
	VehicleMovementComp = NULL;
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("AIVehicleBehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("AIVehicleBlackboardComp"));
}

void AAIWheeledVehicleController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// Initialize Controller Members
	AAIWheeledVehicle* AIVehicle = Cast<AAIWheeledVehicle>(InPawn);

	if (AIVehicle)
	{
		VehicleMovementComp = AIVehicle->GetVehicleMovementComponent();

		if (AIVehicle->BehaviorTree && AIVehicle->BehaviorTree->BlackboardAsset)
		{
			// Cache and initialize a blackboard comp is the BT has one
			BlackboardComp->InitializeBlackboard(*(AIVehicle->BehaviorTree->BlackboardAsset));
		}

		if (AIVehicle->BehaviorTree)
		{
			//Start the BT
			BehaviorTreeComp->StartTree(*AIVehicle->BehaviorTree);
		}

	}
}

void AAIWheeledVehicleController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	AAIWheeledVehicle* AIVehicle = Cast<AAIWheeledVehicle>(GetPawn());

	if (AIVehicle && !AIVehicle->BehaviorTree && VehicleMovementComp)
	{
		// Testing AI
		//VehicleMovementComp->SetThrottleInput(1.0);
		//VehicleMovementComp->SetSteeringInput(-1.0);
	}
}
