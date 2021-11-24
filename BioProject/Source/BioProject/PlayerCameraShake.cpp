//----------------------------------------------------
// �t�@�C����		:PlayerCameraShake.cpp
// �T�v				:�J�����h�炷����
// �쐬��			:19CU0334 �{�䐰��
//-----------------------------------------------------


#include "PlayerCameraShake.h"

UPlayerCameraShake::UPlayerCameraShake()
{
    //ShootShake();

    DamageShake();

}

void UPlayerCameraShake::ShootShake()
{
    OscillationDuration = 0.1f;            // ���݂̉�ʂ��h��鎞�ԁi�b�P�ʁj�B0�����͕s����Ӗ����A0�͔��U���Ȃ����Ƃ��Ӗ����܂��B          
    OscillationBlendInTime = 0.1f;         // �u�����h�C���̊��ԁB�U����0����1�܂ŕω����܂��B
    OscillationBlendOutTime = 0.1f;        // �u�����h�A�E�g�̊��ԁB�U����1����0�܂ŕω����܂��B

    RotOscillation.Pitch.Amplitude = FMath::RandRange(5.0f, 1.0f);
    RotOscillation.Pitch.Frequency = FMath::RandRange(5.0f, 1.0f);

    RotOscillation.Yaw.Amplitude = FMath::RandRange(1.0f, 1.0f);
    RotOscillation.Yaw.Frequency = FMath::RandRange(1.0f, 1.0f);
}

void UPlayerCameraShake::DamageShake()
{
    OscillationDuration = 0.5f;            // ���݂̉�ʂ��h��鎞�ԁi�b�P�ʁj�B0�����͕s����Ӗ����A0�͔��U���Ȃ����Ƃ��Ӗ����܂��B          
    OscillationBlendInTime = 1.0f;         // �u�����h�C���̊��ԁB�U����0����1�܂ŕω����܂��B
    OscillationBlendOutTime = 1.f;        // �u�����h�A�E�g�̊��ԁB�U����1����0�܂ŕω����܂��B

    RotOscillation.Pitch.Amplitude = FMath::RandRange(70.0f, 80.0f);
    RotOscillation.Pitch.Frequency = FMath::RandRange(70.0f, 80.0f);

    RotOscillation.Yaw.Amplitude = FMath::RandRange(30.0f, 70.0f);
    RotOscillation.Yaw.Frequency = FMath::RandRange(30.0f, 70.0f);
}