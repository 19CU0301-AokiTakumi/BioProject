// -----------------------------------------
// ファイル名	：EventControl.h
// 概要			：敵の行動を制御するプログラム
// 作成者		：森下雄太
// 作成日		：2021年5月1日
// 更新履歴		：2021年5月21日　
//------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "EventControl.generated.h"

class UBoxComponent;

UCLASS()
class BIOPROJECT_API AEventControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// オーバーラップ接触をしたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// オーバーラップ接触をし終えたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	// ベースの追加
	UPROPERTY()
		USceneComponent* m_pBase;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		TArray<USceneComponent*> m_pSpawnPoint;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		USceneComponent* m_pSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;		// 接触用コリジョン

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (AllowPrivateAccess = "true"))
		TArray<FVector> m_SpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Data")
		int id;

	bool PlayerHit;

	bool SpawnOnce;

	int m_SpawnLocationLength;

public:
	int SendId();

	USceneComponent* GetSpawnPoint() const { return m_pSpawnPoint; }

	bool GetSpawnOnce()const { return SpawnOnce; }

	bool GetPlayerHit()const { return PlayerHit; }

	int GetSpawnLocationLength() const { return m_SpawnLocationLength; }

	TArray<FVector> GetSpawnLocation() const { return m_SpawnLocation; }

	void SetSpawnOnce(const bool _isSpawn) { SpawnOnce = _isSpawn; }
};