// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleDoor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

ADoubleDoor::ADoubleDoor()
	: m_pBoxComp(NULL)
	, m_pBoxComp_2(NULL)
	, m_pMesh(NULL)
	, m_pMesh_2(NULL)
	, angle(0.f)
	, angle2(0.f)
	, m_MeshRelativeRotation(FRotator::ZeroRotator)
{
	// メッシュ生成
	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pDoorMesh"));
	m_pMesh->SetupAttachment(RootComponent);
	m_pMesh_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_pDoorMesh_2"));
	m_pMesh_2->SetupAttachment(RootComponent);

	// 衝突判定用のボックスコンポーネント生成
	m_pBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pDoorCollisionComp"));
	m_pBoxComp->SetupAttachment(m_pMesh);
	m_pBoxComp_2 = CreateDefaultSubobject<UBoxComponent>(TEXT("m_pDoorCollisionComp_2"));
	m_pBoxComp_2->SetupAttachment(m_pMesh_2);
}

void ADoubleDoor::BeginPlay()
{
	Super::BeginPlay();

	// ドアの種類によって初期値を変更
	if (m_IsSlide)
	{
		GetDoorLocation = m_pMesh->GetRelativeLocation();
		angle = GetDoorLocation.X + 90.f;
		angle2 = m_pMesh_2->GetRelativeLocation().X - 90.f;
	}
	else
	{
		m_MeshRelativeRotation = m_pMesh->GetRelativeRotation();
		angle = m_pMesh->GetRelativeRotation().Yaw;
		angle2 = m_pMesh_2->GetRelativeRotation().Yaw;
	}
}

void ADoubleDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 横開きのドアの開閉処理
void ADoubleDoor::SideOpen(float _deltaTime)
{
	switch (m_DoorState)
	{
		case State::Idle:
			return;
			break;

		case State::Open:
			if (angle >= 138.f + GetDoorLocation.Y)
			{
				m_DoorState = State::CloseWait;
				return;
			}

			angle += m_speed * _deltaTime;
			angle2 -= m_speed * _deltaTime;
			break;

		case State::Close:
			if (angle <= 0.f + GetDoorLocation.Y)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorCloseSE, GetActorLocation());
				m_DoorState = State::Idle;
				return;
			}

			angle -= m_speed * _deltaTime;
			angle2 += m_speed * _deltaTime;
			break;

		default:
			break;
	}
	m_pMesh->SetRelativeLocation(FVector(m_pMesh->GetRelativeLocation().X, angle, m_pMesh->GetRelativeLocation().Z));
	m_pMesh_2->SetRelativeLocation(FVector(m_pMesh_2->GetRelativeLocation().X, angle2, m_pMesh_2->GetRelativeLocation().Z));

}

// 奥開きのドアの開閉処理
void ADoubleDoor::FrontOpen(float _deltaTime)
{
	switch (m_DoorState)
	{
		case State::Idle:
			m_pFrontBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			m_pBackBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			break;

		case State::Open:
			if (angle >= 90 + m_MeshRelativeRotation.Yaw)
			{
				m_DoorState = State::CloseWait;
				return;
			}

			angle += m_speed * _deltaTime;
			angle2 -= m_speed * _deltaTime;
			break;

		case State::Close:
			if (angle <= 0 + m_MeshRelativeRotation.Yaw)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDoorCloseSE, GetActorLocation());
				m_DoorState = State::Idle;
				return;
			}

			angle -= m_speed * _deltaTime;
			angle2 += m_speed * _deltaTime;
			break;

		default:
			break;
	}
	float offset = (m_bIsOpenReverse) ? -1.f : 1.f;
	float offset2 = (m_bIsOpenReverse) ? -1.f : 1.f;
	m_pMesh->SetRelativeRotation(FRotator(m_MeshRelativeRotation.Pitch, angle * offset, m_MeshRelativeRotation.Roll));
	m_pMesh_2->SetRelativeRotation(FRotator(m_MeshRelativeRotation.Pitch, angle2 * offset2, m_MeshRelativeRotation.Roll));
}

// 両種類のドアの開閉処理をまとめたメソッド
void ADoubleDoor::OpenClose(float _deltaTime)
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
