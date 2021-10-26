
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Components/StaticMeshComponent.h"
#include "MyGameInstance.generated.h"

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

public:
	FItemData(const int _id = 0, const FString _name = "", ItemType _type = ItemType::None, FString _comment = "")
	{
		id = _id;
		name = _name;
		type = _type;
		comment = _comment;
	}
	static FItemData NoneData() { return FItemData(-1, "", ItemType::None, ""); }
};

UCLASS()
class BIOPROJECT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_pItemDatas;

public:
	static AActor* GetActorFromTag(const AActor* _pOwnerActor, const FName& _tag);

	static AActor* GetSpawnActor(UWorld* _spawnWorld, FString _path);
};
