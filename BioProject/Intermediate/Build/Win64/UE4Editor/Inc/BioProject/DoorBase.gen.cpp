// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/DoorBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDoorBase() {}
// Cross Module References
	BIOPROJECT_API UClass* Z_Construct_UClass_ADoorBase_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_ADoorBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BioProject();
// End Cross Module References
	void ADoorBase::StaticRegisterNativesADoorBase()
	{
	}
	UClass* Z_Construct_UClass_ADoorBase_NoRegister()
	{
		return ADoorBase::StaticClass();
	}
	struct Z_Construct_UClass_ADoorBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADoorBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoorBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DoorBase.h" },
		{ "ModuleRelativePath", "DoorBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADoorBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADoorBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADoorBase_Statics::ClassParams = {
		&ADoorBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADoorBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADoorBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADoorBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADoorBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADoorBase, 2400761477);
	template<> BIOPROJECT_API UClass* StaticClass<ADoorBase>()
	{
		return ADoorBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADoorBase(Z_Construct_UClass_ADoorBase, &ADoorBase::StaticClass, TEXT("/Script/BioProject"), TEXT("ADoorBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADoorBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
