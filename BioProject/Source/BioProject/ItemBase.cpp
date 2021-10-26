
#include "ItemBase.h"
#include "PlayerChara.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// �R���X�g���N�^
AItemBase::AItemBase()
	: m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_pOtherPlayer(NULL)
{
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	// ���b�V������
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pItemMesh"));

	//	�R���W��������p�{�b�N�X�R���|�[�l���g����
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pItemCollisionComp"));
	m_pBoxComp->SetupAttachment(m_pMesh);
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlapBegin);
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &AItemBase::OnOverlapEnd);
	}
}

// ���t���[���X�V����
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �v���C���[���u���g���痣��Ă��Ȃ��v���u�A�N�V�����L�[����͂��Ă���v�ꍇ
	if (m_pOtherPlayer && m_pOtherPlayer->IsGetItem())
	{
		// �������g������
		Destroy();
	}
}

// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
void AItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ���������A�N�^�[��ۊ�
	m_pOtherPlayer = Cast<APlayerChara>(OtherActor);
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void AItemBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// �v���C���[�Ɨ��ꂽ��ۊǂ��Ă���v���C���[����������
	if (Cast<APlayerChara>(OtherActor))
		m_pOtherPlayer = NULL;
}
