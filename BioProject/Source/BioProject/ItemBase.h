
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGameInstance.h"
#include "ItemBase.generated.h"

// �O���錾
class UBoxComponent;
class UStaticMeshComponent;
class APlayerChara;

UCLASS()
class BIOPROJECT_API AItemBase : public AActor
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	AItemBase();

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
	// �����蔻��̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;

	// ���b�V���̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;

	// ���g�̃A�C�e���f�[�^
	UPROPERTY(EditAnywhere, Category = "Data")
		FItemData ItemData;

	// ���g���G��Ă���v���C���[��ۊ�
	APlayerChara* m_pOtherPlayer;

public:
	// ���g�̃A�C�e���f�[�^��n��
	FItemData GetFItemData() { return ItemData; }
};