//---------------------------------------------------------------
// ファイル名	：BathtubEventControl.cpp
// 概要			：浴槽のイベントを行う
// 作成者		：青木拓洋
// 作成日		：2022年12月21日 青木拓洋 作成
// 更新履歴		：2022年12月21日 メッシュ、当たり判定の生成
//				：2022年12月21日 イベント中の処理を追加
//				：2022年12月22日 ウィジェットの追加、サウンドの追加
//				：2022年12月24日 カーソルの追加
//---------------------------------------------------------------

#include "BathtubEventControl.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

// コンストラクタ
ABathtubEventControl::ABathtubEventControl()
	: m_pWaterMesh(NULL)
	, m_SpawnItem(NULL)
	, m_downSpeed(1.f)
	, m_WaterShrink(1.f)
	, m_WaterMeshLocation(0.f)
	, m_WaterMaxDown(0.f)
	, m_downShrink(0.f)
	, m_WidgetOpen(false)
	, m_DoAction(false)
	, m_ActionEnd(false)
	, m_index(0)
{
	// 毎フレーム、このクラスのTick()を呼ぶかどうかを決めるフラグ
	PrimaryActorTick.bCanEverTick = true;

	// メッシュを生成
	m_pWaterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pWaterMesh"));
	if (m_pWaterMesh)
		m_pWaterMesh->SetupAttachment(RootComponent);

	// SEの生成
	ConstructorHelpers::FObjectFinder<USoundBase> WaterSE(TEXT("/Game/Sound/Ambient/haisui.haisui"));
	m_pWaterSE = WaterSE.Object;
}

// ゲーム開始時に呼ばれる処理
void ABathtubEventControl::BeginPlay()
{
	Super::BeginPlay();

	// アイテムをスポーンさせる
	m_SpawnItem = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/OwnerRoomKeyBP.OwnerRoomKeyBP_C");
	m_SpawnItem->SetActorLocation(GetActorLocation());
	m_SpawnItem->SetActorEnableCollision(ECollisionEnabled::NoCollision);

	// 水を動かす前の位置情報を保管し、移動量を設定
	m_WaterMeshLocation = m_pWaterMesh->GetRelativeLocation().Z;
	m_WaterMaxDown += m_WaterMeshLocation;

	// プレイヤーの情報を格納
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// 毎フレームの処理
void ABathtubEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ウィジェットを開くかどうか
	if (GetEventStartCheck() && !m_DoAction)
		SetOpenWidget(true);

	// イベントが終わり次第、ウィジェットを閉じる
	if (m_DoAction)
		SetOpenWidget(false);

	// イベント中かどうか
	if (m_DoAction && m_WaterMeshLocation >= m_WaterMaxDown)
	{
		DownWaterSurface(DeltaTime);
	}

	// プレイヤーのナイフを消す処理(判定はプレイヤー側)
	m_Player->KnifeVisible(GetDoAction(), GetActionEnd());
}

// イベント中
void ABathtubEventControl::DownWaterSurface(float _deltaTime)
{
	// カーソルがいいえになっている場合
	if (m_index != 0)
	{
		m_bIsEventStart = false;
		m_DoAction = false;
		return;
	}
	
	// イベントを行うコリジョンを切る
	m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 移動
	m_WaterMeshLocation -= m_downSpeed * _deltaTime;
	m_pWaterMesh->SetRelativeLocation(FVector(m_pWaterMesh->GetRelativeLocation().X, m_pWaterMesh->GetRelativeLocation().Y, m_WaterMeshLocation));

	// 縮小
	m_WaterShrink -= m_downShrink * _deltaTime;
	m_pWaterMesh->SetRelativeScale3D(FVector(m_WaterShrink, m_WaterShrink, m_pWaterMesh->GetRelativeScale3D().Z));

	// イベントを終えた場合
	if (m_WaterMeshLocation <= m_WaterMaxDown)
	{
		// イベントを終えたフラグを立てる
		m_ActionEnd = true;	

		// アイテムの当たり判定をつける
		m_SpawnItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);
	}
}

// サウンド
void ABathtubEventControl::PlaySound()
{
	// 音を鳴らす
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pWaterSE, FVector(-1820.f, -1320.f, 40.f));
}