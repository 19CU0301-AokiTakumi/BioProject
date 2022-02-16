
#include "PlayerChara.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "DoorBase.h"
#include "ItemBase.h"
#include "EventObjectBase.h"
#include "Bullet.h"
#include "GunControl.h"
#include "BathtubEventControl.h"
#include "BookEventControl.h"
#include "DrawerControl.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"
//#include "MotionControllerComponent.h"
//#include "XRMotionControllerBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Engine.h"
#include "MessageObject.h"
#include "RopeDoubleDoor.h"

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
	, m_SocketLocation(FVector::ZeroVector)
	, m_GunLocation(FVector::ZeroVector)
	, m_afterDead(false)
	, m_SetView(0.f)
	, m_DefaultViewvalue(91.f)
	, m_prevAxisValue(0.f)
	, m_pAttachObject(NULL)
	, m_pTempKnife(NULL)
	, m_pTempGun(NULL)
	, m_Bathtub(NULL)
	, m_Piano(NULL)
	, m_pmagazine(NULL)
	, LadderDown(false)
	, Ladderflag(false)
	, LadderUp(false)
	, Ladderflag2(false)
	, GameClear(false)
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
		m_pSpringArm->CameraLagSpeed = 0.f;
		//　カメラの回転ラグを使うかを設定
		m_pSpringArm->bEnableCameraRotationLag = true;
		//　カメラ回転ラグの速度を設定
		m_pSpringArm->CameraRotationLagSpeed = 20.f;
	}

	// カメラのオブジェクトを生成
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (m_pCamera)
		m_pCamera->SetupAttachment(m_pSpringArm);

	ConstructorHelpers::FObjectFinder<USoundBase> ShotSE(TEXT("/Game/Sound/Bullet/HandGunSE.HandGunSE"));
	m_pShotSE = ShotSE.Object;

	ConstructorHelpers::FObjectFinder<USoundBase> DiningSE(TEXT("/Game/Sound/Ambient/Dining.Dining"));
	m_pDiningSE = DiningSE.Object;

	// 構造体の初期化
	m_playerStatus = { 10, 10, 1000.f, 0 };
	m_statusConst = { 1000.f, 10000000.f };

	// アニメーションが終わった時間を格納する配列の初期化
	for (int i = 0; i < (int)EActionStatus::Max; i++)
	{
		AnimEndFrame[i] = 0;
	}
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
	m_Viewvalue = 90.f;
	m_DefaultViewvalue = 90.f;
	m_pCamera->SetFieldOfView(m_DefaultViewvalue);

	m_playerStatus.moveSpeed = m_statusConst.walkSpeed;

	// アニメーション初期化
	m_PrevStatus = m_ActionStatus;

	m_Bathtub = Cast<ABathtubEventControl>(UMyGameInstance::GetActorFromTag(this, "Bathtub"));
	m_Piano = Cast<APianoEventControl>(UMyGameInstance::GetActorFromTag(this, "Piano"));
}

