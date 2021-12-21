
#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "DoubleDoor.generated.h"

UCLASS()
class BIOPROJECT_API ADoubleDoor : public ADoorBase
{
	GENERATED_BODY()

public:
	ADoubleDoor();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

private:
	void OpenClose(float _deltaTime) override;
	void SideOpen(float _deltaTime);
	void FrontOpen(float _deltaTime);

private:
	// �����蔻��̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp_2;

protected:
	// ���b�V���̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;
	// ���b�V���̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh_2;

private:
	float angle;
	float angle2;

	FRotator m_MeshRelativeRotation;
	FVector GetDoorLocation;
};
