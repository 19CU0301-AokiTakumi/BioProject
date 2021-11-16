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
	, m_Count(0.f)
	, m_status(ActionStatus::Idle)
	, m_ReduceOnce(false)
	, m_SearchAria(0.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���b�V��������
	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_EnemyMesh"));
	m_Mesh->SetupAttachment(RootComponent);

	m_EnemyStatus = { 10, 10, 10, 1000.f };
}

// Called when the game starts or when spawned
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	
	// �I�[�o�[���b�v������Ă΂��֐���o�^
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

// Called to bind functionality to input
void AEnemyChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ABullet>(OtherActor))
		m_status = ActionStatus::KnockBack;
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

	// ���C���΂�
	// ���C�̎n�_��Actor�̈ʒu
	FVector Start = GetActorLocation();
	// ���C�̏I�_��Actor����O�����̈�苗��
	FVector End = GetActorLocation() + m_Mesh->GetForwardVector() * m_SearchAria;

	//// �f�o�b�O�m�F�p�̃��C����`��
	DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 1.0f);

	// �R���W��������Ŗ������鍀�ڂ��w��i����͂���Actor�������g�Bthis�|�C���^�Ŏw��j
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	// �q�b�g�����i=�R���W����������󂯂��j�I�u�W�F�N�g���i�[����ϐ�
	FHitResult OutHit;

	// ���C���΂��A�I�u�W�F�N�g�ɑ΂��ăR���W����������s��
	// isHit�́A�q�b�g�����ꍇ��true�ɂȂ�
	bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_WorldStatic, CollisionParams);

	// �q�b�g����I�u�W�F�N�g������ꍇ
	if (isHit)
	{
		// ���q�b�g����Actor���A�ۑ����ꂽ�q�b�gActor�ƈႤ�ꍇ
		if (OutHit.GetActor()->ActorHasTag("Player"))
			m_status = ActionStatus::Attack;
	}
}

void AEnemyChara::Attack(float _deltaTime)
{
	m_Player->Damage(m_EnemyStatus.atk);
}

void AEnemyChara::Avoid(float _deltaTime)
{

}

void AEnemyChara::KnockBack(float _deltaTime)
{
	m_Count += _deltaTime;

	if (m_Count > 2.f)	// 2.f�̓A�j���[�V�����̎��ԁi��ŕύX�j
	{
		m_ReduceOnce = true;
	}

	if (m_ReduceOnce == true)
	{
		m_EnemyStatus.hp--;

		if (m_EnemyStatus.hp <= 0)
		{
			Destroy();
		}

		m_Count = 0.f;
		m_ReduceOnce = false;
		m_status = ActionStatus::Move;
	}
}