//---------------------------------------------------------------
// ファイル名	：BathtubEventControl.h
// 概要			：浴槽のイベントを行う
// 作成者		：青木拓洋
// 作成日		：2022年12月21日 青木拓洋 作成
// 更新履歴		：2022年12月21日 メッシュ、当たり判定の生成
//				：2022年12月21日 イベント中の処理を追加
//				：2022年12月22日 ウィジェットの追加、サウンドの追加
//				：2022年12月24日 カーソルの追加
//---------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "BathtubEventControl.generated.h"

// 前方宣言
class APlayerChara;

UCLASS()
class BIOPROJECT_API ABathtubEventControl : public AEventObjectBase
{
	GENERATED_BODY()
	
public:
	// コンストラクタ
	ABathtubEventControl();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

private:
	APlayerChara* m_Player;		// プレイヤーを格納
	AActor* m_SpawnItem;		// スポーンさせるアイテムを格納

	int m_index;	// カーソルの位置を取得

	float m_WaterMeshLocation;	// 水のメッシュの初期位置
	float m_WaterShrink;		// 現在の縮小値

	bool m_WidgetOpen;			// ウィジェットが開いてるかを確認
	bool m_DoAction;			// イベント中かを判断
	bool m_ActionEnd;			// イベントを終えたか判断

	void DownWaterSurface(float _deltaTime);	// 水を下げる関数

public:
	void SetDoAction(bool _doAction) { m_DoAction = _doAction; }	// イベント中かどうかをセットする関数	
	void PlaySound();												// サウンドをならす関数

private:
	// メッシュの生成
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pWaterMesh;

	// 水を下げるスピードの設定
	UPROPERTY(EditAnywhere, Category = "Component")
		float m_downSpeed;

	// 移動値の最大を設定
	UPROPERTY(EditAnywhere, Category = "Component")
		float m_WaterMaxDown;

	// 縮小値量の設定
	UPROPERTY(EditAnywhere, Category = "Component")
		float m_downShrink;

	// サウンドの設定
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pWaterSE;

public:
	// プレイヤーが当たり判定内でEキーを押してるかをセットする関数
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetEventStart(const bool _eventStart) { m_bIsEventStart = _eventStart; }

	// プレイヤーが当たり判定内でEキーを押してるかをゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetEventStartCheck() { return m_bIsEventStart; }

	// ウィジェットを開くかどうかをセットする関数
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetOpenWidget(bool _widgetOpen) { m_WidgetOpen = _widgetOpen; }

	// ウィジェットを開くかどうかをゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetOpenWidget()const { return m_WidgetOpen; }

	// カーソルの位置をセットする関数
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIndex(const int _index) { m_index = _index; }

	// イベント中かどうかをゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetDoAction()const { return m_DoAction; }

	// イベントを終えたかどうかをゲットする関数
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetActionEnd()const { return m_ActionEnd; }
};