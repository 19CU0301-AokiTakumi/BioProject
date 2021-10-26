
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

AActor* UMyGameInstance::GetActorFromTag(const AActor* _pOwnerActor, const FName& _tag)
{
	if (_pOwnerActor == NULL)
		return NULL;

	TSubclassOf<AActor> findClass;

	findClass = AActor::StaticClass();
	TArray<AActor*> actors;

	UGameplayStatics::GetAllActorsOfClass(_pOwnerActor->GetWorld(), findClass, actors);

	if (actors.Num() <= 0)
		return NULL;

	for (int idx = 0; idx < actors.Num(); ++idx)
	{
		AActor* pActor = Cast<AActor>(actors[idx]);

		if (pActor->ActorHasTag(_tag))
		{
			return pActor;
		}
	}
	return NULL;
}

// 指定のパスにあるアクターを生成するメソッド
AActor* UMyGameInstance::GetSpawnActor(UWorld* _spawnWorld, FString _path)
{
	TSubclassOf<class AActor> NewActor = TSoftClassPtr<AActor>(FSoftObjectPath(*_path)).LoadSynchronous();
	return _spawnWorld->SpawnActor<AActor>(NewActor);
}