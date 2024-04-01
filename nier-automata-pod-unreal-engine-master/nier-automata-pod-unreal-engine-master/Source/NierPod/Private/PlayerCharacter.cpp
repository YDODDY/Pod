

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h>
#include <C_BossCharacter.h>




APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;


	//�÷��̾� �þ� 
	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera -> bUsePawnControlRotation = false;

	//�÷��̾� �̵�, �þ� ���� 
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator (0, 540, 0);
	

}void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//�÷��̾� ��ǲ���� ����
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = CastChecked <UEnhancedInputComponent>(PlayerInputComponent))
	{	//��ǲ-�Լ� ���ε�
		Input -> BindAction (MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		Input -> BindAction (LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		Input -> BindAction (JumpAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Jump);
		Input -> BindAction (AttackAction, ETriggerEvent::Started, this, &APlayerCharacter::Attack);
	}

}



//�̵�
void APlayerCharacter::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	
	if (IsValid(Controller))
	{
		const FRotator Rotation = Controller -> GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}
	//�þ�
void APlayerCharacter::Look(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}
	//����
void APlayerCharacter::Jump()
{
	ACharacter::Jump();
}
// 	//����
 void APlayerCharacter::Attack()
 {	
	
 
 	TArray<TEnumAsByte<EObjectTypeQuery>> enemy;
  	enemy.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_EngineTraceChannel1));
  
  	TArray<AActor*> ignore;
  	ignore.Init(this, 1);
  
  	TArray<AActor*> OutActors;
  	TArray<FHitResult> bossHit;
  
  	//�÷��̾� ���� ���ݹ��� ���� 
  	FVector attackRange = GetActorLocation() + GetActorForwardVector() * 100.0f;
  
  	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), GetActorLocation(), attackRange, 20.0f, enemy, false, ignore, EDrawDebugTrace::ForDuration, bossHit, true, FLinearColor::Red, FLinearColor::Blue, 1.0f);
  
  	UE_LOG(LogTemp, Warning, TEXT("Attack"));
  
  
  }




