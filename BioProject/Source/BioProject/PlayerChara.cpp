// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChara.h"

// Sets default values
APlayerChara::APlayerChara()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerChara::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Move_Forward", this, &APlayerChara::MoveForward);
	InputComponent->BindAxis("Move_Right", this, &APlayerChara::MoveRight);
}

void APlayerChara::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APlayerChara::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}