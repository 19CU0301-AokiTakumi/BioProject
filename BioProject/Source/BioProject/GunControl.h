// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "GunControl.generated.h"

// �e�̎��
UENUM(BlueprintType)
enum class EGunType : uint8
{
	None,	// ��
	Hand,	// �n���h�K��
	Shot,	// �V���b�g�K��
	Max,	// �V�����̂͂������ɒǉ�
};

// �e�̃f�[�^
USTRUCT(BlueprintType)
struct FGunData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") EGunType gunType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int ammoStock;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int ammoStockMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float fireRate;

public:
	FGunData(const EGunType _gunType = EGunType::None, const int _ammoStock = 0, const int _ammoStockMax = 0, const int _atk = 0, const float _fireRate = 0.f)
		: gunType(_gunType)
		, ammoStock(_ammoStock)
		, ammoStockMax(_ammoStockMax)
		, atk(_atk)
		, fireRate(_fireRate)
	{
	}
	static FGunData NoneData() { return FGunData(); }
};

UCLASS()
class BIOPROJECT_API AGunControl : public AItemBase
{
	GENERATED_BODY()
	
public:
	// �R���X�g���N�^
	AGunControl();

public:
	// �X�V����
	void CheckFireRate(float _deltaTime);

private:
	// �e�̃f�[�^
	UPROPERTY(EditAnywhere, Category = "Data")
		FGunData m_gunData;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pShotSE;

	float m_fireRateCount;

	bool m_bIsShot;

public:
	// �e�̃f�[�^��n��
	FGunData GetGunData() const { return m_gunData; }

	// �e�̃f�[�^���Z�b�g����
	void SetGunData(const FGunData _gunData) { m_gunData = _gunData; }

	void RemoveAmmo(const int _removeValue) { m_gunData.ammoStock -= _removeValue; }

	// ����
	void Shot();

	// �����[�h����
	void Reload(int& _ammoStock);

	void SetIsShot(const bool _isShot) { m_bIsShot = _isShot; }

	bool GetIsShot() const { return m_bIsShot; }
};
