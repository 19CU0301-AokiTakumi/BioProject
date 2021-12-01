
#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "DoorBase.h"
#include "ItemBase.h"
#include "Bullet.h"
#include "GunControl.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"

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
	, m_invenoryState(EInventoryState::Idle)
	, m_Count(0.f)
	, m_ActionStatus(EActionStatus::Idle)
	, m_CountTime(0.f)
	, m_Viewvalue(90.f)
	, m_pShotSE(NULL)

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

	// 構造体の初期化
	m_playerStatus = { 10, 10, 1000.f, FGunData::NoneData(), 0 };
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

	// 画角の初期設定(追加)
	m_Viewvalue = 90;
	m_pCamera->SetFieldOfView(m_Viewvalue);
}

// 毎フレーム更新処理
void APlayerChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove(DeltaTime);
	UpdateCamera(DeltaTime);
	ShootCameraShake(DeltaTime);

	// 画角変更
	Changeview(DeltaTime);

	if (m_playerFlags.flagBits.isHaveGun)
	{
		m_haveGunDatas[m_playerStatus.equipGunID]->CheckFireRate(DeltaTime);
	}
		

	switch (m_ActionStatus)
	{
	case EActionStatus::Idle:
		UE_LOG(LogTemp, Error, TEXT("Idle"));
		break;

	case EActionStatus::Reload:
		UE_LOG(LogTemp, Error, TEXT("Reload"));
		break;

	case EActionStatus::Walk:
		UE_LOG(LogTemp, Error, TEXT("Walk"));
		break;

	case EActionStatus::Shot:
		m_ActionStatus = EActionStatus::Idle;
		m_CountTime += DeltaTime;
		if (m_CountTime >= 2.f)
		{
			UE_LOG(LogTemp, Error, TEXT("BAKA"));
			m_CountTime = 0.f;
		}

	//case eactionstatus::avoid:
		//avoid(_deltatime);
		//break;

	//case eactionstatus::knockback:
		//knockback(_deltatime);
		//break;

	default:
		break;
	}

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
	InputComponent->BindAction("Hold", IE_Pressed, this, &APlayerChara::Input_Hold);
	InputComponent->BindAction("Hold", IE_Released, this, &APlayerChara::Input_Hold);

	// 銃を撃つ
	InputComponent->BindAction("Shooting", IE_Pressed, this, &APlayerChara::Input_Shooting);

	// リロード
	InputComponent->BindAction("Reload", IE_Pressed, this, &APlayerChara::Input_Reload);

	// インベントリ開閉
	InputComponent->BindAction("Inventory", IE_Pressed, this, &APlayerChara::Input_Inventory);

	// 銃を切り替える
	InputComponent->BindAxis("ChangeGun", this, &APlayerChara::Input_ChangeGun);
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APlayerChara::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 触れているアクターを保管
	m_pOverlapActor = OtherActor;

	// アイテムに触れている時
	if (Cast<AItemBase>(OtherActor))
	{
		// アイテムに触れているフラグを立てる
		m_playerFlags.flagBits.isItemTouch = true;
	}

	// 扉に触れている時
	if (Cast<ADoorBase>(OtherActor))
	{
		// いづれの場合もプレイヤーからして奥に開くようにする
		// 前面に触れている時
		if (OtherComp->ComponentHasTag("Front"))
		{
			// 開く方向を設定
			Cast<ADoorBase>(OtherActor)->SetOpenReverse(false);
		}
		// 背面に触れている時
		else if (OtherComp->ComponentHasTag("Back"))
		{
			// 開く方向を設定
			Cast<ADoorBase>(OtherActor)->SetOpenReverse(true);
		}
	}
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APlayerChara::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// アイテムに触れているフラグをおろす
	m_playerFlags.flagBits.isItemTouch = false;

	// 保管していた触れていたアクターを無効にする
	m_pOverlapActor = NULL;

	// 扉から離れた時
	if (Cast<ADoorBase>(OtherActor))
	{
		// インベントリを閉じる
		m_playerFlags.flagBits.isOpenMenu = false;
	}
}


