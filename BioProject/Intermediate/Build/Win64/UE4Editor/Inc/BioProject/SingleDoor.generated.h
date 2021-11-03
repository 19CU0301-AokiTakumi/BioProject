// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BIOPROJECT_SingleDoor_generated_h
#error "SingleDoor.generated.h already included, missing '#pragma once' in SingleDoor.h"
#endif
#define BIOPROJECT_SingleDoor_generated_h

#define BioProject_Source_BioProject_SingleDoor_h_12_SPARSE_DATA
#define BioProject_Source_BioProject_SingleDoor_h_12_RPC_WRAPPERS
#define BioProject_Source_BioProject_SingleDoor_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define BioProject_Source_BioProject_SingleDoor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASingleDoor(); \
	friend struct Z_Construct_UClass_ASingleDoor_Statics; \
public: \
	DECLARE_CLASS(ASingleDoor, ADoorBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ASingleDoor)


#define BioProject_Source_BioProject_SingleDoor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASingleDoor(); \
	friend struct Z_Construct_UClass_ASingleDoor_Statics; \
public: \
	DECLARE_CLASS(ASingleDoor, ADoorBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ASingleDoor)


#define BioProject_Source_BioProject_SingleDoor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASingleDoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASingleDoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASingleDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASingleDoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASingleDoor(ASingleDoor&&); \
	NO_API ASingleDoor(const ASingleDoor&); \
public:


#define BioProject_Source_BioProject_SingleDoor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASingleDoor(ASingleDoor&&); \
	NO_API ASingleDoor(const ASingleDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASingleDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASingleDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASingleDoor)


#define BioProject_Source_BioProject_SingleDoor_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pBoxComp() { return STRUCT_OFFSET(ASingleDoor, m_pBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_pMesh() { return STRUCT_OFFSET(ASingleDoor, m_pMesh); }


#define BioProject_Source_BioProject_SingleDoor_h_9_PROLOG
#define BioProject_Source_BioProject_SingleDoor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_SingleDoor_h_12_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_SingleDoor_h_12_SPARSE_DATA \
	BioProject_Source_BioProject_SingleDoor_h_12_RPC_WRAPPERS \
	BioProject_Source_BioProject_SingleDoor_h_12_INCLASS \
	BioProject_Source_BioProject_SingleDoor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_SingleDoor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_SingleDoor_h_12_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_SingleDoor_h_12_SPARSE_DATA \
	BioProject_Source_BioProject_SingleDoor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_SingleDoor_h_12_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_SingleDoor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class ASingleDoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_SingleDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
