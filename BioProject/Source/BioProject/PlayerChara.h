
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyGameInstance.h"
#include "ItemBase.h"
#include "GunControl.h"
#include "GunAmmoControl.h"
#include "PlayerChara.generated.h"

// �O���錾
class USpringArmComponent;
class UCameraComponent;

USTRUCT(BlueprintType)
struct FPlayerStatus
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// ���݂�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxHP;				// �ő�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// �ړ����x
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") FGunData equipGunData;		// �������Ă��镐���ID

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
	Idle,			// ������
	Walk,			// ����
	Run,			// ����
	GunHold,		// �e���\���Ă���
	Reload,			// �����[�h
	Guard,			// Daisuke
};

UENUM(BlueprintType)
enum class EInventoryState : uint8
{
	Idle,			// ������
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
	};

	union PlayerFlags
	{
		FPlayerFlagBits flagBits;
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

	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FStatusConstant m_statusConst;

	UPROPERTY(EditAnywhere, Category = "Status")
		EActionStatus m_ActionStatus;

	PlayerFlags m_playerFlags;

	// Player �̃J�o���̒��g���i�[
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_ItemDatas;

	FAmmoData m_haveAmmoDatas[(int)EAmmoType::Max];

	// �o�b�O�̃T�C�Y
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int m_bagSize;

	// ���C�������������W(�e�e�p)
	FVector m_rayLandingPoint;

	// �I�[�o�[���b�v�����A�N�^�[
	AActor* m_pOverlapActor;

	FVector m_OverlapActorPos;

	EInventoryState m_invenoryState;

private:
	// �ړ�����
	void UpdateMove(float _deltaTime);

	// �J�����X�V����
	void UpdateCamera(float _deltaTime);

public:
	// �A�C�e�����擾��������n��
	bool IsGetItem() { return m_playerFlags.flagBits.isItemGet; }

	// �o�b�O�̒��g��n��
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

	void Input_Inventory();

public:
	// �A�j���[�V�����J�ڗpReturn�֐�
	UFUNCTION(BlueprintCallable, CateGory = "Return", BlueprintPure)
		EActionStatus GetAnimStatus() { return m_ActionStatus; };

	UFUNCTION(BlueprintCallable, CateGory = "Gun", BlueprintPure)
		FVector GetLandingPoint()const { return m_rayLandingPoint; }
};
