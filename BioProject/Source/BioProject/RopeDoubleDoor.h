// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoubleDoor.h"
#include "RopeDoubleDoor.generated.h"

/**
 * 
 */
class USkeletalMeshComponent;

UCLASS()
class BIOPROJECT_API ARopeDoubleDoor : public ADoubleDoor
{
	GENERATED_BODY()
public:
	ARopeDoubleDoor();

protected:
	// メッシュの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* m_RopeLeftMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* m_RopeLightMesh;

	// オーバーラップ用のコリジョン(背面)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_RopeComp;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAccess = "true"))
		bool m_AnimStart;

public:
	void HitKnife();
};