// 毎フレーム更新処理
void APlayerChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove(DeltaTime);
	UpdateCamera(DeltaTime);
	ShootCameraShake(DeltaTime);

	CountTime(DeltaTime);

	// 画角変更
	Changeview(DeltaTime);

	if (m_haveGunDatas.Num() > 0 && Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
	{
		Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID])->CheckFireRate(DeltaTime);
	}

	switch (m_ActionStatus)
	{
	case EActionStatus::Idle:
		//UE_LOG(LogTemp, Error, TEXT("Idle"));
		break;

	case EActionStatus::Reload:
		//UE_LOG(LogTemp, Error, TEXT("Reload"));
		break;

	case EActionStatus::Walk:
		//UE_LOG(LogTemp, Error, TEXT("Walk"));
		break;

	case EActionStatus::Run:
		break;

	case EActionStatus::Shot:
		//UE_LOG(LogTemp, Error, TEXT("Shot"));
		m_ActionStatus = EActionStatus::GunIdle;
		m_CountTime += DeltaTime;
		if (m_CountTime >= 2.f)
		{
			m_CountTime = 0.f;
		}

		break;

	case EActionStatus::Aim:
		//UE_LOG(LogTemp, Error, TEXT("aim"));
		break;

	case EActionStatus::KnifeIdle:
		//UE_LOG(LogTemp, Error, TEXT("KnifeIdle"));
		break;

	case EActionStatus::KnifeAttack:
		//UE_LOG(LogTemp, Error, TEXT("KnifeAttack"));
		break;

	case EActionStatus::GunIdle:
		//UE_LOG(LogTemp, Error, TEXT("GunIdle"));
		break;

	case EActionStatus::KnifeWalk:
		//UE_LOG(LogTemp, Error, TEXT("GunWalk"));
		break;

	case EActionStatus::ChangeWeapon:
		UE_LOG(LogTemp, Error, TEXT("ChangeWeapon"));
		break;

	case EActionStatus::GunRun:
		break;

	case EActionStatus::KnifeRun:
		break;
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
	InputComponent->BindAction("Run", IE_Released, this, &APlayerChara::Input_RunEnd);

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
	// アイテムに触れている時
	if (Cast<AItemBase>(OtherActor) && !OtherComp->ComponentHasTag("Blade"))
	{
		// アイテムに触れているフラグを立てる
		m_playerFlags.flagBits.isItemTouch = true;

		// 触れているアクターを保管
		m_pOverlapActor = OtherActor;
	}

	if (OtherActor->ActorHasTag("GameClear"))
	{
		GameClear = true;
	}
	
	if (OtherComp->ComponentHasTag("Ladder"))
	{
		LadderDown = true;
	}

	if (OtherComp->ComponentHasTag("Ladder2"))
	{
		LadderUp = true;
	}

	if (OtherComp->ComponentHasTag("floorsound"))
	{
		UE_LOG(LogTemp, Error, TEXT("morio"));
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pDiningSE, FVector(-3300.f, 450.f, 500.f));
	}

	if (Cast<AEventObjectBase>(OtherActor))
	{
		m_playerFlags.flagBits.isEventObjTouch = true;

		// 触れているアクターを保管
		m_pOverlapActor = OtherActor;
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
			Cast<ADoorBase>(OtherActor)->SetIsLock(false);
		}

		// 触れているアクターを保管
		m_pOverlapActor = OtherActor;
		
	}
}

// オーバーラップ接触をし終えたときに呼ばれるイベント関数
void APlayerChara::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// アイテムに触れているフラグをおろす
	m_playerFlags.flagBits.isItemTouch = false;

	m_playerFlags.flagBits.isEventObjTouch = false;

	if (Cast<AMessageObject>(m_pOverlapActor) || Cast<ADoorBase>(m_pOverlapActor))
	{
		// 保管していた触れていたアクターを無効にする
		m_pOverlapActor = NULL;
	}

	// 扉から離れた時
	if (Cast<ADoorBase>(OtherActor))
	{
		// インベントリを閉じる
		m_playerFlags.flagBits.isOpenMenu = false;
	}

	if (OtherComp->ComponentHasTag("Ladder"))
	{
		LadderDown = false;
	}

	if (OtherComp->ComponentHasTag("Ladder2"))
	{
		LadderUp = false;
	}
}


