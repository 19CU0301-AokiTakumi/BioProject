// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"
#include "typeinfo"

// コンストラクタ
ADoorBase::ADoorBase()
	: m_pBase(NULL)
	, m_pRootBoxComp(NULL)
	, m_pFrontBoxComp(NULL)
	, m_pBackBoxComp(NULL)
	, m_DoorState(State::Idle)
	, m_speed(100.f)
	, m_bIsLock(false)
	, m_id(-1)
	, m_bIsOpenReverse(false)
	, m_bIsOverlapPlayer(false)
	, m_pDoorOpenSE(NULL)
	, m_pDoorCloseSE(NULL)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	// ベースの追加
	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	RootComponent = m_pBase;

	// 衝突判定用のボックスコンポーネント生成
	m_pRootBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MainCollision"));
	m_pRootBoxComp->SetupAttachment(RootComponent);
	

	// オーバーラップ用のボックスコンポーネント生成(前面)
	m_pFrontBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("FrontCollision"));
	m_pFrontBoxComp->SetupAttachment(RootComponent);

	// オーバーラップ用のボックスコンポーネント生成(背面)
	m_pBackBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BackCollision"));
	m_pBackBoxComp->SetupAttachment(RootComponent);

	// ドア開音
	ConstructorHelpers::FObjectFinder<USoundBase> DoorOpenSE(TEXT("/Game/Sound/Door/DoorOpenSE.DoorOpenSE"));
	m_pDoorOpenSE = DoorOpenSE.Object;

	// ドア閉音
	ConstructorHelpers::FObjectFinder<USoundBase> DoorCloseSE(TEXT("/Game/Sound/Door/DoorCloseSE.DoorCloseSE"));
	m_pDoorCloseSE = DoorCloseSE.Object;
}

// ゲーム開始時、または生成時に呼ばれる処理
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();

	// オーバーラップしたら呼ばれる関数を登録
	if (m_pRootBoxComp != NULL)
	{
		m_pRootBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
		m_pRootBoxComp->OnComponentEndOverlap.AddDynamic(this, &ADoorBase::OnOverlapEnd);
	}
	// オーバーラップしたら呼ばれる関数を登録
	if (m_pFrontBoxComp != NULL)
	{
		m_pFrontBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
		m_pFrontBoxComp->OnComponentEndOverlap.AddDynamic(this, &ADoorBase::OnOverlapEnd);
	}

	if (m_pBackBoxComp != NULL)
	{
		m_pBackBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
		m_pBackBoxComp->OnComponentEndOverlap.AddDynamic(this, &ADoorBase::OnOverlapEnd);
	}

	m_pRootBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// 毎フレーム更新処理
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 開閉処理
	OpenClose(DeltaTime);
}

// オーバーラップ接触をし始めたときに呼ばれるイベント関数
void ADoorBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 当たったオブジェクトのTag名が"Player"だった時に処理する
	if (OtherActor->ActorHasTag("Player"))
	{
		// 開いている状態でないとき開ける準備に入る
		if (m_DoorState != State::Open && m_bIsLock == false)
		{
			OpenSetup();
		}
	}
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void ADoorBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// プレイヤーと離れたらフラグをおろす
	if (OtherActor->ActorHasTag("Player"))
	{
		m_bIsOverlapPlayer = false;
	}
}

// 閉めてよいかを判断する
void ADoorBase::CheckClose(float _deltaTime)
{
	// 待機(開いてる)状態 かつ プレイヤーが触れていないとき
	if (m_DoorState == State::CloseWait && m_bIsOverlapPlayer == false)
	{
		// 時間のカウント
		m_countTime += _deltaTime;

		// 設定した時間が経過したら閉める準備に入る
		if (m_closeTime < m_countTime)
		{
			m_DoorState = State::Close;
			m_countTime = 0.f;
		}
	}
	// プレイヤーが触れたらカウントを初期化
	else
	{
		m_countTime = 0.f;
	}
}

void ADoorBase::OpenSetup()
{
	// コリジョンを一旦無効化
	m_pFrontBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_pBackBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	m_DoorState = State::Open;
	m_pRootBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorOpenSE, GetActorLocation());
	m_bIsOverlapPlayer = true;
	m_countTime = 0.f;
}