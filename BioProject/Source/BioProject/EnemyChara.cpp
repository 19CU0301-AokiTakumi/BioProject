// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyChara.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerChara.h"
#include "Bullet.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemyChara::AEnemyChara()
	: m_Mesh(NULL)
	, m_Player(NULL)
	, m_Speed(0.f)
	, m_Count(0.f)
	, m_HP(0.f)
	, m_status(Status::Idle)
	, m_ReduceOnce(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// メッシュをつける
	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_EnemyMesh"));
	m_Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	
	// オーバーラップしたら呼ばれる関数を登録
	if (GetCapsuleComponent() != NULL)
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyChara::OnOverlapBegin);
	}
}

// Called every frame
void AEnemyChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAction(DeltaTime);
}

// Called to bind functionality to input
void AEnemyChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerChara>(OtherActor))
		m_status = Status::Attack;

	if (Cast<ABullet>(OtherActor))
		m_status = Status::KnockBack;
}

void AEnemyChara::UpdateAction(float _deltaTime)
{
	switch (m_status)
	{
	case Status::Idle:
		Idle(_deltaTime);
		break;

	case Status::Move:
		Move(_deltaTime);
		break;

	case Status::Attack:
		Attack(_deltaTime);
		break;

	case Status::Avoid:
		Avoid(_deltaTime);
		break;

	case Status::KnockBack:
		KnockBack(_deltaTime);
		break;

	default:
		break;
	}
}

void AEnemyChara::Idle(float _deltaTime)
{
	m_Count += _deltaTime;

	if (m_Count > 5.f)
	{
		m_Count = 0.f;
		m_status = Status::Move;
	}
}

// 移動処理
void AEnemyChara::Move(float _deltaTime)
{
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));

	// 自分とターゲットの距離を取得
	float TargetDistanceX = m_Player->GetActorLocation().X - GetActorLocation().X;
	float TargetDistanceY = m_Player->GetActorLocation().Y - GetActorLocation().Y;

	float angle = atan2(-TargetDistanceX, TargetDistanceY);

	float angleDeg = FMath::RadiansToDegrees(angle) + 90.f;

	SetActorRotation(FRotator(0, angleDeg, 0));

	AddActorWorldOffset(GetActorForwardVector() * m_Speed * _deltaTime);

	// レイを飛ばす
	// レイの始点はActorの位置
	FVector Start = GetActorLocation();
	// レイの終点はActorから前方向の一定距離
	FVector End = GetActorLocation() + m_Mesh->GetForwardVector() * 300.f;

	//// デバッグ確認用のラインを描画
	DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 1.0f);

	// コリジョン判定で無視する項目を指定（今回はこのActor自分自身。thisポインタで指定）
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	// ヒットした（=コリジョン判定を受けた）オブジェクトを格納する変数
	FHitResult OutHit;

	// レイを飛ばし、オブジェクトに対してコリジョン判定を行う
	// isHitは、ヒットした場合にtrueになる
	bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_WorldStatic, CollisionParams);

	// ヒットするオブジェクトがある場合
	if (isHit)
	{
		// 今ヒットしたActorが、保存されたヒットActorと違う場合
		if (OutHit.GetActor()->ActorHasTag("Player"))
			m_status = Status::Attack;
	}
}

void AEnemyChara::Attack(float _deltaTime)
{

}

void AEnemyChara::Avoid(float _deltaTime)
{

}

void AEnemyChara::KnockBack(float _deltaTime)
{
	m_Count += _deltaTime;

	if (m_Count > 2.f)	// 2.fはアニメーションの時間（後で変更）
	{
		m_ReduceOnce = true;
	}

	if (m_ReduceOnce == true)
	{
		m_HP--;

		if (m_HP <= 0)
		{
			Destroy();
		}

		m_Count = 0.f;
		m_ReduceOnce = false;
		m_status = Status::Move;
	}
}