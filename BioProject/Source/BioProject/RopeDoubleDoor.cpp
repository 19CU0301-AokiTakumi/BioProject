// Fill out your copyright notice in the Description page of Project Settings.


#include "RopeDoubleDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ARopeDoubleDoor::ARopeDoubleDoor()
	: m_RopeMesh(NULL)
	, m_RopeComp(NULL)
{
	// ���t���[��Tick()�������ĂԂ��ǂ���
	PrimaryActorTick.bCanEverTick = true;

	m_RopeComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_RopeComp"));
	if (m_RopeComp)
		m_RopeComp->SetupAttachment(RootComponent);

	// ���b�V������
	m_RopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_RopeMesh"));
	if (m_RopeMesh)
		m_RopeMesh->SetupAttachment(m_RopeComp);
}

void ARopeDoubleDoor::HitKnife()
{
	m_RopeMesh->SetVisibility(false);
	m_RopeComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}