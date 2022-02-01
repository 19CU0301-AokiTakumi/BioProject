// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"
#include "typeinfo"

// �R���X�g���N�^
ADoorBase::ADoorBase()
	: m_pBase(NULL)
	, m_pRootBoxComp(NULL)
	, m_pFrontBoxComp(NULL)
	, m_pBackBoxComp(NULL)
	, m_DoorState(State::Idle)
	, m_speed(100.f)
	, m_bIsLock(false)
	, m_id(-1)
	, m_bIsOpenReverse(false)
	, m_bIsOverlapPlayer(false)
	, m_pDoorOpenSE(NULL)
	, m_pDoorCloseSE(NULL)
{
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	// �x�[�X�̒ǉ�
	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	RootComponent = m_pBase;

	// �Փ˔���p�̃{�b�N�X�R���|�[�l���g����
	m_pRootBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MainCollision"));
	m_pRootBoxComp->SetupAttachment(RootComponent);
	

	// �I�[�o�[���b�v�p�̃{�b�N�X�R���|�[�l���g����(�O��)
	m_pFrontBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("FrontCollision"));
	m_pFrontBoxComp->SetupAttachment(RootComponent);

	// �I�[�o�[���b�v�p�̃{�b�N�X�R���|�[�l���g����(�w��)
	m_pBackBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BackCollision"));
	m_pBackBoxComp->SetupAttachment(RootComponent);

	// �h�A�J��
	ConstructorHelpers::FObjectFinder<USoundBase> DoorOpenSE(TEXT("/Game/Sound/Door/DoorOpenSE.DoorOpenSE"));
	m_pDoorOpenSE = DoorOpenSE.Object;

	// �h�A��
	ConstructorHelpers::FObjectFinder<USoundBase> DoorCloseSE(TEXT("/Game/Sound/Door/DoorCloseSE.DoorCloseSE"));
	m_pDoorCloseSE = DoorCloseSE.Object;
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();

	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pRootBoxComp != NULL)
	{
		m_pRootBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
		m_pRootBoxComp->OnComponentEndOverlap.AddDynamic(this, &ADoorBase::OnOverlapEnd);
	}
	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pFrontBoxComp != NULL)
	{
		m_pFrontBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
		m_pFrontBoxComp->OnComponentEndOverlap.AddDynamic(this, &ADoorBase::OnOverlapEnd);
	}

	if (m_pBackBoxComp != NULL)
	{
		m_pBackBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
		m_pBackBoxComp->OnComponentEndOverlap.AddDynamic(this, &ADoorBase::OnOverlapEnd);
	}

	m_pRootBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// ���t���[���X�V����
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �J����
	OpenClose(DeltaTime);
}

// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
void ADoorBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ���������I�u�W�F�N�g��Tag����"Player"���������ɏ�������
	if (OtherActor->ActorHasTag("Player"))
	{
		// �J���Ă����ԂłȂ��Ƃ��J���鏀���ɓ���
		if (m_DoorState != State::Open && m_bIsLock == false)
		{
			OpenSetup();
		}
	}
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void ADoorBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// �v���C���[�Ɨ��ꂽ��t���O�����낷
	if (OtherActor->ActorHasTag("Player"))
	{
		m_bIsOverlapPlayer = false;
	}
}

// �߂Ă悢���𔻒f����
void ADoorBase::CheckClose(float _deltaTime)
{
	// �ҋ@(�J���Ă�)��� ���� �v���C���[���G��Ă��Ȃ��Ƃ�
	if (m_DoorState == State::CloseWait && m_bIsOverlapPlayer == false)
	{
		// ���Ԃ̃J�E���g
		m_countTime += _deltaTime;

		// �ݒ肵�����Ԃ��o�߂�����߂鏀���ɓ���
		if (m_closeTime < m_countTime)
		{
			m_DoorState = State::Close;
			m_countTime = 0.f;
		}
	}
	// �v���C���[���G�ꂽ��J�E���g��������
	else
	{
		m_countTime = 0.f;
	}
}

void ADoorBase::OpenSetup()
{
	// �R���W��������U������
	m_pFrontBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_pBackBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	m_DoorState = State::Open;
	m_pRootBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorOpenSE, GetActorLocation());
	m_bIsOverlapPlayer = true;
	m_countTime = 0.f;
}