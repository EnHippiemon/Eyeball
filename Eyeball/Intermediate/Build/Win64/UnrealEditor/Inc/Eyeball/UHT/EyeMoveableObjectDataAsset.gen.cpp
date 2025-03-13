// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/DataAssets/EyeMoveableObjectDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeMoveableObjectDataAsset() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
EYEBALL_API UClass* Z_Construct_UClass_UEyeMoveableObjectDataAsset();
EYEBALL_API UClass* Z_Construct_UClass_UEyeMoveableObjectDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class UEyeMoveableObjectDataAsset
void UEyeMoveableObjectDataAsset::StaticRegisterNativesUEyeMoveableObjectDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEyeMoveableObjectDataAsset);
UClass* Z_Construct_UClass_UEyeMoveableObjectDataAsset_NoRegister()
{
	return UEyeMoveableObjectDataAsset::StaticClass();
}
struct Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DataAssets/EyeMoveableObjectDataAsset.h" },
		{ "ModuleRelativePath", "DataAssets/EyeMoveableObjectDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveDirection_MetaData[] = {
		{ "Category", "EyeMoveableObjectDataAsset" },
		{ "ModuleRelativePath", "DataAssets/EyeMoveableObjectDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "EyeMoveableObjectDataAsset" },
		{ "ModuleRelativePath", "DataAssets/EyeMoveableObjectDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetOffset_MetaData[] = {
		{ "Category", "EyeMoveableObjectDataAsset" },
		{ "ModuleRelativePath", "DataAssets/EyeMoveableObjectDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnToStartLocation_MetaData[] = {
		{ "Category", "EyeMoveableObjectDataAsset" },
		{ "ModuleRelativePath", "DataAssets/EyeMoveableObjectDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveDirection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetOffset;
	static void NewProp_ReturnToStartLocation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnToStartLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEyeMoveableObjectDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_MoveDirection = { "MoveDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeMoveableObjectDataAsset, MoveDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveDirection_MetaData), NewProp_MoveDirection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeMoveableObjectDataAsset, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSpeed_MetaData), NewProp_MoveSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_TargetOffset = { "TargetOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeMoveableObjectDataAsset, TargetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetOffset_MetaData), NewProp_TargetOffset_MetaData) };
void Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_ReturnToStartLocation_SetBit(void* Obj)
{
	((UEyeMoveableObjectDataAsset*)Obj)->ReturnToStartLocation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_ReturnToStartLocation = { "ReturnToStartLocation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEyeMoveableObjectDataAsset), &Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_ReturnToStartLocation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnToStartLocation_MetaData), NewProp_ReturnToStartLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_MoveDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_MoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_TargetOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::NewProp_ReturnToStartLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::ClassParams = {
	&UEyeMoveableObjectDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEyeMoveableObjectDataAsset()
{
	if (!Z_Registration_Info_UClass_UEyeMoveableObjectDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEyeMoveableObjectDataAsset.OuterSingleton, Z_Construct_UClass_UEyeMoveableObjectDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEyeMoveableObjectDataAsset.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<UEyeMoveableObjectDataAsset>()
{
	return UEyeMoveableObjectDataAsset::StaticClass();
}
UEyeMoveableObjectDataAsset::UEyeMoveableObjectDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEyeMoveableObjectDataAsset);
UEyeMoveableObjectDataAsset::~UEyeMoveableObjectDataAsset() {}
// End Class UEyeMoveableObjectDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeMoveableObjectDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEyeMoveableObjectDataAsset, UEyeMoveableObjectDataAsset::StaticClass, TEXT("UEyeMoveableObjectDataAsset"), &Z_Registration_Info_UClass_UEyeMoveableObjectDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEyeMoveableObjectDataAsset), 1472222440U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeMoveableObjectDataAsset_h_3484538334(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeMoveableObjectDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeMoveableObjectDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
