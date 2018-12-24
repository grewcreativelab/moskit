// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Moskit/Public/MoskitBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMoskitBPLibrary() {}
// Cross Module References
	MOSKIT_API UClass* Z_Construct_UClass_UMoskitBPLibrary_NoRegister();
	MOSKIT_API UClass* Z_Construct_UClass_UMoskitBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Moskit();
	MOSKIT_API UFunction* Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit();
	MOSKIT_API UFunction* Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit();
	MOSKIT_API UFunction* Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MOSKIT_API UFunction* Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit();
// End Cross Module References
	void UMoskitBPLibrary::StaticRegisterNativesUMoskitBPLibrary()
	{
		UClass* Class = UMoskitBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndMoskit", &UMoskitBPLibrary::execEndMoskit },
			{ "RunMoskit", &UMoskitBPLibrary::execRunMoskit },
			{ "SettingMoskit", &UMoskitBPLibrary::execSettingMoskit },
			{ "StartMoskit", &UMoskitBPLibrary::execStartMoskit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Moskit function" },
		{ "DisplayName", "End Moskit" },
		{ "Keywords", "Moskit" },
		{ "ModuleRelativePath", "Public/MoskitBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMoskitBPLibrary, "EndMoskit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics
	{
		struct MoskitBPLibrary_eventRunMoskit_Parms
		{
			bool bisActive;
			float DeltaTime;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static void NewProp_bisActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bisActive;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::NewProp_DeltaTime = { UE4CodeGen_Private::EPropertyClass::Float, "DeltaTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MoskitBPLibrary_eventRunMoskit_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::NewProp_bisActive_SetBit(void* Obj)
	{
		((MoskitBPLibrary_eventRunMoskit_Parms*)Obj)->bisActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::NewProp_bisActive = { UE4CodeGen_Private::EPropertyClass::Bool, "bisActive", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MoskitBPLibrary_eventRunMoskit_Parms), &Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::NewProp_bisActive_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::NewProp_DeltaTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::NewProp_bisActive,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Moskit function" },
		{ "DisplayName", "Run Moskit" },
		{ "Keywords", "Moskit" },
		{ "ModuleRelativePath", "Public/MoskitBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMoskitBPLibrary, "RunMoskit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(MoskitBPLibrary_eventRunMoskit_Parms), Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics
	{
		struct MoskitBPLibrary_eventSettingMoskit_Parms
		{
			FString strOutputFilePath;
			AActor* _pPlayer;
			float fHeight;
			bool bisConnectedToHardware;
		};
		static void NewProp_bisConnectedToHardware_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bisConnectedToHardware;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_fHeight;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__pPlayer;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_strOutputFilePath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_bisConnectedToHardware_SetBit(void* Obj)
	{
		((MoskitBPLibrary_eventSettingMoskit_Parms*)Obj)->bisConnectedToHardware = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_bisConnectedToHardware = { UE4CodeGen_Private::EPropertyClass::Bool, "bisConnectedToHardware", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MoskitBPLibrary_eventSettingMoskit_Parms), &Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_bisConnectedToHardware_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_fHeight = { UE4CodeGen_Private::EPropertyClass::Float, "fHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MoskitBPLibrary_eventSettingMoskit_Parms, fHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp__pPlayer = { UE4CodeGen_Private::EPropertyClass::Object, "_pPlayer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MoskitBPLibrary_eventSettingMoskit_Parms, _pPlayer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_strOutputFilePath = { UE4CodeGen_Private::EPropertyClass::Str, "strOutputFilePath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MoskitBPLibrary_eventSettingMoskit_Parms, strOutputFilePath), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_bisConnectedToHardware,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_fHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp__pPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::NewProp_strOutputFilePath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Moskit function" },
		{ "DisplayName", "Setting Moskit" },
		{ "Keywords", "Moskit" },
		{ "ModuleRelativePath", "Public/MoskitBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMoskitBPLibrary, "SettingMoskit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(MoskitBPLibrary_eventSettingMoskit_Parms), Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Moskit function" },
		{ "DisplayName", "Start Moskit" },
		{ "Keywords", "Moskit" },
		{ "ModuleRelativePath", "Public/MoskitBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMoskitBPLibrary, "StartMoskit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMoskitBPLibrary_NoRegister()
	{
		return UMoskitBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UMoskitBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMoskitBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Moskit,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMoskitBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMoskitBPLibrary_EndMoskit, "EndMoskit" }, // 1560455007
		{ &Z_Construct_UFunction_UMoskitBPLibrary_RunMoskit, "RunMoskit" }, // 4269367723
		{ &Z_Construct_UFunction_UMoskitBPLibrary_SettingMoskit, "SettingMoskit" }, // 802433002
		{ &Z_Construct_UFunction_UMoskitBPLibrary_StartMoskit, "StartMoskit" }, // 3225827254
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMoskitBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MoskitBPLibrary.h" },
		{ "ModuleRelativePath", "Public/MoskitBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMoskitBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMoskitBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMoskitBPLibrary_Statics::ClassParams = {
		&UMoskitBPLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UMoskitBPLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMoskitBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMoskitBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMoskitBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMoskitBPLibrary, 3470222395);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMoskitBPLibrary(Z_Construct_UClass_UMoskitBPLibrary, &UMoskitBPLibrary::StaticClass, TEXT("/Script/Moskit"), TEXT("UMoskitBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMoskitBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
