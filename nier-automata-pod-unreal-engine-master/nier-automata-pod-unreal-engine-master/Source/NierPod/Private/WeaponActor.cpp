// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "EngineUtils.h"
#include "Enemy.h"

// Sets default values
AWeaponActor::AWeaponActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Comp"));
	SetRootComponent(BoxComp);
	BoxComp->SetWorldScale3D(FVector(1, 1, 2));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetCollisionObjectType(ECC_GameTraceChannel1);
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	BoxComp->SetGenerateOverlapEvents(true);
	
	
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon"));
	meshComp->SetupAttachment(BoxComp);
	meshComp->SetWorldScale3D(FVector(0.6, 0.6, 0.35));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AWeaponActor::OnoverlapEnemy);

	AEnemy* enemy = FindEnemy_Iterate();
	if (enemy != nullptr)
	{
		FVector lookDirection = enemy->GetActorLocation() - GetActorLocation();
		moveDir = lookDirection.GetSafeNormal();
	}
	else
	{
		moveDir = GetActorForwardVector();
	}
}

// Called every frame
void AWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!bShouldStopMoving)
	{
		FVector targetLoc = GetActorLocation() + moveDir * Speed * DeltaTime;
		SetActorLocation(targetLoc);
	}

}



AEnemy* AWeaponActor::FindEnemy_Iterate()
{
	TArray<AEnemy*> enemys;
	for (TActorIterator<AEnemy> enemy(GetWorld());enemy;++enemy)
	{
		enemys.Add(*enemy);
	}
	if (enemys.Num() > 0)
	{
		return enemys[0];
	}
	else
	{
		return nullptr;
	}

}

void AWeaponActor::OnoverlapEnemy(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFX, otherActor->GetActorLocation(), FRotator::ZeroRotator);

	if (explosionSound != nullptr)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), explosionSound);
	}
	UE_LOG(LogTemp, Warning, TEXT("Weaponnnnn"));
	
	bShouldStopMoving = true;

}