// 移動処理
void APlayerChara::UpdateMove(float _deltaTime)
{
	if ((Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart())
		|| m_playerFlags.flagBits.isOpenMenu || m_playerFlags.flagBits.isOpenKeyMenu || m_Bathtub->GetOpenWidget() || (m_Bathtub->GetIsEventStart() && m_Bathtub->GetActionEnd() == false) || m_playerFlags.flagBits.isOpenNotKeyMatchMenu)
		return;

	if (m_pSpringArm)
	{
		m_Count += _deltaTime;

		//　キャラクターの移動
		{
			// SpringArmが向く方向に、入力による移動量をPawnMovementComponentに渡す
			const FVector forwardVec = m_pSpringArm->GetForwardVector();
			AddMovementInput(forwardVec, m_CharaMoveInput.Y * m_playerStatus.moveSpeed);

			const FVector rightVec = m_pSpringArm->GetRightVector();
			AddMovementInput(rightVec, m_CharaMoveInput.X * m_statusConst.sideWalkSpeed);
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
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart()
		|| m_playerFlags.flagBits.isOpenMenu || m_playerFlags.flagBits.isOpenKeyMenu || m_Bathtub->GetOpenWidget() || (m_Bathtub->GetIsEventStart() && m_Bathtub->GetActionEnd() == false) || m_playerFlags.flagBits.isOpenNotKeyMatchMenu)
		return;

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

FGunData APlayerChara::GetEquipGunData() const
{ 
	
	if (m_haveGunDatas.Num() > 0)
		if (Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
			return  Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID])->GetGunData();

	return FGunData::NoneData();
}

//　【入力バインド】キャラ移動：前後
void APlayerChara::Input_MoveForward(float _axisValue)
{
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart() || m_Bathtub->GetOpenWidget() == true)
		return;
	if (m_playerFlags.flagBits.isOpenMenu == false && m_playerFlags.flagBits.isOpenKeyMenu == false)
		m_CharaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;

	if (m_CharaMoveInput.Y != 0 || m_CharaMoveInput.X != 0.f)
	{
		if (m_playerStatus.moveSpeed == m_statusConst.walkSpeed)
		{
			if (m_playerFlags.flagBits.isHaveGun == true && m_ActionStatus != EActionStatus::Reload && m_ActionStatus != EActionStatus::GunWalk && m_ActionStatus != EActionStatus::ChangeWeapon
				&& m_ActionStatus != EActionStatus::KnifeWalk)
			{
				m_ActionStatus = EActionStatus::GunWalk;
			}
			else if (m_playerFlags.flagBits.isHaveKnife == true  && m_ActionStatus != EActionStatus::KnifeWalk
				     && m_ActionStatus != EActionStatus::KnifeAttack && m_ActionStatus != EActionStatus::GunWalk && m_ActionStatus != EActionStatus::ChangeWeapon && m_ActionStatus != EActionStatus::Reload)
			{
				m_ActionStatus = EActionStatus::KnifeWalk;
			}
			else if (m_playerFlags.flagBits.isHaveGun == false && m_playerFlags.flagBits.isHaveKnife == false && m_ActionStatus != EActionStatus::Walk && m_ActionStatus != EActionStatus::ChangeWeapon
				    && m_ActionStatus != EActionStatus::KnifeWalk && m_ActionStatus != EActionStatus::GunWalk && m_ActionStatus != EActionStatus::Reload)
			{
				m_ActionStatus = EActionStatus::Walk;
			}
		}
	}

	if (m_CharaMoveInput.Y == 0.f && m_CharaMoveInput.X == 0.f)
	{
		if (m_playerFlags.flagBits.isHaveGun == true && m_ActionStatus == EActionStatus::GunWalk)
		{
			if (m_ActionStatus != EActionStatus::Reload && m_ActionStatus != EActionStatus::ChangeWeapon)
			{
				m_ActionStatus = EActionStatus::GunIdle;
			}
		}
		else if (m_playerFlags.flagBits.isHaveKnife == true  && m_ActionStatus == EActionStatus::KnifeWalk)
		{
			if (m_ActionStatus != EActionStatus::KnifeAttack && m_ActionStatus != EActionStatus::ChangeWeapon)
			{
				m_ActionStatus = EActionStatus::KnifeIdle;
			}
		}
		else if (m_playerFlags.flagBits.isHaveGun == false && m_playerFlags.flagBits.isHaveKnife == false && m_ActionStatus != EActionStatus::ChangeWeapon)
		{
			m_ActionStatus = EActionStatus::Idle;
		}
	}

}

//　【入力バインド】キャラ移動左右
void APlayerChara::Input_MoveRight(float _axisValue)
{
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart() || m_Bathtub->GetOpenWidget() == true)
		return;
	if (m_playerFlags.flagBits.isOpenMenu == false && m_playerFlags.flagBits.isOpenKeyMenu == false)
		m_CharaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 1.0f;

}



//　【入力バインド】カメラの回転：（Y軸）
void APlayerChara::Input_CameraRotatePitch(float _axisValue)
{
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart() || m_Bathtub->GetOpenWidget() == true)
		return;
	if (m_playerFlags.flagBits.isOpenMenu == false && m_playerFlags.flagBits.isOpenKeyMenu == false)
		m_CameraRotationInput.Y = _axisValue;
}

//　【入力バインド】カメラ回転：（Z軸）
void APlayerChara::Input_CameraRotateYaw(float _axisValue)
{
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart() || m_Bathtub->GetOpenWidget() == true)
		return;
	if (m_playerFlags.flagBits.isOpenMenu == false && m_playerFlags.flagBits.isOpenKeyMenu == false)
		m_CameraRotationInput.X = _axisValue;
}

//【入力バインド】銃を構える
void APlayerChara::Input_Hold()
{
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart())
	{
		if (m_playerFlags.flagBits.isGunHold)
			m_playerFlags.flagBits.isGunHold = false;
		return;
	}
		
	if (m_haveGunDatas.Num() <= 0 || m_haveGunDatas[m_playerStatus.equipGunID] == NULL)
		return;

	// 銃を構えているかのフラグを切り替える
	m_playerFlags.flagBits.isGunHold = !(m_playerFlags.flagBits.isGunHold);
	m_playerStatus.moveSpeed = (m_playerFlags.flagBits.isGunHold) ? m_statusConst.gunHoldSpeed : m_statusConst.walkSpeed;
}

