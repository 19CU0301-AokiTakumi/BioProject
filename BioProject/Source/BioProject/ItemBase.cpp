
#include "ItemBase.h"
#include "PlayerChara.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// コンストラクタ
AItemBase::AItemBase()
	: m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_pOtherPlayer(NULL)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	// メッシュ生成
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pItemMesh"));

	//	コリジョン判定用ボックスコンポーネント生成
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pItemCollisionComp"));
	m_pBoxComp->SetupAttachment(m_pMesh);
}

// ゲーム開始時、または生成時に呼ばれる処理
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlapBegin);
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &AItemBase::OnOverlapEnd);
	}
}

// 毎フレーム更新処理
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// プレイヤーが「自身から離れていない」かつ「アクションキーを入力している」場合
	if (m_pOtherPlayer && m_pOtherPlayer->IsGetItem())
	{
		// 自分自身を消す
		Destroy();
	}
}

// オーバーラップ接触をし始めたときに呼ばれるイベント関数
void AItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 当たったアクターを保管
	m_pOtherPlayer = Cast<APlayerChara>(OtherActor);
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void AItemBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// プレイヤーと離れたら保管しているプレイヤー情報を初期化
	if (Cast<APlayerChara>(OtherActor))
		m_pOtherPlayer = NULL;
}
