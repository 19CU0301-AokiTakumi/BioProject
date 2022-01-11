// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "BookEventControl.generated.h"

UCLASS()
class BIOPROJECT_API ABookEventControl : public AEventObjectBase
{
	GENERATED_BODY()
	
public:
	ABookEventControl();

protected:
	// 初期化
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

protected:
	// オーバーラップ接触をし始めたときに呼ばれるイベント関数
	UFUNCTION() virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// オーバーラップ接触をし終えたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	UPROPERTY(EditAnywhere, Category = "Data")
		float m_MoveSpeed;

	UPROPERTY(EditAnywhere, Category = "Data")
		float m_MaxMove;

private:
	bool m_bIsBookCheck;

	void OpenBookShelf(float _deltaTime);
};