// 【入力バインド】銃を撃つ
void APlayerChara::Input_Shooting()
{
	if (Cast<AMessageObject>(m_pOverlapActor) && Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart())
		return;

	if (m_playerFlags.flagBits.isOpenMenu || m_playerFlags.flagBits.isOpenKeyMenu)
		return;

	// 武器を持っていない場合は処理しない
	if (m_haveGunDatas.Num() <= 0)
		return;

	// 装備している武器がナイフの時
	if (Cast<AKnifeControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
	{
		// ナイフの刀身のコリジョン判定を有効にする
		Cast<AKnifeControl>(m_pAttachObject)->SetAttckColEnable(true);

		// ナイフ攻撃状態にする
		m_ActionStatus = EActionStatus::KnifeAttack;

		return;
	}
		
	if (Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]) == NULL)
		return;

	AGunControl* GunControl = Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]);

	if (GunControl == NULL)
		return;

	// 銃が既に撃たれている状態の場合処理しない
	if (GunControl->GetIsShot())
		return;

	// 銃に弾が入っていない場合は処理しない
	if (GunControl->GetGunData().ammoStock <= 0)
	{
		if (m_haveAmmoDatas[(int)GunControl->GetGunData().gunType].ammoStock > 0)
			Input_Reload();
		return;
	}

	

	if (!m_playerFlags.flagBits.isGunHold)
		return;

	Cast<AGunControl>(m_pAttachObject)->Shot(GetMesh()->GetSocketLocation("R_Flash_Socket"));
	//UGameplayStatics::PlaySoundAtLocation(GetWorld(), m_pShotSE, FVector::ZeroVector);

	// 装備している銃の情報を一時保管
	FGunData NewGunData = GunControl->GetGunData();

	// 銃の弾を減らす
	GunControl->RemoveAmmo(1);

	// データを反映
	//m_playerStatus.equipGunData = Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]);

	// 弾の発射位置
	//FVector Start = m_GunLocation + m_SocketLocation;
	//FVector Start = m_pSpringArm->GetRelativeLocation()+GetActorLocation();
	FVector Start = GetActorLocation() + m_pSpringArm->GetRelativeLocation();
	/*UE_LOG(LogTemp, Error, TEXT("= %f,= %f,= %f"), m_SocketLocation.X, m_SocketLocation.Y, m_SocketLocation.Z);*/

	// 弾の弾着位置
	FVector EndOffset = FVector(0.f, 0.f, 0.f);
	FVector End = GetActorLocation() + EndOffset + m_pCamera->GetRelativeLocation() + m_pSpringArm->GetRelativeLocation() + m_pCamera->GetForwardVector() * 10000.f;
	DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 1.0f);
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
		SpawnBullet->SetAtk(GunControl->GetGunData().atk + m_haveAmmoDatas[(int)GunControl->GetGunData().gunType].atk);
	}

	GunControl->SetIsShot(true);

	if (m_ActionStatus == EActionStatus::Aim)
	{
		m_ActionStatus = EActionStatus::Shot;
	}
	
}

// 【入力バインド】走り
void APlayerChara::Input_Run()
{
	m_playerFlags.flagBits.isRun = true;

	// 移動速度を走りの速度に変更
	m_playerStatus.moveSpeed = m_statusConst.runSpeed;

	// アクションの状態を走り状態に変更
	if (m_playerFlags.flagBits.isHaveGun == true && m_playerFlags.flagBits.isRun == true && m_ActionStatus == EActionStatus::GunWalk )
	{
		m_ActionStatus = EActionStatus::GunRun;
		//UE_LOG(LogTemp, Error, TEXT("mogu111111111111111111111111111111"));
	}
	else if (m_playerFlags.flagBits.isHaveKnife == true && m_playerFlags.flagBits.isRun == true && m_ActionStatus == EActionStatus::KnifeWalk)
	{
		m_ActionStatus = EActionStatus::KnifeRun;
	}
	else if(m_playerFlags.flagBits.isHaveGun == false && m_playerFlags.flagBits.isHaveKnife == false && m_playerFlags.flagBits.isRun == true && m_ActionStatus == EActionStatus::Walk)
	{
		m_ActionStatus = EActionStatus::Run;
	}
}

