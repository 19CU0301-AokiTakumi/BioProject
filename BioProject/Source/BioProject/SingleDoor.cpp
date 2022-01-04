// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleDoor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

// �R���X�g���N�^
ASingleDoor::ASingleDoor()
	: m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_angle(0.f)
	, m_MeshRelativeRotation(FRotator::ZeroRotator)
	, m_MeshRelativeLocation(FVector::ZeroVector)
{
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	// ���b�V������
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pDoorMesh"));
	m_pMesh->SetupAttachment(RootComponent);

	// �Փ˔���p�̃{�b�N�X�R���|�[�l���g����
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pDoorCollisionComp"));
	m_pBoxComp->SetupAttachment(m_pMesh);
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void ASingleDoor::BeginPlay()
{
	Super::BeginPlay();

	// �h�A�̎�ނɂ���ď����l��ύX
	if (m_IsSlide)
	{
		m_MeshRelativeLocation = m_pMesh->GetRelativeLocation();
		m_angle = m_MeshRelativeLocation.Y;
	}
	else
	{
		m_MeshRelativeRotation = m_pMesh->GetRelativeRotation();
		m_angle = m_pMesh->GetRelativeRotation().Yaw;
	}
}

// ���t���[���X�V����
void ASingleDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ���J���̃h�A�̊J����
void ASingleDoor::SideOpen(float _deltaTime)
{
	switch (m_DoorState)
	{
		case State::Idle:
			return;
			break;

		case State::Open:
			if (m_angle >= 138.f + m_MeshRelativeLocation.Y)
			{
				m_DoorState = State::CloseWait;
				return;
			}

			m_angle += m_speed * _deltaTime;
			break;

		case State::Close:
			if (m_angle <= 0.f + m_MeshRelativeLocation.Y)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorCloseSE, GetActorLocation());
				m_DoorState = State::Idle;
				return;
			}
			m_angle -= m_speed * _deltaTime;
			break;

		default:
			break;
	}
	m_pMesh->SetRelativeLocation(FVector(m_MeshRelativeLocation.X, m_angle, m_MeshRelativeLocation.Z));
}

// ���J���̃h�A�̊J����
void ASingleDoor::FrontOpen(float _deltaTime)
{
	switch (m_DoorState)
	{
		case State::Idle:
			m_pFrontBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			m_pBackBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			break;

		case State::Open:
			if (m_angle >= 90 + m_MeshRelativeRotation.Yaw)
			{
				m_DoorState = State::CloseWait;
				return;
			}

			m_angle += m_speed * _deltaTime;
			break;

		case State::Close:
			if (m_angle <= 0 + m_MeshRelativeRotation.Yaw)
			{
				m_DoorState = State::Idle;
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorCloseSE, GetActorLocation());
				return;
			}

			m_angle -= m_speed * _deltaTime;
			break;

		default:
			break;
	}
	float offset = (m_bIsOpenReverse) ? -1.f : 1.f;
	m_pMesh->SetRelativeRotation(FRotator(m_MeshRelativeRotation.Pitch, m_angle * offset, m_MeshRelativeRotation.Roll));
}

// ����ނ̃h�A�̊J�������܂Ƃ߂����\�b�h
void ASingleDoor::OpenClose(float _deltaTime)
{
	// �����������Ă���Ώ������Ȃ�
	if (m_bIsLock)
		return;

	// �h�A��߂ėǂ����̃`�F�b�N
	CheckClose(_deltaTime);

	// ���J���h�A�ݒ�̂Ƃ�
	if (m_IsSlide)
	{
		SideOpen(_deltaTime);
	}
	// ���J���h�A�ݒ�̂Ƃ�
	else
	{
		FrontOpen(_deltaTime);
	}
}

