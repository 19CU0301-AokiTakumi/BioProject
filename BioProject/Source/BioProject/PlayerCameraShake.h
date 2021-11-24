//----------------------------------------------------
// �t�@�C����		:PlayerCameraShake.h
// �T�v				:�J�����h�炷����
// �쐬��			:19CU0334 �{�䐰��
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
