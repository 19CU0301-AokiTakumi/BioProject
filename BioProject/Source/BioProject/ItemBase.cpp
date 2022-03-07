
#include "ItemBase.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// コンストラクタ
AItemBase::AItemBase()
	: m_pBase(NULL)
	, m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_pOtherPlayer(NULL)
	, m_itemData(FItemData::NoneData())
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	RootComponent = m_pBase;

	//	コリジョン判定用ボックスコンポーネント生成
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pItemCollisionComp"));
	if (m_pBoxComp)
		m_pBoxComp->SetupAttachment(RootComponent);

	// メッシュ生成
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pItemMesh"));
	if (m_pMesh)
		m_pMesh->SetupAttachment(RootComponent);
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
	//if (m_pOtherPlayer && m_pOtherPlayer->IsGetItem())
	//{
	//	m_pOtherPlayer->SetIsGetItem(false);

	//	// 自分自身を消す
	//	Destroy();
	//}
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

FVector AItemBase::GetCenterPos() const 
{ 
	return m_pBoxComp->GetComponentLocation(); 
}

void AItemBase::SetCollisionEnabled(const bool _isEnable)
{
	if (m_pBoxComp)
		(_isEnable) ? m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly) : m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AItemBase::DestroyMesh()
{
	if (UMyGameInstance::GetActorFromTag(this, "OwnerRoomKey"))
	{
		APlayerChara* m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
		m_Player->SetIsGetItem(false);
		m_pMesh->SetVisibility(false);
		Destroy();
	}

	if (!UMyGameInstance::GetActorFromTag(this, "OwnerRoomKey"))
	{
		m_pMesh->SetVisibility(true);
	}
}
