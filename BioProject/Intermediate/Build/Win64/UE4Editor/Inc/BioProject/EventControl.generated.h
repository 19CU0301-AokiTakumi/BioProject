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
#ifdef BIOPROJECT_EventControl_generated_h
#error "EventControl.generated.h already included, missing '#pragma once' in EventControl.h"
#endif
#define BIOPROJECT_EventControl_generated_h

#define BioProject_Source_BioProject_EventControl_h_21_SPARSE_DATA
#define BioProject_Source_BioProject_EventControl_h_21_RPC_WRAPPERS \
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


#define BioProject_Source_BioProject_EventControl_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define BioProject_Source_BioProject_EventControl_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEventControl(); \
	friend struct Z_Construct_UClass_AEventControl_Statics; \
public: \
	DECLARE_CLASS(AEventControl, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AEventControl)


#define BioProject_Source_BioProject_EventControl_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAEventControl(); \
	friend struct Z_Construct_UClass_AEventControl_Statics; \
public: \
	DECLARE_CLASS(AEventControl, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AEventControl)


#define BioProject_Source_BioProject_EventControl_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEventControl(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEventControl) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEventControl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEventControl); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEventControl(AEventControl&&); \
	NO_API AEventControl(const AEventControl&); \
public:


#define BioProject_Source_BioProject_EventControl_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEventControl(AEventControl&&); \
	NO_API AEventControl(const AEventControl&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEventControl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEventControl); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEventControl)


#define BioProject_Source_BioProject_EventControl_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pBase() { return STRUCT_OFFSET(AEventControl, m_pBase); } \
	FORCEINLINE static uint32 __PPO__m_pSpawnPoint() { return STRUCT_OFFSET(AEventControl, m_pSpawnPoint); } \
	FORCEINLINE static uint32 __PPO__m_pBoxComp() { return STRUCT_OFFSET(AEventControl, m_pBoxComp); } \
	FORCEINLINE static uint32 __PPO__m_SpawnLocation() { return STRUCT_OFFSET(AEventControl, m_SpawnLocation); } \
	FORCEINLINE static uint32 __PPO__id() { return STRUCT_OFFSET(AEventControl, id); }


#define BioProject_Source_BioProject_EventControl_h_18_PROLOG
#define BioProject_Source_BioProject_EventControl_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_EventControl_h_21_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_EventControl_h_21_SPARSE_DATA \
	BioProject_Source_BioProject_EventControl_h_21_RPC_WRAPPERS \
	BioProject_Source_BioProject_EventControl_h_21_INCLASS \
	BioProject_Source_BioProject_EventControl_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_EventControl_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_EventControl_h_21_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_EventControl_h_21_SPARSE_DATA \
	BioProject_Source_BioProject_EventControl_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_EventControl_h_21_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_EventControl_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class AEventControl>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_EventControl_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
