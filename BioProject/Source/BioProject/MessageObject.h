// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventObjectBase.h"
#include "MessageObject.generated.h"

/**
 * 
 */
UCLASS()
class BIOPROJECT_API AMessageObject : public AEventObjectBase
{
	GENERATED_BODY()

public:
	AMessageObject();
	
private:
	UPROPERTY(EditAnywhere, Category = "Data")
		TArray<FString> m_message;

public:
	UFUNCTION(BlueprintCallable, CateGory = "GetData", BlueprintPure)
		FString GetMessage() const;
};
