//----------------------------------------------------
// ファイル名		:PlayerCameraShake.cpp
// 概要				:カメラ揺らす処理
// 作成者			:19CU0334 宮井晴生
//-----------------------------------------------------


#include "PlayerCameraShake.h"

UPlayerCameraShake::UPlayerCameraShake()
{
    //ShootShake();

    DamageShake();

}

void UPlayerCameraShake::ShootShake()
{
    OscillationDuration = 0.1f;            // 現在の画面が揺れる時間（秒単位）。0未満は不定を意味し、0は発振がないことを意味します。          
    OscillationBlendInTime = 0.1f;         // ブレンドインの期間。振動は0から1まで変化します。
    OscillationBlendOutTime = 0.1f;        // ブレンドアウトの期間。振動は1から0まで変化します。

    RotOscillation.Pitch.Amplitude = FMath::RandRange(5.0f, 1.0f);
    RotOscillation.Pitch.Frequency = FMath::RandRange(5.0f, 1.0f);

    RotOscillation.Yaw.Amplitude = FMath::RandRange(1.0f, 1.0f);
    RotOscillation.Yaw.Frequency = FMath::RandRange(1.0f, 1.0f);
}

void UPlayerCameraShake::DamageShake()
{
    OscillationDuration = 0.5f;            // 現在の画面が揺れる時間（秒単位）。0未満は不定を意味し、0は発振がないことを意味します。          
    OscillationBlendInTime = 1.0f;         // ブレンドインの期間。振動は0から1まで変化します。
    OscillationBlendOutTime = 1.f;        // ブレンドアウトの期間。振動は1から0まで変化します。

    RotOscillation.Pitch.Amplitude = FMath::RandRange(70.0f, 80.0f);
    RotOscillation.Pitch.Frequency = FMath::RandRange(70.0f, 80.0f);

    RotOscillation.Yaw.Amplitude = FMath::RandRange(30.0f, 70.0f);
    RotOscillation.Yaw.Frequency = FMath::RandRange(30.0f, 70.0f);
}