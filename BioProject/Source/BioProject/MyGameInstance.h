
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Components/StaticMeshComponent.h"
#include "MyGameInstance.generated.h"

UCLASS()
class BIOPROJECT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Mission")
		TArray<FString> m_Missions;

public:
	UFUNCTION(BlueprintCallable, CateGory = "Mission")
		FString GetMission(const int _index) const;

	static AActor* GetActorFromTag(const AActor* _pOwnerActor, const FName& _tag);

	static AActor* GetSpawnActor(UWorld* _spawnWorld, FString _path);
};
