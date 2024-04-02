// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindpatrolPos.generated.h"

/**
 * 
 */
UCLASS()
class NIERPOD_API UBTTask_FindpatrolPos : public UBTTaskNode
{
	GENERATED_BODY()



public:
	UBTTask_FindpatrolPos();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
