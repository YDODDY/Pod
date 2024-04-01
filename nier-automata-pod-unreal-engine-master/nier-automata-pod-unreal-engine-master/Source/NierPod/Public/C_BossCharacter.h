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

	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class UCapsuleComponent* capsuleComp;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	class AC_BossCharacter* playerREF;


	//체력
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	float bossHealth = 1000.0f;

	//공격데미지
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	float bossDamage = 10.0f;



};