// 移動処理
void APlayerChara::UpdateMove(float _deltaTime)
{
	if (m_pSpringArm)
	{
		m_Count += _deltaTime;

		//　キャラクターの移動
		{
			// SpringArmが向く方向に、入力による移動量をPawnMovementComponentに渡す
			const FVector forwardVec = m_pSpringArm->GetForwardVector();
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_playerStatus.moveSpeed);

			const FVector rightVec = m_pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_playerStatus.moveSpeed);
		}

		// 移動時のカメラの揺れ
		if (m_Count < 0.5f && m_CharaMoveInput.Y != 0)
		{
			if (m_Count < 0.3f)
			{
				m_pCamera->SetRelativeLocation(FVector(m_pCamera->GetRelativeLocation().X, m_pCamera->GetRelativeLocation().Y, m_pCamera->GetRelativeLocation().Z + 0.015));
			}
			else
			{
				m_pCamera->SetRelativeLocation(FVector(m_pCamera->GetRelativeLocation().X, m_pCamera->GetRelativeLocation().Y, m_pCamera->GetRelativeLocation().Z - 0.015));
			}
		}
		else if (m_Count > 0.5f && m_CharaMoveInput.Y != 0)
		{
			m_Count = 0.f;
			m_pCamera->SetRelativeLocation(FVector(m_pCamera->GetRelativeLocation().X, m_pCamera->GetRelativeLocation().Y, 0));
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

		// プレイヤーの向いている方向に腕を回転させる
		GetMesh()->SetRelativeRotation(FRotator(NewRotation.Pitch, NewRotation.Yaw, NewRotation.Roll));

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
	if (m_playerFlags.flagBits.isOpenMenu == false)
		m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;

}

//　【入力バインド】キャラ移動左右
void APlayerChara::Input_MoveRight(float _axisValue)
{
	if (m_playerFlags.flagBits.isOpenMenu == false)
		m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;

}



//　【入力バインド】カメラの回転：（Y軸）
void APlayerChara::Input_CameraRotatePitch(float _axisValue)
{
	if (m_playerFlags.flagBits.isOpenMenu == false)
		m_CameraRotationInput.Y = _axisValue;
}

//　【入力バインド】カメラ回転：（Z軸）
void APlayerChara::Input_CameraRotateYaw(float _axisValue)
{
	if (m_playerFlags.flagBits.isOpenMenu == false)
		m_CameraRotationInput.X = _axisValue;
}

//【入力バインド】銃を構える
void APlayerChara::Input_Hold()
{
	// 銃を構えているかのフラグを切り替える
	m_playerFlags.flagBits.isGunHold = !(m_playerFlags.flagBits.isGunHold);
}

// 【入力バインド】銃を撃つ
void APlayerChara::Input_Shooting()
{
	// 銃を持っていない場合は処理しない
	if (m_playerFlags.flagBits.isHaveGun == false)
		return;

	// 銃に弾が入っていない場合は処理しない
	if (m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData().ammoStock <= 0)
		return;

	// 銃が既に撃たれている状態の場合処理しない
	if (m_haveGunDatas[m_playerStatus.equipGunID]->GetIsShot())
		return;

	//m_haveGunDatas[m_playerStatus.equipGunID]->Shot(this);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pShotSE, FVector::ZeroVector);

	// 装備している銃の情報を一時保管
	FGunData NewGunData = m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData();
	
	// 銃の弾を減らす
	m_haveGunDatas[m_playerStatus.equipGunID]->RemoveAmmo(1);

	// データを反映
	m_playerStatus.equipGunData = m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData();
		
	// 弾の発射位置
	FVector Start = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100.f);

	// 弾の弾着位置
	FVector End = m_pCamera->GetRelativeLocation() + m_pCamera->GetForwardVector() * 10000.f;

	// 仕事してない。仕事しろ（怒り）
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	// 弾の情報げっちゅ
	FString path = "/Game/BP/BulletBP.BulletBP_C";
	TSubclassOf<class AActor> sc = TSoftClassPtr<AActor>(FSoftObjectPath(*path)).LoadSynchronous();
	ABullet* SpawnBullet = (ABullet*)UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/Player/BulletBP.BulletBP_C");
	if (SpawnBullet != NULL)
	{
		m_playerFlags.flagBits.isShoot = true;
		//SpawnBullet->SetActorLocation(m_pSpringArm->GetRelativeLocation());
		SpawnBullet->Init(Start, End);
		SpawnBullet->SetAtk(m_playerStatus.equipGunData.atk + m_haveAmmoDatas[(int)m_playerStatus.equipGunData.gunType].atk);
	}

	m_haveGunDatas[m_playerStatus.equipGunID]->SetIsShot(true);

	m_ActionStatus = EActionStatus::Shot;
}

