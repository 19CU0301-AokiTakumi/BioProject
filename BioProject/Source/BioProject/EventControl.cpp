// -----------------------------------------
// ファイル名	：EventControl.h
// 概要			：イベントを制御するプログラム
// 作成者		：森下雄太
// 作成日		：2021年7月3日
// 更新履歴		：2021年7月3日　
//------------------------------------------

#include "EventControl.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "EnemyManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEventControl::AEventControl()
	: id(0)
	, PlayerHit(false)
	, m_pBase(NULL)
	, m_pBoxComp(NULL)
	, SpawnOnce(false)
	, m_pSpawnPoint(NULL)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ベースの追加
	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	RootComponent = m_pBase;

	/*for (int i = 0; i < m_SpawnNum; ++i)
	{
		FString s = "SpawnPoint" + FString::FromInt(i);
		m_pSpawnPoint.Add(CreateDefaultSubobject<USceneComponent>(FName(*s)));
		m_pSpawnPoint[i]->SetupAttachment(m_pBase);
	}*/

	m_pSpawnPoint = (CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint")));
	m_pSpawnPoint->SetupAttachment(m_pBase);

	// コリジョン判定用ボックスコンポーネント生成
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	m_pBoxComp->SetupAttachment(m_pBase);

	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEventControl::OnOverlapBegin);
	}
	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &AEventControl::OnOverlapEnd);
	}
}

// Called when the game starts or when spawned
void AEventControl::BeginPlay()
{
	Super::BeginPlay();


	m_SpawnLocationLength = m_SpawnLocation.Num();
	UE_LOG(LogTemp, Error, TEXT("%d"), m_SpawnLocationLength);
}

// Called every frame
void AEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEventControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerChara>(OtherActor))
	{
		PlayerHit = true;
	}
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void AEventControl::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<APlayerChara>(OtherActor))
	{
		PlayerHit = false;
	}
}

int AEventControl::SendId()
{
	return id;
}