void APlayerChara::Input_RunEnd()
{
	m_playerFlags.flagBits.isRun = false;

	m_playerStatus.moveSpeed = m_statusConst.walkSpeed;

	if (m_playerFlags.flagBits.isHaveGun == true && m_playerFlags.flagBits.isRun == false && m_ActionStatus == EActionStatus::GunRun)
	{
		m_ActionStatus = EActionStatus::GunWalk;
		//UE_LOG(LogTemp, Error, TEXT("mogu111111111111111111111111111111"));
	}
	else if (m_playerFlags.flagBits.isHaveKnife == true && m_playerFlags.flagBits.isRun == false && m_ActionStatus == EActionStatus::KnifeRun)
	{
		m_ActionStatus = EActionStatus::KnifeWalk;
	}
	else if (m_playerFlags.flagBits.isHaveGun == false && m_playerFlags.flagBits.isHaveKnife == false && m_playerFlags.flagBits.isRun == true && m_ActionStatus == EActionStatus::Run)
	{
		m_ActionStatus = EActionStatus::Walk;
	}
}

// 【入力バインド】アクション
void APlayerChara::Input_Action()
{
	if (LadderDown == true)
	{
		Ladderflag = true;
		SetActorRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y - 400.f, GetActorLocation().Z - 500.f));
	}

	if (LadderUp == true)
	{
		SetActorRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y + 400.f, GetActorLocation().Z + 500.f));
	}

	// 何にも触れていない場合は処理しない
	if (m_pOverlapActor == NULL)
		return;
	UE_LOG(LogTemp, Error, TEXT("DoorTouch"));

	if (m_playerFlags.flagBits.isRun)
		m_playerFlags.flagBits.isRun = false;

	// 扉に触れていた場合
	if (Cast<ADoorBase>(m_pOverlapActor))
	{
		// 扉に鍵がかかっていた場合
		if (Cast<ADoorBase>(m_pOverlapActor)->GetIsLock() && Cast<ARopeDoubleDoor>(m_pOverlapActor) == NULL && m_playerFlags.flagBits.isOpenNotKeyMatchMenu == false)
		{
			// インベントリを開く
			m_playerFlags.flagBits.isOpenKeyMenu = true;

			// インベントリの状態を設定
			m_invenoryState = (m_playerFlags.flagBits.isOpenKeyMenu) ? EInventoryState::Open : EInventoryState::Close;
		}
		return;
	}

	if (m_playerFlags.flagBits.isGunHold)
		return;

	if (Cast<AEventObjectBase>(m_pOverlapActor))
	{
		if (Cast<AMessageObject>(m_pOverlapActor))
		{
			if (Cast<AMessageObject>(m_pOverlapActor)->GetIsEventStart())
			{
				Cast<AMessageObject>(m_pOverlapActor)->SetIsEventStart(false);
				return;
			}
			Cast<AMessageObject>(m_pOverlapActor)->SetIsEventStart(true);
		}
		else if (Cast<ABathtubEventControl>(m_pOverlapActor))
		{
			Cast<ABathtubEventControl>(m_pOverlapActor)->SetIsEventStart(true);

			//if (Cast<ABathtubEventControl>(m_pOverlapActor)->GetIsEventStart())
			//{
			//	
			//}

			if (Cast<ABathtubEventControl>(m_pOverlapActor)->GetOpenWidget())
			{
				Cast<ABathtubEventControl>(m_pOverlapActor)->SetDoAction(true);
				Cast<ABathtubEventControl>(m_pOverlapActor)->PlaySound();
			}
				
		}
		else if (Cast<ADrawerControl>(m_pOverlapActor))
		{
			Cast<ADrawerControl>(m_pOverlapActor)->SetIsEventStart(true);
		}
		else if (Cast<ABookEventControl>(m_pOverlapActor))
		{
			Cast<ABookEventControl>(m_pOverlapActor)->SetIsEventStart(true);
		}
		else if (Cast<APianoEventControl>(m_pOverlapActor))
		{
			Cast<APianoEventControl>(m_pOverlapActor)->SetIsEventStart(true);
		}
	}

	// アイテムに触れていた時
	if (m_playerFlags.flagBits.isItemTouch == true && Cast<AItemBase>(m_pOverlapActor))
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
			// 触れている武器を所持している武器に新しく追加
			if (m_pTempGun)
				m_pTempGun = nullptr;
			m_pTempGun = NewObject<AGunControl>();
			m_pTempGun->SetItemData(Cast<AItemBase>(m_pOverlapActor)->GetItemData());
			m_pTempGun->SetGunData(Cast<AGunControl>(m_pOverlapActor)->GetGunData());
			m_haveGunDatas.Add(m_pTempGun);


			// 銃を初めて手に入れたとき
			if (m_haveGunDatas.Num() > 0 || m_haveGunDatas[m_playerStatus.equipGunID])
			{
				// 銃の所持フラグを立てる
				m_playerFlags.flagBits.isHaveGun = true;

				// 装備している銃を更新
				//m_haveGunDatas[m_playerStatus.equipGunID] = Cast<AGunControl>(m_haveGunDatas[m_haveGunDatas.Num() - 1]);
				m_ActionStatus = EActionStatus::GunIdle;
				m_playerStatus.equipGunID = m_haveGunDatas.Num() - 1;
				SetAttachWeapon(m_haveGunDatas[m_playerStatus.equipGunID]);
			}
		}

		if (Cast<AKnifeControl>(m_pOverlapActor))
		{
			// 触れている武器を所持している武器に新しく追加
			if (m_pTempKnife)
				m_pTempKnife = nullptr;
			m_pTempKnife = NewObject<AKnifeControl>();
			m_pTempKnife->SetItemData(Cast<AItemBase>(m_pOverlapActor)->GetItemData());
			m_pTempKnife->SetKnifeData(Cast<AKnifeControl>(m_pOverlapActor)->GetKnifeData());
			m_haveGunDatas.Add(m_pTempKnife);
			m_ActionStatus = EActionStatus::KnifeIdle;


			// 銃を初めて手に入れたとき
			if (m_haveGunDatas.Num() > 0 || m_haveGunDatas[m_playerStatus.equipGunID])
			{
				// 銃の所持フラグを立てる
				m_playerFlags.flagBits.isHaveGun = false;
				m_playerFlags.flagBits.isHaveKnife = true;

				// 装備している銃を更新
				//m_haveGunDatas[m_playerStatus.equipGunID] = Cast<AKnifeControl>(m_haveGunDatas[m_haveGunDatas.Num() - 1]);
				
				m_playerStatus.equipGunID = m_haveGunDatas.Num() - 1;

				SetAttachWeapon(m_haveGunDatas[m_playerStatus.equipGunID]);
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

	if (m_pOverlapActor->ActorHasTag("OwnerRoomKey"))
		Cast<AItemBase>(m_pOverlapActor)->DestroyMesh();
}

// 【入力バインド】リロード処理
void APlayerChara::Input_Reload()
{
	// 銃を装備していない場合は処理しない
	if (m_haveGunDatas.Num() <= 0 || Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]) == NULL)
		return;

	if (m_ActionStatus == EActionStatus::Aim)
		return;

	AGunControl* GunControl = Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]);

	if (GunControl->GetIsShot())
		return;

	// 装備している銃の種類を数値化
	int EcuipGunTypeIndex = (int)GunControl->GetGunData().gunType;

	// 装備している武器が存在している時
	if (m_haveGunDatas[m_playerStatus.equipGunID])
	{
		if (m_haveAmmoDatas[EcuipGunTypeIndex].ammoStock)
		{
			// ステータスをリロードに
			m_ActionStatus = EActionStatus::Reload;

			m_pmagazine = UMyGameInstance::GetSpawnActor(GetWorld(), "/Game/BP/Gun/Magazine.Magazine_C");
			if (m_pmagazine != NULL)
				m_pmagazine->AttachToComponent(GetMesh(), { EAttachmentRule::SnapToTarget, true }, "Hand_Mug");
			
		}

		// リロード処理
		GunControl->Reload(m_haveAmmoDatas[EcuipGunTypeIndex].ammoStock);

		// 装備している銃を更新
		//m_playerStatus.equipGunData = GunControl;
	}

}

