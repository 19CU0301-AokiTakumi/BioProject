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
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_EInventoryState();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_EActionStatus();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FStatusConstant();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerStatus();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGunData();
	BIOPROJECT_API UClass* Z_Construct_UClass_APlayerChara_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_APlayerChara();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_Damage();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetAmmoData();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAmmoData();
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_EGunType();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetAnimStatus();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetCursorIndex();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetInventoryState();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetIsDead();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetIsGunHold();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetIsItemTouch();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetIsOpenInventory();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetLandingPoint();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetOverlapActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerBag();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FItemData();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerHP();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerStatus();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_Heal();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_OnOverlapBegin();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_OnOverlapEnd();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_SetEquipGunData();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_SetInventoryState();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_APlayerChara_SetIsGetItem();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	BIOPROJECT_API UClass* Z_Construct_UClass_UPlayerCameraShake_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	static UEnum* EInventoryState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioProject_EInventoryState, Z_Construct_UPackage__Script_BioProject(), TEXT("EInventoryState"));
		}
		return Singleton;
	}
	template<> BIOPROJECT_API UEnum* StaticEnum<EInventoryState>()
	{
		return EInventoryState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EInventoryState(EInventoryState_StaticEnum, TEXT("/Script/BioProject"), TEXT("EInventoryState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioProject_EInventoryState_Hash() { return 3519519293U; }
	UEnum* Z_Construct_UEnum_BioProject_EInventoryState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EInventoryState"), 0, Get_Z_Construct_UEnum_BioProject_EInventoryState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EInventoryState::Idle", (int64)EInventoryState::Idle },
				{ "EInventoryState::Open", (int64)EInventoryState::Open },
				{ "EInventoryState::Close", (int64)EInventoryState::Close },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Close.Comment", "// ??????\n// ?J???\xc4\x82???\n" },
				{ "Close.Name", "EInventoryState::Close" },
				{ "Close.ToolTip", "??????\n?J???\xc4\x82???" },
				{ "Comment", "// ?C???x???g???\xcc\x8f??\xd4\x8a\xc7\x97??p?\xcc\x97\xf1\x8b\x93\x8c^\n" },
				{ "Idle.Name", "EInventoryState::Idle" },
				{ "ModuleRelativePath", "PlayerChara.h" },
				{ "Open.Comment", "// ??????\n" },
				{ "Open.Name", "EInventoryState::Open" },
				{ "ToolTip", "?C???x???g???\xcc\x8f??\xd4\x8a\xc7\x97??p?\xcc\x97\xf1\x8b\x93\x8c^" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioProject,
				nullptr,
				"EInventoryState",
				"EInventoryState",
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
	static UEnum* EActionStatus_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioProject_EActionStatus, Z_Construct_UPackage__Script_BioProject(), TEXT("EActionStatus"));
		}
		return Singleton;
	}
	template<> BIOPROJECT_API UEnum* StaticEnum<EActionStatus>()
	{
		return EActionStatus_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EActionStatus(EActionStatus_StaticEnum, TEXT("/Script/BioProject"), TEXT("EActionStatus"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioProject_EActionStatus_Hash() { return 47971065U; }
	UEnum* Z_Construct_UEnum_BioProject_EActionStatus()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EActionStatus"), 0, Get_Z_Construct_UEnum_BioProject_EActionStatus_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EActionStatus::Idle", (int64)EActionStatus::Idle },
				{ "EActionStatus::Walk", (int64)EActionStatus::Walk },
				{ "EActionStatus::Run", (int64)EActionStatus::Run },
				{ "EActionStatus::GunHold", (int64)EActionStatus::GunHold },
				{ "EActionStatus::Reload", (int64)EActionStatus::Reload },
				{ "EActionStatus::Guard", (int64)EActionStatus::Guard },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "// ?A?N?V?????\xcc\x8f??\xd4\x8a\xc7\x97??p?\xcc\x97\xf1\x8b\x93\x8c^\n" },
				{ "Guard.Comment", "// ?????[?h\n" },
				{ "Guard.Name", "EActionStatus::Guard" },
				{ "Guard.ToolTip", "?????[?h" },
				{ "GunHold.Comment", "// ??????\n// ????\n// ????\n" },
				{ "GunHold.Name", "EActionStatus::GunHold" },
				{ "Idle.Name", "EActionStatus::Idle" },
				{ "ModuleRelativePath", "PlayerChara.h" },
				{ "Reload.Comment", "// ??????\n// ????\n// ????\n// ?e???\\???\xc4\x82???\n" },
				{ "Reload.Name", "EActionStatus::Reload" },
				{ "Reload.ToolTip", "??????\n????\n????\n?e???\\???\xc4\x82???" },
				{ "Run.Comment", "// ??????\n// ????\n" },
				{ "Run.Name", "EActionStatus::Run" },
				{ "ToolTip", "?A?N?V?????\xcc\x8f??\xd4\x8a\xc7\x97??p?\xcc\x97\xf1\x8b\x93\x8c^" },
				{ "Walk.Comment", "// ??????\n" },
				{ "Walk.Name", "EActionStatus::Walk" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioProject,
				nullptr,
				"EActionStatus",
				"EActionStatus",
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
class UScriptStruct* FStatusConstant::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BIOPROJECT_API uint32 Get_Z_Construct_UScriptStruct_FStatusConstant_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStatusConstant, Z_Construct_UPackage__Script_BioProject(), TEXT("StatusConstant"), sizeof(FStatusConstant), Get_Z_Construct_UScriptStruct_FStatusConstant_Hash());
	}
	return Singleton;
}
template<> BIOPROJECT_API UScriptStruct* StaticStruct<FStatusConstant>()
{
	return FStatusConstant::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStatusConstant(FStatusConstant::StaticStruct, TEXT("/Script/BioProject"), TEXT("StatusConstant"), false, nullptr, nullptr);
static struct FScriptStruct_BioProject_StaticRegisterNativesFStatusConstant
{
	FScriptStruct_BioProject_StaticRegisterNativesFStatusConstant()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("StatusConstant")),new UScriptStruct::TCppStructOps<FStatusConstant>);
	}
} ScriptStruct_BioProject_StaticRegisterNativesFStatusConstant;
	struct Z_Construct_UScriptStruct_FStatusConstant_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_runSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_runSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_walkSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_walkSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStatusConstant_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// ?X?e?[?^?X?\xcf\x8dX?\xcc\x8d\xdb\x82\xcc\x8a\xee\x8f\x80?\xc6\x82\xc8\x82??f?[?^???\xdc\x82\xc6\x82\xdf\x82??\\????\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?X?e?[?^?X?\xcf\x8dX?\xcc\x8d\xdb\x82\xcc\x8a\xee\x8f\x80?\xc6\x82\xc8\x82??f?[?^???\xdc\x82\xc6\x82\xdf\x82??\\????" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStatusConstant_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStatusConstant>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_runSpeed_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?????\xcc\x83X?s?[?h\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?????\xcc\x83X?s?[?h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_runSpeed = { "runSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStatusConstant, runSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_runSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_runSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_walkSpeed_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?????\xcc\x83X?s?[?h\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?????\xcc\x83X?s?[?h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_walkSpeed = { "walkSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStatusConstant, walkSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_walkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_walkSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStatusConstant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_runSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatusConstant_Statics::NewProp_walkSpeed,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStatusConstant_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"StatusConstant",
		sizeof(FStatusConstant),
		alignof(FStatusConstant),
		Z_Construct_UScriptStruct_FStatusConstant_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatusConstant_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStatusConstant_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatusConstant_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStatusConstant()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStatusConstant_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StatusConstant"), sizeof(FStatusConstant), Get_Z_Construct_UScriptStruct_FStatusConstant_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStatusConstant_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStatusConstant_Hash() { return 2345283792U; }
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_equipGunID_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_equipGunID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_equipGunData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_equipGunData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_moveSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_moveSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxHP_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_maxHP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hp_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_hp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// ?v???C???[?\xcc\x83X?e?[?^?X???\xdc\x82\xc6\x82\xdf\x82??\\????\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?v???C???[?\xcc\x83X?e?[?^?X???\xdc\x82\xc6\x82\xdf\x82??\\????" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerStatus>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunID_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ???????\xc4\x82??\xe9\x95\x90???\xcc\x83""f?[?^\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "???????\xc4\x82??\xe9\x95\x90???\xcc\x83""f?[?^" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunID = { "equipGunID", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlayerStatus, equipGunID), METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunData_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?\xda\x93????x\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?\xda\x93????x" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunData = { "equipGunData", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlayerStatus, equipGunData), Z_Construct_UScriptStruct_FGunData, METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_moveSpeed_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?\xc5\x91?HP\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?\xc5\x91?HP" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_moveSpeed = { "moveSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlayerStatus, moveSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_moveSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_moveSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_maxHP_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ???\xdd\x82?HP\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "???\xdd\x82?HP" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_maxHP = { "maxHP", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlayerStatus, maxHP), METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_maxHP_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_maxHP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_hp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_hp = { "hp", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlayerStatus, hp), METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_hp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_hp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlayerStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_equipGunData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_moveSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_maxHP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStatus_Statics::NewProp_hp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerStatus_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"PlayerStatus",
		sizeof(FPlayerStatus),
		alignof(FPlayerStatus),
		Z_Construct_UScriptStruct_FPlayerStatus_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStatus_Statics::PropPointers),
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
	uint32 Get_Z_Construct_UScriptStruct_FPlayerStatus_Hash() { return 1426935838U; }
	void APlayerChara::StaticRegisterNativesAPlayerChara()
	{
		UClass* Class = APlayerChara::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Damage", &APlayerChara::execDamage },
			{ "GetAmmoData", &APlayerChara::execGetAmmoData },
			{ "GetAnimStatus", &APlayerChara::execGetAnimStatus },
			{ "GetCursorIndex", &APlayerChara::execGetCursorIndex },
			{ "GetInventoryState", &APlayerChara::execGetInventoryState },
			{ "GetIsDead", &APlayerChara::execGetIsDead },
			{ "GetIsGunHold", &APlayerChara::execGetIsGunHold },
			{ "GetIsItemTouch", &APlayerChara::execGetIsItemTouch },
			{ "GetIsOpenInventory", &APlayerChara::execGetIsOpenInventory },
			{ "GetLandingPoint", &APlayerChara::execGetLandingPoint },
			{ "GetOverlapActor", &APlayerChara::execGetOverlapActor },
			{ "GetPlayerBag", &APlayerChara::execGetPlayerBag },
			{ "GetPlayerHP", &APlayerChara::execGetPlayerHP },
			{ "GetPlayerMaxHP", &APlayerChara::execGetPlayerMaxHP },
			{ "GetPlayerStatus", &APlayerChara::execGetPlayerStatus },
			{ "Heal", &APlayerChara::execHeal },
			{ "OnOverlapBegin", &APlayerChara::execOnOverlapBegin },
			{ "OnOverlapEnd", &APlayerChara::execOnOverlapEnd },
			{ "SetEquipGunData", &APlayerChara::execSetEquipGunData },
			{ "SetInventoryState", &APlayerChara::execSetInventoryState },
			{ "SetIsGetItem", &APlayerChara::execSetIsGetItem },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APlayerChara_Damage_Statics
	{
		struct PlayerChara_eventDamage_Parms
		{
			int32 _atk;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp__atk;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_Damage_Statics::NewProp__atk = { "_atk", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventDamage_Parms, _atk), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_Damage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_Damage_Statics::NewProp__atk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_Damage_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetData" },
		{ "Comment", "// ???_???[?W????\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "???_???[?W????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_Damage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "Damage", nullptr, nullptr, sizeof(PlayerChara_eventDamage_Parms), Z_Construct_UFunction_APlayerChara_Damage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_Damage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_Damage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_Damage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_Damage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_Damage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics
	{
		struct PlayerChara_eventGetAmmoData_Parms
		{
			EGunType _ammoType;
			FAmmoData ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__ammoType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp__ammoType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp__ammoType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetAmmoData_Parms, ReturnValue), Z_Construct_UScriptStruct_FAmmoData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType = { "_ammoType", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetAmmoData_Parms, _ammoType), Z_Construct_UEnum_BioProject_EGunType, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::NewProp__ammoType_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerData" },
		{ "Comment", "// ???????\xc4\x82????e???\xcc\x83""f?[?^???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "???????\xc4\x82????e???\xcc\x83""f?[?^???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetAmmoData", nullptr, nullptr, sizeof(PlayerChara_eventGetAmmoData_Parms), Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetAmmoData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetAmmoData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics
	{
		struct PlayerChara_eventGetAnimStatus_Parms
		{
			EActionStatus ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetAnimStatus_Parms, ReturnValue), Z_Construct_UEnum_BioProject_EActionStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Return" },
		{ "Comment", "// ?A?j???[?V?????J?\xda\x97pReturn?\xd6\x90?\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?A?j???[?V?????J?\xda\x97pReturn?\xd6\x90?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetAnimStatus", nullptr, nullptr, sizeof(PlayerChara_eventGetAnimStatus_Parms), Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetAnimStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetAnimStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics
	{
		struct PlayerChara_eventGetCursorIndex_Parms
		{
			int32 _index;
			int32 _moveValue;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__moveValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp__moveValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__index_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp__index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetCursorIndex_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__moveValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__moveValue = { "_moveValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetCursorIndex_Parms, _moveValue), METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__moveValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__moveValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__index_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__index = { "_index", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetCursorIndex_Parms, _index), METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__index_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__index_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__moveValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::NewProp__index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetData" },
		{ "Comment", "// ?C???x???g???\xcc\x83J?[?\\???\xca\x92u???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?C???x???g???\xcc\x83J?[?\\???\xca\x92u???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetCursorIndex", nullptr, nullptr, sizeof(PlayerChara_eventGetCursorIndex_Parms), Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetCursorIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetCursorIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics
	{
		struct PlayerChara_eventGetInventoryState_Parms
		{
			EInventoryState ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetInventoryState_Parms, ReturnValue), Z_Construct_UEnum_BioProject_EInventoryState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetBool" },
		{ "Comment", "// ?C???x???g???\xcc\x8f??\xd4\x82??n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?C???x???g???\xcc\x8f??\xd4\x82??n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetInventoryState", nullptr, nullptr, sizeof(PlayerChara_eventGetInventoryState_Parms), Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetInventoryState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetInventoryState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetIsDead_Statics
	{
		struct PlayerChara_eventGetIsDead_Parms
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
	void Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PlayerChara_eventGetIsDead_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PlayerChara_eventGetIsDead_Parms), &Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "Comment", "// ???S?????????n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "???S?????????n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetIsDead", nullptr, nullptr, sizeof(PlayerChara_eventGetIsDead_Parms), Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetIsDead()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetIsDead_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics
	{
		struct PlayerChara_eventGetIsGunHold_Parms
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
	void Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PlayerChara_eventGetIsGunHold_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PlayerChara_eventGetIsGunHold_Parms), &Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "Comment", "// ?e???\\???\xc4\x82??\xe9\x82\xa9???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?e???\\???\xc4\x82??\xe9\x82\xa9???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetIsGunHold", nullptr, nullptr, sizeof(PlayerChara_eventGetIsGunHold_Parms), Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetIsGunHold()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetIsGunHold_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics
	{
		struct PlayerChara_eventGetIsItemTouch_Parms
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
	void Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PlayerChara_eventGetIsItemTouch_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PlayerChara_eventGetIsItemTouch_Parms), &Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetBool" },
		{ "Comment", "// ?A?C?e???\xc9\x90G???\xc4\x82??\xe9\x82\xa9???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?A?C?e???\xc9\x90G???\xc4\x82??\xe9\x82\xa9???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetIsItemTouch", nullptr, nullptr, sizeof(PlayerChara_eventGetIsItemTouch_Parms), Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetIsItemTouch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetIsItemTouch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics
	{
		struct PlayerChara_eventGetIsOpenInventory_Parms
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
	void Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PlayerChara_eventGetIsOpenInventory_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PlayerChara_eventGetIsOpenInventory_Parms), &Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "Comment", "// ?C???x???g?????J?????\xc4\x82??\xe9\x82\xa9???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?C???x???g?????J?????\xc4\x82??\xe9\x82\xa9???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetIsOpenInventory", nullptr, nullptr, sizeof(PlayerChara_eventGetIsOpenInventory_Parms), Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetIsOpenInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetIsOpenInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics
	{
		struct PlayerChara_eventGetLandingPoint_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetLandingPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gun" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetLandingPoint", nullptr, nullptr, sizeof(PlayerChara_eventGetLandingPoint_Parms), Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetLandingPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetLandingPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics
	{
		struct PlayerChara_eventGetOverlapActor_Parms
		{
			AActor* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetOverlapActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "Comment", "// ?G???\xc4\x82????A?N?^?[???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?G???\xc4\x82????A?N?^?[???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetOverlapActor", nullptr, nullptr, sizeof(PlayerChara_eventGetOverlapActor_Parms), Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetOverlapActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetOverlapActor_Statics::FuncParams);
		}
		return ReturnFunction;
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
		{ "Comment", "// ?v???C???[??HP???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?v???C???[??HP???n??" },
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
		{ "Comment", "// ?v???C???[?\xcc\x8d\xc5\x91?HP???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?v???C???[?\xcc\x8d\xc5\x91?HP???n??" },
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
	struct Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics
	{
		struct PlayerChara_eventGetPlayerStatus_Parms
		{
			FPlayerStatus ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventGetPlayerStatus_Parms, ReturnValue), Z_Construct_UScriptStruct_FPlayerStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerData" },
		{ "Comment", "// ?v???C???[?\xcc\x83X?e?[?^?X???n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?v???C???[?\xcc\x83X?e?[?^?X???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "GetPlayerStatus", nullptr, nullptr, sizeof(PlayerChara_eventGetPlayerStatus_Parms), Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_GetPlayerStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_GetPlayerStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_Heal_Statics
	{
		struct PlayerChara_eventHeal_Parms
		{
			int32 _index;
			int32 _value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__value_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp__value;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__index_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp__index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__value = { "_value", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventHeal_Parms, _value), METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__value_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__index_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__index = { "_index", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventHeal_Parms, _index), METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__index_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__index_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_Heal_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_Heal_Statics::NewProp__index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_Heal_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetData" },
		{ "Comment", "// ?\xf1\x95\x9c\x8f???\n" },
		{ "CPP_Default__value", "0" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?\xf1\x95\x9c\x8f???" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_Heal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "Heal", nullptr, nullptr, sizeof(PlayerChara_eventHeal_Parms), Z_Construct_UFunction_APlayerChara_Heal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_Heal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_Heal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_Heal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_Heal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_Heal_Statics::FuncParams);
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
	struct Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics
	{
		struct PlayerChara_eventOnOverlapEnd_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapEnd_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapEnd_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapEnd_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventOnOverlapEnd_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// ?I?[?o?[???b?v?\xda\x90G?????I?????\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?I?[?o?[???b?v?\xda\x90G?????I?????\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "OnOverlapEnd", nullptr, nullptr, sizeof(PlayerChara_eventOnOverlapEnd_Parms), Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_OnOverlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_OnOverlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics
	{
		struct PlayerChara_eventSetEquipGunData_Parms
		{
			FGunData _gunData;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__gunData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__gunData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::NewProp__gunData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::NewProp__gunData = { "_gunData", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventSetEquipGunData_Parms, _gunData), Z_Construct_UScriptStruct_FGunData, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::NewProp__gunData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::NewProp__gunData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::NewProp__gunData,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetData" },
		{ "Comment", "// ?y?f?o?b?O?p?z???????\xc4\x82??\xe9\x95\x90????????BP?\xc5\x95\xcf\x8dX????\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?y?f?o?b?O?p?z???????\xc4\x82??\xe9\x95\x90????????BP?\xc5\x95\xcf\x8dX????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "SetEquipGunData", nullptr, nullptr, sizeof(PlayerChara_eventSetEquipGunData_Parms), Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_SetEquipGunData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_SetEquipGunData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics
	{
		struct PlayerChara_eventSetInventoryState_Parms
		{
			EInventoryState _state;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__state_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp__state;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp__state_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state = { "_state", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerChara_eventSetInventoryState_Parms, _state), Z_Construct_UEnum_BioProject_EInventoryState, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::NewProp__state_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetData" },
		{ "Comment", "// ?C???x???g???\xcc\x8f??\xd4\x82??Z?b?g????\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?C???x???g???\xcc\x8f??\xd4\x82??Z?b?g????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "SetInventoryState", nullptr, nullptr, sizeof(PlayerChara_eventSetInventoryState_Parms), Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_SetInventoryState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_SetInventoryState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics
	{
		struct PlayerChara_eventSetIsGetItem_Parms
		{
			bool _isGet;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__isGet_MetaData[];
#endif
		static void NewProp__isGet_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp__isGet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet_SetBit(void* Obj)
	{
		((PlayerChara_eventSetIsGetItem_Parms*)Obj)->_isGet = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet = { "_isGet", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PlayerChara_eventSetIsGetItem_Parms), &Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet_SetBit, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::NewProp__isGet,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetData" },
		{ "Comment", "// ?A?C?e?????\xe6\x93\xbe?????????n??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?A?C?e?????\xe6\x93\xbe?????????n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerChara, nullptr, "SetIsGetItem", nullptr, nullptr, sizeof(PlayerChara_eventSetIsGetItem_Parms), Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerChara_SetIsGetItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerChara_SetIsGetItem_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ActionStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_m_ActionStatus;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_m_ActionStatus_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_statusConst_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_statusConst;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraShake_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_CameraShake;
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
		{ &Z_Construct_UFunction_APlayerChara_Damage, "Damage" }, // 2361091218
		{ &Z_Construct_UFunction_APlayerChara_GetAmmoData, "GetAmmoData" }, // 3642170984
		{ &Z_Construct_UFunction_APlayerChara_GetAnimStatus, "GetAnimStatus" }, // 112538986
		{ &Z_Construct_UFunction_APlayerChara_GetCursorIndex, "GetCursorIndex" }, // 2847117731
		{ &Z_Construct_UFunction_APlayerChara_GetInventoryState, "GetInventoryState" }, // 3529943451
		{ &Z_Construct_UFunction_APlayerChara_GetIsDead, "GetIsDead" }, // 2101020249
		{ &Z_Construct_UFunction_APlayerChara_GetIsGunHold, "GetIsGunHold" }, // 3869676710
		{ &Z_Construct_UFunction_APlayerChara_GetIsItemTouch, "GetIsItemTouch" }, // 1257226073
		{ &Z_Construct_UFunction_APlayerChara_GetIsOpenInventory, "GetIsOpenInventory" }, // 4142243934
		{ &Z_Construct_UFunction_APlayerChara_GetLandingPoint, "GetLandingPoint" }, // 3134137772
		{ &Z_Construct_UFunction_APlayerChara_GetOverlapActor, "GetOverlapActor" }, // 2770926758
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerBag, "GetPlayerBag" }, // 3185049530
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerHP, "GetPlayerHP" }, // 1833687356
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerMaxHP, "GetPlayerMaxHP" }, // 2053296764
		{ &Z_Construct_UFunction_APlayerChara_GetPlayerStatus, "GetPlayerStatus" }, // 1740782829
		{ &Z_Construct_UFunction_APlayerChara_Heal, "Heal" }, // 3510132999
		{ &Z_Construct_UFunction_APlayerChara_OnOverlapBegin, "OnOverlapBegin" }, // 2666479904
		{ &Z_Construct_UFunction_APlayerChara_OnOverlapEnd, "OnOverlapEnd" }, // 2233022717
		{ &Z_Construct_UFunction_APlayerChara_SetEquipGunData, "SetEquipGunData" }, // 1698143967
		{ &Z_Construct_UFunction_APlayerChara_SetInventoryState, "SetInventoryState" }, // 2236854109
		{ &Z_Construct_UFunction_APlayerChara_SetIsGetItem, "SetIsGetItem" }, // 630411286
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// ?A?N?V?????\xcc\x8f???\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?A?N?V?????\xcc\x8f???" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus = { "m_ActionStatus", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_ActionStatus), Z_Construct_UEnum_BioProject_EActionStatus, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_statusConst_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Status" },
		{ "Comment", "// ?X?e?[?^?X?\xcc\x8a\xee\x8f\x80?\xc6\x82\xc8\x82??f?[?^\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?X?e?[?^?X?\xcc\x8a\xee\x8f\x80?\xc6\x82\xc8\x82??f?[?^" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_m_statusConst = { "m_statusConst", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, m_statusConst), Z_Construct_UScriptStruct_FStatusConstant, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_statusConst_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_m_statusConst_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::NewProp_CameraShake_MetaData[] = {
		{ "Category", "PlayerChara" },
		{ "Comment", "//?@?J?????\xcc\x97h??\n" },
		{ "ModuleRelativePath", "PlayerChara.h" },
		{ "ToolTip", "?@?J?????\xcc\x97h??" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_APlayerChara_Statics::NewProp_CameraShake = { "CameraShake", nullptr, (EPropertyFlags)0x0044000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayerChara, CameraShake), Z_Construct_UClass_UPlayerCameraShake_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_APlayerChara_Statics::NewProp_CameraShake_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerChara_Statics::NewProp_CameraShake_MetaData)) };
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
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_ActionStatus_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_statusConst,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_playerStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraPitchLimit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_m_CameraYawLimit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerChara_Statics::NewProp_CameraShake,
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
	IMPLEMENT_CLASS(APlayerChara, 1742199119);
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
