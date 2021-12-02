// Fill out your copyright notice in the Description page of Project Settings.


#include "GunControl.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

// �R���X�g���N�^
AGunControl::AGunControl()
	: m_gunData(FGunData::NoneData())
	, m_pShotSE(NULL)
	, m_fireRateCount(0.f)
	, m_bIsShot(false)
	, m_BulletLocation(NULL)
{
	ConstructorHelpers::FObjectFinder<USoundBase> ShotSE(TEXT("/Game/Sound/HandGunSE.HandGunSE"));
	m_pShotSE = ShotSE.Object;

	m_BulletLocation = CreateDefaultSubobject<USceneComponent>(TEXT("m_BulletLocation"));
	m_BulletLocation->SetupAttachment(RootComponent);
}

// ���t���[���X�V����
void AGunControl::CheckFireRate(float _deltaTime)
{
	if (m_bIsShot == false)
		return;

	m_fireRateCount += _deltaTime;
	if (m_gunData.fireRate <= m_fireRateCount)
	{
		m_bIsShot = false;
		m_fireRateCount = 0.f;
	}
}

// ����
void AGunControl::Shot(AActor* _actor)
{
	if (m_pShotSE)
		UGameplayStatics::PlaySoundAtLocation(_actor->GetWorld(), m_pShotSE, FVector::ZeroVector);
}

// �����[�h����
void AGunControl::Reload(int& _ammoStock)
{
	// �e�򐔂�0�ȉ��̏ꍇ�͏������Ȃ�
	if (_ammoStock <= 0)
		return;

	// ���ɒe����[����Ă���ꍇ�͏������Ȃ�
	if (m_gunData.ammoStock >= m_gunData.ammoStockMax)
		return;

	// �������Ă���e�򂩂烊���[�h��������
	_ammoStock -= m_gunData.ammoStockMax - m_gunData.ammoStock;

	// �e�򂪑��肽�ꍇ
	if (_ammoStock >= 0)
	{
		// �ő�ʂ܂ő��₷
		m_gunData.ammoStock = m_gunData.ammoStockMax;
	}
	// �e�򂪑���Ȃ������ꍇ
	else
	{
		// �ő�ʂ��瑫��Ȃ���������������������
		m_gunData.ammoStock = m_gunData.ammoStockMax + _ammoStock;

		// �e�򐔂�0�����ɂȂ�Ȃ��悤�⊮
		_ammoStock = 0;
	}
}