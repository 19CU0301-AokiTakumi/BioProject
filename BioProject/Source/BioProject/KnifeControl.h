// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "KnifeControl.generated.h"

USTRUCT(BlueprintType)
struct FKnifeData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;				// 攻撃力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float coolTime;		// 攻撃の間隔

public:
	FKnifeData(const int _atk = 0, const float _coolTime = 0.f)
		: atk(_atk)
		, coolTime(_coolTime)
	{}
	static FKnifeData NoneData() { return FKnifeData(0, 0.f); }
};

UCLASS()
class BIOPROJECT_API AKnifeControl : public AItemBase
{
	GENERATED_BODY()

public:
	AKnifeControl();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

private:
	// オーバーラップ接触をし始めたときに呼ばれるイベント関数
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	void SetCollisionEnabled(const bool _isEnable) override;
	void SetAttckColEnable(const bool _isEnable);
	FKnifeData GetKnifeData() const { return m_KnifeData; }
	void SetKnifeData(const FKnifeData _knifeData) { m_KnifeData = _knifeData; }

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBladeBoxComp;

	UPROPERTY(EditAnywhere, Category = "Data")
		FKnifeData m_KnifeData;
};
