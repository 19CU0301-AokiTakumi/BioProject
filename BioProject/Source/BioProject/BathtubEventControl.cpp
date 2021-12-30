// Fill out your copyright notice in the Description page of Project Settings.


#include "BathtubEventControl.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PlayerChara.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

ABathtubEventControl::ABathtubEventControl()
	: m_pWaterMesh(NULL)
	, SpawnItem(NULL)
	, m_downSpeed(1.f)
	, m_WaterShrink(1.f)
	, m_WaterMeshLocation(0.f)
	, m_WaterMaxDown(0.f)
	, m_downShrink(0.f)
	, m_SpawnOnce(false)
	, m_WidgetOpen(false)
	, m_DoAction(false)
	, m_index(0)
{
	PrimaryActorTick.bCanEverTick = true;

	m_pWaterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pWaterMesh"));
	if (m_pWaterMesh)
		m_pWaterMesh->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<USoundBase> WaterSE(TEXT("/Game/Sound/Ambient/haisui.haisui"));
	m_pWaterSE = WaterSE.Object;
}

void ABathtubEventControl::BeginPlay()
{
	Super::BeginPlay();

	m_WaterMeshLocation = m_pWaterMesh->GetRelativeLocation().Z;
	m_WaterMaxDown += m_WaterMeshLocation;

	// ÉvÉåÉCÉÑÅ[ÇÃèÓïÒÇäiî[
	m_Player = Cast<APlayerChara>(UMyGameInstance::GetActorFromTag(this, "Player"));
}

void ABathtubEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetEventStartCheck() && !m_DoAction)
		SetOpenWidget(true);

	if (m_DoAction)
		SetOpenWidget(false);

	if (m_DoAction && m_WaterMeshLocation >= m_WaterMaxDown)
	{
		DownWaterSurface(DeltaTime);

		if (!m_SpawnOnce)
			ItemSpawn();
	}

	if (SpawnItem)
	{
		if (m_Player->ItemDestroy)
			SpawnItem->Destroy();
	}
}

void ABathtubEventControl::DownWaterSurface(float _deltaTime)
{
	if (m_index != 0)
	{
		m_bIsEventStart = false;
		m_DoAction = false;
		return;
	}

	m_pBoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// à⁄ìÆ
	m_WaterMeshLocation -= m_downSpeed * _deltaTime;
	m_pWaterMesh->SetRelativeLocation(FVector(m_pWaterMesh->GetRelativeLocation().X, m_pWaterMesh->GetRelativeLocation().Y, m_WaterMeshLocation));

	// èkè¨
	m_WaterShrink -= m_downShrink * _deltaTime;
	m_pWaterMesh->SetRelativeScale3D(FVector(m_WaterShrink, m_WaterShrink, m_pWaterMesh->GetRelativeScale3D().Z));

	if (m_WaterMeshLocation <= m_WaterMaxDown)
		SpawnItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);
}

void ABathtubEventControl::ItemSpawn()
{
	SpawnItem = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/Gun/AirAmmoControl.AirAmmoControl_C");

	if (SpawnItem)
	{
		SpawnItem->SetActorLocation(GetActorLocation());
		SpawnItem->SetActorEnableCollision(ECollisionEnabled::NoCollision);

		m_SpawnOnce = true;
	}
}

void ABathtubEventControl::PlaySound()
{
	// âπÇñ¬ÇÁÇ∑
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pWaterSE, FVector(-1820.f, -1320.f, 40.f));
}