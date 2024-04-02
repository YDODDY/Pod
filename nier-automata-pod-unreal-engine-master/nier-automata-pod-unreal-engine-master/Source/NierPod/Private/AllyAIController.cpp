// Fill out your copyright notice in the Description page of Project Settings.


#include "AllyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AAllyAIController::HomePosKey(TEXT("HomePos"));
const FName AAllyAIController::PatrolPosKey(TEXT("PatrolPos"));

AAllyAIController::AAllyAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_Allycharacter.BB_AllyCharacter"));

	if(BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_Allycharacter.BT_AllyCharacter"));
	if(BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}


void AAllyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UBlackboardComponent* BlackboardComponent = Blackboard;

	if(UseBlackboard(BBAsset,BlackboardComponent))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
	}
}

