// Fill out your copyright notice in the Description page of Project Settings.


#include "C_BossCharacter.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacter.h"


// Sets default values
AC_BossCharacter::AC_BossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//���ݰ��� ĸ������
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	SetRootComponent(capsuleComp);
	capsuleComp -> SetCapsuleSize(40.0f,80.0f, true);
	
}

// Called when the game starts or when spawned
void AC_BossCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_BossCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AC_BossCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}




