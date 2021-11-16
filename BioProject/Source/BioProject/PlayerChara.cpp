
#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "DoorBase.h"
#include "ItemBase.h"
#include "DrawDebugHelpers.h"
#include "Bullet.h"

// �R���X�g���N�^
APlayerChara::APlayerChara()
	: m_pSpringArm(NULL)
	, m_pCamera(NULL)
	, m_CharaMoveInput(FVector::ZeroVector)
	, m_CameraRotationInput(FVector::ZeroVector)
	, m_CameraYawLimit(FVector2D(-100.f, 100.f))
	, m_CameraPitchLimit(FVector2D(-80.f, 80.f))
	, m_bagSize(8)
	, m_pOverlapActor(NULL)
	, m_OverlapActorPos(FVector::ZeroVector)
	, m_invenoryState(EInventoryState::Idle)
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

	m_playerStatus = { 10, 10, 1000.f };
	m_statusConst = { 1000.f, 10000000.f };
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void APlayerChara::BeginPlay()
{
	Super::BeginPlay();

	//	�o�b�O�̒��g��������
	m_ItemDatas.Init(FItemData::NoneData(), m_bagSize);

	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerChara::OnOverlapBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &APlayerChara::OnOverlapEnd);
	}
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
	InputComponent->BindAxis("Move_Forward", this, &APlayerChara::Input_MoveForward);
	InputComponent->BindAxis("Move_Right", this, &APlayerChara::Input_MoveRight);

	// �J�����̉�]
	InputComponent->BindAxis("Camera_Forward", this, &APlayerChara::Input_CameraRotatePitch);
	InputComponent->BindAxis("Camera_Right", this, &APlayerChara::Input_CameraRotateYaw);

	// ����
	InputComponent->BindAction("Run", IE_Pressed, this, &APlayerChara::Input_Run);

	// �A�N�V����
	InputComponent->BindAction("Action", IE_Pressed, this, &APlayerChara::Input_Action);

	// �e���\����
	InputComponent->BindAxis("Hold", this, &APlayerChara::Input_Hold);

	// �e������
	InputComponent->BindAction("Shooting", IE_Pressed, this, &APlayerChara::Input_Shooting);

	// �����[�h
	InputComponent->BindAction("Reload", IE_Pressed, this, &APlayerChara::Input_Reload);

	// �C���x���g��
	InputComponent->BindAction("Inventory", IE_Pressed, this, &APlayerChara::Input_Inventory);
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void APlayerChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	m_pOverlapActor = OtherActor;
	m_OverlapActorPos = OtherActor->GetActorLocation();

	if (Cast<AItemBase>(OtherActor))
	{
		m_playerFlags.flagBits.isItemTouch = true;
	}

	if (Cast<ADoorBase>(OtherActor))
	{
		if (OtherComp->ComponentHasTag("Front"))
		{
			Cast<ADoorBase>(OtherActor)->SetOpenReverse(false);
		}
		else if (OtherComp->ComponentHasTag("Back"))
		{
			Cast<ADoorBase>(OtherActor)->SetOpenReverse(true);
		}
	}
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void APlayerChara::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// �������Ă����A�C�e���𖳌��ɂ���
	m_playerFlags.flagBits.isItemTouch = false;

	if (m_pOverlapActor)
	{
		m_pOverlapActor = NULL;
	}
	if (Cast<ADoorBase>(OtherActor))
	{
		if (Cast<ADoorBase>(OtherActor)->GetIsLock())
		{
			m_playerFlags.flagBits.isOpenMenu = false;
		}
		m_playerFlags.flagBits.isOpenMenu = false;
	}
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
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_playerStatus.moveSpeed);

			const FVector rightVec = m_pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_playerStatus.moveSpeed);
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
void APlayerChara::Input_MoveForward(float _axisValue)
{
	m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//�@�y���̓o�C���h�z�L�����ړ����E
void APlayerChara::Input_MoveRight(float _axisValue)
{
	m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//�@�y���̓o�C���h�z�J�����̉�]�F�iY���j
void APlayerChara::Input_CameraRotatePitch(float _axisValue)
{
	m_CameraRotationInput.Y = _axisValue;
}

//�@�y���̓o�C���h�z�J������]�F�iZ���j
void APlayerChara::Input_CameraRotateYaw(float _axisValue)
{
	m_CameraRotationInput.X = _axisValue;
}

//�y���̓o�C���h�z�e���\����
void APlayerChara::Input_Hold(float _axisValue)
{
	m_playerFlags.flagBits.isGunHold = !(m_playerFlags.flagBits.isGunHold);
}

// �y���̓o�C���h�z�e������
void APlayerChara::Input_Shooting()
{

	//m_bShootGun = true;
	//UE_LOG(LogTemp, Log, TEXT("MM"));

	//if (m_iGunAmmoCount < 1)
	//{
	//	m_ZeroBullet = true;
	//}

	//if (!m_bHaveGun && m_iGunAmmoCount >= 0) { return; }

	//FRotator SpawnRotation = GetControlRotation();
	//FVector SpawnLocation = GetCapsuleComponent()->GetComponentLocation();
	//FActorSpawnParameters ActorSpawnParams;
	////GetWorld()->SpawnActor<APlayerChara>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	//m_iGunAmmoCount--;


	//if (m_playerFlags.flagBits.isHaveGun == false)
	//	return;


	// ���C���΂�
	// ���C�̎n�_��Actor�̈ʒu
	FVector Start = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100.f);
	// ���C�̏I�_��Actor����O�����̈�苗��
	FVector End = m_pCamera->GetRelativeLocation() + m_pCamera->GetForwardVector() * 10000.f;

	//// �f�o�b�O�m�F�p�̃��C����`��
	//DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 1.0f);

	// �R���W��������Ŗ������鍀�ڂ��w��i����͂���Actor�������g�Bthis�|�C���^�Ŏw��j
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	//// �q�b�g�����i=�R���W����������󂯂��j�I�u�W�F�N�g���i�[����ϐ�
	//FHitResult OutHit;

	//// ���C���΂��A�I�u�W�F�N�g�ɑ΂��ăR���W����������s��
	//// isHit�́A�q�b�g�����ꍇ��true�ɂȂ�
	//bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_WorldStatic, CollisionParams);

	//// �q�b�g����I�u�W�F�N�g������ꍇ
	//if (isHit)
	//{

	//}

	FString path = "/Game/BP/BulletBP.BulletBP_C";
	TSubclassOf<class AActor> sc = TSoftClassPtr<AActor>(FSoftObjectPath(*path)).LoadSynchronous();
	ABullet* SpawnBullet = (ABullet*)UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/Player/BulletBP.BulletBP_C");
	if (SpawnBullet != NULL)
	{
		//SpawnBullet->SetActorLocation(m_pSpringArm->GetRelativeLocation());
		SpawnBullet->Init(Start, End);
	}
}

// �y���̓o�C���h�z����
void APlayerChara::Input_Run()
{
	// �R���g���[���o���邩
	m_playerStatus.moveSpeed = m_statusConst.runSpeed;
	m_ActionStatus = EActionStatus::Run;
}

// �y���̓o�C���h�z�A�N�V����
void APlayerChara::Input_Action()
{
	if (m_pOverlapActor == NULL)
		return;

	if (Cast<ADoorBase>(m_pOverlapActor))
	{
		if (Cast<ADoorBase>(m_pOverlapActor)->GetIsLock())
		{
			m_playerFlags.flagBits.isOpenMenu = true;
		}
		return;
	}

	if (m_playerFlags.flagBits.isItemTouch == true)
	{
		for (int i = 0; i < m_ItemDatas.Num(); i++)
		{
			if (m_ItemDatas[i].type == ItemType::None)
			{
				m_ItemDatas[i] = Cast<AItemBase>(m_pOverlapActor)->GetItemData();

				AGunControl* OverlapGun = Cast<AGunControl>(m_pOverlapActor);
				if (OverlapGun)
				{
					m_playerFlags.flagBits.isHaveGun = true;
					m_playerStatus.equipGunData = Cast<AGunControl>(m_pOverlapActor)->GetGunData();
				}
				
				m_playerFlags.flagBits.isItemGet = true;
				UE_LOG(LogTemp, Error, TEXT("ItemGet"));
				break;
			}
		}
	}
}

void APlayerChara::Input_Reload()
{
	if (Cast<AGunControl>(m_pOverlapActor) == NULL)
		return;

	//Cast<AGunControl>(m_pOverlapActor)->Reload();
}

void APlayerChara::Input_Inventory()
{
	m_playerFlags.flagBits.isOpenMenu = !(m_playerFlags.flagBits.isOpenMenu);
	m_invenoryState = (m_playerFlags.flagBits.isOpenMenu) ? EInventoryState::Open : EInventoryState::Close;
}

void APlayerChara::Damage(int _atk)
{
	m_playerStatus.hp -= _atk;

	if (m_playerStatus.hp <= 0)
	{
		m_playerStatus.hp = 0;
	}
}

bool APlayerChara::GetIsDead()
{
	return (m_playerStatus.hp <= 0) ? true : false;
}