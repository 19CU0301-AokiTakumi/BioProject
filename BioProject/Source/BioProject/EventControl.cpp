// -----------------------------------------
// �t�@�C����	�FEventControl.h
// �T�v			�F�C�x���g�𐧌䂷��v���O����
// �쐬��		�F�X���Y��
// �쐬��		�F2021�N7��3��
// �X�V����		�F2021�N7��3���@
//------------------------------------------

#include "EventControl.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "EnemyManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEventControl::AEventControl()
	: id(0)
	, PlayerHit(false)
	, m_pBase(NULL)
	, m_pBoxComp(NULL)
	, SpawnOnce(false)
	, m_pSpawnPoint(NULL)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �x�[�X�̒ǉ�
	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	RootComponent = m_pBase;

	/*for (int i = 0; i < m_SpawnNum; ++i)
	{
		FString s = "SpawnPoint" + FString::FromInt(i);
		m_pSpawnPoint.Add(CreateDefaultSubobject<USceneComponent>(FName(*s)));
		m_pSpawnPoint[i]->SetupAttachment(m_pBase);
	}*/

	m_pSpawnPoint = (CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint")));
	m_pSpawnPoint->SetupAttachment(m_pBase);

	// �R���W��������p�{�b�N�X�R���|�[�l���g����
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	m_pBoxComp->SetupAttachment(m_pBase);

	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEventControl::OnOverlapBegin);
	}
	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &AEventControl::OnOverlapEnd);
	}
}

// Called when the game starts or when spawned
void AEventControl::BeginPlay()
{
	Super::BeginPlay();


	m_SpawnLocationLength = m_SpawnLocation.Num();
	UE_LOG(LogTemp, Error, TEXT("%d"), m_SpawnLocationLength);
}

// Called every frame
void AEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEventControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerChara>(OtherActor))
	{
		PlayerHit = true;
	}
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void AEventControl::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<APlayerChara>(OtherActor))
	{
		PlayerHit = false;
	}
}

int AEventControl::SendId()
{
	return id;
}