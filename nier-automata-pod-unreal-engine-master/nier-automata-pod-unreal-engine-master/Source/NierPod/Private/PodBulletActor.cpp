// Fill out your copyright notice in the Description page of Project Settings.


#include "PodBulletActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Enemy.h"


APodBulletActor::APodBulletActor()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Comp"));
	SetRootComponent(SphereComp);
	SphereComp->SetSphereRadius(5);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionObjectType(ECC_GameTraceChannel1);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	SphereComp->SetGenerateOverlapEvents(true);

	
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	meshComp ->SetupAttachment(SphereComp);
	meshComp->SetWorldScale3D(FVector(0.1f));
	meshComp->SetRelativeLocation(FVector(0, 0, -5));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


void APodBulletActor::BeginPlay()
{
	Super::BeginPlay();
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &APodBulletActor::OnoverlapEnermy);

	AEnemy* enemy = FindEnemy_Iterator();
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


void APodBulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector targetLoc = GetActorLocation() + moveDir* Speed * DeltaTime;
	SetActorLocation(targetLoc);
	UE_LOG(LogTemp, Warning, TEXT("Shoot~"));


}

void APodBulletActor::OnoverlapEnermy(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFX, otherActor->GetActorLocation(), FRotator::ZeroRotator);

	if (explosionSound != nullptr)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), explosionSound);
	}

	Destroy();

}

AEnemy* APodBulletActor::FindEnemy_Iterator()
{
	TArray<AEnemy*> enemys;
	for (TActorIterator<AEnemy> enemy(GetWorld()); enemy; ++enemy)
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
