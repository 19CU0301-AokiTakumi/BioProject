
#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// コンストラクタ
APlayerChara::APlayerChara()
	: m_pSpringArm(NULL)
	, m_pCamera(NULL)
	, m_CharaMoveInput(FVector::ZeroVector)
	, m_CameraRotationInput(FVector::ZeroVector)
	, m_CameraYawLimit(FVector2D(-100.f, 100.f))
	, m_CameraPitchLimit(FVector2D(-80.f, 80.f))
	, m_MoveSpeed(1000.f)
	, m_bagSize(8)
{
	// 毎フレームTick()処理を呼ぶかどうか
	PrimaryActorTick.bCanEverTick = true;

	//　スプリングアームのオブジェクトを生成
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

	// カメラのオブジェクトを生成
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (m_pCamera)
		m_pCamera->SetupAttachment(m_pSpringArm);
}

// ゲーム開始時、または生成時に呼ばれる処理
void APlayerChara::BeginPlay()
{
	Super::BeginPlay();

	//	バッグの中身を初期化
	m_ItemDatas.Init(FItemData::NoneData(), m_bagSize);
}

// 毎フレーム更新処理
void APlayerChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove(DeltaTime);
	UpdateCamera(DeltaTime);
}

// 各入力関係メソッドとのバインド処理
void APlayerChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 移動
	InputComponent->BindAxis("Move_Forward", this, &APlayerChara::MoveForward);
	InputComponent->BindAxis("Move_Right", this, &APlayerChara::MoveRight);

	// カメラの回転
	InputComponent->BindAxis("Camera_Forward", this, &APlayerChara::CameraRotatePitch);
	InputComponent->BindAxis("Camera_Right", this, &APlayerChara::CameraRotateYaw);
}

// 移動処理
void APlayerChara::UpdateMove(float _deltaTime)
{
	if (m_pSpringArm)
	{
		//　キャラクターの移動
		{
			// SpringArmが向く方向に、入力による移動量をPawnMovementComponentに渡す
			const FVector forwardVec = m_pSpringArm->GetForwardVector();
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_MoveSpeed);

			const FVector rightVec = m_pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_MoveSpeed);
		}
	}
}

//　カメラの更新処理
void APlayerChara::UpdateCamera(float _deltaTime)
{
	if (m_pSpringArm)
	{
		//　カメラの新しい角度を求める
		//　現在の角度を取得
		FRotator NewRotation = m_pSpringArm->GetRelativeRotation();

		//　Yawは入力した分回す
		NewRotation.Yaw += m_CameraRotationInput.X;

		//　Pitchに関しては、上下の制限角度の範囲内で切る
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + m_CameraRotationInput.Y, m_CameraPitchLimit.X, m_CameraPitchLimit.Y);

		//　新しい角度を反映
		m_pSpringArm->SetRelativeRotation(NewRotation);
	}
}

//　【入力バインド】キャラ移動：前後
void APlayerChara::MoveForward(float _axisValue)
{
	m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//　【入力バインド】キャラ移動左右
void APlayerChara::MoveRight(float _axisValue)
{
	m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//　【入力バインド】カメラの回転：（Y軸）
void APlayerChara::CameraRotatePitch(float _axisValue)
{
	m_CameraRotationInput.Y = _axisValue;
}

//　【入力バインド】カメラ回転：（Z軸）
void APlayerChara::CameraRotateYaw(float _axisValue)
{
	m_CameraRotationInput.X = _axisValue;
}