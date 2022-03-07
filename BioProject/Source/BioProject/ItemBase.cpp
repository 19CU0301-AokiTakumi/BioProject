
#include "ItemBase.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// �R���X�g���N�^
AItemBase::AItemBase()
	: m_pBase(NULL)
	, m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_pOtherPlayer(NULL)
	, m_itemData(FItemData::NoneData())
{
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	RootComponent = m_pBase;

	//	�R���W��������p�{�b�N�X�R���|�[�l���g����
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pItemCollisionComp"));
	if (m_pBoxComp)
		m_pBoxComp->SetupAttachment(RootComponent);

	// ���b�V������
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pItemMesh"));
	if (m_pMesh)
		m_pMesh->SetupAttachment(RootComponent);
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
	//if (m_pOtherPlayer && m_pOtherPlayer->IsGetItem())
	//{
	//	m_pOtherPlayer->SetIsGetItem(false);

	//	// �������g������
	//	Destroy();
	//}
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

FVector AItemBase::GetCenterPos() const 
{ 
	return m_pBoxComp->GetComponentLocation(); 
}

void AItemBase::SetCollisionEnabled(const bool _isEnable)
{
	if (m_pBoxComp)
		(_isEnable) ? m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly) : m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AItemBase::DestroyMesh()
{
	if (UMyGameInstance::GetActorFromTag(this, "OwnerRoomKey"))
	{
		APlayerChara* m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
		m_Player->SetIsGetItem(false);
		m_pMesh->SetVisibility(false);
		Destroy();
	}

	if (!UMyGameInstance::GetActorFromTag(this, "OwnerRoomKey"))
	{
		m_pMesh->SetVisibility(true);
	}
}
