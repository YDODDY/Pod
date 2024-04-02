// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AllyAIController.generated.h"

/**
 * 
 */
UCLASS()
class NIERPOD_API AAllyAIController : public AAIController
{
	GENERATED_BODY()


public:
	AAllyAIController();
	virtual void OnPossess(APawn* InPawn) override;

	static const FName HomePosKey;
	static const FName PatrolPosKey;

private:
	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;


	
};
