
#pragma once

#include "CoreMinimal.h"
#include "MyGameInstance.h"
#include "ItemBase.h"
#include "GameFramework/Character.h"
#include "PlayerChara.generated.h"

// �O���錾
class USpringArmComponent;
class UCameraComponent;

USTRUCT(BlueprintType)
struct FPlayerStatus
{
	GENERATED_USTRUCT_BODY()

	int hp;
	int maxHP;
	float moveSpeed;
};

UCLASS()
class BIOPROJECT_API APlayerChara : public ACharacter
{
	GENERATED_BODY()

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
	UPROPERTY(EditAnywhere, Category = "Status")
		FPlayerStatus m_playerStatus;

	// Player �̃J�o���̒��g���i�[
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_ItemDatas;

	// �o�b�O�̃T�C�Y
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int m_bagSize;

	// �A�C�e�����擾������
	bool m_bisItemGet;

private:
	// �ړ�����
	void UpdateMove(float _deltaTime);

	// �J�����X�V����
	void UpdateCamera(float _deltaTime);

public:
	// �A�C�e�����擾��������n��
	bool IsGetItem() { return m_bisItemGet; }

	// �o�b�O�̒��g��n��
	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		TArray<FItemData> GetPlayerBag() const { return m_ItemDatas; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerHP() const { return m_playerStatus.hp; }

	UFUNCTION(BlueprintCallable, CateGory = "PlayerData", BlueprintPure)
		int GetPlayerMaxHP() const { return m_playerStatus.maxHP; }

public:
	// �y���̓o�C���h�z�L�����ړ��F�O��
	void MoveForward(float _axisValue);

	// �y���̓o�C���h�z�L�����ړ��F���E
	void MoveRight(float _axisValue);

	// �y���̓o�C���h�z�J������]�FPitch�iY���j
	void CameraRotatePitch(float _axisValue);

	// �y���̓o�C���h�z�J������]�FYaw�iZ���j
	void CameraRotateYaw(float _axisValue);
};