// 【入力バインド】走り
void APlayerChara::Input_Run()
{
	// 移動速度を走りの速度に変更
	m_playerStatus.moveSpeed = m_statusConst.runSpeed;

	// アクションの状態を走り状態に変更
	m_ActionStatus = EActionStatus::Run;
}

// 【入力バインド】アクション
void APlayerChara::Input_Action()
{
	// 何にも触れていない場合は処理しない
	if (m_pOverlapActor == NULL)
		return;

	// 扉に触れていた場合
	if (Cast<ADoorBase>(m_pOverlapActor))
	{
		// 扉に鍵がかかっていた場合
		if (Cast<ADoorBase>(m_pOverlapActor)->GetIsLock())
		{
			// インベントリを開く
			m_playerFlags.flagBits.isOpenMenu = true;
		}
		return;
	}

	// アイテムに触れていた時
	if (m_playerFlags.flagBits.isItemTouch == true)
	{
		// 取得時にメッシュを表示するアイテムかをセット
		m_playerFlags.flagBits.isShowGetItem = Cast<AItemBase>(m_pOverlapActor)->GetItemData().isShowInventory;

		// 弾薬に触れていた時
		if (Cast<AGunAmmoControl>(m_pOverlapActor))
		{
			// 触れていた弾薬
			AGunAmmoControl* OverlapAmmo = Cast<AGunAmmoControl>(m_pOverlapActor);

			// 触れていた弾薬を所持しているかを保管
			bool isHaveTypeAmmo = false;

			// 所持しているかをチェック
			for (int i = 0; i < (int)EAmmoType::Max; ++i)
			{
				// 持っていない
				if (m_haveAmmoDatas[i].ammoType == OverlapAmmo->GetAmmoData().ammoType)
				{
					isHaveTypeAmmo = true;
					break;
				}

			}

			// 取得した弾薬を弾薬管理用の配列に加算
			m_haveAmmoDatas[(int)OverlapAmmo->GetAmmoData().ammoType].ammoStock += OverlapAmmo->GetAmmoData().ammoStock;
			m_haveAmmoDatas[(int)OverlapAmmo->GetAmmoData().ammoType].ammoType = OverlapAmmo->GetAmmoData().ammoType;
			
			// 弾薬が1スタックの容量を超えていた場合
			if (m_haveAmmoDatas[(int)OverlapAmmo->GetAmmoData().ammoType].ammoStock > OverlapAmmo->GetAmmoData().ammoStockMax)
			{
				// 1スタックの最大値に補完
				m_haveAmmoDatas[(int)OverlapAmmo->GetAmmoData().ammoType].ammoStock = OverlapAmmo->GetAmmoData().ammoStockMax;
				return;
			}
			
			// アイテムの取得フラグを立てる
			m_playerFlags.flagBits.isItemGet = true;

			// アイテムに触れていない状態にする
			m_playerFlags.flagBits.isItemTouch = false;

			
			if (isHaveTypeAmmo)
				return;
		}

		// 銃に触れていた時
		if (Cast<AGunControl>(m_pOverlapActor))
		{
			// 触れている銃を一時保管
			AGunControl* OverlapGun = Cast<AGunControl>(m_pOverlapActor);

			// 触れている武器を所持している武器に新しく追加
			m_haveGunDatas.Add(OverlapGun);

			// 銃を初めて手に入れたとき
			if (m_playerStatus.equipGunData.gunType == EGunType::None)
			{
				// 銃の所持フラグを立てる
				m_playerFlags.flagBits.isHaveGun = true;

				// 装備している銃を更新
				m_playerStatus.equipGunData = OverlapGun->GetGunData();

				FString path = "/Game/BP/HandGunBP.HandGunBP_C";
				TSubclassOf<class AActor> sc = TSoftClassPtr<AActor>(FSoftObjectPath(*path)).LoadSynchronous();
				AGunControl* HandGun = (AGunControl*)UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/HandGunBP.HandGunBP_C");
				HandGun->SetActorLocation(GetActorLocation());
			}
		}
		
		// 鞄の更新処理
		for (int i = 0; i < m_ItemDatas.Num(); i++)
		{
			// 検索した場所が空の時
			if (m_ItemDatas[i].type == ItemType::None)
			{
				// 取得したアイテムの情報を入れる
				m_ItemDatas[i] = Cast<AItemBase>(m_pOverlapActor)->GetItemData();
				
				// アイテム取得フラグを立てる
				m_playerFlags.flagBits.isItemGet = true;

				// アイテムに触れていない状態にする
				m_playerFlags.flagBits.isItemTouch = false;
				break;
			}
		}
	}
}

