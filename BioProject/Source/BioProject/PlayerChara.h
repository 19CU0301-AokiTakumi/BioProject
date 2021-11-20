
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyGameInstance.h"
#include "ItemBase.h"
#include "GunControl.h"
#include "GunAmmoControl.h"
#include "PlayerChara.generated.h"

// 前方宣言
class USpringArmComponent;
class UCameraComponent;

USTRUCT(BlueprintType)
struct FPlayerStatus
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// 現在のHP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxHP;				// 最大HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// 移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") FGunData equipGunData;		// 装備している武器のID

public:
	FPlayerStatus(const int _hp = 0, const int _maxHP = 0, const float _moveSpeed = 0.f, FGunData _equipGunData = FGunData::NoneData())
	{
		hp = _hp;
		maxHP = _maxHP;
		moveSpeed = _moveSpeed;
		equipGunData = _equipGunData;
	}
	static FPlayerStatus ZeroStatus() { return FPlayerStatus(0, 0, 0.f); }
};

UENUM(BlueprintType)
enum class EActionStatus : uint8
{
	Idle,			// 未操作
	Walk,			// 歩き
	Run,			// 走り
	GunHold,		// 銃を構えている
	Reload,			// リロード
	Guard,			// Daisuke
};

UENUM(BlueprintType)
enum class EInventoryState : uint8
{
	Idle,			// 未操作
	Open,
	Close,
};

USTRUCT(BlueprintType)
struct FStatusConstant
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float walkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float runSpeed;
};

UCLASS()
class BIOPROJECT_API APlayerChara : public ACharacter
{
	GENERATED_BODY()


	struct FPlayerFlagBits	// ※16個まで
	{
		// アイテムを取得したか
		bool isItemGet : 1;		// 1

		// アイテムに触れているか
		bool isItemTouch : 1;	// 2

		// 銃を所持しているか
		bool isHaveGun : 1;		// 3

		// 銃を構えているか
		bool isGunHold : 1;		// 4

		// メニューを開いているか
		bool isOpenMenu : 1;	// 5
	};

	union PlayerFlags
	{
		FPlayerFlagBits flagBits;
		int flagAll;
	};

public:
	// コンストラクタ
	APlayerChara();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:	
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

	// 各入力関係とのバインド処理
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// オーバーラップ接触をし始めたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// オーバーラップ接触をし終えたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	// スプリングアーム
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* m_pSpringArm;

	// カメラ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* m_pCamera;

private:
	//　キャラ移動入力量
	FVector m_CharaMoveInput;

	//　カメラ回転入力量
	FVector m_CameraRotationInput;

	// カメラの左右の稼働範囲
	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FVector2D m_CameraYawLimit;

	// カメラの上下の稼働範囲
	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FVector2D m_CameraPitchLimit;

	// 移動速度
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FPlayerStatus m_playerStatus;

	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FStatusConstant m_statusConst;

	UPROPERTY(EditAnywhere, Category = "Status")
		EActionStatus m_ActionStatus;

	PlayerFlags m_playerFlags;

	// Player のカバンの中身を格納
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_ItemDatas;

	FAmmoData m_haveAmmoDatas[(int)EAmmoType::Max];

	// バッグのサイズ
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int m_bagSize;

	// レイが当たった座標(銃弾用)
	FVector m_rayLandingPoint;

	// オーバーラップしたアクター
	AActor* m_pOverlapActor;

	FVector m_OverlapActorPos;

	EInventoryState m_invenoryState;

private:
	// 移動処理
	void UpdateMove(float _deltaTime);

	// カメラ更新処理
	void UpdateCamera(float _deltaTime);

public:
	// アイテムを取得したかを渡す
	bool IsGetItem() { return m_playerFlags.flagBits.isItemGet; }

	// バッグの中身を渡す
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		TArray<FItemData> GetPlayerBag() const { return m_ItemDatas; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		FPlayerStatus GetPlayerStatus() const { return m_playerStatus; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		FAmmoData GetAmmoData(const EGunType _ammoType) const { return m_haveAmmoDatas[(int)_ammoType]; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerHP() const { return m_playerStatus.hp; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerMaxHP() const { return m_playerStatus.maxHP; }

	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetIsItemTouch()const { return m_playerFlags.flagBits.isItemTouch; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		AActor* GetOverlapActor() const { return m_pOverlapActor; }

	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		EInventoryState GetInventoryState() const { return m_invenoryState; }

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetInventoryState(const EInventoryState _state) { m_invenoryState = _state; }

	UFUNCTION(BlueprintCallable, CateGory = "SetData", BlueprintPure)
		int GetCursorIndex(const int _index, const int _moveValue);

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void Heal(const int _index, const int _value = 0);

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void Damage(int _atk);

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIsGetItem(const bool _isGet) { m_playerFlags.flagBits.isItemGet = _isGet; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsOpenInventory() const { return m_playerFlags.flagBits.isOpenMenu; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsGunHold() const { return m_playerFlags.flagBits.isGunHold; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsDead();
	
public:
	// 【入力バインド】キャラ移動：前後
	void Input_MoveForward(float _axisValue);

	// 【入力バインド】キャラ移動：左右
	void Input_MoveRight(float _axisValue);

	// 【入力バインド】カメラ回転：Pitch（Y軸）
	void Input_CameraRotatePitch(float _axisValue);

	// 【入力バインド】カメラ回転：Yaw（Z軸）
	void Input_CameraRotateYaw(float _axisValue);

	// 【入力バインド】銃を構える
	void Input_Hold();

	// 【入力バインド】銃を撃つ
	void Input_Shooting();

	// 【入力バインド】走る
	void Input_Run();

	// 【入力バインド】物に対してのアクション
	void Input_Action();

	// 【入力バインド】リロード処理
	void Input_Reload();

	void Input_Inventory();

public:
	// アニメーション遷移用Return関数
	UFUNCTION(BlueprintCallable, CateGory = "Return", BlueprintPure)
		EActionStatus GetAnimStatus() { return m_ActionStatus; };

	UFUNCTION(BlueprintCallable, CateGory = "Gun", BlueprintPure)
		FVector GetLandingPoint()const { return m_rayLandingPoint; }
};
