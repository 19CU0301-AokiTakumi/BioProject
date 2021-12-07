// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SingleDoor.h"
#include "RopeDoor.generated.h"

UCLASS()
class BIOPROJECT_API ARopeDoor : public ASingleDoor
{
	GENERATED_BODY()

public:
	ARopeDoor();

//protected:
//	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
//	virtual void BeginPlay() override;
//
//public:
//	// ���t���[���čX�V����
//	virtual void Tick(float DeltaTime) override;

protected:
	// ���b�V���̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_RopeMesh;

	// �I�[�o�[���b�v�p�̃R���W����(�w��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_RopeComp;

public:
	void HitKnife();
};
