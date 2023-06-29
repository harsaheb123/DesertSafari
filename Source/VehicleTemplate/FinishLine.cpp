// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"
#include <Runtime\Engine\Classes\GameFramework\Character.h>
#include <Components/BoxComponent.h>

// Sets default values

AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//FinishLineBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBox"));
	//RootComponent = FinishLineBox;

	//FinishLineBox->GenerateOverlapEvents = true;
	//FinishLineBox->OnComponentOverlap.AddDynamic(this, &AFinishLine::TriggerEnter);

}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ACharacter::StaticMesh()
//{
	
//}

//void AFinishLine::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
//{
	//if (OtherActor->IsA(ACharacter::StaticClass()))
	//{
		//UGameplayStatics::SpawnSoundAttached(MySound, OtherActor->GetRootComponent());
	//}
//}
