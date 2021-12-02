// Fill out your copyright notice in the Description page of Project Settings.


#include "GunControl.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

// コンストラクタ
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

// 毎フレーム更新処理
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

// 撃つ
void AGunControl::Shot(AActor* _actor)
{
	if (m_pShotSE)
		UGameplayStatics::PlaySoundAtLocation(_actor->GetWorld(), m_pShotSE, FVector::ZeroVector);
}

// リロード処理
void AGunControl::Reload(int& _ammoStock)
{
	// 弾薬数が0以下の場合は処理しない
	if (_ammoStock <= 0)
		return;

	// 既に弾が補充されている場合は処理しない
	if (m_gunData.ammoStock >= m_gunData.ammoStockMax)
		return;

	// 所持している弾薬からリロード分を引く
	_ammoStock -= m_gunData.ammoStockMax - m_gunData.ammoStock;

	// 弾薬が足りた場合
	if (_ammoStock >= 0)
	{
		// 最大量まで増やす
		m_gunData.ammoStock = m_gunData.ammoStockMax;
	}
	// 弾薬が足りなかった場合
	else
	{
		// 最大量から足りなかった分を引いた数を代入
		m_gunData.ammoStock = m_gunData.ammoStockMax + _ammoStock;

		// 弾薬数が0未満にならないよう補完
		_ammoStock = 0;
	}
}