// 【入力バインド】リロード処理
void APlayerChara::Input_Reload()
{
	// 銃を装備していない場合は処理しない
	if (m_playerStatus.equipGunData.gunType == EGunType::None)
		return;

	// 装備している銃の種類を数値化
	int EcuipGunTypeIndex = (int)m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData().gunType;

	// 装備している武器が存在している時
	if (m_haveGunDatas[m_playerStatus.equipGunID])
	{
		// ステータスをリロードに
		m_ActionStatus = EActionStatus::Reload;

		// リロード処理
		m_haveGunDatas[m_playerStatus.equipGunID]->Reload(m_haveAmmoDatas[EcuipGunTypeIndex].ammoStock);

		// 装備している銃を更新
		m_playerStatus.equipGunData = m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData();
	}
		
}

// 【入力バインド】インベントリ処理
void APlayerChara::Input_Inventory()
{
	// インベントリの開閉を切り替え
	m_playerFlags.flagBits.isOpenMenu = !(m_playerFlags.flagBits.isOpenMenu);

	// インベントリの状態を設定
	m_invenoryState = (m_playerFlags.flagBits.isOpenMenu) ? EInventoryState::Open : EInventoryState::Close;
}

// 【入力バインド】銃の切り替え処理
void APlayerChara::Input_ChangeGun(float _axisValue)
{
	// 銃を所持していない場合は処理しない
	if (m_playerFlags.flagBits.isHaveGun == false)
		return;

	// 上ホイール
	if (_axisValue >= 1.f)
	{
		// 装備中の武器の番号を減らす
		--m_playerStatus.equipGunID;

		// 0未満の時、補正をかける
		if (m_playerStatus.equipGunID < 0)
			m_playerStatus.equipGunID = m_haveGunDatas.Num() - 1;

		// 装備している銃を更新
		m_playerStatus.equipGunData = m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData();
	}
	// 下したホイール
	else if (_axisValue <= -1.f)
	{
		// 装備中の武器の番号を増やす
		++m_playerStatus.equipGunID;

		// 所持している銃の種類数を超えたら、補正をかける
		if (m_playerStatus.equipGunID > m_haveGunDatas.Num() - 1)
			m_playerStatus.equipGunID = 0;

		// 装備している銃を更新
		m_playerStatus.equipGunData = m_haveGunDatas[m_playerStatus.equipGunID]->GetGunData();
	}
}

