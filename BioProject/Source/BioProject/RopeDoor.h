// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SingleDoor.h"
#include "RopeDoor.generated.h"

UCLASS()
class BIOPROJECT_API ARopeDoor : public ASingleDoor
{
	GENERATED_BODY()

public:
	ARopeDoor();

//protected:
//	// ゲーム開始時、または生成時に呼ばれる処理
//	virtual void BeginPlay() override;
//
//public:
//	// 毎フレーム呼更新処理
//	virtual void Tick(float DeltaTime) override;

protected:
	// メッシュの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_RopeMesh;

	// オーバーラップ用のコリジョン(背面)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_RopeComp;

public:
	void HitKnife();
};
