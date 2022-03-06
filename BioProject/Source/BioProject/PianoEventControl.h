//---------------------------------------------------------------
// ファイル名	：BathtubEventControl.h
// 概要			：浴槽のイベントを行う
// 作成者		：青木拓洋
// 作成日		：2022年12月21日 青木拓洋 作成
// 更新履歴		：2022年12月21日 メッシュ、当たり判定の生成
//---------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "Sound/SoundBase.h"
#include "PianoEventControl.generated.h"

// 前方宣言
class APlayerChara;

UCLASS()
class BIOPROJECT_API APianoEventControl : public AEventObjectBase
{
	GENERATED_BODY()

public:
	// コンストラクタ
	APianoEventControl();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
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
	APlayerChara* m_Player;		// プレイヤーを格納
	AActor* SpawnItem;			// スポーンさせるアイテムを格納

	int m_index;		// カーソルの位置を取得
	int m_CountNumber;	// イベントの回数をカウントする 
	int m_MaxNumber;	// イベントの最大の関数を設定

	bool m_bIsOpen;				// イベントを終えてるかを判断
	bool m_bIsItemOnce;			// アイテムを一度だけしか生成しないようにする
	//bool m_bIsMusicHaveCheck;	// 本がインベントリにあるかをチェック

	USoundBase* m_PianoSEs[8];

	void GetItem();		// アイテムをスポーンする関数
	bool KeyCheck();	// 番号があっているかを判断する関数

private:
	// プレイヤーが押しているキーボードを入れる
	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<int> m_ArrayKeybord;

	// 答えとなるキーボードを入れる
	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<int> m_AnswerKeybord;

public:
	// キーボードが押された瞬間に呼ばれる関数
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void InputKeybord(const int _index);

	// 押したキーボードの番号をゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "Getint", BlueprintPure)
		int GetPushNumber() { return m_CountNumber; }

	// イベントの回数をゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "Getint", BlueprintPure)
		int GetMaxNumber() { return m_ArrayKeybord.Num(); }

	// インベントリに本が入っているかをゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetScoreHaveCheck() { return m_bIsMusicHaveCheck; }

	bool m_bIsMusicHaveCheck;	// 本がインベントリにあるかをチェック
};
