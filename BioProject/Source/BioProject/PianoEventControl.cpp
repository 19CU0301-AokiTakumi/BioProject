//---------------------------------------------------------------
// ファイル名	：BathtubEventControl.cpp
// 概要			：浴槽のイベントを行う
// 作成者		：青木拓洋
// 作成日		：2022年12月21日 青木拓洋 作成
// 更新履歴		：2022年12月21日 メッシュ、当たり判定の生成
//---------------------------------------------------------------

#include "PianoEventControl.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

// コンストラクタ
APianoEventControl::APianoEventControl()
	: m_Player(NULL)
	, SpawnItem(NULL)
	, m_index(0)
	, m_CountNumber(0)
	, m_bIsOpen(false)
	, m_bIsItemOnce(false)
	, m_bIsMusicHaveCheck(false)
{
	// 毎フレーム、このクラスのTick()を呼ぶかどうかを決めるフラグ
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USoundBase> C1_SE(TEXT("/Game/Sound/Piano/C1.C1"));
	ConstructorHelpers::FObjectFinder<USoundBase> D1_SE(TEXT("/Game/Sound/Piano/D1.D1"));
	ConstructorHelpers::FObjectFinder<USoundBase> E1_SE(TEXT("/Game/Sound/Piano/E1.E1"));
	ConstructorHelpers::FObjectFinder<USoundBase> F1_SE(TEXT("/Game/Sound/Piano/F1.F1"));
	ConstructorHelpers::FObjectFinder<USoundBase> G1_SE(TEXT("/Game/Sound/Piano/G1.G1"));
	ConstructorHelpers::FObjectFinder<USoundBase> A1_SE(TEXT("/Game/Sound/Piano/A1.A1"));
	ConstructorHelpers::FObjectFinder<USoundBase> B1_SE(TEXT("/Game/Sound/Piano/B1.B1"));
	ConstructorHelpers::FObjectFinder<USoundBase> C2_SE(TEXT("/Game/Sound/Piano/C2.C2"));

	m_PianoSEs[1] = C1_SE.Object;
	m_PianoSEs[2] = D1_SE.Object;
	m_PianoSEs[3] = E1_SE.Object;
	m_PianoSEs[4] = F1_SE.Object;
	m_PianoSEs[5] = G1_SE.Object;
	m_PianoSEs[6] = A1_SE.Object;
	m_PianoSEs[7] = B1_SE.Object;
}

// ゲーム開始時に呼ばれる処理
void APianoEventControl::BeginPlay()
{
	Super::BeginPlay();

	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &APianoEventControl::OnOverlapBegin);
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &APianoEventControl::OnOverlapEnd);
	}

	// プレイヤーの情報を格納
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// 毎フレームの処理
void APianoEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsOpen&& !m_bIsItemOnce)
		GetItem();
}

// オーバーラップ接触をし始めたときに呼ばれるイベント関数
void APianoEventControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 当たっているオブジェクトがプレイヤーだった場合
	if (Cast<APlayerChara>(OtherActor))
	{
		// バッグの中身を検索
		for (int i = 0; i < Cast<APlayerChara>(OtherActor)->GetPlayerBag().Num(); i++)
		{
			//  バッグの中身に本が入っていたらフラグを立てる
			if (Cast<APlayerChara>(OtherActor)->GetPlayerBag()[i].type == ItemType::MusicScore)
				(!m_bIsOpen) ? m_bIsMusicHaveCheck = true : m_bIsMusicHaveCheck = false;
		}
	}
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APianoEventControl::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// フラグを下げる
	m_bIsMusicHaveCheck = false;
	SetIsEventStart(false);
}

// キーボードが押された瞬間に呼ばれる関数
void APianoEventControl::InputKeybord(const int _index)
{
	if (!m_bIsMusicHaveCheck)
	{
		SetIsEventStart(false);
		return;
	}

	UGameplayStatics::PlaySound2D(GetWorld(), m_PianoSEs[_index]);

	if (m_CountNumber >= m_ArrayKeybord.Num() || m_bIsOpen)
		return;

	m_ArrayKeybord[m_CountNumber] = _index;

	KeyCheck();

	if (!KeyCheck())
	{
		m_CountNumber = 0;
		return;
	}

	if (m_CountNumber + 1 == m_ArrayKeybord.Num())
		m_bIsOpen = true;

	m_CountNumber++;
}

// 番号があっているかを判断する関数
bool APianoEventControl::KeyCheck()
{
	if (m_ArrayKeybord[m_CountNumber] == m_AnswerKeybord[m_CountNumber])
		return true;
	
	return false;
}

// アイテムをスポーンする関数
void APianoEventControl::GetItem()
{
	SpawnItem = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/BackyardKeyBP.BackyardKeyBP_C");

	if (SpawnItem)
	{
		m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SpawnItem->SetActorLocation(GetActorLocation());
		SpawnItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);

		m_bIsItemOnce = true;
		m_Player->SetIsOpenPianoWidget(false);
	}
}