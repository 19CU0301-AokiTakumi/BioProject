
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGameInstance.h"
#include "ItemBase.generated.h"

// �O���錾
class UBoxComponent;
class UStaticMeshComponent;
class APlayerChara;

UENUM(BlueprintType)
enum class ItemType : uint8
{
	None,
	Key,
	Heal,
	Weapon,
	Bullet,
	Event,
	Debug,
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") int id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") ItemType type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") FString comment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data") bool isShowInventory;

public:
	FItemData(const int _id = 0, const FString _name = "", ItemType _type = ItemType::None, FString _comment = "", bool _isShowInventory = false)
		: id(_id)
		, name(_name)
		, type(_type)
		, comment(_comment)
		, isShowInventory(_isShowInventory)
		{}
	static FItemData NoneData() { return FItemData(-1, "", ItemType::None, ""); }
};

UCLASS()
class BIOPROJECT_API AItemBase : public AActor
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	AItemBase();

protected:
	// �Q�[���J�n���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���čX�V����
	virtual void Tick(float DeltaTime) override;

private:
	// �I�[�o�[���b�v�ڐG�����n�߂��Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// �I�[�o�[���b�v�ڐG�����I�����Ƃ��ɌĂ΂��C�x���g�֐�
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	// �����蔻��̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;

	// ���b�V���̒ǉ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;

	// ���g�̃A�C�e���f�[�^
	UPROPERTY(EditAnywhere, Category = "Data")
		FItemData m_itemData;

	// ���g���G��Ă���v���C���[��ۊ�
	APlayerChara* m_pOtherPlayer;

public:
	// ���g�̃A�C�e���f�[�^��n��
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		FItemData GetItemData() { return m_itemData; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		FVector GetCenterPos() const;
};