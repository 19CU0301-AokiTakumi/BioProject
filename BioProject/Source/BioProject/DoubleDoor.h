
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
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

private:
	void OpenClose(float _deltaTime) override;
	void SideOpen(float _deltaTime);
	void FrontOpen(float _deltaTime);

private:
	// 当たり判定の追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp_2;

protected:
	// メッシュの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;
	// メッシュの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh_2;

private:
	float angle;
	float angle2;

	FRotator m_MeshRelativeRotation;
	FVector GetDoorLocation;
};
