// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/PlayerCameraShake.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerCameraShake() {}
// Cross Module References
	BIOPROJECT_API UClass* Z_Construct_UClass_UPlayerCameraShake_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_UPlayerCameraShake();
	ENGINE_API UClass* Z_Construct_UClass_UCameraShake();
	UPackage* Z_Construct_UPackage__Script_BioProject();
// End Cross Module References
	void UPlayerCameraShake::StaticRegisterNativesUPlayerCameraShake()
	{
	}
	UClass* Z_Construct_UClass_UPlayerCameraShake_NoRegister()
	{
		return UPlayerCameraShake::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerCameraShake_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerCameraShake_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCameraShake,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCameraShake_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PlayerCameraShake.h" },
		{ "ModuleRelativePath", "PlayerCameraShake.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerCameraShake_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerCameraShake>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPlayerCameraShake_Statics::ClassParams = {
		&UPlayerCameraShake::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPlayerCameraShake_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCameraShake_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPlayerCameraShake()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPlayerCameraShake_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPlayerCameraShake, 815867030);
	template<> BIOPROJECT_API UClass* StaticClass<UPlayerCameraShake>()
	{
		return UPlayerCameraShake::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPlayerCameraShake(Z_Construct_UClass_UPlayerCameraShake, &UPlayerCameraShake::StaticClass, TEXT("/Script/BioProject"), TEXT("UPlayerCameraShake"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerCameraShake);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
