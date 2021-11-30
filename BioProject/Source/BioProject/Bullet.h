// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class APlayerChara;

UCLASS()
class BIOPROJECT_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

	void Init(FVector startPoint, FVector endPoint);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	// 当たり判定の追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		USphereComponent* m_pBoxComp;

	// メッシュの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;

	UPROPERTY(EditAnywhere, Category = "State")
		float m_speed;

	APlayerChara* m_pPlayer;

	FVector m_MoveDir;	// 進行方向

	float m_Time;
	float m_DestroyCount;

	bool m_isDestroy;

	int m_Atk;

	void BulletMove(float _deltaTime);

public:
	void SetIsDestoy(bool _isHit);

	void SetAtk(const int _atk) { m_Atk = _atk; }
};