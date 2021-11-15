// -----------------------------------------
// �t�@�C����	�FEventControl.h
// �T�v			�F�G�̍s���𐧌䂷��v���O����
// �쐬��		�F�X���Y��
// �쐬��		�F2021�N5��1��
// �X�V����		�F2021�N5��21���@
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
	// �I�[�o�[���b�v�ڐG�������Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	// �x�[�X�̒ǉ�
	UPROPERTY()
		USceneComponent* m_pBase;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		TArray<USceneComponent*> m_pSpawnPoint;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		USceneComponent* m_pSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;		// �ڐG�p�R���W����

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