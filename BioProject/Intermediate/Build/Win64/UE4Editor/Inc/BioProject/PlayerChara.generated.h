// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FItemData;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef BIOPROJECT_PlayerChara_generated_h
#error "PlayerChara.generated.h already included, missing '#pragma once' in PlayerChara.h"
#endif
#define BIOPROJECT_PlayerChara_generated_h

#define BioProject_Source_BioProject_PlayerChara_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerStatus_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FPlayerStatus>();

#define BioProject_Source_BioProject_PlayerChara_h_27_SPARSE_DATA
#define BioProject_Source_BioProject_PlayerChara_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetPlayerMaxHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPlayerMaxHP(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPlayerHP(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerBag) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FItemData>*)Z_Param__Result=P_THIS->GetPlayerBag(); \
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


#define BioProject_Source_BioProject_PlayerChara_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetPlayerMaxHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPlayerMaxHP(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPlayerHP(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerBag) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FItemData>*)Z_Param__Result=P_THIS->GetPlayerBag(); \
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


#define BioProject_Source_BioProject_PlayerChara_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerChara(); \
	friend struct Z_Construct_UClass_APlayerChara_Statics; \
public: \
	DECLARE_CLASS(APlayerChara, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(APlayerChara)


#define BioProject_Source_BioProject_PlayerChara_h_27_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerChara(); \
	friend struct Z_Construct_UClass_APlayerChara_Statics; \
public: \
	DECLARE_CLASS(APlayerChara, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(APlayerChara)


#define BioProject_Source_BioProject_PlayerChara_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerChara(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerChara) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerChara); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerChara); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerChara(APlayerChara&&); \
	NO_API APlayerChara(const APlayerChara&); \
public:


#define BioProject_Source_BioProject_PlayerChara_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerChara(APlayerChara&&); \
	NO_API APlayerChara(const APlayerChara&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerChara); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerChara); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerChara)


#define BioProject_Source_BioProject_PlayerChara_h_27_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pSpringArm() { return STRUCT_OFFSET(APlayerChara, m_pSpringArm); } \
	FORCEINLINE static uint32 __PPO__m_pCamera() { return STRUCT_OFFSET(APlayerChara, m_pCamera); } \
	FORCEINLINE static uint32 __PPO__m_CameraYawLimit() { return STRUCT_OFFSET(APlayerChara, m_CameraYawLimit); } \
	FORCEINLINE static uint32 __PPO__m_CameraPitchLimit() { return STRUCT_OFFSET(APlayerChara, m_CameraPitchLimit); } \
	FORCEINLINE static uint32 __PPO__m_playerStatus() { return STRUCT_OFFSET(APlayerChara, m_playerStatus); } \
	FORCEINLINE static uint32 __PPO__m_ItemDatas() { return STRUCT_OFFSET(APlayerChara, m_ItemDatas); } \
	FORCEINLINE static uint32 __PPO__m_bagSize() { return STRUCT_OFFSET(APlayerChara, m_bagSize); }


#define BioProject_Source_BioProject_PlayerChara_h_24_PROLOG
#define BioProject_Source_BioProject_PlayerChara_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_PlayerChara_h_27_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_PlayerChara_h_27_SPARSE_DATA \
	BioProject_Source_BioProject_PlayerChara_h_27_RPC_WRAPPERS \
	BioProject_Source_BioProject_PlayerChara_h_27_INCLASS \
	BioProject_Source_BioProject_PlayerChara_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_PlayerChara_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_PlayerChara_h_27_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_PlayerChara_h_27_SPARSE_DATA \
	BioProject_Source_BioProject_PlayerChara_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_PlayerChara_h_27_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_PlayerChara_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class APlayerChara>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_PlayerChara_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
