// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageObject.h"

AMessageObject::AMessageObject()
{
	m_message.Init("", 3);
}

FString AMessageObject::GetMessage() const
{
	FString retStr;
	for (int i = 0; i < 3; ++i)
	{
		retStr += m_message[i] + "\n";

	}
	return retStr;
}
