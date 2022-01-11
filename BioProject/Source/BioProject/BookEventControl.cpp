// Fill out your copyright notice in the Description page of Project Settings.


#include "BookEventControl.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerChara.h"
#include "ItemBase.h"

ABookEventControl::ABookEventControl()
	: m_MoveSpeed(0.f)
	, m_MaxMove(0.f)
	, m_bIsBookCheck(false)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABookEventControl::BeginPlay()
{
	Super::BeginPlay();

	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABookEventControl::OnOverlapBegin);
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &ABookEventControl::OnOverlapEnd);
	}

	m_MaxMove = m_MaxMove + m_pMainMesh->GetRelativeLocation().Y;
}

// 毎フレーム更新処理
void ABookEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetIsEventStart() && m_bIsBookCheck)
		OpenBookShelf(DeltaTime);
}

void ABookEventControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerChara>(OtherActor))
	{
		for (int i = 0;i < Cast<APlayerChara>(OtherActor)->GetPlayerBag().Num(); i++)
		{
			if (Cast<APlayerChara>(OtherActor)->GetPlayerBag()[i].type == ItemType::Book)
				m_bIsBookCheck = true;
		}
	}
}
// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void ABookEventControl::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	m_bIsBookCheck = false;
}

void ABookEventControl::OpenBookShelf(float _deltaTime)
{
	if (m_MaxMove <= m_pMainMesh->GetRelativeLocation().Y)
		return;

	FVector Vec = m_pMainMesh->GetRelativeLocation();
	float speed = m_MoveSpeed * _deltaTime;

	m_pMainMesh->SetRelativeLocation(FVector(Vec.X, Vec.Y + speed, Vec.Z));
}