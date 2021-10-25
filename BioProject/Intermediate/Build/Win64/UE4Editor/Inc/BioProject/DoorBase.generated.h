// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BIOPROJECT_DoorBase_generated_h
#error "DoorBase.generated.h already included, missing '#pragma once' in DoorBase.h"
#endif
#define BIOPROJECT_DoorBase_generated_h

#define BioProject_Source_BioProject_DoorBase_h_12_SPARSE_DATA
#define BioProject_Source_BioProject_DoorBase_h_12_RPC_WRAPPERS
#define BioProject_Source_BioProject_DoorBase_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define BioProject_Source_BioProject_DoorBase_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADoorBase(); \
	friend struct Z_Construct_UClass_ADoorBase_Statics; \
public: \
	DECLARE_CLASS(ADoorBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ADoorBase)


#define BioProject_Source_BioProject_DoorBase_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADoorBase(); \
	friend struct Z_Construct_UClass_ADoorBase_Statics; \
public: \
	DECLARE_CLASS(ADoorBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ADoorBase)


#define BioProject_Source_BioProject_DoorBase_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADoorBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADoorBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoorBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoorBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoorBase(ADoorBase&&); \
	NO_API ADoorBase(const ADoorBase&); \
public:


#define BioProject_Source_BioProject_DoorBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoorBase(ADoorBase&&); \
	NO_API ADoorBase(const ADoorBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoorBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoorBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADoorBase)


#define BioProject_Source_BioProject_DoorBase_h_12_PRIVATE_PROPERTY_OFFSET
#define BioProject_Source_BioProject_DoorBase_h_9_PROLOG
#define BioProject_Source_BioProject_DoorBase_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_DoorBase_h_12_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_DoorBase_h_12_SPARSE_DATA \
	BioProject_Source_BioProject_DoorBase_h_12_RPC_WRAPPERS \
	BioProject_Source_BioProject_DoorBase_h_12_INCLASS \
	BioProject_Source_BioProject_DoorBase_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_DoorBase_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_DoorBase_h_12_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_DoorBase_h_12_SPARSE_DATA \
	BioProject_Source_BioProject_DoorBase_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_DoorBase_h_12_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_DoorBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class ADoorBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_DoorBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
