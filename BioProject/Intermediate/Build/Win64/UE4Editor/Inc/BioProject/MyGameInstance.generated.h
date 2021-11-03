// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BIOPROJECT_MyGameInstance_generated_h
#error "MyGameInstance.generated.h already included, missing '#pragma once' in MyGameInstance.h"
#endif
#define BIOPROJECT_MyGameInstance_generated_h

#define BioProject_Source_BioProject_MyGameInstance_h_24_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemData_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FItemData>();

#define BioProject_Source_BioProject_MyGameInstance_h_45_SPARSE_DATA
#define BioProject_Source_BioProject_MyGameInstance_h_45_RPC_WRAPPERS
#define BioProject_Source_BioProject_MyGameInstance_h_45_RPC_WRAPPERS_NO_PURE_DECLS
#define BioProject_Source_BioProject_MyGameInstance_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyGameInstance(); \
	friend struct Z_Construct_UClass_UMyGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMyGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(UMyGameInstance)


#define BioProject_Source_BioProject_MyGameInstance_h_45_INCLASS \
private: \
	static void StaticRegisterNativesUMyGameInstance(); \
	friend struct Z_Construct_UClass_UMyGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMyGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(UMyGameInstance)


#define BioProject_Source_BioProject_MyGameInstance_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyGameInstance(UMyGameInstance&&); \
	NO_API UMyGameInstance(const UMyGameInstance&); \
public:


#define BioProject_Source_BioProject_MyGameInstance_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyGameInstance(UMyGameInstance&&); \
	NO_API UMyGameInstance(const UMyGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyGameInstance)


#define BioProject_Source_BioProject_MyGameInstance_h_45_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pItemDatas() { return STRUCT_OFFSET(UMyGameInstance, m_pItemDatas); }


#define BioProject_Source_BioProject_MyGameInstance_h_42_PROLOG
#define BioProject_Source_BioProject_MyGameInstance_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_MyGameInstance_h_45_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_MyGameInstance_h_45_SPARSE_DATA \
	BioProject_Source_BioProject_MyGameInstance_h_45_RPC_WRAPPERS \
	BioProject_Source_BioProject_MyGameInstance_h_45_INCLASS \
	BioProject_Source_BioProject_MyGameInstance_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_MyGameInstance_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_MyGameInstance_h_45_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_MyGameInstance_h_45_SPARSE_DATA \
	BioProject_Source_BioProject_MyGameInstance_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_MyGameInstance_h_45_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_MyGameInstance_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class UMyGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_MyGameInstance_h


#define FOREACH_ENUM_ITEMTYPE(op) \
	op(ItemType::None) \
	op(ItemType::Key) \
	op(ItemType::Heal) \
	op(ItemType::Weapon) \
	op(ItemType::Bullet) \
	op(ItemType::Event) \
	op(ItemType::Debug) 

enum class ItemType : uint8;
template<> BIOPROJECT_API UEnum* StaticEnum<ItemType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
