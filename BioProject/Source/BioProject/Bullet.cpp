// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PlayerChara.h"
#include "EnemyChara.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABullet::ABullet()
	: m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_pPlayer(NULL)
	, m_speed(500.f)
	, m_Time(0.f)
	, m_DestroyCount(0.f)
	, m_isDestroy(false)
	, m_MoveDir(FVector::ZeroVector)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//	�R���W��������p�{�b�N�X�R���|�[�l���g����
	m_pBoxComp = CreateDefaultSubobject<USphereComponent>(TEXT("m_pCollisionComp"));
	RootComponent = m_pBoxComp;

	// ���b�V������
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pDoorMesh"));
	m_pMesh->SetupAttachment(RootComponent);

}
// Called when the game starts or when spawned
void ABullet::Init(FVector startPoint, FVector endPoint)
{
	// �����ʒu�̐ݒ�
	SetActorLocation(startPoint);

	// �i�s�����̌v�Z
	// ���˒n�_�ƃ��C�̏I���_�̍�������A�i�s�������v�Z
	m_MoveDir = endPoint - startPoint;	// ����
	m_MoveDir.Normalize();
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlapBegin);
	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	BulletMove(DeltaTime);

	if (m_isDestroy)
		Destroy();
}

void ABullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag("EnemyComp"))
	{

	}
}

void ABullet::BulletMove(float _deltaTime)
{
	m_Time += _deltaTime;
	//SetActorLocation(FVector(GetActorLocation().X - m_Time, GetActorLocation().Y, GetActorLocation().Z));

	m_pPlayer = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
	if (m_pPlayer != NULL)
	{
		// �i�s�����Ɏ������g���ړ�������
		SetActorLocation(GetActorLocation() + ( m_MoveDir * m_speed + _deltaTime ) );
	}
}

void ABullet::SetIsDestoy(bool _isHit)
{
	m_isDestroy = _isHit;
}