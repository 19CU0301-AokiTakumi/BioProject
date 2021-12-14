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

// �R���X�g���N�^
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
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	// �G�t�F�N�g
	ConstructorHelpers::FObjectFinder<UNiagaraSystem> DamageEffect(TEXT("/Game/Effect/Blood/BloodSystem_02.BloodSystem_02"));
	m_pDamageEffect = DamageEffect.Object;

	// SE
	ConstructorHelpers::FObjectFinder<USoundBase> DamageSE(TEXT("/Game/Sound/BulletHitSE_Z.BulletHitSE_Z"));
	m_pDamageSE = DamageSE.Object;

	// �\���̃X�e�[�^�X�̏�����
	m_EnemyStatus = { 10,5,5,10,1000.f };

	// �A�j���[�V�������I��������Ԃ��i�[����z��̏�����
	for (int i = 0; i < (int)ActionStatus::Max; i++)
	{
		AnimEndFrame[i] = 0;
	}
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	
	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (GetCapsuleComponent() != NULL)
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyChara::OnOverlapBegin);
	}

	// �v���C���[�̏����i�[
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// ���t���[���X�V����
void AEnemyChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �X�e�[�^�X���Ǘ�����֐�
	UpdateAction(DeltaTime);

	// ���C���΂��֐�
	UpdateRay();

	// �A�^�b�N�A�j���[�V�������Đ����ꂽ��
	// �A�j���[�V�����̎��Ԃ����Z���Ă����֐�
	if(ReturnAttack())
		AddAtkAnimTime(DeltaTime);
}

void AEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �e���������Ă���ꍇ
	if (Cast<ABullet>(OtherActor))
	{
		// �G�t�F�N�g�̐���
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

		// SE�̐���
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

	// ���C�̏I�_��Actor����O�����̈�苗��
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

		// �R���W��������Ŗ������鍀�ڂ��w��i����͂���Actor�������g�Bthis�|�C���^�Ŏw��j
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		// �q�b�g�����i=�R���W����������󂯂��j�I�u�W�F�N�g���i�[����ϐ�
		FHitResult OutHit;

		// ���C���΂��A�I�u�W�F�N�g�ɑ΂��ăR���W����������s��
		// isHit�́A�q�b�g�����ꍇ��true�ɂȂ�
		bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, m_BodyCollisionPos, End2, ECC_WorldStatic, CollisionParams);

		// �q�b�g����I�u�W�F�N�g������ꍇ
		if (isHit)
		{
			// ���q�b�g����Actor���A�ۑ����ꂽ�q�b�gActor�ƈႤ�ꍇ
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

// �ړ�����
void AEnemyChara::Move(float _deltaTime)
{
	// �����ƃ^�[�Q�b�g�̋������擾
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
// �A�j���[�V�����J��
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