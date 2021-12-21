// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

// �O���錾
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class BIOPROJECT_API ADoorBase : public AActor
{
	GENERATED_BODY()

protected:
	// ���̏��
	enum class State
	{
		Idle,		// �ҋ@(���Ă�)���
		Open,		// �J���Ă�Œ�
		CloseWait,	// �ҋ@(�J���Ă�)���
		Close,		// ���Ă�Œ�
	};

public:
	// �R���X�g���N�^
	ADoorBase();

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

	// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	// �x�[�X�̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		USceneComponent* m_pBase;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pDoorSE;

protected:
	// �J�����̔���p�̃R���W����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pRootBoxComp;

	// �I�[�o�[���b�v�p�̃R���W����(�O��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pFrontBoxComp;

	// �I�[�o�[���b�v�p�̃R���W����(�w��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBackBoxComp;

	// �����������Ă��邩
	UPROPERTY(EditAnywhere, Category = "State")
		bool m_bIsLock;

	// �������ɊJ����
	bool m_bIsOpenReverse;

	// �J���x
	UPROPERTY(EditAnywhere, Category = "State")
		float m_speed;

	// ���̏��
	State m_DoorState;

	// ���g��ID
	UPROPERTY(EditAnywhere, Category = "State")
		int m_id;

	// �J���̎��Ԃ̃J�E���g�p
	float m_countTime;

	// �܂�n�߂�܂ł̎���
	UPROPERTY(EditAnywhere, Category = "State")
		float m_closeTime;

	// ���J���̔���
	UPROPERTY(EditAnywhere, Category = "State")
		bool m_IsSlide;

	// �v���C���[���G��Ă��邩
	bool m_bIsOverlapPlayer;

protected:
	// �J����
	virtual void OpenClose(float _deltaTime) {};

	// �߂Ă悢���𔻒f����
	void CheckClose(float _deltaTime);

public:
	// �����������Ă��邩��n��
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool", BlueprintPure)
		bool GetIsLock() const { return m_bIsLock; }

	// ���̏�Ԃ�ύX����
	UFUNCTION(BlueprintCallable, CateGory = "SetBool")
		void SetIsLock(const bool _isLock) { m_bIsLock = _isLock; }

	// ���g��ID��n��
	int GetID()const { return m_id; }

	// �J��������ݒ肷��
	void SetOpenReverse(bool _isBack) { m_bIsOpenReverse = _isBack; }
};