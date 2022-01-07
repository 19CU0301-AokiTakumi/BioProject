
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyGameInstance.h"
#include "ItemBase.h"
#include "GunControl.h"
#include "KnifeControl.h"
#include "GunAmmoControl.h"
#include "BathtubEventControl.h"
#include "PlayerCameraShake.h"
#include "PlayerChara.generated.h"

// 前方宣言
class USpringArmComponent;
class UCameraComponent;

// プレイヤーのステータスをまとめた構造体
USTRUCT(BlueprintType)
struct FPlayerStatus
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// 現在のHP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxHP;				// 最大HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// 移動速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int equipGunID;			// 装備している武器の番号

public:
	// コンストラクタ
	FPlayerStatus(const int _hp = 0, const int _maxHP = 0, const float _moveSpeed = 0.f, int _equipGunID = 0)
	{
		hp = _hp;
		maxHP = _maxHP;
		moveSpeed = _moveSpeed;
		equipGunID = _equipGunID;
	}

	// 初期化用
	static FPlayerStatus ZeroStatus() { return FPlayerStatus(); }
};


// アクションの状態管理用の列挙型
UENUM(BlueprintType)
enum class EActionStatus : uint8
{
	Idle,			// 未操作
	Walk,			// 歩き
	Run,			// 走り
	GunHold,		// 銃を構えている
	Reload,			// リロード
	Guard,			// Daisuke
	Shot,			// 銃を撃つ
	KnifeIdle,
	KnifeAttack,
	Aim,			// 銃を覗く
	GunIdle,		// 銃のIdle
	KnifeWalk,      // ナイフを所持して歩く
	ChangeWeapon,   //
	Max,			// Max用
};

// インベントリの状態管理用の列挙型
UENUM(BlueprintType)
enum class EInventoryState : uint8
{
	Idle,			// 未操作
	Open,			// 開いている
	Close,			// 閉じている
};

// ステータス変更の際の基準となるデータをまとめた構造体
USTRUCT(BlueprintType)
struct FStatusConstant
{
	GENERATED_USTRUCT_BODY()

	// 歩きのスピード
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (Clampmin = 0.f, Clampmax = 1.f)) float walkSpeed;

	// 走りのスピード
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (Clampmin = 0.f, Clampmax = 1.f)) float runSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (Clampmin = 0.f, Clampmax = 1.f)) float gunHoldSpeed;
};

UCLASS()
class BIOPROJECT_API APlayerChara : public ACharacter
{
	GENERATED_BODY()

	// プレイヤーに関わるフラグをまとめた構造体
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

		// 撃っているかどうか
		bool isShoot	: 1;    // 6

		// 取得時にアイテムを表示するか
		bool isShowGetItem : 1;	// 6

		// イベントオブジェクトに触れているか
		bool isEventObjTouch : 1;	// 7

		bool isRun : 1;

		bool isShowMessage : 1;

