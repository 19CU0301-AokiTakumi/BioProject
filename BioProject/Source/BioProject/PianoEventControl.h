//---------------------------------------------------------------
// �t�@�C����	�FBathtubEventControl.h
// �T�v			�F�����̃C�x���g���s��
// �쐬��		�F�ؑ�m
// �쐬��		�F2022�N12��21�� �ؑ�m �쐬
// �X�V����		�F2022�N12��21�� ���b�V���A�����蔻��̐���
//---------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "Sound/SoundBase.h"
#include "PianoEventControl.generated.h"

// �O���錾
class APlayerChara;

UCLASS()
class BIOPROJECT_API APianoEventControl : public AEventObjectBase
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	APianoEventControl();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

protected:
	// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	APlayerChara* m_Player;		// �v���C���[���i�[
	AActor* SpawnItem;			// �X�|�[��������A�C�e�����i�[

	int m_index;		// �J�[�\���̈ʒu���擾
	int m_CountNumber;	// �C�x���g�̉񐔂��J�E���g���� 
	int m_MaxNumber;	// �C�x���g�̍ő�̊֐���ݒ�

	bool m_bIsOpen;				// �C�x���g���I���Ă邩�𔻒f
	bool m_bIsItemOnce;			// �A�C�e������x���������������Ȃ��悤�ɂ���
	//bool m_bIsMusicHaveCheck;	// �{���C���x���g���ɂ��邩���`�F�b�N

	USoundBase* m_PianoSEs[8];

	void GetItem();		// �A�C�e�����X�|�[������֐�
	bool KeyCheck();	// �ԍ��������Ă��邩�𔻒f����֐�

private:
	// �v���C���[�������Ă���L�[�{�[�h������
	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<int> m_ArrayKeybord;

	// �����ƂȂ�L�[�{�[�h������
	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<int> m_AnswerKeybord;

public:
	// �L�[�{�[�h�������ꂽ�u�ԂɌĂ΂��֐�
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void InputKeybord(const int _index);

	// �������L�[�{�[�h�̔ԍ����Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "Getint", BlueprintPure)
		int GetPushNumber() { return m_CountNumber; }

	// �C�x���g�̉񐔂��Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "Getint", BlueprintPure)
		int GetMaxNumber() { return m_ArrayKeybord.Num(); }

	// �C���x���g���ɖ{�������Ă��邩���Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetScoreHaveCheck() { return m_bIsMusicHaveCheck; }

	bool m_bIsMusicHaveCheck;	// �{���C���x���g���ɂ��邩���`�F�b�N
};
