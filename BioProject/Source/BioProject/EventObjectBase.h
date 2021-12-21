// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventObjectBase.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EEventType : uint8
{
	Inventory,
	Bathroom,
	BookShelf,
};

UCLASS()
class BIOPROJECT_API AEventObjectBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// コンストラクタ
	AEventObjectBase();

protected:
	// しょきか
	virtual void BeginPlay() override;

public:	
	// こうしん
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		USceneComponent* m_pBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* m_pBoxComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pMainMesh;

	UPROPERTY(EditAnywhere, Category = "Component")
		EEventType m_eventType;

protected:
	bool m_bIsEventStart;

public:
	void SetIsEventStart(const bool _IsEventStart) { m_bIsEventStart = _IsEventStart; }
};
