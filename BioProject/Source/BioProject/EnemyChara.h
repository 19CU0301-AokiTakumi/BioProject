// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyChara.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class UBoxComponent;
class APlayerChara;
class UNiagaraSystem;

UENUM(BlueprintType)
enum class ActionStatus : uint8
{
	Idle,		// 待機
	Move,		// 移動
	Attack,		// 攻撃
	Avoid,		// 回避
	KnockBack,	// ノックバック
	StandUp,	// スタンドアップ
	Down,		// ダウン
	Death,		// 死亡
	Max,		// ステータスの数を数える
};

USTRUCT(BlueprintType)
struct FEnemyStatus
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// 現在のHP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxDownPoint;		// 最大ダウンカウント
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int knockBackPoint;		// ノックバックカウント
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;					// 攻撃
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// 移動速度

public:
	FEnemyStatus(const int _hp = 0, const int _maxDownPoint = 0, const int _knockBackPoint = 0, const int _atk = 0, const float _moveSpeed = 0.f)
		: hp(_hp)
		, maxDownPoint(_maxDownPoint)
		, knockBackPoint(knockBackPoint)
		, atk(_atk)
		, moveSpeed(_moveSpeed)
	{}
	static FEnemyStatus ZeroStatus() { return FEnemyStatus(0, 0, 0, 0, 0.f); }
};

UCLASS()
class BIOPROJECT_API AEnemyChara : public ACharacter
{
	GENERATED_BODY()

public:
	// コンストラクタ
	AEnemyChara();

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

private:
	// レイの長さ（扇形当たり判定の長さ）
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_SearchArea;

	// アニメーションの終わる時間を格納
	UPROPERTY(EditAnywhere, Category = "Status")
		float AnimEndFrame[(int)ActionStatus::Max];

	// ステータスを保管
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FEnemyStatus m_EnemyStatus;

	// ヘッドショット倍率
	UPROPERTY(EditAnywhere, Category = "Status")
		int m_HeadShotOfSet;

	// アタックアニメーションの当たり判定を始める
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_AtkStartTime;

	// アタックアニメーションの当たり判定を終える
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_AtkEndTime;

	// レイの始点
	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
		FVector m_BodyCollisionPos;

	// ダウン中かどうか
	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool m_IsDown;

	UPROPERTY(EditAnywhere, Category = "Status")
		float m_LengthDis;

private:
	// エフェクト
	UPROPERTY(EditAnywhere, Category = "Effects")
		UNiagaraSystem* m_pDamageEffect;

	// SE
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pDamageSE;

private:
	// オブジェクト
	APlayerChara* m_Player;		// プレイヤーを格納
	ActionStatus m_status;		// ステータスを格納

	// 整数
	int m_DownCount;	// ダウンするまでをカウントする

	// 実数
	float m_AnimCount;			// アニメーションをカウントする
	float m_AtkAnimCount;		// アタックアニメーションが始まったらカウントする

	// フラグ
	bool m_bIsAttack;	// 攻撃可能かどうか

	// アップデート関数
	void UpdateAction(float _deltaTime);	// ステータスを管理する
	void UpdateRay();						// レイを飛ばす

	// ステータス関数
	void Idle();					// 待機
	void Move(float _deltaTime);	// 移動
	void Attack();					// 攻撃

	void AddAtkAnimTime(float _deltaTime);	// アタックアニメーションが始まったら呼ばれる関数

public:
	void Damage(AActor* Bullet, const int _atk, FName _compName);	// ダメージを受ける

public:
	// エネミーのステータスを渡す
	UFUNCTION(BlueprintCallable, CateGory = "EnemyState", BlueprintPure)
		FEnemyStatus GetEnemyStatus() const { return m_EnemyStatus; }

	// ダウン回数をカウント
	UFUNCTION(BlueprintCallable, CateGory = "EnemyState")
		void DownPoint();

public:
	// アニメーション用
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnWalk();			// 歩きアニメーション

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnDeath();			// 死亡アニメーション

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnKnockBack();		// ノックバックアニメーション

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnAttack();		// アタックアニメーション

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnDown();			// ダウンアニメーション

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnStandUp();		// スタンドアップアニメーション
};
