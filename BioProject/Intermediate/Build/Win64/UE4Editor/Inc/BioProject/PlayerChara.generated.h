// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
enum class EActionStatus : uint8;
struct FGunData;
enum class EInventoryState : uint8;
class AActor;
enum class EGunType : uint8;
struct FAmmoData;
struct FPlayerStatus;
struct FItemData;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BIOPROJECT_PlayerChara_generated_h
#error "PlayerChara.generated.h already included, missing '#pragma once' in PlayerChara.h"
#endif
#define BIOPROJECT_PlayerChara_generated_h

#define BioProject_Source_BioProject_PlayerChara_h_70_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStatusConstant_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FStatusConstant>();

#define BioProject_Source_BioProject_PlayerChara_h_21_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerStatus_Statics; \
	BIOPROJECT_API static class UScriptStruct* StaticStruct();


template<> BIOPROJECT_API UScriptStruct* StaticStruct<struct FPlayerStatus>();

#define BioProject_Source_BioProject_PlayerChara_h_82_SPARSE_DATA
#define BioProject_Source_BioProject_PlayerChara_h_82_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetLandingPoint) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetLandingPoint(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAnimStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EActionStatus*)Z_Param__Result=P_THIS->GetAnimStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEquipGunData) \
	{ \
		P_GET_STRUCT(FGunData,Z_Param__gunData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEquipGunData(Z_Param__gunData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsDead) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsDead(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsGunHold) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsGunHold(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsOpenInventory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsOpenInventory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIsGetItem) \
	{ \
		P_GET_UBOOL(Z_Param__isGet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetIsGetItem(Z_Param__isGet); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDamage) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param__atk); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Damage(Z_Param__atk); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeal) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param__index); \
		P_GET_PROPERTY(UIntProperty,Z_Param__value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Heal(Z_Param__index,Z_Param__value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCursorIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param__index); \
		P_GET_PROPERTY(UIntProperty,Z_Param__moveValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCursorIndex(Z_Param__index,Z_Param__moveValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInventoryState) \
	{ \
		P_GET_ENUM(EInventoryState,Z_Param__state); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetInventoryState(EInventoryState(Z_Param__state)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInventoryState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EInventoryState*)Z_Param__Result=P_THIS->GetInventoryState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOverlapActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=P_THIS->GetOverlapActor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsItemTouch) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsItemTouch(); \
		P_NATIVE_END; \
	} \
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
	DECLARE_FUNCTION(execGetAmmoData) \
	{ \
		P_GET_ENUM(EGunType,Z_Param__ammoType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FAmmoData*)Z_Param__Result=P_THIS->GetAmmoData(EGunType(Z_Param__ammoType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FPlayerStatus*)Z_Param__Result=P_THIS->GetPlayerStatus(); \
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


#define BioProject_Source_BioProject_PlayerChara_h_82_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetLandingPoint) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetLandingPoint(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAnimStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EActionStatus*)Z_Param__Result=P_THIS->GetAnimStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEquipGunData) \
	{ \
		P_GET_STRUCT(FGunData,Z_Param__gunData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEquipGunData(Z_Param__gunData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsDead) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsDead(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsGunHold) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsGunHold(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsOpenInventory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsOpenInventory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIsGetItem) \
	{ \
		P_GET_UBOOL(Z_Param__isGet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetIsGetItem(Z_Param__isGet); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDamage) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param__atk); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Damage(Z_Param__atk); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeal) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param__index); \
		P_GET_PROPERTY(UIntProperty,Z_Param__value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Heal(Z_Param__index,Z_Param__value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCursorIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param__index); \
		P_GET_PROPERTY(UIntProperty,Z_Param__moveValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCursorIndex(Z_Param__index,Z_Param__moveValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInventoryState) \
	{ \
		P_GET_ENUM(EInventoryState,Z_Param__state); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetInventoryState(EInventoryState(Z_Param__state)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInventoryState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EInventoryState*)Z_Param__Result=P_THIS->GetInventoryState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOverlapActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=P_THIS->GetOverlapActor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsItemTouch) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsItemTouch(); \
		P_NATIVE_END; \
	} \
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
	DECLARE_FUNCTION(execGetAmmoData) \
	{ \
		P_GET_ENUM(EGunType,Z_Param__ammoType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FAmmoData*)Z_Param__Result=P_THIS->GetAmmoData(EGunType(Z_Param__ammoType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FPlayerStatus*)Z_Param__Result=P_THIS->GetPlayerStatus(); \
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


#define BioProject_Source_BioProject_PlayerChara_h_82_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerChara(); \
	friend struct Z_Construct_UClass_APlayerChara_Statics; \
public: \
	DECLARE_CLASS(APlayerChara, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(APlayerChara)


#define BioProject_Source_BioProject_PlayerChara_h_82_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerChara(); \
	friend struct Z_Construct_UClass_APlayerChara_Statics; \
public: \
	DECLARE_CLASS(APlayerChara, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioProject"), NO_API) \
	DECLARE_SERIALIZER(APlayerChara)


#define BioProject_Source_BioProject_PlayerChara_h_82_STANDARD_CONSTRUCTORS \
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


#define BioProject_Source_BioProject_PlayerChara_h_82_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerChara(APlayerChara&&); \
	NO_API APlayerChara(const APlayerChara&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerChara); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerChara); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerChara)


#define BioProject_Source_BioProject_PlayerChara_h_82_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pSpringArm() { return STRUCT_OFFSET(APlayerChara, m_pSpringArm); } \
	FORCEINLINE static uint32 __PPO__m_pCamera() { return STRUCT_OFFSET(APlayerChara, m_pCamera); } \
	FORCEINLINE static uint32 __PPO__CameraShake() { return STRUCT_OFFSET(APlayerChara, CameraShake); } \
	FORCEINLINE static uint32 __PPO__m_CameraYawLimit() { return STRUCT_OFFSET(APlayerChara, m_CameraYawLimit); } \
	FORCEINLINE static uint32 __PPO__m_CameraPitchLimit() { return STRUCT_OFFSET(APlayerChara, m_CameraPitchLimit); } \
	FORCEINLINE static uint32 __PPO__m_playerStatus() { return STRUCT_OFFSET(APlayerChara, m_playerStatus); } \
	FORCEINLINE static uint32 __PPO__m_statusConst() { return STRUCT_OFFSET(APlayerChara, m_statusConst); } \
	FORCEINLINE static uint32 __PPO__m_ActionStatus() { return STRUCT_OFFSET(APlayerChara, m_ActionStatus); } \
	FORCEINLINE static uint32 __PPO__m_ItemDatas() { return STRUCT_OFFSET(APlayerChara, m_ItemDatas); } \
	FORCEINLINE static uint32 __PPO__m_bagSize() { return STRUCT_OFFSET(APlayerChara, m_bagSize); }


#define BioProject_Source_BioProject_PlayerChara_h_79_PROLOG
#define BioProject_Source_BioProject_PlayerChara_h_82_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_PlayerChara_h_82_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_PlayerChara_h_82_SPARSE_DATA \
	BioProject_Source_BioProject_PlayerChara_h_82_RPC_WRAPPERS \
	BioProject_Source_BioProject_PlayerChara_h_82_INCLASS \
	BioProject_Source_BioProject_PlayerChara_h_82_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioProject_Source_BioProject_PlayerChara_h_82_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioProject_Source_BioProject_PlayerChara_h_82_PRIVATE_PROPERTY_OFFSET \
	BioProject_Source_BioProject_PlayerChara_h_82_SPARSE_DATA \
	BioProject_Source_BioProject_PlayerChara_h_82_RPC_WRAPPERS_NO_PURE_DECLS \
	BioProject_Source_BioProject_PlayerChara_h_82_INCLASS_NO_PURE_DECLS \
	BioProject_Source_BioProject_PlayerChara_h_82_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOPROJECT_API UClass* StaticClass<class APlayerChara>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioProject_Source_BioProject_PlayerChara_h


#define FOREACH_ENUM_EINVENTORYSTATE(op) \
	op(EInventoryState::Idle) \
	op(EInventoryState::Open) \
	op(EInventoryState::Close) 

enum class EInventoryState : uint8;
template<> BIOPROJECT_API UEnum* StaticEnum<EInventoryState>();

#define FOREACH_ENUM_EACTIONSTATUS(op) \
	op(EActionStatus::Idle) \
	op(EActionStatus::Walk) \
	op(EActionStatus::Run) \
	op(EActionStatus::GunHold) \
	op(EActionStatus::Reload) \
	op(EActionStatus::Guard) 

enum class EActionStatus : uint8;
template<> BIOPROJECT_API UEnum* StaticEnum<EActionStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
