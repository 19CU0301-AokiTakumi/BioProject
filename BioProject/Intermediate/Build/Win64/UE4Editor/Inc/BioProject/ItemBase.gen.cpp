// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/ItemBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemBase() {}
// Cross Module References
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_ItemType();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FItemData();
	BIOPROJECT_API UClass* Z_Construct_UClass_AItemBase_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_AItemBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AItemBase_GetCenterPos();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AItemBase_GetItemData();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AItemBase_OnOverlapBegin();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AItemBase_OnOverlapEnd();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	static UEnum* ItemType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioProject_ItemType, Z_Construct_UPackage__Script_BioProject(), TEXT("ItemType"));
		}
		return Singleton;
	}
	template<> BIOPROJECT_API UEnum* StaticEnum<ItemType>()
	{
		return ItemType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ItemType(ItemType_StaticEnum, TEXT("/Script/BioProject"), TEXT("ItemType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioProject_ItemType_Hash() { return 2141165318U; }
	UEnum* Z_Construct_UEnum_BioProject_ItemType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ItemType"), 0, Get_Z_Construct_UEnum_BioProject_ItemType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ItemType::None", (int64)ItemType::None },
				{ "ItemType::Key", (int64)ItemType::Key },
				{ "ItemType::Heal", (int64)ItemType::Heal },
				{ "ItemType::Weapon", (int64)ItemType::Weapon },
				{ "ItemType::Bullet", (int64)ItemType::Bullet },
				{ "ItemType::Event", (int64)ItemType::Event },
				{ "ItemType::Debug", (int64)ItemType::Debug },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Bullet.Name", "ItemType::Bullet" },
				{ "Debug.Name", "ItemType::Debug" },
				{ "Event.Name", "ItemType::Event" },
				{ "Heal.Name", "ItemType::Heal" },
				{ "Key.Name", "ItemType::Key" },
				{ "ModuleRelativePath", "ItemBase.h" },
				{ "None.Name", "ItemType::None" },
				{ "Weapon.Name", "ItemType::Weapon" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioProject,
				nullptr,
				"ItemType",
				"ItemType",
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
class UScriptStruct* FItemData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BIOPROJECT_API uint32 Get_Z_Construct_UScriptStruct_FItemData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemData, Z_Construct_UPackage__Script_BioProject(), TEXT("ItemData"), sizeof(FItemData), Get_Z_Construct_UScriptStruct_FItemData_Hash());
	}
	return Singleton;
}
template<> BIOPROJECT_API UScriptStruct* StaticStruct<FItemData>()
{
	return FItemData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FItemData(FItemData::StaticStruct, TEXT("/Script/BioProject"), TEXT("ItemData"), false, nullptr, nullptr);
static struct FScriptStruct_BioProject_StaticRegisterNativesFItemData
{
	FScriptStruct_BioProject_StaticRegisterNativesFItemData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ItemData")),new UScriptStruct::TCppStructOps<FItemData>);
	}
} ScriptStruct_BioProject_StaticRegisterNativesFItemData;
	struct Z_Construct_UScriptStruct_FItemData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isShowInventory_MetaData[];
