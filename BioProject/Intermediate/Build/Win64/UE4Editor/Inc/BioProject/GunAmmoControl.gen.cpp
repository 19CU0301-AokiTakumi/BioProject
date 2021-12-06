// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/GunAmmoControl.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGunAmmoControl() {}
// Cross Module References
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_EAmmoType();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAmmoData();
	BIOPROJECT_API UClass* Z_Construct_UClass_AGunAmmoControl_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_AGunAmmoControl();
	BIOPROJECT_API UClass* Z_Construct_UClass_AItemBase();
	BIOPROJECT_API UFunction* Z_Construct_UFunction_AGunAmmoControl_GetAmmoData();
// End Cross Module References
	static UEnum* EAmmoType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioProject_EAmmoType, Z_Construct_UPackage__Script_BioProject(), TEXT("EAmmoType"));
		}
		return Singleton;
	}
	template<> BIOPROJECT_API UEnum* StaticEnum<EAmmoType>()
	{
		return EAmmoType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAmmoType(EAmmoType_StaticEnum, TEXT("/Script/BioProject"), TEXT("EAmmoType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioProject_EAmmoType_Hash() { return 3784966724U; }
	UEnum* Z_Construct_UEnum_BioProject_EAmmoType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAmmoType"), 0, Get_Z_Construct_UEnum_BioProject_EAmmoType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAmmoType::None", (int64)EAmmoType::None },
				{ "EAmmoType::Hand", (int64)EAmmoType::Hand },
				{ "EAmmoType::Shot", (int64)EAmmoType::Shot },
				{ "EAmmoType::Max", (int64)EAmmoType::Max },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "// ?e?\xcc\x8e???\n" },
				{ "Hand.Comment", "// ??\n" },
				{ "Hand.Name", "EAmmoType::Hand" },
				{ "Max.Comment", "// ?V???b?g?K??\n" },
				{ "Max.Name", "EAmmoType::Max" },
				{ "Max.ToolTip", "?V???b?g?K??" },
				{ "ModuleRelativePath", "GunAmmoControl.h" },
				{ "None.Name", "EAmmoType::None" },
				{ "Shot.Comment", "// ??\n// ?n???h?K??\n" },
				{ "Shot.Name", "EAmmoType::Shot" },
				{ "Shot.ToolTip", "??\n?n???h?K??" },
				{ "ToolTip", "?e?\xcc\x8e???" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioProject,
				nullptr,
				"EAmmoType",
				"EAmmoType",
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
class UScriptStruct* FAmmoData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BIOPROJECT_API uint32 Get_Z_Construct_UScriptStruct_FAmmoData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAmmoData, Z_Construct_UPackage__Script_BioProject(), TEXT("AmmoData"), sizeof(FAmmoData), Get_Z_Construct_UScriptStruct_FAmmoData_Hash());
	}
	return Singleton;
}
template<> BIOPROJECT_API UScriptStruct* StaticStruct<FAmmoData>()
{
	return FAmmoData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAmmoData(FAmmoData::StaticStruct, TEXT("/Script/BioProject"), TEXT("AmmoData"), false, nullptr, nullptr);
static struct FScriptStruct_BioProject_StaticRegisterNativesFAmmoData
{
	FScriptStruct_BioProject_StaticRegisterNativesFAmmoData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AmmoData")),new UScriptStruct::TCppStructOps<FAmmoData>);
	}
} ScriptStruct_BioProject_StaticRegisterNativesFAmmoData;
	struct Z_Construct_UScriptStruct_FAmmoData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_atk_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_atk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ammoStockMax_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ammoStockMax;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ammoStock_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ammoStock;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ammoType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ammoType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ammoType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAmmoData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// ?e?\xcc\x83""f?[?^\n" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
		{ "ToolTip", "?e?\xcc\x83""f?[?^" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAmmoData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAmmoData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_atk_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_atk = { "atk", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAmmoData, atk), METADATA_PARAMS(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_atk_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_atk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStockMax_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStockMax = { "ammoStockMax", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAmmoData, ammoStockMax), METADATA_PARAMS(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStockMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStockMax_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStock_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStock = { "ammoStock", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAmmoData, ammoStock), METADATA_PARAMS(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStock_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStock_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType = { "ammoType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAmmoData, ammoType), Z_Construct_UEnum_BioProject_EAmmoType, METADATA_PARAMS(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAmmoData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_atk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStockMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoStock,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAmmoData_Statics::NewProp_ammoType_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAmmoData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"AmmoData",
		sizeof(FAmmoData),
		alignof(FAmmoData),
		Z_Construct_UScriptStruct_FAmmoData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAmmoData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAmmoData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAmmoData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAmmoData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAmmoData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AmmoData"), sizeof(FAmmoData), Get_Z_Construct_UScriptStruct_FAmmoData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAmmoData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAmmoData_Hash() { return 3803740213U; }
	void AGunAmmoControl::StaticRegisterNativesAGunAmmoControl()
	{
		UClass* Class = AGunAmmoControl::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAmmoData", &AGunAmmoControl::execGetAmmoData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics
	{
		struct GunAmmoControl_eventGetAmmoData_Parms
		{
			FAmmoData ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GunAmmoControl_eventGetAmmoData_Parms, ReturnValue), Z_Construct_UScriptStruct_FAmmoData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::Function_MetaDataParams[] = {
		{ "Category", "GetData" },
		{ "Comment", "// ?e?\xcc\x83""f?[?^???n??\n" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
		{ "ToolTip", "?e?\xcc\x83""f?[?^???n??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGunAmmoControl, nullptr, "GetAmmoData", nullptr, nullptr, sizeof(GunAmmoControl_eventGetAmmoData_Parms), Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGunAmmoControl_GetAmmoData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGunAmmoControl_GetAmmoData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGunAmmoControl_NoRegister()
	{
		return AGunAmmoControl::StaticClass();
	}
	struct Z_Construct_UClass_AGunAmmoControl_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ammoData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_ammoData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGunAmmoControl_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItemBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGunAmmoControl_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGunAmmoControl_GetAmmoData, "GetAmmoData" }, // 1142534332
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGunAmmoControl_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GunAmmoControl.h" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGunAmmoControl_Statics::NewProp_m_ammoData_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?e?\xcc\x83""f?[?^\n" },
		{ "ModuleRelativePath", "GunAmmoControl.h" },
		{ "ToolTip", "?e?\xcc\x83""f?[?^" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGunAmmoControl_Statics::NewProp_m_ammoData = { "m_ammoData", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGunAmmoControl, m_ammoData), Z_Construct_UScriptStruct_FAmmoData, METADATA_PARAMS(Z_Construct_UClass_AGunAmmoControl_Statics::NewProp_m_ammoData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGunAmmoControl_Statics::NewProp_m_ammoData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGunAmmoControl_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGunAmmoControl_Statics::NewProp_m_ammoData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGunAmmoControl_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGunAmmoControl>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGunAmmoControl_Statics::ClassParams = {
		&AGunAmmoControl::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AGunAmmoControl_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AGunAmmoControl_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGunAmmoControl_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGunAmmoControl_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGunAmmoControl()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGunAmmoControl_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGunAmmoControl, 3176438752);
	template<> BIOPROJECT_API UClass* StaticClass<AGunAmmoControl>()
	{
		return AGunAmmoControl::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGunAmmoControl(Z_Construct_UClass_AGunAmmoControl, &AGunAmmoControl::StaticClass, TEXT("/Script/BioProject"), TEXT("AGunAmmoControl"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGunAmmoControl);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
