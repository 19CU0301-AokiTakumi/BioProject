// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "SingleDoor.generated.h"

UCLASS()
class BIOPROJECT_API ASingleDoor : public ADoorBase
{
	GENERATED_BODY()
public:
	// コンストラクタ
	ASingleDoor();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

private:
	// 衝突判定用のコリジョン
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;

	// メッシュ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;

private:
	float m_angle;
	void OpenClose(float _deltaTime) override;
	void SideOpen(float _deltaTime);
	void FrontOpen(float _deltaTime);

	FRotator m_MeshRelativeRotation;
	FVector m_MeshRelativeLocation;
};

