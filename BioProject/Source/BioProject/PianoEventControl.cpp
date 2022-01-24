// Fill out your copyright notice in the Description page of Project Settings.


#include "PianoEventControl.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Components/BoxComponent.h"

APianoEventControl::APianoEventControl()
	: m_Player(NULL)
	, SpawnItem(NULL)
	, m_index(0)
	, m_CountNumber(0)
	, m_bIsOpen(false)
	, m_bIsItemOnce(false)
	, m_bIsMusicHaveCheck(false)
{
	PrimaryActorTick.bCanEverTick = true;
}

void APianoEventControl::BeginPlay()
{
	Super::BeginPlay();

	// オーバーラップしたら呼ばれる関数を登録
	if (m_pBoxComp != NULL)
	{
		m_pBoxComp->OnComponentBeginOverlap.AddDynamic(this, &APianoEventControl::OnOverlapBegin);
		m_pBoxComp->OnComponentEndOverlap.AddDynamic(this, &APianoEventControl::OnOverlapEnd);
	}

	// プレイヤーの情報を格納
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

void APianoEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsOpen&& !m_bIsItemOnce)
		GetItem();
}

void APianoEventControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerChara>(OtherActor))
	{
		for (int i = 0; i < Cast<APlayerChara>(OtherActor)->GetPlayerBag().Num(); i++)
		{
			if (Cast<APlayerChara>(OtherActor)->GetPlayerBag()[i].type == ItemType::MusicScore)
				(!m_bIsOpen) ? m_bIsMusicHaveCheck = true : m_bIsMusicHaveCheck = false;
		}
	}
}
// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APianoEventControl::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	m_bIsMusicHaveCheck = false;
}

void APianoEventControl::InputKeybord(const int _index)
{
	if (!m_bIsMusicHaveCheck)
	{
		SetIsEventStart(false);
		return;
	}

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

bool APianoEventControl::KeyCheck()
{
	if (m_ArrayKeybord[m_CountNumber] == m_AnswerKeybord[m_CountNumber])
		return true;
	
	return false;
}

void APianoEventControl::GetItem()
{
	SpawnItem = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/BackyardKeyBP.BackyardKeyBP_C");

	if (SpawnItem)
	{
		m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SpawnItem->SetActorLocation(GetActorLocation());
		SpawnItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);

		m_bIsItemOnce = true;
	}
}