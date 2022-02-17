// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ACamera::ACamera()
	:m_pCameraArm(NULL)
	, m_speed(1.0f)
	, m_pFollowCamera(NULL)
	, m_Base(NULL)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Base = CreateDefaultSubobject<USceneComponent>(TEXT("Base"));

	if (m_Base != NULL)
	{
		RootComponent = m_Base;
	}

	// �X�v�����O�A�[���̃I�u�W�F�N�g�𐶐�
	m_pCameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("m_pCameraArm"));

	// �����Ɛ����o���Ă��邩�m�F
	if (m_pCameraArm != NULL)
	{
		m_pCameraArm->SetupAttachment(RootComponent);

		// �A�[���̒�����ݒ�
		m_pCameraArm->TargetArmLength = 300.0f;

		// �J�����A�[���𓮂����邩�ǂ���
		m_pCameraArm->bUsePawnControlRotation = true;
	}

	// �J�����̃I�u�W�F�N�g�𐶐�
	m_pFollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("m_pFollowCamera"));

	// �����Ɛ����o���Ă��邩�ǂ���
	if (m_pFollowCamera != NULL)
	{
		// �J�����̃X�v�����O�A�[���ɃA�^�b�`������
		m_pFollowCamera->SetupAttachment(m_pCameraArm, USpringArmComponent::SocketName);
	}

}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

