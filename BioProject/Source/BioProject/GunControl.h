// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "GunControl.generated.h"

// 銃の種類
UENUM(BlueprintType)
enum class EGunType : uint8
{
	None,	// 無
	Hand,	// ハンドガン
	Shot,	// ショットガン
	Max,	// 新しいのはこれより上に追加
};

// 銃のデータ
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
	// コンストラクタ
	AGunControl();

public:
	// 更新処理
	void CheckFireRate(float _deltaTime);

private:
	// 銃のデータ
	UPROPERTY(EditAnywhere, Category = "Data")
		FGunData m_gunData;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pShotSE;

	float m_fireRateCount;

	bool m_bIsShot;

public:
	// 銃のデータを渡す
	FGunData GetGunData() const { return m_gunData; }

	// 銃のデータをセットする
	void SetGunData(const FGunData _gunData) { m_gunData = _gunData; }

	void RemoveAmmo(const int _removeValue) { m_gunData.ammoStock -= _removeValue; }

	// 撃つ
	void Shot();

	// リロード処理
	void Reload(int& _ammoStock);

	void SetIsShot(const bool _isShot) { m_bIsShot = _isShot; }

	bool GetIsShot() const { return m_bIsShot; }
};
