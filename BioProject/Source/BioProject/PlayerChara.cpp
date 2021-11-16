
#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "DoorBase.h"
#include "ItemBase.h"
#include "DrawDebugHelpers.h"
#include "Bullet.h"

// コンストラクタ
APlayerChara::APlayerChara()
	: m_pSpringArm(NULL)
	, m_pCamera(NULL)
	, m_CharaMoveInput(FVector::ZeroVector)
	, m_CameraRotationInput(FVector::ZeroVector)
	, m_CameraYawLimit(FVector2D(-100.f, 100.f))
	, m_CameraPitchLimit(FVector2D(-80.f, 80.f))
	, m_bagSize(8)
	, m_pOverlapActor(NULL)
	, m_OverlapActorPos(FVector::ZeroVector)
	, m_invenoryState(EInventoryState::Idle)
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

	m_playerStatus = { 10, 10, 1000.f };
	m_statusConst = { 1000.f, 10000000.f };
}

// ゲーム開始時、または生成時に呼ばれる処理
void APlayerChara::BeginPlay()
{
	Super::BeginPlay();

	//	バッグの中身を初期化
	m_ItemDatas.Init(FItemData::NoneData(), m_bagSize);

	// オーバーラップしたら呼ばれる関数を登録
	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerChara::OnOverlapBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &APlayerChara::OnOverlapEnd);
	}
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
	InputComponent->BindAxis("Move_Forward", this, &APlayerChara::Input_MoveForward);
	InputComponent->BindAxis("Move_Right", this, &APlayerChara::Input_MoveRight);

	// カメラの回転
	InputComponent->BindAxis("Camera_Forward", this, &APlayerChara::Input_CameraRotatePitch);
	InputComponent->BindAxis("Camera_Right", this, &APlayerChara::Input_CameraRotateYaw);

	// 走り
	InputComponent->BindAction("Run", IE_Pressed, this, &APlayerChara::Input_Run);

	// アクション
	InputComponent->BindAction("Action", IE_Pressed, this, &APlayerChara::Input_Action);

	// 銃を構える
	InputComponent->BindAxis("Hold", this, &APlayerChara::Input_Hold);

	// 弾を撃つ
	InputComponent->BindAction("Shooting", IE_Pressed, this, &APlayerChara::Input_Shooting);

	// リロード
	InputComponent->BindAction("Reload", IE_Pressed, this, &APlayerChara::Input_Reload);

	// インベントリ
	InputComponent->BindAction("Inventory", IE_Pressed, this, &APlayerChara::Input_Inventory);
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APlayerChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	m_pOverlapActor = OtherActor;
	m_OverlapActorPos = OtherActor->GetActorLocation();

	if (Cast<AItemBase>(OtherActor))
	{
		m_playerFlags.flagBits.isItemTouch = true;
	}

	if (Cast<ADoorBase>(OtherActor))
	{
		if (OtherComp->ComponentHasTag("Front"))
		{
			Cast<ADoorBase>(OtherActor)->SetOpenReverse(false);
		}
		else if (OtherComp->ComponentHasTag("Back"))
		{
			Cast<ADoorBase>(OtherActor)->SetOpenReverse(true);
		}
	}
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APlayerChara::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// 当たっていたアイテムを無効にする
	m_playerFlags.flagBits.isItemTouch = false;

	if (m_pOverlapActor)
	{
		m_pOverlapActor = NULL;
	}
	if (Cast<ADoorBase>(OtherActor))
	{
		if (Cast<ADoorBase>(OtherActor)->GetIsLock())
		{
			m_playerFlags.flagBits.isOpenMenu = false;
		}
		m_playerFlags.flagBits.isOpenMenu = false;
	}
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
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_playerStatus.moveSpeed);

			const FVector rightVec = m_pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_playerStatus.moveSpeed);
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
void APlayerChara::Input_MoveForward(float _axisValue)
{
	m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//　【入力バインド】キャラ移動左右
void APlayerChara::Input_MoveRight(float _axisValue)
{
	m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;
}

//　【入力バインド】カメラの回転：（Y軸）
void APlayerChara::Input_CameraRotatePitch(float _axisValue)
{
	m_CameraRotationInput.Y = _axisValue;
}

//　【入力バインド】カメラ回転：（Z軸）
void APlayerChara::Input_CameraRotateYaw(float _axisValue)
{
	m_CameraRotationInput.X = _axisValue;
}

//【入力バインド】銃を構える
void APlayerChara::Input_Hold(float _axisValue)
{
	m_playerFlags.flagBits.isGunHold = !(m_playerFlags.flagBits.isGunHold);
}

// 【入力バインド】銃を撃つ
void APlayerChara::Input_Shooting()
{

	//m_bShootGun = true;
	//UE_LOG(LogTemp, Log, TEXT("MM"));

	//if (m_iGunAmmoCount < 1)
	//{
	//	m_ZeroBullet = true;
	//}

	//if (!m_bHaveGun && m_iGunAmmoCount >= 0) { return; }

	//FRotator SpawnRotation = GetControlRotation();
	//FVector SpawnLocation = GetCapsuleComponent()->GetComponentLocation();
	//FActorSpawnParameters ActorSpawnParams;
	////GetWorld()->SpawnActor<APlayerChara>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	//m_iGunAmmoCount--;


	//if (m_playerFlags.flagBits.isHaveGun == false)
	//	return;


	// レイを飛ばす
	// レイの始点はActorの位置
	FVector Start = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100.f);
	// レイの終点はActorから前方向の一定距離
	FVector End = m_pCamera->GetRelativeLocation() + m_pCamera->GetForwardVector() * 10000.f;

	//// デバッグ確認用のラインを描画
	//DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 1.0f);

	// コリジョン判定で無視する項目を指定（今回はこのActor自分自身。thisポインタで指定）
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	//// ヒットした（=コリジョン判定を受けた）オブジェクトを格納する変数
	//FHitResult OutHit;

	//// レイを飛ばし、オブジェクトに対してコリジョン判定を行う
	//// isHitは、ヒットした場合にtrueになる
	//bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_WorldStatic, CollisionParams);

	//// ヒットするオブジェクトがある場合
	//if (isHit)
	//{

	//}

	FString path = "/Game/BP/BulletBP.BulletBP_C";
	TSubclassOf<class AActor> sc = TSoftClassPtr<AActor>(FSoftObjectPath(*path)).LoadSynchronous();
	ABullet* SpawnBullet = (ABullet*)UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/Player/BulletBP.BulletBP_C");
	if (SpawnBullet != NULL)
	{
		//SpawnBullet->SetActorLocation(m_pSpringArm->GetRelativeLocation());
		SpawnBullet->Init(Start, End);
	}
}

