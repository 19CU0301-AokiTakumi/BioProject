//---------------------------------------------------------------
// �t�@�C����	�FBathtubEventControl.cpp
// �T�v			�F�����̃C�x���g���s��
// �쐬��		�F�ؑ�m
// �쐬��		�F2022�N12��21�� �ؑ�m �쐬
// �X�V����		�F2022�N12��21�� ���b�V���A�����蔻��̐���
//---------------------------------------------------------------

#include "PianoEventControl.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

// �R���X�g���N�^
APianoEventControl::APianoEventControl()
	: m_Player(NULL)
	, SpawnItem(NULL)
	, m_index(0)
	, m_CountNumber(0)
	, m_bIsOpen(false)
	, m_bIsItemOnce(false)
	, m_bIsMusicHaveCheck(false)
{
	// ���t���[���A���̃N���X��Tick()���ĂԂ��ǂ��������߂�t���O
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USoundBase> C1_SE(TEXT("/Game/Sound/Piano/C1.C1"));
	ConstructorHelpers::FObjectFinder<USoundBase> D1_SE(TEXT("/Game/Sound/Piano/D1.D1"));
	ConstructorHelpers::FObjectFinder<USoundBase> E1_SE(TEXT("/Game/Sound/Piano/E1.E1"));
	ConstructorHelpers::FObjectFinder<USoundBase> F1_SE(TEXT("/Game/Sound/Piano/F1.F1"));
	ConstructorHelpers::FObjectFinder<USoundBase> G1_SE(TEXT("/Game/Sound/Piano/G1.G1"));
	ConstructorHelpers::FObjectFinder<USoundBase> A1_SE(TEXT("/Game/Sound/Piano/A1.A1"));
	ConstructorHelpers::FObjectFinder<USoundBase> B1_SE(TEXT("/Game/Sound/Piano/B1.B1"));
	ConstructorHelpers::FObjectFinder<USoundBase> C2_SE(TEXT("/Game/Sound/Piano/C2.C2"));

	m_PianoSEs[1] = C1_SE.Object;
	m_PianoSEs[2] = D1_SE.Object;
	m_PianoSEs[3] = E1_SE.Object;
	m_PianoSEs[4] = F1_SE.Object;
	m_PianoSEs[5] = G1_SE.Object;
	m_PianoSEs[6] = A1_SE.Object;
	m_PianoSEs[7] = B1_SE.Object;
}

// �Q�[���J�n���ɌĂ΂�鏈��
void APianoEventControl::BeginPlay()
{
	Super::BeginPlay();

	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &APianoEventControl::OnOverlapBegin);
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &APianoEventControl::OnOverlapEnd);
	}

	// �v���C���[�̏����i�[
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

// ���t���[���̏���
void APianoEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsOpen&& !m_bIsItemOnce)
		GetItem();
}

// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
void APianoEventControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �������Ă���I�u�W�F�N�g���v���C���[�������ꍇ
	if (Cast<APlayerChara>(OtherActor))
	{
		// �o�b�O�̒��g������
		for (int i = 0; i < Cast<APlayerChara>(OtherActor)->GetPlayerBag().Num(); i++)
		{
			//  �o�b�O�̒��g�ɖ{�������Ă�����t���O�𗧂Ă�
			if (Cast<APlayerChara>(OtherActor)->GetPlayerBag()[i].type == ItemType::MusicScore)
				(!m_bIsOpen) ? m_bIsMusicHaveCheck = true : m_bIsMusicHaveCheck = false;
		}
	}
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void APianoEventControl::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// �t���O��������
	m_bIsMusicHaveCheck = false;
	SetIsEventStart(false);
}

// �L�[�{�[�h�������ꂽ�u�ԂɌĂ΂��֐�
void APianoEventControl::InputKeybord(const int _index)
{
	if (!m_bIsMusicHaveCheck)
	{
		SetIsEventStart(false);
		return;
	}

	UGameplayStatics::PlaySound2D(GetWorld(), m_PianoSEs[_index]);

	if (m_CountNumber >= m_ArrayKeybord.Num() || m_bIsOpen)
		return;

	m_ArrayKeybord[m_CountNumber] = _index;

	KeyCheck();

	if (!KeyCheck())
	{
		m_CountNumber = 0;
		return;
	}

	if (m_CountNumber + 1 == m_ArrayKeybord.Num())
		m_bIsOpen = true;

	m_CountNumber++;
}

// �ԍ��������Ă��邩�𔻒f����֐�
bool APianoEventControl::KeyCheck()
{
	if (m_ArrayKeybord[m_CountNumber] == m_AnswerKeybord[m_CountNumber])
		return true;
	
	return false;
}

// �A�C�e�����X�|�[������֐�
void APianoEventControl::GetItem()
{
	SpawnItem = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/BackyardKeyBP.BackyardKeyBP_C");

	if (SpawnItem)
	{
		m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SpawnItem->SetActorLocation(GetActorLocation());
		SpawnItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);

		m_bIsItemOnce = true;
		m_Player->SetIsOpenPianoWidget(false);
	}
}