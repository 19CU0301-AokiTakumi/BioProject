// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleDoor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

// コンストラクタ
ASingleDoor::ASingleDoor()
	: m_pBoxComp(NULL)
	, m_pMesh(NULL)
	, m_angle(0.f)
	, m_MeshRelativeRotation(FRotator::ZeroRotator)
	, m_MeshRelativeLocation(FVector::ZeroVector)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	// メッシュ生成
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pDoorMesh"));
	m_pMesh->SetupAttachment(RootComponent);

	// 衝突判定用のボックスコンポーネント生成
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pDoorCollisionComp"));
	m_pBoxComp->SetupAttachment(m_pMesh);
}

// ゲーム開始時、または生成時に呼ばれる処理
void ASingleDoor::BeginPlay()
{
	Super::BeginPlay();

	// ドアの種類によって初期値を変更
	if (m_IsSlide)
	{
		m_MeshRelativeLocation = m_pMesh->GetRelativeLocation();
		m_angle = m_MeshRelativeLocation.Y;
	}
	else
	{
		m_MeshRelativeRotation = m_pMesh->GetRelativeRotation();
		m_angle = m_pMesh->GetRelativeRotation().Yaw;
	}
}

// 毎フレーム更新処理
void ASingleDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 横開きのドアの開閉処理
void ASingleDoor::SideOpen(float _deltaTime)
{
	switch (m_DoorState)
	{
		case State::Idle:
			return;
			break;

		case State::Open:
			if (m_angle >= 138.f + m_MeshRelativeLocation.Y)
			{
				m_DoorState = State::CloseWait;
				return;
			}

			m_angle += m_speed * _deltaTime;
			break;

		case State::Close:
			if (m_angle <= 0.f + m_MeshRelativeLocation.Y)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorCloseSE, GetActorLocation());
				m_DoorState = State::Idle;
				return;
			}
			m_angle -= m_speed * _deltaTime;
			break;

		default:
			break;
	}
	m_pMesh->SetRelativeLocation(FVector(m_MeshRelativeLocation.X, m_angle, m_MeshRelativeLocation.Z));
}

// 奥開きのドアの開閉処理
void ASingleDoor::FrontOpen(float _deltaTime)
{
	switch (m_DoorState)
	{
		case State::Idle:
			m_pFrontBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			m_pBackBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			break;

		case State::Open:
			if (m_angle >= 90 + m_MeshRelativeRotation.Yaw)
			{
				m_DoorState = State::CloseWait;
				return;
			}

			m_angle += m_speed * _deltaTime;
			break;

		case State::Close:
			if (m_angle <= 0 + m_MeshRelativeRotation.Yaw)
			{
				m_DoorState = State::Idle;
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorCloseSE, GetActorLocation());
				return;
			}

			m_angle -= m_speed * _deltaTime;
			break;

		default:
			break;
	}
	float offset = (m_bIsOpenReverse) ? -1.f : 1.f;
	m_pMesh->SetRelativeRotation(FRotator(m_MeshRelativeRotation.Pitch, m_angle * offset, m_MeshRelativeRotation.Roll));
}

// 両種類のドアの開閉処理をまとめたメソッド
void ASingleDoor::OpenClose(float _deltaTime)
{
	// 鍵がかかっていれば処理しない
	if (m_bIsLock)
		return;

	// ドアを閉めて良いかのチェック
	CheckClose(_deltaTime);

	// 横開きドア設定のとき
	if (m_IsSlide)
	{
		SideOpen(_deltaTime);
	}
	// 奥開きドア設定のとき
	else
	{
		FrontOpen(_deltaTime);
	}
}

