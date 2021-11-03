// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef BIOPROJECT_DoorBase_generated_h
#error "DoorBase.generated.h already included, missing '#pragma once' in DoorBase.h"
#endif
#define BIOPROJECT_DoorBase_generated_h

#define BioProject_Source_BioProject_DoorBase_h_16_SPARSE_DATA
#define BioProject_Source_BioProject_DoorBase_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetIsLock) \
	{ \
		P_GET_UBOOL(Z_Param__isLock); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetIsLock(Z_Param__isLock); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsLock) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsLock(); \
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


#define BioProject_Source_BioProject_DoorBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetIsLock) \
	{ \
		P_GET_UBOOL(Z_Param__isLock); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetIsLock(Z_Param__isLock); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsLock) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsLock(); \
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


#define BioProject_Source_BioProject_DoorBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADoorBase(); \
	friend struct Z_Construct_UClass_ADoorBase_Statics; \
public: \
	DECLARE_CLASS(ADoorBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ADoorBase)


#define BioProject_Source_BioProject_DoorBase_h_16_INCLASS \
private: \
	static void StaticRegisterNativesADoorBase(); \
	friend struct Z_Construct_UClass_ADoorBase_Statics; \
public: \
	DECLARE_CLASS(ADoorBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(ADoorBase)


#define BioProject_Source_BioProject_DoorBase_h_16_STANDARD_CONSTRUCTORS \
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


#define BioProject_Source_BioProject_DoorBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoorBase(ADoorBase&&); \
	NO_API ADoorBase(const ADoorBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoorBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoorBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADoorBase)


#define BioProject_Source_BioProject_DoorBase_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pBase() { return STRUCT_OFFSET(ADoorBase, m_pBase); } \
	FORCEINLINE static uint32 __PPO__m_pRootBoxComp() { return STRUCT_OFFSET(ADoorBase, m_pRootBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_pFrontBoxComp() { return STRUCT_OFFSET(ADoorBase, m_pFrontBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_pBackBoxComp() { return STRUCT_OFFSET(ADoorBase, m_pBackBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_bIsLock() { return STRUCT_OFFSET(ADoorBase, m_bIsLock); } \
	FORCEINLINE static uint32 __PPO__m_speed() { return STRUCT_OFFSET(ADoorBase, m_speed); } \
	FORCEINLINE static uint32 __PPO__m_id() { return STRUCT_OFFSET(ADoorBase, m_id); } \
	FORCEINLINE static uint32 __PPO__m_closeTime() { return STRUCT_OFFSET(ADoorBase, m_closeTime); } \
	FORCEINLINE static uint32 __PPO__m_IsSlide() { return STRUCT_OFFSET(ADoorBase, m_IsSlide); }


#define BioProject_Source_BioProject_DoorBase_h_13_PROLOG
#define BioProject_Source_BioProject_DoorBase_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_DoorBase_h_16_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_DoorBase_h_16_SPARSE_DATA \
	BioProject_Source_BioProject_DoorBase_h_16_RPC_WRAPPERS \
	BioProject_Source_BioProject_DoorBase_h_16_INCLASS \
	BioProject_Source_BioProject_DoorBase_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_DoorBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_DoorBase_h_16_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_DoorBase_h_16_SPARSE_DATA \
	BioProject_Source_BioProject_DoorBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_DoorBase_h_16_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_DoorBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class ADoorBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_DoorBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
