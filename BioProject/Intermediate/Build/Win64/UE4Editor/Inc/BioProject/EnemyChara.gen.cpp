// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/EnemyChara.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyChara() {}
// Cross Module References
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_ActionStatus();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FEnemyStatus();
	BIOPROJECT_API UClass* Z_Construct_UClass_AEnemyChara_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_AEnemyChara();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AEnemyChara_GetEnemyStatus();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AEnemyChara_OnOverlapBegin();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AEnemyChara_ReturnAttack();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AEnemyChara_ReturnDeath();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AEnemyChara_ReturnKnockBack();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AEnemyChara_ReturnWalk();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static UEnum* ActionStatus_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioProject_ActionStatus, Z_Construct_UPackage__Script_BioProject(), TEXT("ActionStatus"));
		}
		return Singleton;
	}
	template<> BIOPROJECT_API UEnum* StaticEnum<ActionStatus>()
	{
		return ActionStatus_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ActionStatus(ActionStatus_StaticEnum, TEXT("/Script/BioProject"), TEXT("ActionStatus"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioProject_ActionStatus_Hash() { return 2857220035U; }
	UEnum* Z_Construct_UEnum_BioProject_ActionStatus()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ActionStatus"), 0, Get_Z_Construct_UEnum_BioProject_ActionStatus_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ActionStatus::Idle", (int64)ActionStatus::Idle },
				{ "ActionStatus::Move", (int64)ActionStatus::Move },
				{ "ActionStatus::Attack", (int64)ActionStatus::Attack },
				{ "ActionStatus::Avoid", (int64)ActionStatus::Avoid },
				{ "ActionStatus::KnockBack", (int64)ActionStatus::KnockBack },
				{ "ActionStatus::Death", (int64)ActionStatus::Death },
				{ "ActionStatus::Max", (int64)ActionStatus::Max },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Attack.Comment", "// ?\xda\x93?\n" },
				{ "Attack.Name", "ActionStatus::Attack" },
				{ "Attack.ToolTip", "?\xda\x93?" },
				{ "Avoid.Comment", "// ?U??\n" },
				{ "Avoid.Name", "ActionStatus::Avoid" },
				{ "Avoid.ToolTip", "?U??" },
				{ "BlueprintType", "true" },
				{ "Death.Comment", "// ????\n// ?m?b?N?o?b?N\n" },
				{ "Death.Name", "ActionStatus::Death" },
				{ "Death.ToolTip", "????\n?m?b?N?o?b?N" },
				{ "Idle.Name", "ActionStatus::Idle" },
				{ "KnockBack.Comment", "// ????\n" },
				{ "KnockBack.Name", "ActionStatus::KnockBack" },
				{ "Max.Comment", "// ???S\n" },
				{ "Max.Name", "ActionStatus::Max" },
				{ "Max.ToolTip", "???S" },
				{ "ModuleRelativePath", "EnemyChara.h" },
				{ "Move.Comment", "// ?\xd2\x8b@\n" },
				{ "Move.Name", "ActionStatus::Move" },
				{ "Move.ToolTip", "?\xd2\x8b@" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioProject,
				nullptr,
				"ActionStatus",
				"ActionStatus",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FEnemyStatus::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BIOPROJECT_API uint32 Get_Z_Construct_UScriptStruct_FEnemyStatus_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FEnemyStatus, Z_Construct_UPackage__Script_BioProject(), TEXT("EnemyStatus"), sizeof(FEnemyStatus), Get_Z_Construct_UScriptStruct_FEnemyStatus_Hash());
	}
	return Singleton;
}
template<> BIOPROJECT_API UScriptStruct* StaticStruct<FEnemyStatus>()
{
	return FEnemyStatus::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FEnemyStatus(FEnemyStatus::StaticStruct, TEXT("/Script/BioProject"), TEXT("EnemyStatus"), false, nullptr, nullptr);
static struct FScriptStruct_BioProject_StaticRegisterNativesFEnemyStatus
{
	FScriptStruct_BioProject_StaticRegisterNativesFEnemyStatus()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("EnemyStatus")),new UScriptStruct::TCppStructOps<FEnemyStatus>);
	}
} ScriptStruct_BioProject_StaticRegisterNativesFEnemyStatus;
	struct Z_Construct_UScriptStruct_FEnemyStatus_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_moveSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_moveSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_atk_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_atk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_downPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_downPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxDownPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_maxDownPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hp_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_hp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyStatus_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "EnemyChara.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEnemyStatus>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_moveSpeed_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?U??\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?U??" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_moveSpeed = { "moveSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyStatus, moveSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_moveSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_moveSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_atk_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?_?E???J?E???g\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?_?E???J?E???g" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_atk = { "atk", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyStatus, atk), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_atk_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_atk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_downPoint_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?\xc5\x91??_?E???J?E???g\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?\xc5\x91??_?E???J?E???g" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_downPoint = { "downPoint", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyStatus, downPoint), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_downPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_downPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_maxDownPoint_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ???\xdd\x82?HP\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "???\xdd\x82?HP" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_maxDownPoint = { "maxDownPoint", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyStatus, maxDownPoint), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_maxDownPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_maxDownPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_hp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "EnemyChara.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_hp = { "hp", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyStatus, hp), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_hp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_hp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEnemyStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_moveSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_atk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_downPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_maxDownPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyStatus_Statics::NewProp_hp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEnemyStatus_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"EnemyStatus",
		sizeof(FEnemyStatus),
		alignof(FEnemyStatus),
		Z_Construct_UScriptStruct_FEnemyStatus_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyStatus_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyStatus_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FEnemyStatus()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FEnemyStatus_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("EnemyStatus"), sizeof(FEnemyStatus), Get_Z_Construct_UScriptStruct_FEnemyStatus_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FEnemyStatus_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FEnemyStatus_Hash() { return 1865972700U; }
	void AEnemyChara::StaticRegisterNativesAEnemyChara()
	{
		UClass* Class = AEnemyChara::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetEnemyStatus", &AEnemyChara::execGetEnemyStatus },
			{ "OnOverlapBegin", &AEnemyChara::execOnOverlapBegin },
			{ "ReturnAttack", &AEnemyChara::execReturnAttack },
			{ "ReturnDeath", &AEnemyChara::execReturnDeath },
			{ "ReturnKnockBack", &AEnemyChara::execReturnKnockBack },
			{ "ReturnWalk", &AEnemyChara::execReturnWalk },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics
	{
		struct EnemyChara_eventGetEnemyStatus_Parms
		{
			FEnemyStatus ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyChara_eventGetEnemyStatus_Parms, ReturnValue), Z_Construct_UScriptStruct_FEnemyStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "EnemyState" },
		{ "Comment", "// ?G?l?~?[?\xcc\x83X?e?[?^?X???n??\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?G?l?~?[?\xcc\x83X?e?[?^?X???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyChara, nullptr, "GetEnemyStatus", nullptr, nullptr, sizeof(EnemyChara_eventGetEnemyStatus_Parms), Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyChara_GetEnemyStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyChara_GetEnemyStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics
	{
		struct EnemyChara_eventOnOverlapBegin_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyChara_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((EnemyChara_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EnemyChara_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyChara_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyChara_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyChara_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyChara_eventOnOverlapBegin_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// ?I?[?o?[???b?v?\xda\x90G?????n?\xdf\x82??\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?I?[?o?[???b?v?\xda\x90G?????n?\xdf\x82??\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyChara, nullptr, "OnOverlapBegin", nullptr, nullptr, sizeof(EnemyChara_eventOnOverlapBegin_Parms), Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyChara_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyChara_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics
	{
		struct EnemyChara_eventReturnAttack_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EnemyChara_eventReturnAttack_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EnemyChara_eventReturnAttack_Parms), &Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::Function_MetaDataParams[] = {
		{ "Category", "ReturnBool" },
		{ "Comment", "// ?m?b?N?o?b?N?A?j???[?V????\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?m?b?N?o?b?N?A?j???[?V????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyChara, nullptr, "ReturnAttack", nullptr, nullptr, sizeof(EnemyChara_eventReturnAttack_Parms), Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyChara_ReturnAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyChara_ReturnAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics
	{
		struct EnemyChara_eventReturnDeath_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EnemyChara_eventReturnDeath_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EnemyChara_eventReturnDeath_Parms), &Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::Function_MetaDataParams[] = {
		{ "Category", "ReturnBool" },
		{ "Comment", "// ?????A?j???[?V????\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?????A?j???[?V????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyChara, nullptr, "ReturnDeath", nullptr, nullptr, sizeof(EnemyChara_eventReturnDeath_Parms), Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyChara_ReturnDeath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyChara_ReturnDeath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics
	{
		struct EnemyChara_eventReturnKnockBack_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EnemyChara_eventReturnKnockBack_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EnemyChara_eventReturnKnockBack_Parms), &Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::Function_MetaDataParams[] = {
		{ "Category", "ReturnBool" },
		{ "Comment", "// ???S?A?j???[?V????\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "???S?A?j???[?V????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyChara, nullptr, "ReturnKnockBack", nullptr, nullptr, sizeof(EnemyChara_eventReturnKnockBack_Parms), Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyChara_ReturnKnockBack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyChara_ReturnKnockBack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics
	{
		struct EnemyChara_eventReturnWalk_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EnemyChara_eventReturnWalk_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EnemyChara_eventReturnWalk_Parms), &Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::Function_MetaDataParams[] = {
		{ "Category", "ReturnBool" },
		{ "Comment", "// ?A?j???[?V?????p\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?A?j???[?V?????p" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyChara, nullptr, "ReturnWalk", nullptr, nullptr, sizeof(EnemyChara_eventReturnWalk_Parms), Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyChara_ReturnWalk()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyChara_ReturnWalk_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEnemyChara_NoRegister()
	{
		return AEnemyChara::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyChara_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pDamageSE_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pDamageSE;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pDamageEffect_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pDamageEffect;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_BodyCollisionPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_BodyCollisionPos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_AtkEndTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_AtkEndTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_AtkStartTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_AtkStartTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_HeadShotOfSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_m_HeadShotOfSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_EnemyStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_EnemyStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AnimEndFrame_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AnimEndFrame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SearchArea_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_SearchArea;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyChara_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemyChara_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemyChara_GetEnemyStatus, "GetEnemyStatus" }, // 998690547
		{ &Z_Construct_UFunction_AEnemyChara_OnOverlapBegin, "OnOverlapBegin" }, // 2696042682
		{ &Z_Construct_UFunction_AEnemyChara_ReturnAttack, "ReturnAttack" }, // 3242205262
		{ &Z_Construct_UFunction_AEnemyChara_ReturnDeath, "ReturnDeath" }, // 3852308762
		{ &Z_Construct_UFunction_AEnemyChara_ReturnKnockBack, "ReturnKnockBack" }, // 207293896
		{ &Z_Construct_UFunction_AEnemyChara_ReturnWalk, "ReturnWalk" }, // 4001487807
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemyChara.h" },
		{ "ModuleRelativePath", "EnemyChara.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageSE_MetaData[] = {
		{ "Category", "CharaStatus" },
		{ "Comment", "// SE\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "SE" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageSE = { "m_pDamageSE", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_pDamageSE), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageSE_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageSE_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageEffect_MetaData[] = {
		{ "Category", "Effects" },
		{ "Comment", "// ?G?t?F?N?g\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?G?t?F?N?g" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageEffect = { "m_pDamageEffect", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_pDamageEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageEffect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageEffect_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_BodyCollisionPos_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "EnemyChara" },
		{ "Comment", "// ???C?\xcc\x8en?_\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "???C?\xcc\x8en?_" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_BodyCollisionPos = { "m_BodyCollisionPos", nullptr, (EPropertyFlags)0x0040000000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_BodyCollisionPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_BodyCollisionPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_BodyCollisionPos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkEndTime_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// ?A?^?b?N?A?j???[?V?????\xcc\x93????\xe8\x94\xbb?????I????\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?A?^?b?N?A?j???[?V?????\xcc\x93????\xe8\x94\xbb?????I????" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkEndTime = { "m_AtkEndTime", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_AtkEndTime), METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkEndTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkEndTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkStartTime_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// ?A?^?b?N?A?j???[?V?????\xcc\x93????\xe8\x94\xbb?????n?\xdf\x82?\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?A?^?b?N?A?j???[?V?????\xcc\x93????\xe8\x94\xbb?????n?\xdf\x82?" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkStartTime = { "m_AtkStartTime", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_AtkStartTime), METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkStartTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkStartTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_HeadShotOfSet_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// ?w?b?h?V???b?g?{??\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?w?b?h?V???b?g?{??" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_HeadShotOfSet = { "m_HeadShotOfSet", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_HeadShotOfSet), METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_HeadShotOfSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_HeadShotOfSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_EnemyStatus_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Status" },
		{ "Comment", "// ?X?e?[?^?X???\xdb\x8a?\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?X?e?[?^?X???\xdb\x8a?" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_EnemyStatus = { "m_EnemyStatus", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_EnemyStatus), Z_Construct_UScriptStruct_FEnemyStatus, METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_EnemyStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_EnemyStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_AnimEndFrame_MetaData[] = {
		{ "ArraySizeEnum", "/Script/BioProject.ActionStatus" },
		{ "Category", "Status" },
		{ "Comment", "// ?A?j???[?V?????\xcc\x8fI???\xe9\x8e\x9e?\xd4\x82??i?[\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "?A?j???[?V?????\xcc\x8fI???\xe9\x8e\x9e?\xd4\x82??i?[" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_AnimEndFrame = { "AnimEndFrame", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, CPP_ARRAY_DIM(AnimEndFrame, AEnemyChara), STRUCT_OFFSET(AEnemyChara, AnimEndFrame), METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_AnimEndFrame_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_AnimEndFrame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_SearchArea_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// ???C?\xcc\x92????i???`?????\xe8\x94\xbb???\xcc\x92????j\n" },
		{ "ModuleRelativePath", "EnemyChara.h" },
		{ "ToolTip", "???C?\xcc\x92????i???`?????\xe8\x94\xbb???\xcc\x92????j" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_SearchArea = { "m_SearchArea", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyChara, m_SearchArea), METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_SearchArea_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_SearchArea_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyChara_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageSE,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_pDamageEffect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_BodyCollisionPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkEndTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_AtkStartTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_HeadShotOfSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_EnemyStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_AnimEndFrame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyChara_Statics::NewProp_m_SearchArea,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyChara_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyChara>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyChara_Statics::ClassParams = {
		&AEnemyChara::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemyChara_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyChara_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyChara_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyChara()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyChara_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyChara, 2355623594);
	template<> BIOPROJECT_API UClass* StaticClass<AEnemyChara>()
	{
		return AEnemyChara::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyChara(Z_Construct_UClass_AEnemyChara, &AEnemyChara::StaticClass, TEXT("/Script/BioProject"), TEXT("AEnemyChara"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyChara);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
