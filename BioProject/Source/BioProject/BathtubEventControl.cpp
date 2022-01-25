//---------------------------------------------------------------
// �t�@�C����	�FBathtubEventControl.cpp
// �T�v			�F�����̃C�x���g���s��
// �쐬��		�F�ؑ�m
// �쐬��		�F2022�N12��21�� �ؑ�m �쐬
// �X�V����		�F2022�N12��21�� ���b�V���A�����蔻��̐���
//				�F2022�N12��21�� �C�x���g���̏�����ǉ�
//				�F2022�N12��22�� �E�B�W�F�b�g�̒ǉ��A�T�E���h�̒ǉ�
//				�F2022�N12��24�� �J�[�\���̒ǉ�
//---------------------------------------------------------------

#include "BathtubEventControl.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

// �R���X�g���N�^
ABathtubEventControl::ABathtubEventControl()
	: m_pWaterMesh(NULL)
	, m_SpawnItem(NULL)
	, m_downSpeed(1.f)
	, m_WaterShrink(1.f)
	, m_WaterMeshLocation(0.f)
	, m_WaterMaxDown(0.f)
	, m_downShrink(0.f)
	, m_WidgetOpen(false)
	, m_DoAction(false)
	, m_ActionEnd(false)
	, m_index(0)
{
	// ���t���[���A���̃N���X��Tick()���ĂԂ��ǂ��������߂�t���O
	PrimaryActorTick.bCanEverTick = true;

	// ���b�V���𐶐�
	m_pWaterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pWaterMesh"));
	if (m_pWaterMesh)
		m_pWaterMesh->SetupAttachment(RootComponent);

	// SE�̐���
	ConstructorHelpers::FObjectFinder<USoundBase> WaterSE(TEXT("/Game/Sound/Ambient/haisui.haisui"));
	m_pWaterSE = WaterSE.Object;
}

// �Q�[���J�n���ɌĂ΂�鏈��
void ABathtubEventControl::BeginPlay()
{
	Super::BeginPlay();

	// �A�C�e�����X�|�[��������
	m_SpawnItem = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/OwnerRoomKeyBP.OwnerRoomKeyBP_C");
	m_SpawnItem->SetActorLocation(GetActorLocation());
	m_SpawnItem->SetActorEnableCollision(ECollisionEnabled::NoCollision);

	// ���𓮂����O�̈ʒu����ۊǂ��A�ړ��ʂ�ݒ�
	m_WaterMeshLocation = m_pWaterMesh->GetRelativeLocation().Z;
	m_WaterMaxDown += m_WaterMeshLocation;

	// �v���C���[�̏����i�[
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// ���t���[���̏���
void ABathtubEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �E�B�W�F�b�g���J�����ǂ���
	if (GetEventStartCheck() && !m_DoAction)
		SetOpenWidget(true);

	// �C�x���g���I��莟��A�E�B�W�F�b�g�����
	if (m_DoAction)
		SetOpenWidget(false);

	// �C�x���g�����ǂ���
	if (m_DoAction && m_WaterMeshLocation >= m_WaterMaxDown)
	{
		DownWaterSurface(DeltaTime);
	}

	// �v���C���[�̃i�C�t����������(����̓v���C���[��)
	m_Player->KnifeVisible(GetDoAction(), GetActionEnd());
}

// �C�x���g��
void ABathtubEventControl::DownWaterSurface(float _deltaTime)
{
	// �J�[�\�����������ɂȂ��Ă���ꍇ
	if (m_index != 0)
	{
		m_bIsEventStart = false;
		m_DoAction = false;
		return;
	}
	
	// �C�x���g���s���R���W������؂�
	m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// �ړ�
	m_WaterMeshLocation -= m_downSpeed * _deltaTime;
	m_pWaterMesh->SetRelativeLocation(FVector(m_pWaterMesh->GetRelativeLocation().X, m_pWaterMesh->GetRelativeLocation().Y, m_WaterMeshLocation));

	// �k��
	m_WaterShrink -= m_downShrink * _deltaTime;
	m_pWaterMesh->SetRelativeScale3D(FVector(m_WaterShrink, m_WaterShrink, m_pWaterMesh->GetRelativeScale3D().Z));

	// �C�x���g���I�����ꍇ
	if (m_WaterMeshLocation <= m_WaterMaxDown)
	{
		// �C�x���g���I�����t���O�𗧂Ă�
		m_ActionEnd = true;	

		// �A�C�e���̓����蔻�������
		m_SpawnItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);
	}
}

// �T�E���h
void ABathtubEventControl::PlaySound()
{
	// ����炷
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pWaterSE, FVector(-1820.f, -1320.f, 40.f));
}