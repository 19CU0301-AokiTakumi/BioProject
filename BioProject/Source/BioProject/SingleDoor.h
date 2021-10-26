// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "SingleDoor.generated.h"

UCLASS()
class BIOPROJECT_API ASingleDoor : public ADoorBase
{
	GENERATED_BODY()
public:
	// �R���X�g���N�^
	ASingleDoor();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

private:
	// �Փ˔���p�̃R���W����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;

	// ���b�V��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;

private:
	float m_angle;
	void OpenClose(float _deltaTime) override;
	void SideOpen(float _deltaTime);
	void FrontOpen(float _deltaTime);

	FRotator m_MeshRelativeRotation;
	FVector m_MeshRelativeLocation;
};

