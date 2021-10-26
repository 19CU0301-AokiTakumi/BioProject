// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyChara.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

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
		UBoxComponent* m_BoxBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_OverLapComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_EnemyMesh;

	UPROPERTY(EditAnywhere, Category = "speed")
		float m_Speed;

	UPROPERTY(EditAnywhere, Category = "speed")
		float m_ToTheGround;

	UPROPERTY(EditAnywhere, Category = "HP")
		float m_HP;

private:
	ACharacter* m_Player;

	bool m_MoveStop;
	bool m_Ground;

	float m_StopCount;
	float m_ToTheGroundCount;

	// à⁄ìÆèàóù
	void EnemyMove(float _deltaTime);

	void StopTime(float _deltaTime);

	void AfterSpawn(float _deltaTime);
};
