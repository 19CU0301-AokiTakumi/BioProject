// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "BookEventControl.generated.h"

UCLASS()
class BIOPROJECT_API ABookEventControl : public AEventObjectBase
{
	GENERATED_BODY()
	
public:
	ABookEventControl();

protected:
	// ������
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
	UPROPERTY(EditAnywhere, Category = "Data")
		float m_MoveSpeed;

	UPROPERTY(EditAnywhere, Category = "Data")
		float m_MaxMove;

private:
	bool m_bIsBookCheck;

	void OpenBookShelf(float _deltaTime);
};
