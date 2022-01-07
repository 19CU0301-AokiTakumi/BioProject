// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyChara.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class UBoxComponent;
class APlayerChara;
class UNiagaraSystem;

UENUM(BlueprintType)
enum class ActionStatus : uint8
{
	Idle,		// �ҋ@
	Move,		// �ړ�
	Attack,		// �U��
	Avoid,		// ���
	KnockBack,	// �m�b�N�o�b�N
	StandUp,	// �X�^���h�A�b�v
	Down,		// �_�E��
	Death,		// ���S
	Max,		// �X�e�[�^�X�̐��𐔂���
};

USTRUCT(BlueprintType)
struct FEnemyStatus
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// ���݂�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxDownPoint;		// �ő�_�E���J�E���g
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int knockBackPoint;		// �m�b�N�o�b�N�J�E���g
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;					// �U��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// �ړ����x

public:
	FEnemyStatus(const int _hp = 0, const int _maxDownPoint = 0, const int _knockBackPoint = 0, const int _atk = 0, const float _moveSpeed = 0.f)
		: hp(_hp)
		, maxDownPoint(_maxDownPoint)
		, knockBackPoint(knockBackPoint)
		, atk(_atk)
		, moveSpeed(_moveSpeed)
	{}
	static FEnemyStatus ZeroStatus() { return FEnemyStatus(0, 0, 0, 0, 0.f); }
};

UCLASS()
class BIOPROJECT_API AEnemyChara : public ACharacter
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	AEnemyChara();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:	
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

private:
	// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	// ���C�̒����i��`�����蔻��̒����j
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_SearchArea;

	// �A�j���[�V�����̏I��鎞�Ԃ��i�[
	UPROPERTY(EditAnywhere, Category = "Status")
		float AnimEndFrame[(int)ActionStatus::Max];

	// �X�e�[�^�X��ۊ�
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FEnemyStatus m_EnemyStatus;

	// �w�b�h�V���b�g�{��
	UPROPERTY(EditAnywhere, Category = "Status")
		int m_HeadShotOfSet;

	// �A�^�b�N�A�j���[�V�����̓����蔻����n�߂�
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_AtkStartTime;

	// �A�^�b�N�A�j���[�V�����̓����蔻����I����
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_AtkEndTime;

	// ���C�̎n�_
	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
		FVector m_BodyCollisionPos;

	// �_�E�������ǂ���
	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool m_IsDown;

	UPROPERTY(EditAnywhere, Category = "Status")
		float m_LengthDis;

private:
	// �G�t�F�N�g
	UPROPERTY(EditAnywhere, Category = "Effects")
		UNiagaraSystem* m_pDamageEffect;

	// SE
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pDamageSE;

private:
	// �I�u�W�F�N�g
	APlayerChara* m_Player;		// �v���C���[���i�[
	ActionStatus m_status;		// �X�e�[�^�X���i�[

	// ����
	int m_DownCount;	// �_�E������܂ł��J�E���g����

	// ����
	float m_AnimCount;			// �A�j���[�V�������J�E���g����
	float m_AtkAnimCount;		// �A�^�b�N�A�j���[�V�������n�܂�����J�E���g����

	// �t���O
	bool m_bIsAttack;	// �U���\���ǂ���

	// �A�b�v�f�[�g�֐�
	void UpdateAction(float _deltaTime);	// �X�e�[�^�X���Ǘ�����
	void UpdateRay();						// ���C���΂�

	// �X�e�[�^�X�֐�
	void Idle();					// �ҋ@
	void Move(float _deltaTime);	// �ړ�
	void Attack();					// �U��

	void AddAtkAnimTime(float _deltaTime);	// �A�^�b�N�A�j���[�V�������n�܂�����Ă΂��֐�

public:
	void Damage(AActor* Bullet, const int _atk, FName _compName);	// �_���[�W���󂯂�

public:
	// �G�l�~�[�̃X�e�[�^�X��n��
	UFUNCTION(BlueprintCallable, CateGory = "EnemyState", BlueprintPure)
		FEnemyStatus GetEnemyStatus() const { return m_EnemyStatus; }

	// �_�E���񐔂��J�E���g
	UFUNCTION(BlueprintCallable, CateGory = "EnemyState")
		void DownPoint();

public:
	// �A�j���[�V�����p
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnWalk();			// �����A�j���[�V����

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnDeath();			// ���S�A�j���[�V����

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnKnockBack();		// �m�b�N�o�b�N�A�j���[�V����

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnAttack();		// �A�^�b�N�A�j���[�V����

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnDown();			// �_�E���A�j���[�V����

	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnStandUp();		// �X�^���h�A�b�v�A�j���[�V����
};