		bool isOpenKeyMenu : 1;
	};

	// フラグの管理をしやすくするための共用体
	union PlayerFlags
	{
		// それぞれのフラグ参照用
		FPlayerFlagBits flagBits;

		// 全てのフラグ初期化用
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

	//　カメラの揺れ
	UPROPERTY(EditAnywhere)
		TSubclassOf<UPlayerCameraShake> CameraShake;

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

	// ステータスの基準となるデータ
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FStatusConstant m_statusConst;

	// アクションの状態
	UPROPERTY(EditAnywhere, Category = "Status")
		EActionStatus m_ActionStatus;

	// 画角変更後の値(追加)
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_SetView;

	// プレイヤーに関わるフラグ
	PlayerFlags m_playerFlags;

	// Player のカバンの中身を格納
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_ItemDatas;

	// バッグのサイズ
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int m_bagSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status", meta = (AllowPrivateAccess = "true"))
		bool m_afterDead;

	// アニメーションの終わる時間を格納
	UPROPERTY(EditAnywhere, Category = "Status")
		float AnimEndFrame[(int)EActionStatus::Max];

	// レイが当たった座標(銃弾用)
	FVector m_rayLandingPoint;

	// オーバーラップしたアクター
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		AActor* m_pOverlapActor;

	// インベントリの状態
	EInventoryState m_invenoryState;

	// 所持している銃の保管用
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		TArray<AItemBase*> m_haveGunDatas;

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData")
		void  SetWeaponDatas(TArray<AItemBase*> _weapons) { m_haveGunDatas = _weapons; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		TArray<AItemBase*> GetWeaponDatas() const { return m_haveGunDatas; }

	// 所持している弾薬の保管用
	FAmmoData m_haveAmmoDatas[(int)EAmmoType::Max];

	float fireRateCount;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pShotSE;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pDiningSE;

	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
		FVector m_SocketLocation;

	AItemBase* m_pAttachObject;

private:
	// 移動処理
	void UpdateMove(float _deltaTime);

	// カメラ更新処理
	void UpdateCamera(float _deltaTime);

	// 画角変更(追加)
	void Changeview(float _deltaTime);

	void AfterDeath(float _deltaTime);

public:
	// アイテムを取得したかを渡す
	bool IsGetItem() { return m_playerFlags.flagBits.isItemGet; }

	// バッグの中身を渡す
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		TArray<FItemData> GetPlayerBag() const { return m_ItemDatas; }

	// プレイヤーのステータスを渡す
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		FPlayerStatus GetPlayerStatus() const { return m_playerStatus; }

	// 所持している弾薬のデータを渡す
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		FAmmoData GetAmmoData(const EGunType _ammoType) const { return m_haveAmmoDatas[(int)_ammoType]; }

	// プレイヤーのHPを渡す
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerHP() const { return m_playerStatus.hp; }

	// プレイヤーの最大HPを渡す
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerMaxHP() const { return m_playerStatus.maxHP; }

	// アイテムに触れているかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetIsItemTouch()const { return m_playerFlags.flagBits.isItemTouch; }

	// イベントオブジェクトに触れているかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetIsEventObjTouch()const { return m_playerFlags.flagBits.isEventObjTouch; }

	// 触れているアクターを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		AActor* GetOverlapActor() const { return m_pOverlapActor; }

	// インベントリの状態を渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		EInventoryState GetInventoryState() const { return m_invenoryState; }

	// インベントリの状態をセットする
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetInventoryState(const EInventoryState _state) { m_invenoryState = _state; }

	// インベントリのカーソル位置を渡す
	UFUNCTION(BlueprintCallable, CateGory = "SetData", BlueprintPure)
		int GetCursorIndex(const int _index, const int _moveValue);

	// 回復処理
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void Heal(const int _index, const int _value = 0);

	// 被ダメージ処理
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void Damage(int _atk);

	// アイテムを取得したかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIsGetItem(const bool _isGet) { m_playerFlags.flagBits.isItemGet = _isGet; }

	// インベントリが開かれているかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsOpenInventory() const { return m_playerFlags.flagBits.isOpenMenu; }

	// 鍵選択用のインベントリが開かれているかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsOpenKeyInventory() const { return m_playerFlags.flagBits.isOpenKeyMenu; }

	// 銃を構えているかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsGunHold() const { return m_playerFlags.flagBits.isGunHold; }

	// 死亡したかを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsDead();

	// 銃を持ったかどうかを返す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsHaveGun() const { return m_playerFlags.flagBits.isHaveGun; }

	// 【デバッグ用】装備している武器情報をBPで変更する
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetPlayerStatus(const FPlayerStatus _playerstatus) { m_playerStatus= _playerstatus; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData")
		bool GetIsShowGetItem() const { return m_playerFlags.flagBits.isShowGetItem; }

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIsShowGetItem(const bool _isShowGetItem) { m_playerFlags.flagBits.isShowGetItem = _isShowGetItem; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData")
		FGunData GetEquipGunData() const;

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetAttachWeapon(AItemBase* _equipWeapon);

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

	// 【入力バインド】インベントリ処理
	void Input_Inventory();

	// 【入力バインド】銃の切り替え処理
	void Input_ChangeGun(float _axisValue);

public:
	// アニメーション遷移用Return関数
	UFUNCTION(BlueprintCallable, CateGory = "Return", BlueprintPure)
		EActionStatus GetAnimStatus() { return m_ActionStatus; };

	UFUNCTION(BlueprintCallable, CateGory = "Gun", BlueprintPure)
		FVector GetLandingPoint()const { return m_rayLandingPoint; }

public:
	// 歩きのカメラ振動の継続カウント
	float m_Count;	

	// 撃った時に生じるカメラの揺れ
	void ShootCameraShake(int _deltaTime);

	// 画角の値(追加)
	float m_Viewvalue;

	bool ItemDestroy;

	UPROPERTY(EditAnywhere, Category = "View")
		float m_DefaultViewvalue;

private:
		float m_CountTime;

		FVector m_GunLocation;

		float m_prevAxisValue;

		// アニメーション用
		void CountTime(float _deltaTime);

		EActionStatus m_PrevStatus;

		AKnifeControl* m_pTempKnife;

		AGunControl* m_pTempGun;

		ABathtubEventControl* m_Bathtub;
};
