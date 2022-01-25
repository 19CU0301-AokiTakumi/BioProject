//---------------------------------------------------------------
// �t�@�C����	�FBathtubEventControl.h
// �T�v			�F�����̃C�x���g���s��
// �쐬��		�F�ؑ�m
// �쐬��		�F2022�N12��21�� �ؑ�m �쐬
// �X�V����		�F2022�N12��21�� ���b�V���A�����蔻��̐���
//				�F2022�N12��21�� �C�x���g���̏�����ǉ�
//				�F2022�N12��22�� �E�B�W�F�b�g�̒ǉ��A�T�E���h�̒ǉ�
//				�F2022�N12��24�� �J�[�\���̒ǉ�
//---------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "BathtubEventControl.generated.h"

// �O���錾
class APlayerChara;

UCLASS()
class BIOPROJECT_API ABathtubEventControl : public AEventObjectBase
{
	GENERATED_BODY()
	
public:
	// �R���X�g���N�^
	ABathtubEventControl();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

private:
	APlayerChara* m_Player;		// �v���C���[���i�[
	AActor* m_SpawnItem;		// �X�|�[��������A�C�e�����i�[

	int m_index;	// �J�[�\���̈ʒu���擾

	float m_WaterMeshLocation;	// ���̃��b�V���̏����ʒu
	float m_WaterShrink;		// ���݂̏k���l

	bool m_WidgetOpen;			// �E�B�W�F�b�g���J���Ă邩���m�F
	bool m_DoAction;			// �C�x���g�����𔻒f
	bool m_ActionEnd;			// �C�x���g���I���������f

	void DownWaterSurface(float _deltaTime);	// ����������֐�

public:
	void SetDoAction(bool _doAction) { m_DoAction = _doAction; }	// �C�x���g�����ǂ������Z�b�g����֐�	
	void PlaySound();												// �T�E���h���Ȃ炷�֐�

private:
	// ���b�V���̐���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pWaterMesh;

	// ����������X�s�[�h�̐ݒ�
	UPROPERTY(EditAnywhere, Category = "Component")
		float m_downSpeed;

	// �ړ��l�̍ő��ݒ�
	UPROPERTY(EditAnywhere, Category = "Component")
		float m_WaterMaxDown;

	// �k���l�ʂ̐ݒ�
	UPROPERTY(EditAnywhere, Category = "Component")
		float m_downShrink;

	// �T�E���h�̐ݒ�
	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pWaterSE;

public:
	// �v���C���[�������蔻�����E�L�[�������Ă邩���Z�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetEventStart(const bool _eventStart) { m_bIsEventStart = _eventStart; }

	// �v���C���[�������蔻�����E�L�[�������Ă邩���Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetEventStartCheck() { return m_bIsEventStart; }

	// �E�B�W�F�b�g���J�����ǂ������Z�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetOpenWidget(bool _widgetOpen) { m_WidgetOpen = _widgetOpen; }

	// �E�B�W�F�b�g���J�����ǂ������Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetOpenWidget()const { return m_WidgetOpen; }

	// �J�[�\���̈ʒu���Z�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIndex(const int _index) { m_index = _index; }

	// �C�x���g�����ǂ������Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetDoAction()const { return m_DoAction; }

	// �C�x���g���I�������ǂ������Q�b�g����֐�
	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetActionEnd()const { return m_ActionEnd; }
};