// Fill out your copyright notice in the Description page of Project Settings.


#include "EventObjectBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AEventObjectBase::AEventObjectBase()
	: m_pBase(NULL)
	, m_pBoxComp(NULL)
	, m_pMainMesh(NULL)
	, m_eventType(EEventType::Inventory)
	, m_bIsEventStart(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pBase = CreateDefaultSubobject<USceneComponent>(TEXT("m_pBase"));
	if (m_pBase)
		RootComponent = m_pBase;

	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pBoxComp"));
	if (m_pBoxComp)
		m_pBoxComp->SetupAttachment(RootComponent);

	m_pMainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pMainMesh"));
	if (m_pMainMesh)
		m_pMainMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEventObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEventObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

