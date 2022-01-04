// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "DrawerControl.generated.h"

class AItemBase;

UENUM(BlueprintType)
enum class ESpawnItem : uint8
{
	None,
	HandGun,
	Key,
	HandGunAmmo,
	ShotGunAmmo,
};

UCLASS()
class BIOPROJECT_API ADrawerControl : public AEventObjectBase
{
	GENERATED_BODY()

public:
	ADrawerControl();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

public:
	void OpenDrawer(const float _deltaTime);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pDrawerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		USceneComponent* m_pItemSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		AItemBase* m_pItem;

	USoundBase* m_pDrawerOpenSE;

	UPROPERTY(EditAnywhere, Category = "State")
		ESpawnItem m_SpawnItem;

	UPROPERTY(EditAnywhere, Category = "State")
		float m_openSpeed;

	UPROPERTY(EditAnywhere, Category = "State")
		float m_maxOpenValue;

	float m_DrawerOpenCount;

	float m_ItemMoveCount;

	bool m_bIsDrawerOpen;
};
