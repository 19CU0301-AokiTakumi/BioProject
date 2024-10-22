// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PlayerChara.h"
#include "EnemyChara.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABullet::ABullet()
	: m_pBoxComp(NULL)
	, m_pAllBlockComp(NULL)
	, m_pPlayer(NULL)
	, m_speed(500.f)
	, m_Time(0.f)
	, m_Atk(0)
	, m_DestroyCount(0.f)
	, m_isDestroy(false)
	, m_MoveDir(FVector::ZeroVector)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//	コリジョン判定用ボックスコンポーネント生成
	m_pBoxComp = CreateDefaultSubobject<USphereComponent>(TEXT("m_pCollisionComp"));
	RootComponent = m_pBoxComp;

	m_pAllBlockComp = CreateDefaultSubobject<USphereComponent>(TEXT("m_pAllBlockComp"));
	m_pAllBlockComp->SetupAttachment(RootComponent);
}
// Called when the game starts or when spawned
void ABullet::Init(FVector startPoint, FVector endPoint)
{
	// 初期位置の設定
	SetActorLocation(startPoint);

	// 進行方向の計算
	// 発射地点とレイの終着点の差分から、進行方向を計算
	m_MoveDir = endPoint - startPoint;	// 差分
	m_MoveDir.Normalize();
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlapBegin);
	}

	m_pAllBlockComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	BulletMove(DeltaTime);

	m_Count += DeltaTime;

	if (m_Count < 0.01f)
		m_pAllBlockComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (m_Count > 0.1f)
		Destroy();
}

void ABullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (m_isDestroy)
		return;

	if (Cast<AEnemyChara>(OtherActor))
	{
		if (OtherComp->ComponentHasTag("EnemyComp"))
		{
			if (OtherComp->ComponentTags.Num() >= 2)
			{
				FName CompName = OtherComp->ComponentTags[1];
				Cast<AEnemyChara>(OtherActor)->Damage(this, m_Atk, CompName);
			}
		}
	}
}

void ABullet::BulletMove(float _deltaTime)
{
	m_Time += _deltaTime;
	//SetActorLocation(FVector(GetActorLocation().X - m_Time, GetActorLocation().Y, GetActorLocation().Z));

	m_pPlayer = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));

	if (m_pPlayer != NULL)
	{
		// 進行方向に自分自身を移動させる
		SetActorLocation(GetActorLocation() + ( m_MoveDir * m_speed + _deltaTime ) );
	}
}

void ABullet::SetIsDestoy(bool _isHit)
{
	m_isDestroy = _isHit;
}