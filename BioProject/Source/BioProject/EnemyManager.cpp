// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "PlayerChara.h"
#include "EventControl.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyManager::AEnemyManager()
	: SpawnEnemy(NULL)
	, PathName("")
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();

	int i = 1;
	FString s = "EventControl" + FString::FromInt(i);
	while (Cast<AEventControl>(UMyGameInstance::GetActorFromTag(this, FName(*s))))
	{
		//UE_LOG(LogTemp, Error, TEXT("%s"), *s);
		m_EventBox.Add(Cast<AEventControl>(UMyGameInstance::GetActorFromTag(this, FName(*s))));
		i++;
		s = "EventControl" + FString::FromInt(i);
	}
	// UE_LOG(LogTemp, Error, TEXT("%d"), m_EventBox.Num());
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	InputPath();
}

void AEnemyManager::InputPath()
{
	for (int i = 0; i < m_EventBox.Num(); i++)
	{
		if (m_EventBox[i]->GetPlayerHit() == false)
			continue;

		// UE_LOG(LogTemp, Error, TEXT("%d"),i);

		switch (i + 1)
		{
		case 1:
			// UE_LOG(LogTemp, Warning, TEXT("—N‚¢‚Ä‚é‚º"))
			PathName = "/Game/BP/Enemy/DropKeyEnemyBP.DropKeyEnemyBP_C";
			break;

		case 2:
			UE_LOG(LogTemp, Warning, TEXT("—N‚¢‚Ä‚é‚º"));
			PathName = "/Game/EnemyAI/NewEnemyBP.NewEnemyBP_C";
			break;

		case 3:
			PathName = "/Game/EnemyAI/ShutterEnemyBP.ShutterEnemyBP_C";
			break;

		case 4:
			PathName = "/Game/EnemyAI/EnemyAIBP.EnemyAIBP_C";
			break;

		default:
			break;
		}

		if (!m_EventBox[i]->GetSpawnOnce())
		{
			//7/23(‹à)C³‰ÓŠ
			//if (i != 0 && !m_EventBox[i - 1]->GetSpawnOnce())
				//return;

			for (int j = 0; j < m_EventBox[i]->GetSpawnLocationLength(); ++j)
			{
				SpawnEnemy = UMyGameInstance::GetSpawnActor(GetWorld(), PathName);

				if (SpawnEnemy != NULL)
				{
					UE_LOG(LogTemp, Error, TEXT("Spawn"));
					SpawnEnemy->SetActorLocation(m_EventBox[i]->GetSpawnLocation()[j] + m_EventBox[i]->GetActorLocation());
					//FVector a0 = m_EventBox[i]->GetSpawnLocation()[j];
					//FVector a1 = m_EventBox[i]->GetActorLocation();
					//FVector a2 = m_EventBox[i]->GetSpawnLocation()[j] + m_EventBox[i]->GetActorLocation();
					////UE_LOG(LogTemp, Error, TEXT("%s + %s = %s"), a0, a1, a2);
					//UE_LOG(LogTemp, Error, TEXT("---------------"));
					//UE_LOG(LogTemp, Error, TEXT("(%f, %f, %f) + "), a0.X, a0.Y, a0.Z);
					//UE_LOG(LogTemp, Error, TEXT("(%f, %f, %f) = "), a1.X, a1.Y, a1.Z);
					//UE_LOG(LogTemp, Error, TEXT("(%f, %f, %f)   "), a2.X, a2.Y, a2.Z);
					//UE_LOG(LogTemp, Error, TEXT("---------------"));

					//SpawnEnemy->SetActorRotation(m_EventBox[i]->GetSpawnPoint()->GetRelativeRotation());
				}
			}
			m_EventBox[i]->SetSpawnOnce(true);
			//
		}
	}
}