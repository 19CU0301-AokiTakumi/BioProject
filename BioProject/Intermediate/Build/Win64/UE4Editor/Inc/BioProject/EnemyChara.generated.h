// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FEnemyStatus;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef BIOPROJECT_EnemyChara_generated_h
#error "EnemyChara.generated.h already included, missing '#pragma once' in EnemyChara.h"
#endif
#define BIOPROJECT_EnemyChara_generated_h

#define BioProject_Source_BioProject_EnemyChara_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEnemyStatus_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FEnemyStatus>();

#define BioProject_Source_BioProject_EnemyChara_h_51_SPARSE_DATA
#define BioProject_Source_BioProject_EnemyChara_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReturnAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnAttack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReturnKnockBack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnKnockBack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReturnDeath) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnDeath(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReturnWalk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnWalk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnemyStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FEnemyStatus*)Z_Param__Result=P_THIS->GetEnemyStatus(); \
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


#define BioProject_Source_BioProject_EnemyChara_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReturnAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnAttack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReturnKnockBack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnKnockBack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReturnDeath) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnDeath(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReturnWalk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReturnWalk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEnemyStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FEnemyStatus*)Z_Param__Result=P_THIS->GetEnemyStatus(); \
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


#define BioProject_Source_BioProject_EnemyChara_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyChara(); \
	friend struct Z_Construct_UClass_AEnemyChara_Statics; \
public: \
	DECLARE_CLASS(AEnemyChara, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AEnemyChara)


#define BioProject_Source_BioProject_EnemyChara_h_51_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyChara(); \
	friend struct Z_Construct_UClass_AEnemyChara_Statics; \
public: \
	DECLARE_CLASS(AEnemyChara, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(AEnemyChara)


#define BioProject_Source_BioProject_EnemyChara_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyChara(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyChara) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyChara); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyChara); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyChara(AEnemyChara&&); \
	NO_API AEnemyChara(const AEnemyChara&); \
public:


#define BioProject_Source_BioProject_EnemyChara_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyChara(AEnemyChara&&); \
	NO_API AEnemyChara(const AEnemyChara&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyChara); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyChara); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyChara)


#define BioProject_Source_BioProject_EnemyChara_h_51_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_SearchArea() { return STRUCT_OFFSET(AEnemyChara, m_SearchArea); } \
	FORCEINLINE static uint32 __PPO__m_EnemyStatus() { return STRUCT_OFFSET(AEnemyChara, m_EnemyStatus); } \
	FORCEINLINE static uint32 __PPO__m_pDamageEffect() { return STRUCT_OFFSET(AEnemyChara, m_pDamageEffect); }


#define BioProject_Source_BioProject_EnemyChara_h_48_PROLOG
#define BioProject_Source_BioProject_EnemyChara_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_EnemyChara_h_51_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_EnemyChara_h_51_SPARSE_DATA \
	BioProject_Source_BioProject_EnemyChara_h_51_RPC_WRAPPERS \
	BioProject_Source_BioProject_EnemyChara_h_51_INCLASS \
	BioProject_Source_BioProject_EnemyChara_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_EnemyChara_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_EnemyChara_h_51_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_EnemyChara_h_51_SPARSE_DATA \
	BioProject_Source_BioProject_EnemyChara_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_EnemyChara_h_51_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_EnemyChara_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class AEnemyChara>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_EnemyChara_h


#define FOREACH_ENUM_ACTIONSTATUS(op) \
	op(ActionStatus::Idle) \
	op(ActionStatus::Move) \
	op(ActionStatus::Attack) \
	op(ActionStatus::Avoid) \
	op(ActionStatus::KnockBack) \
	op(ActionStatus::Death) 

enum class ActionStatus : uint8;
template<> BIOPROJECT_API UEnum* StaticEnum<ActionStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
