// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "GunControl.generated.h"

UENUM(BlueprintType)
enum class EGunType : uint8
{
	None,
	Hand,
	Shot,
	Max,
};

USTRUCT(BlueprintType)
struct FGunData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") EGunType gunType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int ammoStock;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int ammoStockMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;

public:
	FGunData(const EGunType _gunType = EGunType::Hand, const int _ammoStock = 0, const int _ammoStockMax = 0, const int _atk = 0)
	{
		gunType = _gunType;
		ammoStock = _ammoStock;
		ammoStockMax = _ammoStockMax;
		atk = _atk;
	}
	static FGunData NoneData() { return FGunData(); }
};

UCLASS()
class BIOPROJECT_API AGunControl : public AItemBase
{
	GENERATED_BODY()
	
public:
	AGunControl();

private:
	UPROPERTY(EditAnywhere, Category = "Data")
		FGunData m_gunData;

public:
	FGunData GetGunData() const { return m_gunData; }

	void Shot();

	void Reload(int _playerHaveAmmo);
};