#endif
		static void NewProp_isShowInventory_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isShowInventory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_comment_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_comment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_type;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_type_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_id;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FItemData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory_SetBit(void* Obj)
	{
		((FItemData*)Obj)->isShowInventory = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory = { "isShowInventory", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FItemData), &Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_comment_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_comment = { "comment", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, comment), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_comment_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_comment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, type), Z_Construct_UEnum_BioProject_ItemType, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_name_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, name), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_id_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, id), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_id_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_id_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_isShowInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_comment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_type_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_id,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"ItemData",
		sizeof(FItemData),
		alignof(FItemData),
		Z_Construct_UScriptStruct_FItemData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FItemData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FItemData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ItemData"), sizeof(FItemData), Get_Z_Construct_UScriptStruct_FItemData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FItemData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FItemData_Hash() { return 1198657170U; }
	void AItemBase::StaticRegisterNativesAItemBase()
	{
		UClass* Class = AItemBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCenterPos", &AItemBase::execGetCenterPos },
			{ "GetItemData", &AItemBase::execGetItemData },
			{ "OnOverlapBegin", &AItemBase::execOnOverlapBegin },
			{ "OnOverlapEnd", &AItemBase::execOnOverlapEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AItemBase_GetCenterPos_Statics
	{
		struct ItemBase_eventGetCenterPos_Parms
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
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventGetCenterPos_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemBase, nullptr, "GetCenterPos", nullptr, nullptr, sizeof(ItemBase_eventGetCenterPos_Parms), Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemBase_GetCenterPos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AItemBase_GetCenterPos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItemBase_GetItemData_Statics
	{
		struct ItemBase_eventGetItemData_Parms
		{
			FItemData ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AItemBase_GetItemData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventGetItemData_Parms, ReturnValue), Z_Construct_UScriptStruct_FItemData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemBase_GetItemData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_GetItemData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_GetItemData_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "Comment", "// ???g?\xcc\x83""A?C?e???f?[?^???n??\n" },
		{ "ModuleRelativePath", "ItemBase.h" },
		{ "ToolTip", "???g?\xcc\x83""A?C?e???f?[?^???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemBase_GetItemData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemBase, nullptr, "GetItemData", nullptr, nullptr, sizeof(ItemBase_eventGetItemData_Parms), Z_Construct_UFunction_AItemBase_GetItemData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_GetItemData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_GetItemData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_GetItemData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemBase_GetItemData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AItemBase_GetItemData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics
	{
		struct ItemBase_eventOnOverlapBegin_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((ItemBase_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ItemBase_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapBegin_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// ?I?[?o?[???b?v?\xda\x90G?????n?\xdf\x82??\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?\n" },
		{ "ModuleRelativePath", "ItemBase.h" },
		{ "ToolTip", "?I?[?o?[???b?v?\xda\x90G?????n?\xdf\x82??\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemBase, nullptr, "OnOverlapBegin", nullptr, nullptr, sizeof(ItemBase_eventOnOverlapBegin_Parms), Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemBase_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AItemBase_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics
	{
		struct ItemBase_eventOnOverlapEnd_Parms
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapEnd_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapEnd_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapEnd_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemBase_eventOnOverlapEnd_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// ?I?[?o?[???b?v?\xda\x90G?????I?????\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?\n" },
		{ "ModuleRelativePath", "ItemBase.h" },
		{ "ToolTip", "?I?[?o?[???b?v?\xda\x90G?????I?????\xc6\x82??\xc9\x8c\xc4\x82\xce\x82????C?x???g?\xd6\x90?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemBase, nullptr, "OnOverlapEnd", nullptr, nullptr, sizeof(ItemBase_eventOnOverlapEnd_Parms), Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemBase_OnOverlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AItemBase_OnOverlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AItemBase_NoRegister()
	{
		return AItemBase::StaticClass();
	}
	struct Z_Construct_UClass_AItemBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_itemData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_itemData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pBoxComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pBoxComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pBase_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pBase;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AItemBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AItemBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AItemBase_GetCenterPos, "GetCenterPos" }, // 3163684655
		{ &Z_Construct_UFunction_AItemBase_GetItemData, "GetItemData" }, // 2335666107
		{ &Z_Construct_UFunction_AItemBase_OnOverlapBegin, "OnOverlapBegin" }, // 1771439896
		{ &Z_Construct_UFunction_AItemBase_OnOverlapEnd, "OnOverlapEnd" }, // 2977564471
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ItemBase.h" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemBase_Statics::NewProp_m_itemData_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ???g?\xcc\x83""A?C?e???f?[?^\n" },
		{ "ModuleRelativePath", "ItemBase.h" },
		{ "ToolTip", "???g?\xcc\x83""A?C?e???f?[?^" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AItemBase_Statics::NewProp_m_itemData = { "m_itemData", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItemBase, m_itemData), Z_Construct_UScriptStruct_FItemData, METADATA_PARAMS(Z_Construct_UClass_AItemBase_Statics::NewProp_m_itemData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItemBase_Statics::NewProp_m_itemData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemBase_Statics::NewProp_m_pMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Component" },
		{ "Comment", "// ???b?V???\xcc\x92\xc7\x89?\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ItemBase.h" },
		{ "ToolTip", "???b?V???\xcc\x92\xc7\x89?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItemBase_Statics::NewProp_m_pMesh = { "m_pMesh", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItemBase, m_pMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItemBase_Statics::NewProp_m_pMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItemBase_Statics::NewProp_m_pMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBoxComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Component" },
		{ "Comment", "// ?????\xe8\x94\xbb???\xcc\x92\xc7\x89?\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ItemBase.h" },
		{ "ToolTip", "?????\xe8\x94\xbb???\xcc\x92\xc7\x89?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBoxComp = { "m_pBoxComp", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItemBase, m_pBoxComp), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBoxComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBoxComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBase_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ItemBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBase = { "m_pBase", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItemBase, m_pBase), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBase_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBase_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AItemBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBase_Statics::NewProp_m_itemData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBase_Statics::NewProp_m_pMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBoxComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBase_Statics::NewProp_m_pBase,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AItemBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AItemBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AItemBase_Statics::ClassParams = {
		&AItemBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AItemBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AItemBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AItemBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AItemBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AItemBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AItemBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AItemBase, 2564748210);
	template<> BIOPROJECT_API UClass* StaticClass<AItemBase>()
	{
		return AItemBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AItemBase(Z_Construct_UClass_AItemBase, &AItemBase::StaticClass, TEXT("/Script/BioProject"), TEXT("AItemBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AItemBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