// 被ダメージ処理
void APlayerChara::Damage(int _atk)
{
	// HPを減らす
	m_playerStatus.hp -= _atk;

	// カメラを揺らす
	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->PlayCameraShake(CameraShake, 1.0f);

	// 0より小さいとき補完をかける
	if (m_playerStatus.hp < 0)
		m_playerStatus.hp = 0;
}

// インベントリのカーソル位置を渡す
int APlayerChara::GetCursorIndex(const int _index , const int _moveValue)
{
	// インベントリを開いていない場合は処理しない
	if (m_playerFlags.flagBits.isOpenMenu == false)
		return _index;

	// 移動可能かのフラグを一時保管
	bool ret = false;

	// 上下のカーソル移動
	if (FMath::Abs(_moveValue) % 4 == 0)
	{
		// 上入力
		if (_moveValue < 0)
			ret = _index >= 4;
		// 下入力
		else
			ret = (_index + 4) < m_bagSize;
	}
	// 左右のカーソル移動
	else if (FMath::Abs(_moveValue) == 1)
	{
		// 左入力
		if (_moveValue < 0)
			ret = (_index % 4) != 0;
		// 右入力
		else
			ret = (_index % 4) <= 2;
	}

	// 移動可能であれば移動
	if (ret)
		return _index + _moveValue;

	return _index;
}

// 死亡したかを渡す
bool APlayerChara::GetIsDead()
{
	return (m_playerStatus.hp <= 0) ? true : false;
}

// 回復処理
void APlayerChara::Heal(const int _index, const int _value)
{
	m_playerStatus.hp += _value;

	if (m_playerStatus.hp > m_playerStatus.maxHP)
		m_playerStatus.hp = m_playerStatus.maxHP;

	m_ItemDatas[_index] = FItemData::NoneData();
}

// 銃を撃った時のカメラの揺れ
void APlayerChara::ShootCameraShake(int _deltaTime)
{
	if (m_playerFlags.flagBits.isShoot == true)
	{
		UE_LOG(LogTemp, Error, TEXT("Error!!!"));
		m_Count += 1;

		if (m_Count < 3.f)
		{

			m_pCamera->SetRelativeRotation(FRotator(m_pCamera->GetRelativeRotation().Pitch + 0.3f, m_pCamera->GetRelativeRotation().Yaw, m_pCamera->GetRelativeRotation().Roll));
			UE_LOG(LogTemp, Error, TEXT("Error..."));
		}
		else if (m_Count > 3.f)
		{
			m_Count = 0.f;
			m_pCamera->SetRelativeRotation(FRotator(m_pCamera->GetRelativeRotation().Pitch - 0.3, m_pCamera->GetRelativeRotation().Yaw, m_pCamera->GetRelativeRotation().Roll));
			m_playerFlags.flagBits.isShoot = false;
		}
	}
}

// 画角変更(追加)
void APlayerChara::Changeview(float _deltaTime)
{
	if (m_playerFlags.flagBits.isHaveGun == true)
	{
		if (m_playerFlags.flagBits.isGunHold == true)
		{
			if (m_Viewvalue > m_SetView)
			{
				m_Viewvalue -= 150.f * _deltaTime;
				m_pCamera->SetFieldOfView(m_Viewvalue);
			}
		}
		else
		{
			if (m_Viewvalue < 91.f)								// ☆☆☆☆☆☆☆☆☆☆7/12(月)に追加しました☆☆☆☆☆☆☆☆☆☆☆☆
			{
				m_Viewvalue += 50.f * _deltaTime;					// ☆☆☆☆☆☆☆☆☆☆7/12(月)に追加しました☆☆☆☆☆☆☆☆☆☆☆☆
				m_pCamera->SetFieldOfView(m_Viewvalue);			// ☆☆☆☆☆☆☆☆☆☆7/12(月)に追加しました☆☆☆☆☆☆☆☆☆☆☆☆
			}
		}
	}
}