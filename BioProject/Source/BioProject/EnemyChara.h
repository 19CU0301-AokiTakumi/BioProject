// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyChara.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UENUM(BlueprintType)
enum class Status : uint8
{
	Idle,		// 待機
	Move,		// 移動
	Attack,		// 攻撃
	Avoid,		// 回避
	KnockBack,	// ノックバック
};

UCLASS()
class BIOPROJECT_API AEnemyChara : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyChara();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditAnywhere, Category = "Status")
		float m_Speed;

	UPROPERTY(EditAnywhere, Category = "Status")
		float m_HP;

	UPROPERTY(EditAnywhere, Category = "Status")
		float m_SearchArea;

private:
	ACharacter* m_Player;

	float m_Count;

	bool m_ReduceOnce;

	void Move(float _deltaTime);
	void Idle(float _deltaTime);
	void Attack(float _deltaTime);
	void Avoid(float _deltaTime);
	void KnockBack(float _deltaTime);

	void UpdateAction(float _deltaTime);;

	Status m_status;
};
