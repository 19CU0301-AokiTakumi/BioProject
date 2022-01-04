#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "BathtubEventControl.generated.h"

class APlayerChara;

UCLASS()
class BIOPROJECT_API ABathtubEventControl : public AEventObjectBase
{
	GENERATED_BODY()
	
public:
	ABathtubEventControl();

protected:
	// 初期化
	virtual void BeginPlay() override;

public:
	// 更新
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* m_pWaterMesh;

	UPROPERTY(EditAnywhere, Category = "Component")
		float m_downSpeed;

	UPROPERTY(EditAnywhere, Category = "Component")
		float m_WaterMaxDown;

	UPROPERTY(EditAnywhere, Category = "Component")
		float m_downShrink;

	UPROPERTY(EditAnywhere, Category = "CharaStatus")
		USoundBase* m_pWaterSE;

private:
	APlayerChara* m_Player;		// プレイヤーを格納
	AActor* SpawnItem;

	int m_index;

	float m_WaterMeshLocation;
	float m_WaterShrink;

	bool m_SpawnOnce;
	bool m_WidgetOpen;
	bool m_DoAction;

	void DownWaterSurface(float _deltaTime);
	void ItemSpawn();

public:
	void SetDoAction(bool _doAction) { m_DoAction = _doAction; }

	void PlaySound();

public:
	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetEventStart(const bool _eventStart) { m_bIsEventStart = _eventStart; }

	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		bool GetEventStartCheck() { return m_bIsEventStart; }

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetOpenWidget(bool _widgetOpen) { m_WidgetOpen = _widgetOpen; }

	UFUNCTION(BlueprintCallable, CateGory = "GetBool", BlueprintPure)
		bool GetOpenWidget()const { return m_WidgetOpen; }

	UFUNCTION(BlueprintCallable, CateGory = "SetData")
		void SetIndex(const int _index) { m_index = _index; }
};
