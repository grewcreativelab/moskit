// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef MOSKIT_MoskitBPLibrary_generated_h
#error "MoskitBPLibrary.generated.h already included, missing '#pragma once' in MoskitBPLibrary.h"
#endif
#define MOSKIT_MoskitBPLibrary_generated_h

#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndMoskit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::EndMoskit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRunMoskit) \
	{ \
		P_GET_UBOOL(Z_Param_bisActive); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_DeltaTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::RunMoskit(Z_Param_bisActive,Z_Param_DeltaTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartMoskit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::StartMoskit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSettingMoskit) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_strOutputFilePath); \
		P_GET_OBJECT(AActor,Z_Param__pPlayer); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_fHeight); \
		P_GET_UBOOL(Z_Param_bisConnectedToHardware); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::SettingMoskit(Z_Param_strOutputFilePath,Z_Param__pPlayer,Z_Param_fHeight,Z_Param_bisConnectedToHardware); \
		P_NATIVE_END; \
	}


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndMoskit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::EndMoskit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRunMoskit) \
	{ \
		P_GET_UBOOL(Z_Param_bisActive); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_DeltaTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::RunMoskit(Z_Param_bisActive,Z_Param_DeltaTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartMoskit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::StartMoskit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSettingMoskit) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_strOutputFilePath); \
		P_GET_OBJECT(AActor,Z_Param__pPlayer); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_fHeight); \
		P_GET_UBOOL(Z_Param_bisConnectedToHardware); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMoskitBPLibrary::SettingMoskit(Z_Param_strOutputFilePath,Z_Param__pPlayer,Z_Param_fHeight,Z_Param_bisConnectedToHardware); \
		P_NATIVE_END; \
	}


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMoskitBPLibrary(); \
	friend struct Z_Construct_UClass_UMoskitBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UMoskitBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Moskit"), NO_API) \
	DECLARE_SERIALIZER(UMoskitBPLibrary)


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUMoskitBPLibrary(); \
	friend struct Z_Construct_UClass_UMoskitBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UMoskitBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Moskit"), NO_API) \
	DECLARE_SERIALIZER(UMoskitBPLibrary)


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMoskitBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMoskitBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMoskitBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMoskitBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMoskitBPLibrary(UMoskitBPLibrary&&); \
	NO_API UMoskitBPLibrary(const UMoskitBPLibrary&); \
public:


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMoskitBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMoskitBPLibrary(UMoskitBPLibrary&&); \
	NO_API UMoskitBPLibrary(const UMoskitBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMoskitBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMoskitBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMoskitBPLibrary)


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET
#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_25_PROLOG
#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_RPC_WRAPPERS \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_INCLASS \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
	ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class MoskitBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ggd_Plugins_Moskit_Source_Moskit_Public_MoskitBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
