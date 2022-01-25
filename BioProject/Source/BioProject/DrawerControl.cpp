// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawerControl.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"
#include "ItemBase.h"
#include "MyGameInstance.h"

ADrawerControl::ADrawerControl()
	: m_pDrawerMesh(NULL)
	, m_pDrawerOpenSE(NULL)
	, m_pItem(NULL)
	, m_SpawnItem(ESpawnItem::None)
	, m_openSpeed(1.f)
	, m_maxOpenValue(1.f)
	, m_DrawerOpenCount(0.f)
	, m_ItemMoveCount(0.f)
	, m_bIsDrawerOpen(false)
{
	m_pDrawerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pDrawerMesh"));
	if (m_pDrawerMesh)
		m_pDrawerMesh->SetupAttachment(RootComponent);

	m_pItemSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("m_pItemSpawnPoint"));
	if (m_pItemSpawnPoint)
		m_pItemSpawnPoint->SetupAttachment(RootComponent);
}
void ADrawerControl::BeginPlay()
{
	Super::BeginPlay();
	FString SpawnPath = "";
	FString SocketName = "";
	FRotator ItemRotation = FRotator::ZeroRotator;
	switch (m_SpawnItem)
	{
		case ESpawnItem::HandGun:
			SpawnPath = "/Game/BP/Gun/HandGunBP.HandGunBP_C";
			SocketName = "GunSocket";
			ItemRotation = FRotator(-90.f, 0.f, 30.f);
			break;
		case ESpawnItem::HandGunAmmo:
			SpawnPath = "/Game/BP/Gun/HandGunAmmoBP.HandGunAmmoBP_C";
			SocketName = "AmmoSocket";
			ItemRotation = FRotator(0.f, 90.f, 0.f);
			break;
		default:
			break;
	}

	m_pItem = Cast<AItemBase>(UMyGameInstance::GetSpawnActor(GetWorld(), *SpawnPath));
	if (m_pItem)
	{
		m_pItem->AttachToComponent(m_pDrawerMesh, { EAttachmentRule::SnapToTarget, true }, *SocketName);
		m_pItem->SetActorRotation(GetActorRotation() + ItemRotation);
		m_pItem->SetCollisionEnabled(false);
		m_ItemMoveCount = m_pItem->GetActorLocation().Y;
	}
	m_DrawerOpenCount = m_pDrawerMesh->GetRelativeLocation().Y;

	m_maxOpenValue = m_DrawerOpenCount + m_maxOpenValue;
}

void ADrawerControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OpenDrawer(DeltaTime);
}

void ADrawerControl::OpenDrawer(const float _deltaTime)
{
	
	if (m_bIsEventStart == false)
		return;

	if (m_bIsDrawerOpen)
		return;
	

	if (m_pItem)
		m_pItem->SetCollisionEnabled(true);
	m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	

	if (m_DrawerOpenCount < m_maxOpenValue)
	{
		m_pDrawerMesh->SetRelativeLocation(FVector(m_pDrawerMesh->GetRelativeLocation().X, m_DrawerOpenCount, m_pDrawerMesh->GetRelativeLocation().Z));
	}
	else
	{
		m_bIsDrawerOpen = true;
	}

	m_DrawerOpenCount += _deltaTime * m_openSpeed;
	if (m_pItem)
		m_ItemMoveCount += _deltaTime * m_openSpeed;
}