// 【入力バインド】インベントリ処理
void APlayerChara::Input_Inventory()
{
	if (m_playerFlags.flagBits.isOpenKeyMenu)
	{
		// インベントリの開閉を切り替え
		m_playerFlags.flagBits.isOpenKeyMenu = false;

		// インベントリの状態を設定
		m_invenoryState = (m_playerFlags.flagBits.isOpenKeyMenu) ? EInventoryState::Open : EInventoryState::Close;
		return;
	}
	// インベントリの開閉を切り替え
	m_playerFlags.flagBits.isOpenMenu = !(m_playerFlags.flagBits.isOpenMenu);

	// インベントリの状態を設定
	m_invenoryState = (m_playerFlags.flagBits.isOpenMenu) ? EInventoryState::Open : EInventoryState::Close;
}

// 【入力バインド】銃の切り替え処理
void APlayerChara::Input_ChangeGun(float _axisValue)
{
	if (m_ActionStatus == EActionStatus::Reload)
		return;

	if (m_ActionStatus == EActionStatus::Aim)
		return;

	if (_axisValue == m_prevAxisValue)
		return;

	if (m_haveGunDatas.Num() <= 1)
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
		//m_playerStatus.equipGunData = m_playerStatus.equipGunData;
	}
	// 下ホイール
	else if (_axisValue <= -1.f)
	{
		// 装備中の武器の番号を増やす
		++m_playerStatus.equipGunID;

		// 所持している銃の種類数を超えたら、補正をかける
		if (m_playerStatus.equipGunID > m_haveGunDatas.Num() - 1)
			m_playerStatus.equipGunID = 0;

		// 装備している銃を更新
		//m_playerStatus.equipGunData = m_playerStatus.equipGunData;
	}

	SetAttachWeapon(m_haveGunDatas[m_playerStatus.equipGunID]);
	
	m_ActionStatus = EActionStatus::ChangeWeapon;
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

