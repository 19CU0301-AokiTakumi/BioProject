
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Components/StaticMeshComponent.h"
#include "MyGameInstance.generated.h"

UCLASS()
class BIOPROJECT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	static AActor* GetActorFromTag(const AActor* _pOwnerActor, const FName& _tag);

	static AActor* GetSpawnActor(UWorld* _spawnWorld, FString _path);
};
