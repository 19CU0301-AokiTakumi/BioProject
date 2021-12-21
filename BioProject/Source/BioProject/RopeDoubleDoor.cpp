// Fill out your copyright notice in the Description page of Project Settings.


#include "RopeDoubleDoor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

ARopeDoubleDoor::ARopeDoubleDoor()
	: m_RopeLeftMesh(NULL)
	, m_RopeLightMesh(NULL)
	, m_RopeComp(NULL)
	, m_AnimStart(false)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	m_RopeComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_RopeComp"));
	if (m_RopeComp)
		m_RopeComp->SetupAttachment(RootComponent);

	// メッシュ生成
	m_RopeLeftMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("m_RopeLeftMesh"));
	if (m_RopeLeftMesh)
		m_RopeLeftMesh->SetupAttachment(m_pMesh_2);

	m_RopeLightMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("m_RopeLightMesh"));
	if (m_RopeLightMesh)
		m_RopeLightMesh->SetupAttachment(m_pMesh);
}

void ARopeDoubleDoor::HitKnife()
{
	// m_RopeMesh->SetVisibility(false);
	m_RopeComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_AnimStart = true;
}