void APlayerChara::SetAttachWeapon(AItemBase* _equipWeapon)
{
	FString weaponPath = "";
	FName socketPath = "";

	if (m_pAttachObject)
	{
		m_pAttachObject->GetMesh()->SetVisibility(false);
		if (Cast<AKnifeControl>(m_pAttachObject))
			Cast<AKnifeControl>(m_pAttachObject)->SetCollisionEnabled(false);
		m_pAttachObject = NULL;
	}

	if (Cast<AGunControl>(_equipWeapon))
	{
		UE_LOG(LogTemp, Error, TEXT("HandGunDESU"));
		weaponPath = "/Game/BP/Gun/HandGunBP.HandGunBP_C";
		socketPath = "R_Middle1_Socket";
	}
	else if (Cast<AKnifeControl>(_equipWeapon))
	{
		UE_LOG(LogTemp, Error, TEXT("KnifeDESU"));
		weaponPath = "/Game/BP/Weapon/Knife.Knife_C";
		socketPath = "R_Knife_Socket";
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("GomiDESU"));
	}

	m_pAttachObject = (AItemBase*)UMyGameInstance::GetSpawnActor(GetWorld(), weaponPath);

	if (Cast<AGunControl>(m_pAttachObject))
	{
		Cast<AGunControl>(m_pAttachObject)->SetCollisionEnabled(false);
		m_playerFlags.flagBits.isHaveGun = true;
	}
	else if (Cast<AKnifeControl>(m_pAttachObject))
	{
		Cast<AKnifeControl>(m_pAttachObject)->SetCollisionEnabled(false);
		Cast<AKnifeControl>(m_pAttachObject)->SetAttckColEnable(false);
		m_playerFlags.flagBits.isHaveGun = false;
	}


	if (m_pAttachObject)
		m_pAttachObject->GetMesh()->AttachToComponent(GetMesh(), { EAttachmentRule::SnapToTarget, true }, socketPath);
}


