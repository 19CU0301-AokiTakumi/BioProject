// Fill out your copyright notice in the Description page of Project Settings.


#include "GunControl.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "UObject/ConstructorHelpers.h"

// �R���X�g���N�^
AGunControl::AGunControl()
	: m_gunData(FGunData::NoneData())
	, m_pShotSE(NULL)
	, m_pMazzleFlashEffect(NULL)
	, m_fireRateCount(0.f)
	, m_bIsShot(false)
	, m_BulletLocation(NULL)
{
	ConstructorHelpers::FObjectFinder<USoundBase> ShotSE(TEXT("/Game/Sound/Bullet/HandGunSE.HandGunSE"));
	m_pShotSE = ShotSE.Object;

	m_BulletLocation = CreateDefaultSubobject<USceneComponent>(TEXT("m_BulletLocation"));
	m_BulletLocation->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UNiagaraSystem> MazzleFlashEffect(TEXT("/Game/niagara/personal_use/Mazzle_Flash/Mazzle_flash_2_System.Mazzle_flash_2_System"));
	m_pMazzleFlashEffect = MazzleFlashEffect.Object;
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
void AGunControl::Shot(FVector _playerPos)
{
	if (m_pShotSE)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pShotSE, GetActorLocation() + m_BulletLocation->GetRelativeLocation());

	FVector pos = _playerPos + m_BulletLocation->GetRelativeLocation();//FVector(_playerPos.X, _playerPos.Y, _playerPos.Z + m_BulletLocation->GetRelativeLocation().Z);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_pMazzleFlashEffect, _playerPos);
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

void AGunControl::SetCollisionEnabled(const bool _isEnable)
{
	if (m_pBoxComp)
		(_isEnable) ? m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly) : m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}