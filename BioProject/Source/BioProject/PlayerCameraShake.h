//----------------------------------------------------
// ファイル名		:PlayerCameraShake.h
// 概要				:カメラ揺らす処理
// 作成者			:19CU0334 宮井晴生
//-----------------------------------------------------
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShake.h"
#include "PlayerCameraShake.generated.h"

/**
 * 
 */
UCLASS()
class BIOPROJECT_API UPlayerCameraShake : public UCameraShake
{
	GENERATED_BODY()

public:
	UPlayerCameraShake();

	void ShootShake();

	void DamageShake();
	
};
