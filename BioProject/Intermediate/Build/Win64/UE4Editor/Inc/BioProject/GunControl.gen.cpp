// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/GunControl.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGunControl() {}
// Cross Module References
	BIOPROJECT_API UEnum* Z_Construct_UEnum_BioProject_EGunType();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	BIOPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGunData();
	BIOPROJECT_API UClass* Z_Construct_UClass_AGunControl_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_AGunControl();
	BIOPROJECT_API UClass* Z_Construct_UClass_AItemBase();
// End Cross Module References
	static UEnum* EGunType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioProject_EGunType, Z_Construct_UPackage__Script_BioProject(), TEXT("EGunType"));
		}
		return Singleton;
	}
	template<> BIOPROJECT_API UEnum* StaticEnum<EGunType>()
	{
		return EGunType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EGunType(EGunType_StaticEnum, TEXT("/Script/BioProject"), TEXT("EGunType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioProject_EGunType_Hash() { return 1714645086U; }
	UEnum* Z_Construct_UEnum_BioProject_EGunType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EGunType"), 0, Get_Z_Construct_UEnum_BioProject_EGunType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EGunType::None", (int64)EGunType::None },
				{ "EGunType::Hand", (int64)EGunType::Hand },
				{ "EGunType::Shot", (int64)EGunType::Shot },
				{ "EGunType::Max", (int64)EGunType::Max },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "// ?e?\xcc\x8e???\n" },
				{ "Hand.Comment", "// ??\n" },
				{ "Hand.Name", "EGunType::Hand" },
				{ "Max.Comment", "// ?V???b?g?K??\n" },
				{ "Max.Name", "EGunType::Max" },
				{ "Max.ToolTip", "?V???b?g?K??" },
				{ "ModuleRelativePath", "GunControl.h" },
				{ "None.Name", "EGunType::None" },
				{ "Shot.Comment", "// ??\n// ?n???h?K??\n" },
				{ "Shot.Name", "EGunType::Shot" },
				{ "Shot.ToolTip", "??\n?n???h?K??" },
				{ "ToolTip", "?e?\xcc\x8e???" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioProject,
				nullptr,
				"EGunType",
				"EGunType",
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
class UScriptStruct* FGunData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern BIOPROJECT_API uint32 Get_Z_Construct_UScriptStruct_FGunData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGunData, Z_Construct_UPackage__Script_BioProject(), TEXT("GunData"), sizeof(FGunData), Get_Z_Construct_UScriptStruct_FGunData_Hash());
	}
	return Singleton;
}
template<> BIOPROJECT_API UScriptStruct* StaticStruct<FGunData>()
{
	return FGunData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGunData(FGunData::StaticStruct, TEXT("/Script/BioProject"), TEXT("GunData"), false, nullptr, nullptr);
static struct FScriptStruct_BioProject_StaticRegisterNativesFGunData
{
	FScriptStruct_BioProject_StaticRegisterNativesFGunData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GunData")),new UScriptStruct::TCppStructOps<FGunData>);
	}
} ScriptStruct_BioProject_StaticRegisterNativesFGunData;
	struct Z_Construct_UScriptStruct_FGunData_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_gunType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_gunType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_gunType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// ?e?\xcc\x83""f?[?^\n" },
		{ "ModuleRelativePath", "GunControl.h" },
		{ "ToolTip", "?e?\xcc\x83""f?[?^" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGunData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGunData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunData_Statics::NewProp_atk_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunControl.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FGunData_Statics::NewProp_atk = { "atk", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGunData, atk), METADATA_PARAMS(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_atk_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_atk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStockMax_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunControl.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStockMax = { "ammoStockMax", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGunData, ammoStockMax), METADATA_PARAMS(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStockMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStockMax_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStock_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunControl.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStock = { "ammoStock", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGunData, ammoStock), METADATA_PARAMS(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStock_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStock_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "GunControl.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType = { "gunType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGunData, gunType), Z_Construct_UEnum_BioProject_EGunType, METADATA_PARAMS(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGunData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunData_Statics::NewProp_atk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStockMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunData_Statics::NewProp_ammoStock,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunData_Statics::NewProp_gunType_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGunData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
		nullptr,
		&NewStructOps,
		"GunData",
		sizeof(FGunData),
		alignof(FGunData),
		Z_Construct_UScriptStruct_FGunData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGunData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGunData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGunData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_BioProject();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GunData"), sizeof(FGunData), Get_Z_Construct_UScriptStruct_FGunData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGunData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGunData_Hash() { return 2758834809U; }
	void AGunControl::StaticRegisterNativesAGunControl()
	{
	}
	UClass* Z_Construct_UClass_AGunControl_NoRegister()
	{
		return AGunControl::StaticClass();
	}
	struct Z_Construct_UClass_AGunControl_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_gunData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_gunData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGunControl_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItemBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGunControl_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GunControl.h" },
		{ "ModuleRelativePath", "GunControl.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGunControl_Statics::NewProp_m_gunData_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "// ?e?\xcc\x83""f?[?^\n" },
		{ "ModuleRelativePath", "GunControl.h" },
		{ "ToolTip", "?e?\xcc\x83""f?[?^" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGunControl_Statics::NewProp_m_gunData = { "m_gunData", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGunControl, m_gunData), Z_Construct_UScriptStruct_FGunData, METADATA_PARAMS(Z_Construct_UClass_AGunControl_Statics::NewProp_m_gunData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGunControl_Statics::NewProp_m_gunData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGunControl_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGunControl_Statics::NewProp_m_gunData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGunControl_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGunControl>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGunControl_Statics::ClassParams = {
		&AGunControl::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGunControl_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGunControl_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGunControl_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGunControl_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGunControl()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGunControl_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGunControl, 3816845165);
	template<> BIOPROJECT_API UClass* StaticClass<AGunControl>()
	{
		return AGunControl::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGunControl(Z_Construct_UClass_AGunControl, &AGunControl::StaticClass, TEXT("/Script/BioProject"), TEXT("AGunControl"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGunControl);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
