// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyChara.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerChara.h"
#include "Bullet.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

// コンストラクタ
AEnemyChara::AEnemyChara()
	: m_Player(NULL)
	, m_pDamageEffect(NULL)
	, m_pDamageSE(NULL)
	, m_AnimCount(0.f)
	, m_AtkAnimCount(0.f)
	, m_SearchArea(0.f)
	, m_AtkStartTime(0.f)
	, m_AtkEndTime(0.f)
	, m_bIsAttack(true)
	, m_IsDown(false)
	, m_status(ActionStatus::Idle)
	, m_BodyCollisionPos(FVector::ZeroVector)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	// エフェクト
	ConstructorHelpers::FObjectFinder<UNiagaraSystem> DamageEffect(TEXT("/Game/Effect/Blood/BloodSystem_02.BloodSystem_02"));
	m_pDamageEffect = DamageEffect.Object;

	// SE
	ConstructorHelpers::FObjectFinder<USoundBase> DamageSE(TEXT("/Game/Sound/BulletHitSE_Z.BulletHitSE_Z"));
	m_pDamageSE = DamageSE.Object;

	// 構造体ステータスの初期化
	m_EnemyStatus = { 10,5,5,10,1000.f };

	// アニメーションが終わった時間を格納する配列の初期化
	for (int i = 0; i < (int)ActionStatus::Max; i++)
	{
		AnimEndFrame[i] = 0;
	}
}

// ゲーム開始時、または生成時に呼ばれる処理
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	
	// オーバーラップしたら呼ばれる関数を登録
	if (GetCapsuleComponent() != NULL)
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyChara::OnOverlapBegin);
	}

	// プレイヤーの情報を格納
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// 毎フレーム更新処理
void AEnemyChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ステータスを管理する関数
	UpdateAction(DeltaTime);

	// レイを飛ばす関数
	UpdateRay();

	// アタックアニメーションが再生されたら
	// アニメーションの時間を加算していく関数
	if(ReturnAttack())
		AddAtkAnimTime(DeltaTime);
}

void AEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 弾が当たっている場合
	if (Cast<ABullet>(OtherActor))
	{
		// エフェクトの生成
		if (m_pDamageEffect)
		{
			for (int i = 0; i < 10; ++i)
			{
				float offsetX = FMath::FRandRange(-10.f, 10.f);
				float offsetY = FMath::FRandRange(-10.f, 10.f);
				float offsetZ = FMath::FRandRange(-10.f, 10.f);

				FVector SpawnLocation = FVector(OtherActor->GetActorLocation().X + offsetX, OtherActor->GetActorLocation().Y + offsetY, OtherActor->GetActorLocation().Z + offsetZ);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_pDamageEffect, SpawnLocation, GetMesh()->GetRelativeRotation());
			}
		}

		// SEの生成
		if (m_pDamageSE)
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDamageSE, GetActorLocation());
	}
}

void AEnemyChara::UpdateRay()
{
	if (!m_bIsAttack && m_AtkAnimCount > 0.f)
		return;

	if (m_status != ActionStatus::Move && m_status != ActionStatus::Attack)
		return;

	if (m_Player->GetIsDead())
		return;

	// レイの終点はActorから前方向の一定距離
	FVector End = GetMesh()->GetForwardVector() * m_SearchArea;

	for (int i = 0; i < 7; i++)
	{
		int fanangle = 120;
		fanangle -= i * 10;

		float radTheta = FMath::DegreesToRadians(fanangle);
		float X = End.X * cos(radTheta) - End.Y * sin(radTheta);
		float Y = End.X * sin(radTheta) + End.Y * cos(radTheta);
		FVector End2 = FVector(X, Y, End.Z) + GetActorLocation();

		// DrawDebugLine(GetWorld(), m_BodyCollisionPos, End2, FColor::Blue, false, 1.0f);

		// コリジョン判定で無視する項目を指定（今回はこのActor自分自身。thisポインタで指定）
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		// ヒットした（=コリジョン判定を受けた）オブジェクトを格納する変数
		FHitResult OutHit;

		// レイを飛ばし、オブジェクトに対してコリジョン判定を行う
		// isHitは、ヒットした場合にtrueになる
		bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, m_BodyCollisionPos, End2, ECC_WorldStatic, CollisionParams);

		// ヒットするオブジェクトがある場合
		if (isHit)
		{
			// 今ヒットしたActorが、保存されたヒットActorと違う場合
			if (OutHit.GetActor()->ActorHasTag("Player"))
			{
				m_status = ActionStatus::Attack;
				m_bIsAttack = true;
				break;
			}
		}
		else
		{
			m_bIsAttack = false;
		}
	}
}

