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
	BIOPROJECT_API UClass* Z_Construct_UClass_APlayerChara_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_APlayerChara();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_BioProject();
// End Cross Module References
	void APlayerChara::StaticRegisterNativesAPlayerChara()
	{
	}
	UClass* Z_Construct_UClass_APlayerChara_NoRegister()
	{
		return APlayerChara::StaticClass();
	}
	struct Z_Construct_UClass_APlayerChara_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerChara_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerChara_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PlayerChara.h" },
		{ "ModuleRelativePath", "PlayerChara.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerChara_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerChara>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayerChara_Statics::ClassParams = {
		&APlayerChara::StaticClass,
		"Game",
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
	IMPLEMENT_CLASS(APlayerChara, 2657718202);
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
