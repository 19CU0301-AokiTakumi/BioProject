// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ACamera::ACamera()
	:m_pCameraArm(NULL)
	, m_speed(1.0f)
	, m_pFollowCamera(NULL)
	, m_Base(NULL)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Base = CreateDefaultSubobject<USceneComponent>(TEXT("Base"));

	if (m_Base != NULL)
	{
		RootComponent = m_Base;
	}

	// スプリングアームのオブジェクトを生成
	m_pCameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("m_pCameraArm"));

	// ちゃんと生成出来ているか確認
	if (m_pCameraArm != NULL)
	{
		m_pCameraArm->SetupAttachment(RootComponent);

		// アームの長さを設定
		m_pCameraArm->TargetArmLength = 300.0f;

		// カメラアームを動かせるかどうか
		m_pCameraArm->bUsePawnControlRotation = true;
	}

	// カメラのオブジェクトを生成
	m_pFollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("m_pFollowCamera"));

	// ちゃんと生成出来ているかどうか
	if (m_pFollowCamera != NULL)
	{
		// カメラのスプリングアームにアタッチさせる
		m_pFollowCamera->SetupAttachment(m_pCameraArm, USpringArmComponent::SocketName);
	}

}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

