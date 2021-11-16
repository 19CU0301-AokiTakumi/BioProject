// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyChara.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class APlayerChara;

UENUM(BlueprintType)
enum class ActionStatus : uint8
{
	Idle,		// �ҋ@
	Move,		// �ړ�
	Attack,		// �U��
	Avoid,		// ���
	KnockBack,	// �m�b�N�o�b�N
	Death,		// ���S
};

USTRUCT(BlueprintType)
struct FEnemyStatus
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int hp;					// ���݂�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int maxHP;				// �ő�HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int atk;					// �U��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") float moveSpeed;			// �ړ����x

public:
	FEnemyStatus(const int _hp = 0, const int _maxHP = 0, const int _atk = 0, const float _moveSpeed = 0.f)
	{
		hp = _hp;
		maxHP = _maxHP;		
		atk = _atk;
		moveSpeed = _moveSpeed;
	}
	static FEnemyStatus ZeroStatus() { return FEnemyStatus(0, 0, 0, 0.f); }
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

private:
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditAnywhere, Category = "Status")
		float m_SearchArea;

public:
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
		FEnemyStatus m_EnemyStatus;

public:
	// �A�j���[�V�����p
	// �����A�j���[�V����
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnWalk();

	// ���S�A�j���[�V����
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnDeath();

	// �m�b�N�o�b�N�A�j���[�V����
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnKnockBack();

	// �m�b�N�o�b�N�A�j���[�V����
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool")
		bool ReturnAttack();

private:
	APlayerChara* m_Player;

	float m_Count;

	void UpdateAction(float _deltaTime);

	void Move(float _deltaTime);
	void Idle(float _deltaTime);
	void Attack(float _deltaTime);
	void Avoid(float _deltaTime);
	void KnockBack(float _deltaTime);
	void Death(float _deltaTime);

	ActionStatus m_status;
};