void AEnemyChara::Damage(AActor* Bullet, const int _atk, FName _compName)
{
	if (_compName == "Head")
	{
		m_EnemyStatus.knockBackPoint -= _atk + m_HeadShotOfSet;
	}
	else if (_compName == "Body")
	{
		m_EnemyStatus.knockBackPoint -= _atk;
	}
	else
	{
		(_atk / 2 < 1) ? m_EnemyStatus.knockBackPoint -= 1 : m_EnemyStatus.knockBackPoint -= _atk / 2;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("knockBackPoint = %d"), m_EnemyStatus.knockBackPoint));

	if (m_EnemyStatus.knockBackPoint <= 0)
	{
		int DamagePoint = -m_EnemyStatus.knockBackPoint / m_EnemyStatus.maxDownPoint;

		if (DamagePoint <= 0)
			DamagePoint = 1;

		m_EnemyStatus.hp -= DamagePoint;

		(m_EnemyStatus.hp > 0) ? m_status = ActionStatus::KnockBack : m_status = ActionStatus::Death;

		int overDownPoint = -m_EnemyStatus.knockBackPoint % m_EnemyStatus.maxDownPoint;
		m_EnemyStatus.knockBackPoint = m_EnemyStatus.maxDownPoint;
		m_EnemyStatus.knockBackPoint -= overDownPoint;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("hp = %d,knockBackPoint = %d"), m_EnemyStatus.hp, m_EnemyStatus.knockBackPoint));
	}

	Cast<ABullet>(Bullet)->SetIsDestoy(true);
}

void AEnemyChara::DownPoint()
{
	m_DownCount++;

	if (m_DownCount <= 2)
		return;

	m_DownCount = 0;

	if(m_status!=ActionStatus::Death)
		m_status = ActionStatus::Down;
}

void AEnemyChara::UpdateAction(float _deltaTime)
{
	switch (m_status)
	{
	case ActionStatus::Idle:
		Idle();
		break;

	case ActionStatus::Move:
		Move(_deltaTime);
		break;

	case ActionStatus::Attack:
		Attack();
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)ActionStatus::Attack])
		{
			m_status = ActionStatus::Move;
			m_AtkAnimCount = 0.f;
			m_AnimCount = 0.f;
		}
		break;

	case ActionStatus::KnockBack:
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)ActionStatus::KnockBack])
		{
			m_status = ActionStatus::Move;

			if (m_AtkAnimCount > 0.f)
				m_AtkAnimCount = 0.f;

			m_AnimCount = 0.f;
		}
		break;

	case ActionStatus::Down:
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)ActionStatus::Down])
		{
			m_status = ActionStatus::StandUp;
			m_AnimCount = 0.f;
		}
		break;

	case ActionStatus::StandUp:
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)ActionStatus::StandUp])
		{
			m_status = ActionStatus::Move;
			m_AnimCount = 0.f;
		}
		break;

	default:
		break;
	}
}

void AEnemyChara::Idle()
{
	m_status = ActionStatus::Move;
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
}

void AEnemyChara::Attack()
{
	if (m_AtkAnimCount >= m_AtkStartTime && m_AtkAnimCount <= m_AtkEndTime)
	{
		if (m_bIsAttack)
		{
			m_Player->Damage(m_EnemyStatus.atk);
			m_bIsAttack = false;
		}
	}
}

void AEnemyChara::AddAtkAnimTime(float _deltaTime)
{
	m_AtkAnimCount += _deltaTime;
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

bool AEnemyChara::ReturnStandUp()
{
	if (m_status == ActionStatus::StandUp)
	{
		return true;
	}
	return false;
}

bool AEnemyChara::ReturnDown()
{
	if (m_status == ActionStatus::Down)
	{
		return true;
	}
	return false;
}