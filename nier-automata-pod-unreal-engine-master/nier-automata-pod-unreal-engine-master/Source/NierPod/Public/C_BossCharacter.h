// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_BossCharacter.generated.h"

UCLASS()
class NIERPOD_API AC_BossCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_BossCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	class AC_BossCharacter* playerREF;

	//Enemy 체력
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	int32 Health = 1000;

	//플레이어 감지 했는지, 플레이어를 공격 가능한지, 방어 상태인지 확인
	bool playerDetected;
	bool canAttackPlayer;
	bool bIsBlocking;

	//플레이어 감지 콜리전
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* playerDetectingCollision;

	//플레이어 공격가능 범위 콜리전
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* playerAttackingCollision;

	//공격 방어범위 콜리전
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* blockingCollision;

	//피격받는 범위 콜리전(디폴트콜리전)
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* bossCharacterCollision;


};
