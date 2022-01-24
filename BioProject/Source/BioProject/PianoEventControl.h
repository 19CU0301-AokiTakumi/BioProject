// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "PianoEventControl.generated.h"

class APlayerChara;

UCLASS()
class BIOPROJECT_API APianoEventControl : public AEventObjectBase
{
	GENERATED_BODY()

public:
	APianoEventControl();

protected:
	// 初期化
	virtual void BeginPlay() override;

public:
	// 更新
	virtual void Tick(float DeltaTime) override;

protected:
	// オーバーラップ接触をし始めたときに呼ばれるイベント関数
	UFUNCTION() virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// オーバーラップ接触をし終えたときに呼ばれるイベント関数
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:
	APlayerChara* m_Player;		// プレイヤーを格納
	AActor* SpawnItem;

	int m_index;
	int m_CountNumber;
	int m_MaxNumber;

	bool m_bIsOpen;
	bool m_bIsItemOnce;
	bool m_bIsMusicHaveCheck;

	void GetItem();
	bool KeyCheck();

private:
	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<int> m_ArrayKeybord;

	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<int> m_AnswerKeybord;

public:
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void InputKeybord(const int _index);

	UFUNCTION(BlueprintCallable, CateGory = "Getint", BlueprintPure)
		int GetPushNumber() { return m_CountNumber; }

	UFUNCTION(BlueprintCallable, CateGory = "Getint", BlueprintPure)
		int GetMaxNumber() { return m_ArrayKeybord.Num(); }

	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetScoreHaveCheck() { return m_bIsMusicHaveCheck; }
};
