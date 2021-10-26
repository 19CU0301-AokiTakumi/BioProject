
#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// �R���X�g���N�^
APlayerChara::APlayerChara()
	: m_pSpringArm(NULL)
	, m_pCamera(NULL)
	, m_CharaMoveInput(FVector::ZeroVector)
	, m_CameraRotationInput(FVector::ZeroVector)
	, m_CameraYawLimit(FVector2D(-100.f, 100.f))
	, m_CameraPitchLimit(FVector2D(-80.f, 80.f))
	, m_MoveSpeed(1000.f)
	, m_bagSize(8)
{
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	//�@�X�v�����O�A�[���̃I�u�W�F�N�g�𐶐�
	m_pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	if (m_pSpringArm)
	{
		m_pSpringArm->SetupAttachment(RootComponent);

		//�@�A�[���̒�����ݒ�
		//�@�J�����̃R���W�����e�X�g���s������ݒ�
		m_pSpringArm->bDoCollisionTest = false;
		//�@�J�����Ǐ]�t���O���g������ݒ�
		m_pSpringArm->bEnableCameraLag = true;
		//�@�J�����Ǐ]���O�̑��x��ݒ�
		m_pSpringArm->CameraLagSpeed = 25.f;
		//�@�J�����̉�]���O���g������ݒ�
		m_pSpringArm->bEnableCameraRotationLag = true;
		//�@�J������]���O�̑��x��ݒ�
		m_pSpringArm->CameraRotationLagSpeed = 20.f;
	}

	// �J�����̃I�u�W�F�N�g�𐶐�
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (m_pCamera)
		m_pCamera->SetupAttachment(m_pSpringArm);
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void APlayerChara::BeginPlay()
{
	Super::BeginPlay();

	//	�o�b�O�̒��g��������
	m_ItemDatas.Init(FItemData::NoneData(), m_bagSize);
}

// ���t���[���X�V����
void APlayerChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove(DeltaTime);
	UpdateCamera(DeltaTime);
}

// �e���͊֌W���\�b�h�Ƃ̃o�C���h����
void APlayerChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// �ړ�
	InputComponent->BindAxis("Move_Forward", this, &APlayerChara::MoveForward);
	InputComponent->BindAxis("Move_Right", this, &APlayerChara::MoveRight);

	// �J�����̉�]
	InputComponent->BindAxis("Camera_Forward", this, &APlayerChara::CameraRotatePitch);
	InputComponent->BindAxis("Camera_Right", this, &APlayerChara::CameraRotateYaw);
}

// �ړ�����
void APlayerChara::UpdateMove(float _deltaTime)
{
	if (m_pSpringArm)
	{
		//�@�L�����N�^�[�̈ړ�
		{
			// SpringArm�����������ɁA���͂ɂ��ړ��ʂ�PawnMovementComponent�ɓn��
			const FVector forwardVec = m_pSpringArm->GetForwardVector();
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_MoveSpeed);

			const FVector rightVec = m_pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_MoveSpeed);
		}
	}
}

//�@�J�����̍X�V����
void APlayerChara::UpdateCamera(float _deltaTime)
{
	if (m_pSpringArm)
	{
		//�@�J�����̐V�����p�x�����߂�
		//�@���݂̊p�x���擾
		FRotator NewRotation = m_pSpringArm->GetRelativeRotation();

		//�@Yaw�͓��͂�������
		NewRotation.Yaw += m_CameraRotationInput.X;

		//�@Pitch�Ɋւ��ẮA�㉺�̐����p�x�͈͓̔��Ő؂�
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + m_CameraRotationInput.Y, m_CameraPitchLimit.X, m_CameraPitchLimit.Y);

		//�@�V�����p�x�𔽉f
		m_pSpringArm->SetRelativeRotation(NewRotation);
	}
}

//�@�y���̓o�C���h�z�L�����ړ��F�O��
void APlayerChara::MoveForward(float _axisValue)
{
	m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//�@�y���̓o�C���h�z�L�����ړ����E
void APlayerChara::MoveRight(float _axisValue)
{
	m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//�@�y���̓o�C���h�z�J�����̉�]�F�iY���j
void APlayerChara::CameraRotatePitch(float _axisValue)
{
	m_CameraRotationInput.Y = _axisValue;
}

//�@�y���̓o�C���h�z�J������]�F�iZ���j
void APlayerChara::CameraRotateYaw(float _axisValue)
{
	m_CameraRotationInput.X = _axisValue;
}