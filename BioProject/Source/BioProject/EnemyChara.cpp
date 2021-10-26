// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyChara.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerChara.h"

// Sets default values
AEnemyChara::AEnemyChara()
	: m_BoxBase(NULL)
	, m_EnemyMesh(NULL)
	, m_OverLapComp(NULL)
	, m_Player(NULL)
	, m_Speed(0.f)
	, m_StopCount(0.f)
	, m_ToTheGround(0.f)
	, m_ToTheGroundCount(0.f)
	, m_HP(0.f)
	, m_MoveStop(false)
	, m_Ground(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ベースをルートにアタッチ
	m_BoxBase = CreateDefaultSubobject<UBoxComponent>(TEXT("m_BoxBase"));
	RootComponent = m_BoxBase;

	// メッシュをつける
	m_EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_EnemyMesh"));
	m_EnemyMesh->SetupAttachment(m_BoxBase);

	// コリジョン判定用ボックスコンポーネント生成
	m_OverLapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_OverLapComp"));
	m_OverLapComp->SetupAttachment(m_BoxBase);
}

// Called when the game starts or when spawned
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	
	// オーバーラップしたら呼ばれる関数を登録
	if (m_OverLapComp != NULL)
	{
		m_OverLapComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyChara::OnOverlapBegin);
	}
}

// Called every frame
void AEnemyChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AfterSpawn(DeltaTime);

	// 移動処理
	/*if (m_Ground)*/
	EnemyMove(DeltaTime);

	if (m_MoveStop)
		StopTime(DeltaTime);
}

// Called to bind functionality to input
void AEnemyChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (Cast<APlayerChara>(OtherActor))
	//{
	//	m_MoveStop = true;
	//}

	//if (Cast<ABullet>(OtherActor))
	//{
	//	m_MoveStop = true;
	//	m_HP--;
	//}
}

// 移動処理
void AEnemyChara::EnemyMove(float _deltaTime)
{
	if (m_MoveStop)
		return;

	//m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));

	//// 自分とターゲットの距離を取得
	//float TargetDistanceX = m_Player->GetActorLocation().X - GetActorLocation().X;
	//float TargetDistanceY = m_Player->GetActorLocation().Y - GetActorLocation().Y;

	//float angle = atan2(-TargetDistanceX, TargetDistanceY);

	//float angleDeg = FMath::RadiansToDegrees(angle) + 90.f;

	//SetActorRotation(FRotator(0, angleDeg, 0));

	//AddActorWorldOffset(GetActorForwardVector() * m_Speed * _deltaTime);
}

void AEnemyChara::StopTime(float _deltaTime)
{
	m_StopCount += _deltaTime;

	if (m_StopCount > 1.f)
	{
		m_StopCount = 0.f;
		m_MoveStop = false;
	}

	if (m_HP <= 0)
	{
		Destroy();
	}
}

void AEnemyChara::AfterSpawn(float _deltaTime)
{
	if (m_ToTheGroundCount == 0.f)
	{
		m_ToTheGroundCount = GetActorLocation().Z;
	}

	if (m_ToTheGround < m_ToTheGroundCount)
	{
		m_ToTheGroundCount -= 1000 * _deltaTime;
		SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, m_ToTheGroundCount));
	}
	else
	{
		m_Ground = true;
	}
}