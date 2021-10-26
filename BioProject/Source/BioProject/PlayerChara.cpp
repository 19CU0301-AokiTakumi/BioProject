// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerChara::APlayerChara()
	: m_pSpringArm(NULL)
	, m_pCamera(NULL)
	, m_CharaMoveInput(FVector::ZeroVector)
	, m_CameraRotationInput(FVector::ZeroVector)
	, m_CameraYawLimit(FVector2D(-100.f, 100.f))
	, m_CameraPitchLimit(FVector2D(-80.f, 80.f))
	, m_MoveSpeed(1000.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	if (m_pSpringArm)
	{
		m_pSpringArm->SetupAttachment(RootComponent);

		//　アームの長さを設定
		//　カメラのコリジョンテストを行うかを設定
		m_pSpringArm->bDoCollisionTest = false;
		//　カメラ追従フラグを使うかを設定
		m_pSpringArm->bEnableCameraLag = true;
		//　カメラ追従ラグの速度を設定
		m_pSpringArm->CameraLagSpeed = 25.f;
		//　カメラの回転ラグを使うかを設定
		m_pSpringArm->bEnableCameraRotationLag = true;
		//　カメラ回転ラグの速度を設定
		m_pSpringArm->CameraRotationLagSpeed = 20.f;
	}

	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (m_pCamera)
		m_pCamera->SetupAttachment(m_pSpringArm);
}

// Called when the game starts or when spawned
void APlayerChara::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove(DeltaTime);
	UpdateCamera(DeltaTime);
}

// Called to bind functionality to input
void APlayerChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Move_Forward", this, &APlayerChara::MoveForward);
	InputComponent->BindAxis("Move_Right", this, &APlayerChara::MoveRight);
	InputComponent->BindAxis("Camera_Forward", this, &APlayerChara::MoveCameraForword);
	InputComponent->BindAxis("Camera_Right", this, &APlayerChara::MoveCameraRight);
}

void APlayerChara::UpdateMove(float _deltaTime)
{
	// 移動入力があった場合のみ
		//　入力に合わせて、Actorを左右前後に移動
	USpringArmComponent* pSpringArm = m_pSpringArm;

	if (pSpringArm != NULL)
	{
		//　キャラクターの移動
		{
			// SpringArmが向く方向に、入力による移動量をPawnMovementComponentに渡す
			const FVector forwardVec = pSpringArm->GetForwardVector();
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_MoveSpeed);

			const FVector rightVec = pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_MoveSpeed);
		}
	}
}

void APlayerChara::UpdateCamera(float _deltaTime)
{
	//if (m_pSpringArm)
	//{
	//	FRotator NewRotation = m_pSpringArm->GetRelativeRotation();

	//	NewRotation.Yaw += m_CameraRotationInput.X;

	//	NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + m_CameraRotationInput.Y, m_CameraPitchLimit.X, m_CameraPitchLimit.Y);

	//	m_pSpringArm->SetRelativeRotation(NewRotation);
	//}

	USpringArmComponent* pSpringArm = m_pSpringArm;
	if (pSpringArm != NULL)
	{
		//　現在のFPSを測定
		float fps = 1.0f / _deltaTime;

		//　処理落ちしても、一定速度でカメラが回るように補正
		float rotateCorrection = 1.0f;// 60.f / fps;

		//　カメラの新しい角度を求める
		//　現在の角度を取得
		FRotator NewRotation = pSpringArm->GetRelativeRotation();

		//　Yawは入力した分回す
		NewRotation.Yaw += m_CameraRotationInput.X * rotateCorrection;

		//　Pitchに関しては、上下の制限角度の範囲内で切る
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + (m_CameraRotationInput.Y * rotateCorrection), m_CameraPitchLimit.X, m_CameraPitchLimit.Y);

		//　新しい角度を反映
		pSpringArm->SetRelativeRotation(NewRotation);

	}
}

void APlayerChara::MoveForward(float _axisValue)
{
	m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

void APlayerChara::MoveRight(float _axisValue)
{
	m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

void APlayerChara::MoveCameraForword(float _axisValue)
{
	m_CameraRotationInput.Y = _axisValue;
}

void APlayerChara::MoveCameraRight(float _axisValue)
{
	m_CameraRotationInput.X = _axisValue;
}