// インベントリのカーソル位置を渡す
int APlayerChara::GetCursorIndex(const int _index, const int _moveValue)
{
	// インベントリを開いていない場合は処理しない
	if (m_playerFlags.flagBits.isOpenMenu == false && m_playerFlags.flagBits.isOpenKeyMenu == false && m_Bathtub->GetOpenWidget() == false && m_Piano->GetIsEventStart() == false)
		return _index;

	// 移動可能かのフラグを一時保管
	bool ret = false;

	if (m_playerFlags.flagBits.isOpenMenu == true || m_playerFlags.flagBits.isOpenKeyMenu == true)
	{
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
	}


	if (m_Bathtub->GetOpenWidget())
	{
		if (FMath::Abs(_moveValue) == 1)
		{
			// 左入力
			if (_moveValue < 0)
				return 0;
			// 右入力
			else
				return 1;
		}
	}

	if (m_Piano->GetIsEventStart())
	{
		if (FMath::Abs(_moveValue) == 1)
		{
			// 左入力
			if (_moveValue < 0)
				ret = (_index % 8) != 0;
			// 右入力
			else
				ret = (_index % 8) != 7;
		}
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

void APlayerChara::AfterDeath(float _deltaTime)
{
	m_CountTime += _deltaTime;

	FRotator camRot = m_pCamera->GetRelativeRotation();
	float camPitchdown = camRot.Pitch + 5.f * m_CountTime;
	m_pCamera->SetRelativeRotation(FRotator(camPitchdown, camRot.Yaw, camRot.Roll));

	FVector camLoc = m_pCamera->GetRelativeLocation();
	float camZdown = camLoc.Z - 10.f * m_CountTime;
	m_pCamera->SetRelativeLocation(FVector(camLoc.X, camLoc.Y, camZdown));

	if (m_CountTime > 2.f)
		m_afterDead = true;
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
		m_playerFlags.flagBits.isShoot = false;
	}
}

// 画角変更(追加)
void APlayerChara::Changeview(float _deltaTime)
{
	if (m_ActionStatus == EActionStatus::Reload)
		return;

		if (m_playerFlags.flagBits.isGunHold == true)
		{
			if (m_ActionStatus != EActionStatus::Shot)
			{
				// ここを変える
				m_ActionStatus = EActionStatus::Aim;
			}
			
			if (m_Viewvalue > m_SetView)
			{
				m_Viewvalue -= 200.f * _deltaTime;
				m_pCamera->SetFieldOfView(m_Viewvalue);
			}
		}
		else
		{
			if (m_Viewvalue < m_DefaultViewvalue)
			{
				m_Viewvalue += 200.f * _deltaTime;
				m_pCamera->SetFieldOfView(m_Viewvalue);
			}
		}
	
}

void APlayerChara::CountTime(float _deltaTime)
{
	if (m_PrevStatus == m_ActionStatus)
		return;

	m_CountTime += _deltaTime;


	switch (m_ActionStatus)
	{
		case EActionStatus::Reload:
			if (m_CountTime >= AnimEndFrame[(int)EActionStatus::Reload])
			{
				m_ActionStatus = EActionStatus::GunIdle;
				m_CountTime = 0.f;
				m_PrevStatus = m_ActionStatus;
			}
			if (m_CountTime >= 2.67f)
			{
				if (m_pmagazine != NULL)
				m_pmagazine->Destroy();
			}
			break;

		case EActionStatus::Shot:
			if (m_CountTime >= AnimEndFrame[(int)EActionStatus::Shot])
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Aho"), m_ActionStatus));
				if (m_playerFlags.flagBits.isShoot == true)
				{
					m_ActionStatus = EActionStatus::GunIdle;
					m_CountTime = 0.f;

					m_PrevStatus = m_ActionStatus;
				}
			}
			break;

		case EActionStatus::Aim:
		{
			if (m_CountTime >= AnimEndFrame[(int)EActionStatus::Aim])
			{
				if (Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
				{
					m_ActionStatus = EActionStatus::GunIdle;
				}
				else if (Cast<AKnifeControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
				{
					m_ActionStatus = EActionStatus::KnifeIdle;
				}
				m_CountTime = 0.f;

				m_PrevStatus = m_ActionStatus;
			}

			break;
		}

		case EActionStatus::KnifeIdle:
		{
			if (m_CountTime >= AnimEndFrame[(int)EActionStatus::KnifeIdle])
			{
				m_ActionStatus = EActionStatus::KnifeIdle;
				m_CountTime = 0.f;

				m_PrevStatus = m_ActionStatus;
			}
			break;
		}

		case EActionStatus::KnifeAttack:
		{
			if (m_CountTime >= AnimEndFrame[(int)EActionStatus::KnifeAttack])
			{
				m_ActionStatus = EActionStatus::KnifeIdle;
				m_CountTime = 0.f;

				Cast<AKnifeControl>(m_pAttachObject)->SetAttckColEnable(false);

				m_PrevStatus = m_ActionStatus;
			}
			break;
		}

		case EActionStatus::ChangeWeapon:
		{
			if (m_CountTime >= AnimEndFrame[(int)EActionStatus::ChangeWeapon])
			{
				if (Cast<AGunControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
				{
					m_ActionStatus = EActionStatus::GunIdle;
					//UE_LOG(LogTemp, Error, TEXT("mogu111111111111111111111111111111"));
				}
				else if (Cast<AKnifeControl>(m_haveGunDatas[m_playerStatus.equipGunID]))
				{
					m_ActionStatus = EActionStatus::KnifeIdle;
				}

				m_CountTime = 0.f;

				m_PrevStatus = m_ActionStatus;
			}
			break;
		}

		default:
			//UE_LOG(LogTemp, Error, TEXT("mogu"));
			m_PrevStatus = m_ActionStatus;
			break;
	}
}

void APlayerChara::KnifeVisible(bool cameraChangeOn, bool cameraChangeOff)
{
	if (m_pAttachObject == NULL)
		return;

	if (cameraChangeOn)
	{
		GetMesh()->SetVisibility(false);
		Cast<AItemBase>(m_pAttachObject)->GetMesh()->SetVisibility(false);
	}

	if (cameraChangeOff)
	{
		GetMesh()->SetVisibility(true);
		Cast<AItemBase>(m_pAttachObject)->GetMesh()->SetVisibility(true);
	}
}

void APlayerChara::SetLadderflag(bool _Ladderflag)
{
	Ladderflag = _Ladderflag;
}