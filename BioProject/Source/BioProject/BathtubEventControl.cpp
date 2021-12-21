// Fill out your copyright notice in the Description page of Project Settings.


#include "BathtubEventControl.h"
#include "Components/StaticMeshComponent.h"

ABathtubEventControl::ABathtubEventControl()
	: m_pWaterMesh(NULL)
	, m_downSpeed(1.f)
	, m_WaterMeshLocation(0.f)
	, m_WaterMaxDown(0.f)
	, m_WaterShrink(1.f)
	, m_downShrink(0.f)
{
	PrimaryActorTick.bCanEverTick = true;

	m_pWaterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pWaterMesh"));
	if (m_pWaterMesh)
		m_pWaterMesh->SetupAttachment(RootComponent);
}

void ABathtubEventControl::BeginPlay()
{
	Super::BeginPlay();

	m_WaterMeshLocation = m_pWaterMesh->GetRelativeLocation().Z;
	m_WaterMaxDown += m_WaterMeshLocation;
}

void ABathtubEventControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsEventStart && m_WaterMeshLocation >= m_WaterMaxDown)
		DownWaterSurface(DeltaTime);
}

void ABathtubEventControl::DownWaterSurface(float _deltaTime)
{
	// ˆÚ“®
	m_WaterMeshLocation -= m_downSpeed * _deltaTime;
	m_pWaterMesh->SetRelativeLocation(FVector(m_pWaterMesh->GetRelativeLocation().X, m_pWaterMesh->GetRelativeLocation().Y, m_WaterMeshLocation));

	// k¬
	m_WaterShrink -= m_downShrink * _deltaTime;
	m_pWaterMesh->SetRelativeScale3D(FVector(m_WaterShrink, m_WaterShrink, m_pWaterMesh->GetRelativeScale3D().Z));
}