// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyEnemyChara.h"
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

// Sets default values
AKeyEnemyChara::AKeyEnemyChara()
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
	, m_status(KeyEnemyActionStatus::Idle)
	, m_BodyCollisionPos(FVector::ZeroVector)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �G�t�F�N�g
	ConstructorHelpers::FObjectFinder<UNiagaraSystem> DamageEffect(TEXT("/Game/Effect/Blood/BloodSystem_02.BloodSystem_02"));
	m_pDamageEffect = DamageEffect.Object;

	// SE
	ConstructorHelpers::FObjectFinder<USoundBase> DamageSE(TEXT("/Game/Sound/Bullet/BulletHitSE_Z.BulletHitSE_Z"));
	m_pDamageSE = DamageSE.Object;

	// �\���̃X�e�[�^�X�̏�����
	m_KeyEnemyStatus = { 10,5,5,10,1000.f };

	// �A�j���[�V�������I��������Ԃ��i�[����z��̏�����
	for (int i = 0; i < (int)KeyEnemyActionStatus::Max; i++)
	{
		AnimEndFrame[i] = 0;
	}
}

// Called when the game starts or when spawned
void AKeyEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	
	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (GetCapsuleComponent() != NULL)
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AKeyEnemyChara::OnOverlapBegin);
	}

	// �v���C���[�̏����i�[
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// Called every frame
void AKeyEnemyChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �X�e�[�^�X���Ǘ�����֐�
	UpdateAction(DeltaTime);

	// ���C���΂��֐�
	UpdateRay();

	// �A�^�b�N�A�j���[�V�������Đ����ꂽ��
	// �A�j���[�V�����̎��Ԃ����Z���Ă����֐�
	if (ReturnAttack())
		AddAtkAnimTime(DeltaTime);
}

void AKeyEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �e���������Ă���ꍇ
	if (Cast<ABullet>(OtherActor))
	{
		// �G�t�F�N�g�̐���
		if (m_pDamageEffect)
		{
			FVector SpawnLocation = FVector(OtherActor->GetActorLocation().X, OtherActor->GetActorLocation().Y, OtherActor->GetActorLocation().Z);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_pDamageEffect, SpawnLocation, GetMesh()->GetRelativeRotation());
		}

		// SE�̐���
		if (m_pDamageSE)
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDamageSE, GetActorLocation());
	}
}

void AKeyEnemyChara::UpdateRay()
{
	if (!m_bIsAttack && m_AtkAnimCount > 0.f)
		return;

	if (m_status != KeyEnemyActionStatus::Move && m_status != KeyEnemyActionStatus::Attack)
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

		DrawDebugLine(GetWorld(), m_BodyCollisionPos, End2, FColor::Blue, false, 1.0f);

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
				m_status = KeyEnemyActionStatus::Attack;
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

void AKeyEnemyChara::Damage(AActor* Bullet, const int _atk, FName _compName)
{
	if (_compName == "Head")
	{
		m_KeyEnemyStatus.knockBackPoint -= _atk + m_HeadShotOfSet;
	}
	else if (_compName == "Body")
	{
		m_KeyEnemyStatus.knockBackPoint -= _atk;
	}
	else
	{
		(_atk / 2 < 1) ? m_KeyEnemyStatus.knockBackPoint -= 1 : m_KeyEnemyStatus.knockBackPoint -= _atk / 2;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("knockBackPoint = %d"), m_KeyEnemyStatus.knockBackPoint));

	if (m_KeyEnemyStatus.knockBackPoint <= 0)
	{
		int DamagePoint = -m_KeyEnemyStatus.knockBackPoint / m_KeyEnemyStatus.maxDownPoint;

		if (DamagePoint <= 0)
			DamagePoint = 1;

		m_KeyEnemyStatus.hp -= DamagePoint;

		(m_KeyEnemyStatus.hp > 0) ? m_status = KeyEnemyActionStatus::KnockBack : m_status = KeyEnemyActionStatus::Death;

		int overDownPoint = -m_KeyEnemyStatus.knockBackPoint % m_KeyEnemyStatus.maxDownPoint;
		m_KeyEnemyStatus.knockBackPoint = m_KeyEnemyStatus.maxDownPoint;
		m_KeyEnemyStatus.knockBackPoint -= overDownPoint;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("hp = %d,knockBackPoint = %d"), m_KeyEnemyStatus.hp, m_KeyEnemyStatus.knockBackPoint));
	}

	Cast<ABullet>(Bullet)->SetIsDestoy(true);
}

void AKeyEnemyChara::DownPoint()
{
	m_DownCount++;

	if (m_DownCount <= 2)
		return;

	m_DownCount = 0;

	if (m_status != KeyEnemyActionStatus::Death)
		m_status = KeyEnemyActionStatus::Down;
}

