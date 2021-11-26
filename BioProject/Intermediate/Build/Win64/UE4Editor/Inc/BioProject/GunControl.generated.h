// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BIOPROJECT_GunControl_generated_h
#error "GunControl.generated.h already included, missing '#pragma once' in GunControl.h"
#endif
#define BIOPROJECT_GunControl_generated_h

#define BioProject_Source_BioProject_GunControl_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGunData_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FGunData>();

#define BioProject_Source_BioProject_GunControl_h_44_SPARSE_DATA
#define BioProject_Source_BioProject_GunControl_h_44_RPC_WRAPPERS
#define BioProject_Source_BioProject_GunControl_h_44_RPC_WRAPPERS_NO_PURE_DECLS
#define BioProject_Source_BioProject_GunControl_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGunControl(); \
	friend struct Z_Construct_UClass_AGunControl_Statics; \
public: \
	DECLARE_CLASS(AGunControl, AItemBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AGunControl)


#define BioProject_Source_BioProject_GunControl_h_44_INCLASS \
private: \
	static void StaticRegisterNativesAGunControl(); \
	friend struct Z_Construct_UClass_AGunControl_Statics; \
public: \
	DECLARE_CLASS(AGunControl, AItemBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AGunControl)


#define BioProject_Source_BioProject_GunControl_h_44_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGunControl(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGunControl) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGunControl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGunControl); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGunControl(AGunControl&&); \
	NO_API AGunControl(const AGunControl&); \
public:


#define BioProject_Source_BioProject_GunControl_h_44_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGunControl(AGunControl&&); \
	NO_API AGunControl(const AGunControl&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGunControl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGunControl); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGunControl)


#define BioProject_Source_BioProject_GunControl_h_44_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_gunData() { return STRUCT_OFFSET(AGunControl, m_gunData); }


#define BioProject_Source_BioProject_GunControl_h_41_PROLOG
#define BioProject_Source_BioProject_GunControl_h_44_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_GunControl_h_44_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_GunControl_h_44_SPARSE_DATA \
	BioProject_Source_BioProject_GunControl_h_44_RPC_WRAPPERS \
	BioProject_Source_BioProject_GunControl_h_44_INCLASS \
	BioProject_Source_BioProject_GunControl_h_44_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_GunControl_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_GunControl_h_44_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_GunControl_h_44_SPARSE_DATA \
	BioProject_Source_BioProject_GunControl_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_GunControl_h_44_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_GunControl_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class AGunControl>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_GunControl_h


#define FOREACH_ENUM_EGUNTYPE(op) \
	op(EGunType::None) \
	op(EGunType::Hand) \
	op(EGunType::Shot) \
	op(EGunType::Max) 

enum class EGunType : uint8;
template<> BIOPROJECT_API UEnum* StaticEnum<EGunType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
