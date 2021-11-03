// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/PlayerChara.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerChara() {}
// Cross Module References
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerStatus();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	BIOPROJECT_API UClass* Z_Construct_UClass_APlayerChara_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_APlayerChara();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerBag();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FItemData();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerHP();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_OnOverlapBegin();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
class UScriptStruct* FPlayerStatus::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BIOPROJECT_API uint32 Get_Z_Construct_UScriptStruct_FPlayerStatus_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerStatus, Z_Construct_UPackage__Script_BioProject(), TEXT("PlayerStatus"), sizeof(FPlayerStatus), Get_Z_Construct_UScriptStruct_FPlayerStatus_Hash());
	}
	return Singleton;
}
template<> BIOPROJECT_API UScriptStruct* StaticStruct<FPlayerStatus>()
{
	return FPlayerStatus::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPlayerStatus(FPlayerStatus::StaticStruct, TEXT("/Script/BioProject"), TEXT("PlayerStatus"), false, nullptr, nullptr);
static struct FScriptStruct_BioProject_StaticRegisterNativesFPlayerStatus
{
	FScriptStruct_BioProject_StaticRegisterNativesFPlayerStatus()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PlayerStatus")),new UScriptStruct::TCppStructOps<FPlayerStatus>);
	}
} ScriptStruct_BioProject_StaticRegisterNativesFPlayerStatus;
	struct Z_Construct_UScriptStruct_FPlayerStatus_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerStatus>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"PlayerStatus",
		sizeof(FPlayerStatus),
		alignof(FPlayerStatus),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStatus_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPlayerStatus()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPlayerStatus_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PlayerStatus"), sizeof(FPlayerStatus), Get_Z_Construct_UScriptStruct_FPlayerStatus_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPlayerStatus_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPlayerStatus_Hash() { return 3134307890U; }
	void APlayerChara::StaticRegisterNativesAPlayerChara()
	{
		UClass* Class = APlayerChara::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPlayerBag", &APlayerChara::execGetPlayerBag },
			{ "GetPlayerHP", &APlayerChara::execGetPlayerHP },
			{ "GetPlayerMaxHP", &APlayerChara::execGetPlayerMaxHP },
			{ "OnOverlapBegin", &APlayerChara::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics
	{
		struct PlayerChara_eventGetPlayerBag_Parms
		{
			TArray<FItemData> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetPlayerBag_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FItemData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerData" },
		{ "Comment", "// ?o?b?O?\xcc\x92??g???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?o?b?O?\xcc\x92??g???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetPlayerBag", nullptr, nullptr, sizeof(PlayerChara_eventGetPlayerBag_Parms), Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerBag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetPlayerBag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics
	{
		struct PlayerChara_eventGetPlayerHP_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetPlayerHP_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerData" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetPlayerHP", nullptr, nullptr, sizeof(PlayerChara_eventGetPlayerHP_Parms), Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerHP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetPlayerHP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics
	{
		struct PlayerChara_eventGetPlayerMaxHP_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetPlayerMaxHP_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerData" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetPlayerMaxHP", nullptr, nullptr, sizeof(PlayerChara_eventGetPlayerMaxHP_Parms), Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics
	{
		struct PlayerChara_eventOnOverlapBegin_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((PlayerChara_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PlayerChara_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapBegin_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// ?I?[?o?[???b?v?\xda\x90G?????n?\xdf\x82??\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?I?[?o?[???b?v?\xda\x90G?????n?\xdf\x82??\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "OnOverlapBegin", nullptr, nullptr, sizeof(PlayerChara_eventOnOverlapBegin_Parms), Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APlayerChara_NoRegister()
	{
		return APlayerChara::StaticClass();
	}
	struct Z_Construct_UClass_APlayerChara_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_bagSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_m_bagSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ItemDatas_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_m_ItemDatas;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_ItemDatas_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_playerStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_playerStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_CameraPitchLimit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_CameraPitchLimit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_CameraYawLimit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_CameraYawLimit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pSpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pSpringArm;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerChara_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APlayerChara_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerBag, "GetPlayerBag" }, // 3185049530
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerHP, "GetPlayerHP" }, // 64706150
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP, "GetPlayerMaxHP" }, // 3006678924
		{ &Z_Construct_UFunction_APlayerChara_OnOverlapBegin, "OnOverlapBegin" }, // 2666479904
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PlayerChara.h" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_bagSize_MetaData[] = {
		{ "Category", "ItemData" },
		{ "Comment", "// ?o?b?O?\xcc\x83T?C?Y\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?o?b?O?\xcc\x83T?C?Y" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_bagSize = { "m_bagSize", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_bagSize), METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_bagSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_bagSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas_MetaData[] = {
		{ "Category", "ItemData" },
		{ "Comment", "// Player ?\xcc\x83J?o???\xcc\x92??g???i?[\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "Player ?\xcc\x83J?o???\xcc\x92??g???i?[" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas = { "m_ItemDatas", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_ItemDatas), METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas_Inner = { "m_ItemDatas", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FItemData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// ?\xda\x93????x\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?\xda\x93????x" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus = { "m_playerStatus", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_playerStatus), Z_Construct_UScriptStruct_FPlayerStatus, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraPitchLimit_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "// ?J?????\xcc\x8f\xe3\x89\xba?\xcc\x89\xd2\x93??\xcd\x88?\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?J?????\xcc\x8f\xe3\x89\xba?\xcc\x89\xd2\x93??\xcd\x88?" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraPitchLimit = { "m_CameraPitchLimit", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_CameraPitchLimit), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraPitchLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraPitchLimit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraYawLimit_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "// ?J?????\xcc\x8d??E?\xcc\x89\xd2\x93??\xcd\x88?\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?J?????\xcc\x8d??E?\xcc\x89\xd2\x93??\xcd\x88?" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraYawLimit = { "m_CameraYawLimit", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_CameraYawLimit), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraYawLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraYawLimit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "// ?J????\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?J????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pCamera = { "m_pCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_pCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "// ?X?v?????O?A?[??\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?X?v?????O?A?[??" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pSpringArm = { "m_pSpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_pSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pSpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pSpringArm_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayerChara_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_bagSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ItemDatas_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraPitchLimit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraYawLimit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_pSpringArm,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerChara_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerChara>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayerChara_Statics::ClassParams = {
		&APlayerChara::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APlayerChara_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayerChara()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlayerChara_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayerChara, 2912403397);
	template<> BIOPROJECT_API UClass* StaticClass<APlayerChara>()
	{
		return APlayerChara::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerChara(Z_Construct_UClass_APlayerChara, &APlayerChara::StaticClass, TEXT("/Script/BioProject"), TEXT("APlayerChara"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerChara);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