void AKeyEnemyChara::UpdateAction(float _deltaTime)
{
	switch (m_status)
	{
	case KeyEnemyActionStatus::Idle:
		Idle();
		break;

	case KeyEnemyActionStatus::Move:
		Move(_deltaTime);
		break;

	case KeyEnemyActionStatus::Attack:
		Attack();
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)KeyEnemyActionStatus::Attack])
		{
			m_status = KeyEnemyActionStatus::Move;
			m_AtkAnimCount = 0.f;
			m_AnimCount = 0.f;
		}
		break;

	case KeyEnemyActionStatus::KnockBack:
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)KeyEnemyActionStatus::KnockBack])
		{
			m_status = KeyEnemyActionStatus::Move;

			if (m_AtkAnimCount > 0.f)
				m_AtkAnimCount = 0.f;

			m_AnimCount = 0.f;
		}
		break;

	case KeyEnemyActionStatus::Down:
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)KeyEnemyActionStatus::Down])
		{
			m_status = KeyEnemyActionStatus::StandUp;
			m_AnimCount = 0.f;
		}
		break;

	case KeyEnemyActionStatus::StandUp:
		m_AnimCount += _deltaTime;

		if (m_AnimCount >= AnimEndFrame[(int)KeyEnemyActionStatus::StandUp])
		{
			m_status = KeyEnemyActionStatus::Move;
			m_AnimCount = 0.f;
		}
		break;

	default:
		break;
	}
}

void AKeyEnemyChara::Idle()
{
	/*
	float disx = m_Player->GetActorLocation().X - GetActorLocation().X;
	float disy = m_Player->GetActorLocation().Y - GetActorLocation().Y;
	if (disx < 0) disx *= -1;
	if (disy < 0) disy *= -1;

	UE_LOG(LogTemp, Error, TEXT("%f"), disx);
	UE_LOG(LogTemp, Error, TEXT("%f"), disy);


	float distance = FMath.sqrt( (m_Player->GetActorLocation().X - GetActorLocation().X) *
								(m_Player->GetActorLocation().X - GetActorLocation().X) +
								(m_Player->GetActorLocation().Y - GetActorLocation().Y) *
								(m_Player->GetActorLocation().Y - GetActorLocation().Y));
	*/

	float distance = FVector::Distance(m_Player->GetActorLocation(), GetActorLocation());

	if (distance <= m_LengthDis)
	{
		m_status = KeyEnemyActionStatus::Move;
	}
}

 // �ړ�����
void AKeyEnemyChara::Move(float _deltaTime)
{
	// �����ƃ^�[�Q�b�g�̋������擾
	float TargetDistanceX = m_Player->GetActorLocation().X - GetActorLocation().X;
	float TargetDistanceY = m_Player->GetActorLocation().Y - GetActorLocation().Y;

	float angle = atan2(-TargetDistanceX, TargetDistanceY);

	float angleDeg = FMath::RadiansToDegrees(angle) + 90.f;

	SetActorRotation(FRotator(0, angleDeg, 0));

	AddActorWorldOffset(GetActorForwardVector() * m_KeyEnemyStatus.moveSpeed * _deltaTime);
}

void AKeyEnemyChara::Attack()
{
	if (m_AtkAnimCount >= m_AtkStartTime && m_AtkAnimCount <= m_AtkEndTime)
	{
		if (m_bIsAttack)
		{
			m_Player->Damage(m_KeyEnemyStatus.atk);
			m_bIsAttack = false;
		}
	}
}

void AKeyEnemyChara::AddAtkAnimTime(float _deltaTime)
{
	m_AtkAnimCount += _deltaTime;
}

//---------------------------------------
// �A�j���[�V�����J��
//---------------------------------------
bool AKeyEnemyChara::ReturnWalk()
{
	// UE_LOG(LogTemp, Error, TEXT("aaaaaaa"));
	if (m_status == KeyEnemyActionStatus::Move)
	{
		return true;
	}
	return false;
}

bool AKeyEnemyChara::ReturnAttack()
{
	if (m_status == KeyEnemyActionStatus::Attack)
	{
		return true;
	}
	return false;
}

bool AKeyEnemyChara::ReturnKnockBack()
{
	if (m_status == KeyEnemyActionStatus::KnockBack)
	{
		return true;
	}
	return false;
}

bool AKeyEnemyChara::ReturnDeath()
{
	if (m_status == KeyEnemyActionStatus::Death)
	{
		return true;
	}
	return false;
}

bool AKeyEnemyChara::ReturnStandUp()
{
	if (m_status == KeyEnemyActionStatus::StandUp)
	{
		return true;
	}
	return false;
}

bool AKeyEnemyChara::ReturnDown()
{
	if (m_status == KeyEnemyActionStatus::Down)
	{
		return true;
	}
	return false;
}

