#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "BathtubEventControl.generated.h"

UCLASS()
class BIOPROJECT_API ABathtubEventControl : public AEventObjectBase
{
	GENERATED_BODY()
	
public:
	ABathtubEventControl();

protected:
	// èâä˙âª
	virtual void BeginPlay() override;

public:
	// çXêV
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

private:
	float m_WaterMeshLocation;
	float m_WaterShrink;

	bool m_SpawnOnce;

	void DownWaterSurface(float _deltaTime);
	void ItemSpawn();
};
