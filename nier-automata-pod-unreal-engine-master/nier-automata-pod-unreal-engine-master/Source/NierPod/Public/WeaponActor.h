// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

UCLASS()
class NIERPOD_API AWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="MySettings")
	class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, Category="MySettings")
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, Category="MySettings")
	float Speed = 1000;

	UPROPERTY(EditAnywhere, Category="MySettings")
	class UParticleSystem* explosionFX;

	UPROPERTY(EditAnywhere, Category="MYSettings")
	class USoundBase* explosionSound;

private:
	FVector moveDir;

	class AEnemy* FindEnemy_Iterate();

	UFUNCTION()
	void OnoverlapEnemy(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* OtherComp,
		int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
