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

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

protected:
	// ���b�V���̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* m_RopeSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_RopeStaticMesh;

	// �I�[�o�[���b�v�p�̃R���W����(�w��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_RopeComp;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAccess = "true"))
		bool m_AnimStart;

	UPROPERTY(EditAnywhere, Category = "Data")
		float m_AnimTime;

private:
	float m_AnimCount;

	/*bool m_Vanish;*/

	void AnimEnd(float _deltaTime);

//public:
//	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
//		bool GetIsVanish()const { return m_Vanish; }

public:
	void HitKnife();
};
