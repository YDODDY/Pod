
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"


#include "PlayerCharacter.generated.h"


UCLASS()
class NIERPOD_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

public:
	APlayerCharacter();




protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//�÷��̾� ü��
	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float playerHealth = 1000.0f;




protected:

	//�̵�, �þ�, ���� �Լ� 
	void Move(const FInputActionValue& InputValue);
	void Look(const FInputActionValue& InputValue);
	void Jump();

	//���� �Լ�
	void Attack();



	//��ǲ�׼Ǹ���
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;

	//��ǲ�׼�
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* AttackAction;

};
