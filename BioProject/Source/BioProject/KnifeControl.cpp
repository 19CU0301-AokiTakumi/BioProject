// Fill out your copyright notice in the Description page of Project Settings.


#include "KnifeControl.h"
#include "RopeDoor.h"
#include "RopeDoubleDoor.h"
#include "Components/BoxComponent.h"

AKnifeControl::AKnifeControl()
	: m_pBladeBoxComp(NULL)
	, m_KnifeData(FKnifeData::NoneData())
{
	m_pBladeBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_Blade"));

	if (m_pBladeBoxComp)
		m_pBladeBoxComp->SetupAttachment(m_pMesh);
}

// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
void AKnifeControl::BeginPlay()
{
	Super::BeginPlay();

	// �I�[�o�[���b�v������Ă΂��֐���o�^
	if (m_pBladeBoxComp != NULL)
	{
		m_pBladeBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AKnifeControl::OnOverlapBegin);
		m_pBladeBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
void AKnifeControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AItemBase::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (OtherComp->ComponentHasTag("Rope"))
	{
		if (Cast<ARopeDoor>(OtherActor))
		{
			ARopeDoor* OverlapRopeDoor = Cast<ARopeDoor>(OtherActor);
			if (!OverlapRopeDoor)
				return;

			OverlapRopeDoor->HitKnife();
			OverlapRopeDoor->SetIsLock(false);
		}
		else if (Cast<ARopeDoubleDoor>(OtherActor))
		{
			ARopeDoubleDoor* OverlapRopeDoor = Cast<ARopeDoubleDoor>(OtherActor);
			if (!OverlapRopeDoor)
				return;

			OverlapRopeDoor->HitKnife();
		}
	}
}

void AKnifeControl::SetCollisionEnabled(const bool _isEnable)
{
	if (m_pBoxComp)
		(_isEnable) ? m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly) : m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AKnifeControl::SetAttckColEnable(const bool _isEnable)
{
	if (m_pBladeBoxComp)
		(_isEnable) ? m_pBladeBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly) : m_pBladeBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}