// 【入力バインド】走り
void APlayerChara::Input_Run()
{
	// コントロール出来るか
	m_playerStatus.moveSpeed = m_statusConst.runSpeed;
	m_ActionStatus = EActionStatus::Run;
}

// 【入力バインド】アクション
void APlayerChara::Input_Action()
{
	if (m_pOverlapActor == NULL)
		return;

	if (Cast<ADoorBase>(m_pOverlapActor))
	{
		if (Cast<ADoorBase>(m_pOverlapActor)->GetIsLock())
		{
			m_playerFlags.flagBits.isOpenMenu = true;
		}
		return;
	}

	if (m_playerFlags.flagBits.isItemTouch == true)
	{
		for (int i = 0; i < m_ItemDatas.Num(); i++)
		{
			if (m_ItemDatas[i].type == ItemType::None)
			{
				m_ItemDatas[i] = Cast<AItemBase>(m_pOverlapActor)->GetItemData();

				AGunControl* OverlapGun = Cast<AGunControl>(m_pOverlapActor);
				if (OverlapGun)
				{
					m_playerFlags.flagBits.isHaveGun = true;
					m_playerStatus.equipGunData = Cast<AGunControl>(m_pOverlapActor)->GetGunData();
				}
				
				m_playerFlags.flagBits.isItemGet = true;
				UE_LOG(LogTemp, Error, TEXT("ItemGet"));
				break;
			}
		}
	}
}

void APlayerChara::Input_Reload()
{
	if (Cast<AGunControl>(m_pOverlapActor) == NULL)
		return;

	//Cast<AGunControl>(m_pOverlapActor)->Reload();
}

void APlayerChara::Input_Inventory()
{
	m_playerFlags.flagBits.isOpenMenu = !(m_playerFlags.flagBits.isOpenMenu);
	m_invenoryState = (m_playerFlags.flagBits.isOpenMenu) ? EInventoryState::Open : EInventoryState::Close;
}

void APlayerChara::Damage(int _atk)
{
	m_playerStatus.hp -= _atk;

	if (m_playerStatus.hp <= 0)
	{
		m_playerStatus.hp = 0;
	}
}

bool APlayerChara::GetIsDead()
{
	return (m_playerStatus.hp <= 0) ? true : false;
}