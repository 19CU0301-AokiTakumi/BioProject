// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

// 前方宣言
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class BIOPROJECT_API ADoorBase : public AActor
{
	GENERATED_BODY()

protected:
	// 扉の状態
	enum class State
	{
		Idle,		// 待機(閉じてる)状態
		Open,		// 開いてる最中
		CloseWait,	// 待機(開いてる)状態
		Close,		// 閉じてる最中
	};

public:
	// コンストラクタ
	ADoorBase();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

private:
	// オーバーラップ接触をし始めたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// オーバーラップ接触をし終えたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	// ベースの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		USceneComponent* m_pBase;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pDoorSE;

protected:
	// 開閉処理の判定用のコリジョン
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pRootBoxComp;

	// オーバーラップ用のコリジョン(前面)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pFrontBoxComp;

	// オーバーラップ用のコリジョン(背面)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBackBoxComp;

	// 鍵がかかっているか
	UPROPERTY(EditAnywhere, Category = "State")
		bool m_bIsLock;

	// 扉が奥に開くか
	bool m_bIsOpenReverse;

	// 開閉速度
	UPROPERTY(EditAnywhere, Category = "State")
		float m_speed;

	// 扉の状態
	State m_DoorState;

	// 自身のID
	UPROPERTY(EditAnywhere, Category = "State")
		int m_id;

	// 開閉時の時間のカウント用
	float m_countTime;

	// 閉まり始めるまでの時間
	UPROPERTY(EditAnywhere, Category = "State")
		float m_closeTime;

	// 横開きの扉か
	UPROPERTY(EditAnywhere, Category = "State")
		bool m_IsSlide;

	// プレイヤーが触れているか
	bool m_bIsOverlapPlayer;

protected:
	// 開閉処理
	virtual void OpenClose(float _deltaTime) {};

	// 閉めてよいかを判断する
	void CheckClose(float _deltaTime);

public:
	// 鍵がかかっているかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool", BlueprintPure)
		bool GetIsLock() const { return m_bIsLock; }

	// 鍵の状態を変更する
	UFUNCTION(BlueprintCallable, CateGory = "SetBool")
		void SetIsLock(const bool _isLock) { m_bIsLock = _isLock; }

	// 自身のIDを渡す
	int GetID()const { return m_id; }

	// 開く方向を設定する
	void SetOpenReverse(bool _isBack) { m_bIsOpenReverse = _isBack; }
};