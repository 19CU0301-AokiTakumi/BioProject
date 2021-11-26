// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAmmoData;
#ifdef BIOPROJECT_GunAmmoControl_generated_h
#error "GunAmmoControl.generated.h already included, missing '#pragma once' in GunAmmoControl.h"
#endif
#define BIOPROJECT_GunAmmoControl_generated_h

#define BioProject_Source_BioProject_GunAmmoControl_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAmmoData_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FAmmoData>();

#define BioProject_Source_BioProject_GunAmmoControl_h_44_SPARSE_DATA
#define BioProject_Source_BioProject_GunAmmoControl_h_44_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAmmoData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FAmmoData*)Z_Param__Result=P_THIS->GetAmmoData(); \
		P_NATIVE_END; \
	}


#define BioProject_Source_BioProject_GunAmmoControl_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAmmoData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FAmmoData*)Z_Param__Result=P_THIS->GetAmmoData(); \
		P_NATIVE_END; \
	}


#define BioProject_Source_BioProject_GunAmmoControl_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGunAmmoControl(); \
	friend struct Z_Construct_UClass_AGunAmmoControl_Statics; \
public: \
	DECLARE_CLASS(AGunAmmoControl, AItemBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AGunAmmoControl)


#define BioProject_Source_BioProject_GunAmmoControl_h_44_INCLASS \
private: \
	static void StaticRegisterNativesAGunAmmoControl(); \
	friend struct Z_Construct_UClass_AGunAmmoControl_Statics; \
public: \
	DECLARE_CLASS(AGunAmmoControl, AItemBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AGunAmmoControl)


#define BioProject_Source_BioProject_GunAmmoControl_h_44_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGunAmmoControl(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGunAmmoControl) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGunAmmoControl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGunAmmoControl); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGunAmmoControl(AGunAmmoControl&&); \
	NO_API AGunAmmoControl(const AGunAmmoControl&); \
public:


#define BioProject_Source_BioProject_GunAmmoControl_h_44_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGunAmmoControl(AGunAmmoControl&&); \
	NO_API AGunAmmoControl(const AGunAmmoControl&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGunAmmoControl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGunAmmoControl); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGunAmmoControl)


#define BioProject_Source_BioProject_GunAmmoControl_h_44_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_ammoData() { return STRUCT_OFFSET(AGunAmmoControl, m_ammoData); }


#define BioProject_Source_BioProject_GunAmmoControl_h_41_PROLOG
#define BioProject_Source_BioProject_GunAmmoControl_h_44_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_GunAmmoControl_h_44_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_GunAmmoControl_h_44_SPARSE_DATA \
	BioProject_Source_BioProject_GunAmmoControl_h_44_RPC_WRAPPERS \
	BioProject_Source_BioProject_GunAmmoControl_h_44_INCLASS \
	BioProject_Source_BioProject_GunAmmoControl_h_44_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_GunAmmoControl_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_GunAmmoControl_h_44_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_GunAmmoControl_h_44_SPARSE_DATA \
	BioProject_Source_BioProject_GunAmmoControl_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_GunAmmoControl_h_44_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_GunAmmoControl_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class AGunAmmoControl>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_GunAmmoControl_h


#define FOREACH_ENUM_EAMMOTYPE(op) \
	op(EAmmoType::None) \
	op(EAmmoType::Hand) \
	op(EAmmoType::Shot) \
	op(EAmmoType::Max) 

enum class EAmmoType : uint8;
template<> BIOPROJECT_API UEnum* StaticEnum<EAmmoType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
