// Fill out your copyright notice in the Description page of Project Settings.


#include "RopeDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ARopeDoor::ARopeDoor()
	: m_RopeMesh(NULL)
	, m_RopeComp(NULL)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	m_RopeComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_RopeComp"));
	if (m_RopeComp)
		m_RopeComp->SetupAttachment(RootComponent);

	// メッシュ生成
	m_RopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_RopeMesh"));
	if (m_RopeMesh)
		m_RopeMesh->SetupAttachment(m_RopeComp);
}

//// ゲーム開始時、または生成時に呼ばれる処理
//void ARopeDoor::BeginPlay()
//{
//	Super::BeginPlay();
//}
//
//// 毎フレーム更新処理
//void ARopeDoor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}

void ARopeDoor::HitKnife()
{
	m_RopeMesh->SetVisibility(false);
}