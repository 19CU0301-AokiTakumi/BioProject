// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyChara.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerChara.h"
#include "Bullet.h"
#include "DrawDebugHelpers.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AEnemyChara::AEnemyChara()
	: m_Mesh(NULL)
	, m_Player(NULL)
	, m_Count(0.f)
	, m_status(ActionStatus::Idle)
	, m_SearchArea(0.f)
	, m_pDamageEffect(NULL)
{

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// メッシュをつける
	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_EnemyMesh"));
	m_Mesh->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UNiagaraSystem> DamageEffect(TEXT("/Game/Effect/Blood/BloodSystem_02.BloodSystem_02"));
	m_pDamageEffect = DamageEffect.Object;

	m_EnemyStatus = { 10,10,10,1000.f };
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

	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// Called every frame
void AEnemyChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAction(DeltaTime);
}

void AEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ABullet>(OtherActor))
	{
		if (m_pDamageEffect)
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_pDamageEffect, GetActorLocation(), GetMesh()->GetRelativeRotation());

		m_EnemyStatus.hp--;
		(m_EnemyStatus.hp > 0) ? m_status = ActionStatus::KnockBack : m_status = ActionStatus::Death;
	}
}

void AEnemyChara::UpdateAction(float _deltaTime)
{
	switch (m_status)
	{
	case ActionStatus::Idle:
		Idle(_deltaTime);
		break;

	case ActionStatus::Move:
		Move(_deltaTime);
		break;

	case ActionStatus::Attack:
		Attack(_deltaTime);
		break;

	case ActionStatus::Avoid:
		Avoid(_deltaTime);
		break;

	case ActionStatus::KnockBack:
		KnockBack(_deltaTime);
		break;

	case ActionStatus::Death:
		Death(_deltaTime);
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
		m_status = ActionStatus::Move;
	}
}

// 移動処理
void AEnemyChara::Move(float _deltaTime)
{
	// 自分とターゲットの距離を取得
	float TargetDistanceX = m_Player->GetActorLocation().X - GetActorLocation().X;
	float TargetDistanceY = m_Player->GetActorLocation().Y - GetActorLocation().Y;

	float angle = atan2(-TargetDistanceX, TargetDistanceY);

	float angleDeg = FMath::RadiansToDegrees(angle) + 90.f;

	SetActorRotation(FRotator(0, angleDeg, 0));

	AddActorWorldOffset(GetActorForwardVector() * m_EnemyStatus.moveSpeed * _deltaTime);

	// レイを飛ばす
	// レイの始点はActorの位置
	FVector Start = GetActorLocation();
	// レイの終点はActorから前方向の一定距離
	FVector End = m_Mesh->GetForwardVector() * m_SearchArea;

	for (int i = 0; i < 7; i++)
	{
		int fanangle = 30;
		fanangle -= i * 10;

		if (fanangle <= 0)
		{
			fanangle += 360;
		}

		float radTheta = FMath::DegreesToRadians(fanangle);
		float X = End.X * cos(radTheta) - End.Y * sin(radTheta);
		float Y = End.X * sin(radTheta) + End.Y * cos(radTheta);
		FVector End2 = FVector(X, Y, End.Z) + GetActorLocation();

		DrawDebugLine(GetWorld(), Start, End2, FColor::Blue, false, 1.0f);

		// コリジョン判定で無視する項目を指定（今回はこのActor自分自身。thisポインタで指定）
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		// ヒットした（=コリジョン判定を受けた）オブジェクトを格納する変数
		FHitResult OutHit;

		// レイを飛ばし、オブジェクトに対してコリジョン判定を行う
		// isHitは、ヒットした場合にtrueになる
		bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End2, ECC_WorldStatic, CollisionParams);

		// ヒットするオブジェクトがある場合
		if (isHit)
		{
			// 今ヒットしたActorが、保存されたヒットActorと違う場合
			if (OutHit.GetActor()->ActorHasTag("Player"))
				m_status = ActionStatus::Attack;
		}
	}
}

void AEnemyChara::Attack(float _deltaTime)
{
	m_Count += _deltaTime;

	if (m_Count > 2.f)	// 2.9fはアニメーションの時間（後で変更）
	{
		m_Player->Damage(m_EnemyStatus.atk);
		m_status = ActionStatus::Idle;
		m_Count = 0.f;
	}
}

void AEnemyChara::Avoid(float _deltaTime)
{

}

void AEnemyChara::KnockBack(float _deltaTime)
{
	m_Count += _deltaTime;

	if (m_Count > 2.4f)	// 2.fはアニメーションの時間（後で変更）
	{
		m_status = ActionStatus::Move;
		m_Count = 0.f;
	}
}

void AEnemyChara::Death(float _deltaTime)
{
	m_Count += _deltaTime;

	if (m_Count > 2.9f)	// 2.9fはアニメーションの時間（後で変更）
	{
		Destroy();
		m_Count = 0.f;
	}
}

//---------------------------------------
// アニメーション遷移
//---------------------------------------
bool AEnemyChara::ReturnWalk()
{
	// UE_LOG(LogTemp, Error, TEXT("aaaaaaa"));
	if (m_status == ActionStatus::Move)
	{
		return true;
	}
	return false;
}

bool AEnemyChara::ReturnAttack()
{
	if (m_status == ActionStatus::Attack)
	{
		return true;
	}
	return false;
}

bool AEnemyChara::ReturnKnockBack()
{
	if (m_status == ActionStatus::KnockBack)
	{
		return true;
	}
	return false;
}

bool AEnemyChara::ReturnDeath()
{
	if (m_status == ActionStatus::Death)
	{
		return true;
	}
	return false;
}