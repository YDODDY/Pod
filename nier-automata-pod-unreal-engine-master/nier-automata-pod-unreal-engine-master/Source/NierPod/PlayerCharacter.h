#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class NIERPOD_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

	

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Inputs")
	class UInputMappingContext* IMC_InputMapping;
	UPROPERTY(EditAnywhere, Category = "Inputs")
	class UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category = "Inputs")
	class UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere, Category = "Inputs")
	class UInputAction* IA_Look;
	UPROPERTY(EditAnywhere, Category = "Inputs")
	class UInputAction* IA_Attack;



public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	void Move(const FInputActionValue& InputValue);
	void Look(const FInputActionValue& InputValue);
	void Jump();


};
