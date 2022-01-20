// Fill out your copyright notice in the Description page of Project Settings.


#include "PianoEventControl.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"

APianoEventControl::APianoEventControl()
	: m_Player(NULL)
	, SpawnItem(NULL)
	, m_index(0)
	, m_CountNumber(0)
	, m_bIsOpen(false)
	, m_ItemOnce(false)
{
	PrimaryActorTick.bCanEverTick = true;
}

void APianoEventControl::BeginPlay()
{
	Super::BeginPlay();

	// ƒvƒŒƒCƒ„[‚Ìî•ñ‚ğŠi”[
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

void APianoEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsOpen&& !m_ItemOnce)
		GetItem();
}

void APianoEventControl::InputKeybord(const int _index)
{
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
	{
		m_bIsOpen = true;
	}

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
		SpawnItem->SetActorLocation(GetActorLocation());
		SpawnItem->SetActorEnableCollision(ECollisionEnabled::NoCollision);

		m_ItemOnce = true;
	}
}