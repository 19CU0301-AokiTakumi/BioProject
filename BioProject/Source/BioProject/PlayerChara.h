
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

// �O���錾
class USpringArmComponent;
class UCameraComponent;

// �v���C���[�̃X�e�[�^�X���܂Ƃ߂��\����
USTRUCT(BlueprintType)
struct FPlayerStatus
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// ���݂�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxHP;				// �ő�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// �ړ����x
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int equipGunID;			// �������Ă��镐��̔ԍ�

public:
	// �R���X�g���N�^
	FPlayerStatus(const int _hp = 0, const int _maxHP = 0, const float _moveSpeed = 0.f, int _equipGunID = 0)
	{
		hp = _hp;
		maxHP = _maxHP;
		moveSpeed = _moveSpeed;
		equipGunID = _equipGunID;
	}

	// �������p
	static FPlayerStatus ZeroStatus() { return FPlayerStatus(); }
};


// �A�N�V�����̏�ԊǗ��p�̗񋓌^
UENUM(BlueprintType)
enum class EActionStatus : uint8
{
	Idle,			// ������
	Walk,			// ����
	Run,			// ����
	GunHold,		// �e���\���Ă���
	Reload,			// �����[�h
	Guard,			// Daisuke
	Shot,			// �e������
	KnifeIdle,
	KnifeAttack,
	Aim,			// �e��`��
	GunIdle,		// �e��Idle
	KnifeWalk,      // �i�C�t���������ĕ���
	ChangeWeapon,   //
	Max,			// Max�p
};

// �C���x���g���̏�ԊǗ��p�̗񋓌^
UENUM(BlueprintType)
enum class EInventoryState : uint8
{
	Idle,			// ������
	Open,			// �J���Ă���
	Close,			// ���Ă���
};

// �X�e�[�^�X�ύX�̍ۂ̊�ƂȂ�f�[�^���܂Ƃ߂��\����
USTRUCT(BlueprintType)
struct FStatusConstant
{
	GENERATED_USTRUCT_BODY()

	// �����̃X�s�[�h
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (Clampmin = 0.f, Clampmax = 1.f)) float walkSpeed;

	// ����̃X�s�[�h
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (Clampmin = 0.f, Clampmax = 1.f)) float runSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (Clampmin = 0.f, Clampmax = 1.f)) float gunHoldSpeed;
};

UCLASS()
class BIOPROJECT_API APlayerChara : public ACharacter
{
	GENERATED_BODY()

	// �v���C���[�Ɋւ��t���O���܂Ƃ߂��\����
	struct FPlayerFlagBits	// ��16�܂�
	{
		// �A�C�e�����擾������
		bool isItemGet : 1;		// 1

		// �A�C�e���ɐG��Ă��邩
		bool isItemTouch : 1;	// 2

		// �e���������Ă��邩
		bool isHaveGun : 1;		// 3

		// �e���\���Ă��邩
		bool isGunHold : 1;		// 4

		// ���j���[���J���Ă��邩
		bool isOpenMenu : 1;	// 5

		// �����Ă��邩�ǂ���
		bool isShoot	: 1;    // 6

		// �擾���ɃA�C�e����\�����邩
		bool isShowGetItem : 1;	// 6

		// �C�x���g�I�u�W�F�N�g�ɐG��Ă��邩
		bool isEventObjTouch : 1;	// 7

		bool isRun : 1;

		bool isShowMessage : 1;

		bool isOpenKeyMenu : 1;
	};

	// �t���O�̊Ǘ������₷�����邽�߂̋��p��
	union PlayerFlags
	{
		// ���ꂼ��̃t���O�Q�Ɨp
		FPlayerFlagBits flagBits;

		// �S�Ẵt���O�������p
		int flagAll;
	};

public:
	// �R���X�g���N�^
	APlayerChara();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:	
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

	// �e���͊֌W�Ƃ̃o�C���h����
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	// �X�v�����O�A�[��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* m_pSpringArm;

	// �J����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* m_pCamera;

	//�@�J�����̗h��
	UPROPERTY(EditAnywhere)
		TSubclassOf<UPlayerCameraShake> CameraShake;

private:
	//�@�L�����ړ����͗�
	FVector m_CharaMoveInput;

	//�@�J������]���͗�
	FVector m_CameraRotationInput;

	// �J�����̍��E�̉ғ��͈�
	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FVector2D m_CameraYawLimit;

	// �J�����̏㉺�̉ғ��͈�
	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FVector2D m_CameraPitchLimit;

	// �ړ����x
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FPlayerStatus m_playerStatus;

	// �X�e�[�^�X�̊�ƂȂ�f�[�^
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FStatusConstant m_statusConst;

	// �A�N�V�����̏��
	UPROPERTY(EditAnywhere, Category = "Status")
		EActionStatus m_ActionStatus;

	// ��p�ύX��̒l(�ǉ�)
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_SetView;

	// �v���C���[�Ɋւ��t���O
	PlayerFlags m_playerFlags;

	// Player �̃J�o���̒��g���i�[
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_ItemDatas;

	// �o�b�O�̃T�C�Y
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int m_bagSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status", meta = (AllowPrivateAccess = "true"))
		bool m_afterDead;

	// �A�j���[�V�����̏I��鎞�Ԃ��i�[
	UPROPERTY(EditAnywhere, Category = "Status")
		float AnimEndFrame[(int)EActionStatus::Max];

	// ���C�������������W(�e�e�p)
	FVector m_rayLandingPoint;

	// �I�[�o�[���b�v�����A�N�^�[
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		AActor* m_pOverlapActor;

