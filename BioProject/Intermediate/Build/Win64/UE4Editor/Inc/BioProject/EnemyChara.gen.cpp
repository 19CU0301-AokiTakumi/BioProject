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
	BIOPROJECT_API UClass* Z_Construct_UClass_AEnemyChara_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_AEnemyChara();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_BioProject();
// End Cross Module References
	void AEnemyChara::StaticRegisterNativesAEnemyChara()
	{
	}
	UClass* Z_Construct_UClass_AEnemyChara_NoRegister()
	{
		return AEnemyChara::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyChara_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyChara_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyChara_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemyChara.h" },
		{ "ModuleRelativePath", "EnemyChara.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyChara_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyChara>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyChara_Statics::ClassParams = {
		&AEnemyChara::StaticClass,
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
	IMPLEMENT_CLASS(AEnemyChara, 2059457306);
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
