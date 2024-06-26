// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "AllyAIController.h"

AAICharacter::AAICharacter()
{
 
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AAllyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

}

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

