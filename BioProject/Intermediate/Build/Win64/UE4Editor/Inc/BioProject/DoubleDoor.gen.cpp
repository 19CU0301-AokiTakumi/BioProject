// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioProject/DoubleDoor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDoubleDoor() {}
// Cross Module References
	BIOPROJECT_API UClass* Z_Construct_UClass_ADoubleDoor_NoRegister();
	BIOPROJECT_API UClass* Z_Construct_UClass_ADoubleDoor();
	BIOPROJECT_API UClass* Z_Construct_UClass_ADoorBase();
	UPackage* Z_Construct_UPackage__Script_BioProject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	void ADoubleDoor::StaticRegisterNativesADoubleDoor()
	{
	}
	UClass* Z_Construct_UClass_ADoubleDoor_NoRegister()
	{
		return ADoubleDoor::StaticClass();
	}
	struct Z_Construct_UClass_ADoubleDoor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pMesh_2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pMesh_2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pBoxComp_2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pBoxComp_2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pBoxComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pBoxComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADoubleDoor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ADoorBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BioProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoubleDoor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DoubleDoor.h" },
		{ "ModuleRelativePath", "DoubleDoor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_2_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gameplay" },
		{ "Comment", "// ???b?V???\xcc\x92\xc7\x89?\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "DoubleDoor.h" },
		{ "ToolTip", "???b?V???\xcc\x92\xc7\x89?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_2 = { "m_pMesh_2", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADoubleDoor, m_pMesh_2), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gameplay" },
		{ "Comment", "// ???b?V???\xcc\x92\xc7\x89?\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "DoubleDoor.h" },
		{ "ToolTip", "???b?V???\xcc\x92\xc7\x89?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh = { "m_pMesh", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADoubleDoor, m_pMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_2_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gameplay" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "DoubleDoor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_2 = { "m_pBoxComp_2", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADoubleDoor, m_pBoxComp_2), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gameplay" },
		{ "Comment", "// ?????\xe8\x94\xbb???\xcc\x92\xc7\x89?\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "DoubleDoor.h" },
		{ "ToolTip", "?????\xe8\x94\xbb???\xcc\x92\xc7\x89?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp = { "m_pBoxComp", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADoubleDoor, m_pBoxComp), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADoubleDoor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh_2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp_2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoubleDoor_Statics::NewProp_m_pBoxComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADoubleDoor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADoubleDoor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADoubleDoor_Statics::ClassParams = {
		&ADoubleDoor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADoubleDoor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADoubleDoor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADoubleDoor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADoubleDoor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADoubleDoor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADoubleDoor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADoubleDoor, 1648555144);
	template<> BIOPROJECT_API UClass* StaticClass<ADoubleDoor>()
	{
		return ADoubleDoor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADoubleDoor(Z_Construct_UClass_ADoubleDoor, &ADoubleDoor::StaticClass, TEXT("/Script/BioProject"), TEXT("ADoubleDoor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADoubleDoor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
