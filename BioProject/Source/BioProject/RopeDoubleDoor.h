// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoubleDoor.h"
#include "RopeDoubleDoor.generated.h"

/**
 * 
 */
UCLASS()
class BIOPROJECT_API ARopeDoubleDoor : public ADoubleDoor
{
	GENERATED_BODY()
public:
	ARopeDoubleDoor();

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
