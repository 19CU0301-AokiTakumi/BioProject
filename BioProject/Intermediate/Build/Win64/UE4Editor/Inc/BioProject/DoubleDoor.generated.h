// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BIOPROJECT_DoubleDoor_generated_h
#error "DoubleDoor.generated.h already included, missing '#pragma once' in DoubleDoor.h"
#endif
#define BIOPROJECT_DoubleDoor_generated_h

#define BioProject_Source_BioProject_DoubleDoor_h_11_SPARSE_DATA
#define BioProject_Source_BioProject_DoubleDoor_h_11_RPC_WRAPPERS
#define BioProject_Source_BioProject_DoubleDoor_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define BioProject_Source_BioProject_DoubleDoor_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADoubleDoor(); \
	friend struct Z_Construct_UClass_ADoubleDoor_Statics; \
public: \
	DECLARE_CLASS(ADoubleDoor, ADoorBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ADoubleDoor)


#define BioProject_Source_BioProject_DoubleDoor_h_11_INCLASS \
private: \
	static void StaticRegisterNativesADoubleDoor(); \
	friend struct Z_Construct_UClass_ADoubleDoor_Statics; \
public: \
	DECLARE_CLASS(ADoubleDoor, ADoorBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ADoubleDoor)


#define BioProject_Source_BioProject_DoubleDoor_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADoubleDoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADoubleDoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoubleDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoubleDoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoubleDoor(ADoubleDoor&&); \
	NO_API ADoubleDoor(const ADoubleDoor&); \
public:


#define BioProject_Source_BioProject_DoubleDoor_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoubleDoor(ADoubleDoor&&); \
	NO_API ADoubleDoor(const ADoubleDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoubleDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoubleDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADoubleDoor)


#define BioProject_Source_BioProject_DoubleDoor_h_11_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pBoxComp() { return STRUCT_OFFSET(ADoubleDoor, m_pBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_pBoxComp_2() { return STRUCT_OFFSET(ADoubleDoor, m_pBoxComp_2); } \
	FORCEINLINE static uint32 __PPO__m_pMesh() { return STRUCT_OFFSET(ADoubleDoor, m_pMesh); } \
	FORCEINLINE static uint32 __PPO__m_pMesh_2() { return STRUCT_OFFSET(ADoubleDoor, m_pMesh_2); }


#define BioProject_Source_BioProject_DoubleDoor_h_8_PROLOG
#define BioProject_Source_BioProject_DoubleDoor_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_DoubleDoor_h_11_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_DoubleDoor_h_11_SPARSE_DATA \
	BioProject_Source_BioProject_DoubleDoor_h_11_RPC_WRAPPERS \
	BioProject_Source_BioProject_DoubleDoor_h_11_INCLASS \
	BioProject_Source_BioProject_DoubleDoor_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_DoubleDoor_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_DoubleDoor_h_11_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_DoubleDoor_h_11_SPARSE_DATA \
	BioProject_Source_BioProject_DoubleDoor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_DoubleDoor_h_11_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_DoubleDoor_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class ADoubleDoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_DoubleDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
