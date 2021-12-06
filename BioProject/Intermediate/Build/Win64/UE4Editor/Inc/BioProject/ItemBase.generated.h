// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FItemData;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef BIOPROJECT_ItemBase_generated_h
#error "ItemBase.generated.h already included, missing '#pragma once' in ItemBase.h"
#endif
#define BIOPROJECT_ItemBase_generated_h

#define BioProject_Source_BioProject_ItemBase_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemData_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FItemData>();

#define BioProject_Source_BioProject_ItemBase_h_51_SPARSE_DATA
#define BioProject_Source_BioProject_ItemBase_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCenterPos) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetCenterPos(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetItemData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FItemData*)Z_Param__Result=P_THIS->GetItemData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define BioProject_Source_BioProject_ItemBase_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCenterPos) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetCenterPos(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetItemData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FItemData*)Z_Param__Result=P_THIS->GetItemData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define BioProject_Source_BioProject_ItemBase_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItemBase(); \
	friend struct Z_Construct_UClass_AItemBase_Statics; \
public: \
	DECLARE_CLASS(AItemBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AItemBase)


#define BioProject_Source_BioProject_ItemBase_h_51_INCLASS \
private: \
	static void StaticRegisterNativesAItemBase(); \
	friend struct Z_Construct_UClass_AItemBase_Statics; \
public: \
	DECLARE_CLASS(AItemBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AItemBase)


#define BioProject_Source_BioProject_ItemBase_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AItemBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AItemBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItemBase(AItemBase&&); \
	NO_API AItemBase(const AItemBase&); \
public:


#define BioProject_Source_BioProject_ItemBase_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItemBase(AItemBase&&); \
	NO_API AItemBase(const AItemBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItemBase)


#define BioProject_Source_BioProject_ItemBase_h_51_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pBase() { return STRUCT_OFFSET(AItemBase, m_pBase); } \
	FORCEINLINE static uint32 __PPO__m_pBoxComp() { return STRUCT_OFFSET(AItemBase, m_pBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_pMesh() { return STRUCT_OFFSET(AItemBase, m_pMesh); } \
	FORCEINLINE static uint32 __PPO__m_itemData() { return STRUCT_OFFSET(AItemBase, m_itemData); }


#define BioProject_Source_BioProject_ItemBase_h_48_PROLOG
#define BioProject_Source_BioProject_ItemBase_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_ItemBase_h_51_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_ItemBase_h_51_SPARSE_DATA \
	BioProject_Source_BioProject_ItemBase_h_51_RPC_WRAPPERS \
	BioProject_Source_BioProject_ItemBase_h_51_INCLASS \
	BioProject_Source_BioProject_ItemBase_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_ItemBase_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_ItemBase_h_51_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_ItemBase_h_51_SPARSE_DATA \
	BioProject_Source_BioProject_ItemBase_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_ItemBase_h_51_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_ItemBase_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class AItemBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_ItemBase_h


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
