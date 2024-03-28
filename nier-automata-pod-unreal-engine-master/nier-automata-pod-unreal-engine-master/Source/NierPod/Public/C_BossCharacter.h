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

	//Enemy ü��
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	int32 Health = 1000;

	//�÷��̾� ���� �ߴ���, �÷��̾ ���� ��������, ��� �������� Ȯ��
	bool playerDetected;
	bool canAttackPlayer;
	bool bIsBlocking;

	//�÷��̾� ���� �ݸ���
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* playerDetectingCollision;

	//�÷��̾� ���ݰ��� ���� �ݸ���
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* playerAttackingCollision;

	//���� ������ �ݸ���
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* blockingCollision;

	//�ǰݹ޴� ���� �ݸ���(����Ʈ�ݸ���)
	UPROPERTY(EditAnywhere, Category = "BossSettings")
	class USphereComponent* bossCharacterCollision;


};
