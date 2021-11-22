// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "GunAmmoControl.generated.h"

// 弾の種類
UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	None,	// 無
	Hand,	// ハンドガン
	Shot,	// ショットガン
	Max,	// 新しいのはこれより上に追加
};

// 弾のデータ
USTRUCT(BlueprintType)
struct FAmmoData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") EAmmoType ammoType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int ammoStock;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int ammoStockMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;

public:
	FAmmoData(const EAmmoType _ammoType = EAmmoType::None, const int _ammoStock = 0, const int _ammoStockMax = 0, const int _atk = 0)
	{
		ammoType = _ammoType;
		ammoStock = _ammoStock;
		ammoStockMax = _ammoStockMax;
		atk = _atk;
	}
	static FAmmoData NoneData() { return FAmmoData(); }
};

UCLASS()
class BIOPROJECT_API AGunAmmoControl : public AItemBase
{
	GENERATED_BODY()

public:
	// コンストラクタ
	AGunAmmoControl();

private:
	// 弾のデータ
	UPROPERTY(EditAnywhere, Category = "Data")
		FAmmoData m_ammoData;

public:
	// 弾のデータを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		FAmmoData GetAmmoData() const { return m_ammoData; }
};