	// �C���x���g���̏��
	EInventoryState m_invenoryState;

	// �������Ă���e�̕ۊǗp
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		TArray<AItemBase*> m_haveGunDatas;

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData")
		void  SetWeaponDatas(TArray<AItemBase*> _weapons) { m_haveGunDatas = _weapons; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		TArray<AItemBase*> GetWeaponDatas() const { return m_haveGunDatas; }

	// �������Ă���e��̕ۊǗp
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
	// �ړ�����
	void UpdateMove(float _deltaTime);

	// �J�����X�V����
	void UpdateCamera(float _deltaTime);

	// ��p�ύX(�ǉ�)
	void Changeview(float _deltaTime);

	void AfterDeath(float _deltaTime);

public:
	// �A�C�e�����擾��������n��
	bool IsGetItem() { return m_playerFlags.flagBits.isItemGet; }

	// �o�b�O�̒��g��n��
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		TArray<FItemData> GetPlayerBag() const { return m_ItemDatas; }

	// �v���C���[�̃X�e�[�^�X��n��
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		FPlayerStatus GetPlayerStatus() const { return m_playerStatus; }

	// �������Ă���e��̃f�[�^��n��
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		FAmmoData GetAmmoData(const EGunType _ammoType) const { return m_haveAmmoDatas[(int)_ammoType]; }

	// �v���C���[��HP��n��
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerHP() const { return m_playerStatus.hp; }

	// �v���C���[�̍ő�HP��n��
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerMaxHP() const { return m_playerStatus.maxHP; }

	// �A�C�e���ɐG��Ă��邩��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetIsItemTouch()const { return m_playerFlags.flagBits.isItemTouch; }

	// �C�x���g�I�u�W�F�N�g�ɐG��Ă��邩��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetIsEventObjTouch()const { return m_playerFlags.flagBits.isEventObjTouch; }

	// �G��Ă���A�N�^�[��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		AActor* GetOverlapActor() const { return m_pOverlapActor; }

	// �C���x���g���̏�Ԃ�n��
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		EInventoryState GetInventoryState() const { return m_invenoryState; }

	// �C���x���g���̏�Ԃ��Z�b�g����
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetInventoryState(const EInventoryState _state) { m_invenoryState = _state; }

	// �C���x���g���̃J�[�\���ʒu��n��
	UFUNCTION(BlueprintCallable, CateGory = "SetData", BlueprintPure)
		int GetCursorIndex(const int _index, const int _moveValue);

	// �񕜏���
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void Heal(const int _index, const int _value = 0);

	// ��_���[�W����
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void Damage(int _atk);

	// �A�C�e�����擾��������n��
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIsGetItem(const bool _isGet) { m_playerFlags.flagBits.isItemGet = _isGet; }

	// �C���x���g�����J����Ă��邩��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsOpenInventory() const { return m_playerFlags.flagBits.isOpenMenu; }

	// ���I��p�̃C���x���g�����J����Ă��邩��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsOpenKeyInventory() const { return m_playerFlags.flagBits.isOpenKeyMenu; }

	// �e���\���Ă��邩��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsGunHold() const { return m_playerFlags.flagBits.isGunHold; }

	// ���S��������n��
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsDead();

	// �e�����������ǂ�����Ԃ�
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetIsHaveGun() const { return m_playerFlags.flagBits.isHaveGun; }

	// �y�f�o�b�O�p�z�������Ă��镐�����BP�ŕύX����
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
	// �y���̓o�C���h�z�L�����ړ��F�O��
	void Input_MoveForward(float _axisValue);

	// �y���̓o�C���h�z�L�����ړ��F���E
	void Input_MoveRight(float _axisValue);

	// �y���̓o�C���h�z�J������]�FPitch�iY���j
	void Input_CameraRotatePitch(float _axisValue);

	// �y���̓o�C���h�z�J������]�FYaw�iZ���j
	void Input_CameraRotateYaw(float _axisValue);

	// �y���̓o�C���h�z�e���\����
	void Input_Hold();

	// �y���̓o�C���h�z�e������
	void Input_Shooting();

	// �y���̓o�C���h�z����
	void Input_Run();

	// �y���̓o�C���h�z���ɑ΂��ẴA�N�V����
	void Input_Action();

	// �y���̓o�C���h�z�����[�h����
	void Input_Reload();

	// �y���̓o�C���h�z�C���x���g������
	void Input_Inventory();

	// �y���̓o�C���h�z�e�̐؂�ւ�����
	void Input_ChangeGun(float _axisValue);

public:
	// �A�j���[�V�����J�ڗpReturn�֐�
	UFUNCTION(BlueprintCallable, CateGory = "Return", BlueprintPure)
		EActionStatus GetAnimStatus() { return m_ActionStatus; };

	UFUNCTION(BlueprintCallable, CateGory = "Gun", BlueprintPure)
		FVector GetLandingPoint()const { return m_rayLandingPoint; }

public:
	// �����̃J�����U���̌p���J�E���g
	float m_Count;	

	// ���������ɐ�����J�����̗h��
	void ShootCameraShake(int _deltaTime);

	// ��p�̒l(�ǉ�)
	float m_Viewvalue;

	bool ItemDestroy;

	UPROPERTY(EditAnywhere, Category = "View")
		float m_DefaultViewvalue;

private:
		float m_CountTime;

		FVector m_GunLocation;

		float m_prevAxisValue;

		// �A�j���[�V�����p
		void CountTime(float _deltaTime);

		EActionStatus m_PrevStatus;

		AKnifeControl* m_pTempKnife;

		AGunControl* m_pTempGun;

		ABathtubEventControl* m_Bathtub;
};
