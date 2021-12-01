
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGameInstance.h"
#include "ItemBase.generated.h"

// 前方宣言
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
	// コンストラクタ
	AItemBase();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

private:
	// オーバーラップ接触をし始めたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// オーバーラップ接触をし終えたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	// 当たり判定の追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;

	// メッシュの追加
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMesh;

	// 自身のアイテムデータ
	UPROPERTY(EditAnywhere, Category = "Data")
		FItemData m_itemData;

	// 自身が触れているプレイヤーを保管
	APlayerChara* m_pOtherPlayer;

public:
	// 自身のアイテムデータを渡す
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		FItemData GetItemData() { return m_itemData; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		FVector GetCenterPos() const;
};