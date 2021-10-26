
#pragma once

#include "CoreMinimal.h"
#include "MyGameInstance.h"
#include "ItemBase.h"
#include "GameFramework/Character.h"
#include "PlayerChara.generated.h"

// 前方宣言
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BIOPROJECT_API APlayerChara : public ACharacter
{
	GENERATED_BODY()

public:
	// コンストラクタ
	APlayerChara();

protected:
	// ゲーム開始時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:	
	// 毎フレーム呼更新処理
	virtual void Tick(float DeltaTime) override;

	// 各入力関係とのバインド処理
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// スプリングアーム
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* m_pSpringArm;

	// カメラ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* m_pCamera;

private:
	//　キャラ移動入力量
	FVector m_CharaMoveInput;

	//　カメラ回転入力量
	FVector m_CameraRotationInput;

	// カメラの左右の稼働範囲
	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FVector2D m_CameraYawLimit;

	// カメラの上下の稼働範囲
	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FVector2D m_CameraPitchLimit;

	// 移動速度
	UPROPERTY(EditAnywhere, Category = "Status")
		float m_MoveSpeed;

	// Player のカバンの中身を格納
	UPROPERTY(EditAnywhere, Category = "ItemData")
		TArray<FItemData> m_ItemDatas;

	// バッグのサイズ
	UPROPERTY(EditAnywhere, Category = "ItemData")
		int m_bagSize;

	// アイテムを取得したか
	bool m_bisItemGet;

private:
	// 移動処理
	void UpdateMove(float _deltaTime);

	// カメラ更新処理
	void UpdateCamera(float _deltaTime);

public:
	// アイテムを取得したかを渡す
	bool IsGetItem() { return m_bisItemGet; }

	// バッグの中身を渡す
	UFUNCTION(BlueprintCallable, CateGory = "ReturnBool", BlueprintPure)
		TArray<FItemData> GetPlayerBag() { return m_ItemDatas; }

public:
	// 【入力バインド】キャラ移動：前後
	void MoveForward(float _axisValue);

	// 【入力バインド】キャラ移動：左右
	void MoveRight(float _axisValue);

	// 【入力バインド】カメラ回転：Pitch（Y軸）
	void CameraRotatePitch(float _axisValue);

	// 【入力バインド】カメラ回転：Yaw（Z軸）
	void CameraRotateYaw(float _axisValue);
};
