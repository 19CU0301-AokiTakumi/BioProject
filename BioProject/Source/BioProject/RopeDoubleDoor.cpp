// Fill out your copyright notice in the Description page of Project Settings.


#include "RopeDoubleDoor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ARopeDoubleDoor::ARopeDoubleDoor()
	: m_RopeSkeletalMesh(NULL)
	, m_RopeStaticMesh(NULL)
	, m_RopeComp(NULL)
	, m_AnimStart(false)
	/*, m_Vanish(false)*/
	, m_AnimTime(0.f)
	, m_AnimCount(0.f)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	m_RopeComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_RopeComp"));
	if (m_RopeComp)
		m_RopeComp->SetupAttachment(RootComponent);

	// メッシュ生成
	m_RopeSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("m_RopeSkeletalMesh"));
	if (m_RopeSkeletalMesh)
		m_RopeSkeletalMesh->SetupAttachment(m_RopeComp);

	m_RopeStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_RopeStaticMesh"));
	if (m_RopeStaticMesh)
		m_RopeStaticMesh->SetupAttachment(m_RopeComp);

	m_RopeSkeletalMesh->SetVisibility(false);
}

void ARopeDoubleDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(m_AnimStart)
		AnimEnd(DeltaTime);
}

void ARopeDoubleDoor::HitKnife()
{
	m_RopeComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_AnimStart = true;

	m_RopeStaticMesh->SetVisibility(false);
	m_RopeSkeletalMesh->SetVisibility(true);
}

void ARopeDoubleDoor::AnimEnd(float _deltaTime)
{
	m_AnimCount += _deltaTime;

	//if (m_AnimCount >= m_AnimTime)
	//	m_Vanish = true;

	if (m_AnimCount >= m_AnimTime)
	{
		m_RopeSkeletalMesh->SetVisibility(false);
		SetIsLock(false);
	}
}