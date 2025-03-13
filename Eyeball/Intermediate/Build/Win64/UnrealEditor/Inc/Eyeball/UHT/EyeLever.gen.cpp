// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/PuzzleComponents/EyeLever.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeLever() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
EYEBALL_API UClass* Z_Construct_UClass_AEyeLever();
EYEBALL_API UClass* Z_Construct_UClass_AEyeLever_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeMoveableObject_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class AEyeLever
void AEyeLever::StaticRegisterNativesAEyeLever()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeLever);
UClass* Z_Construct_UClass_AEyeLever_NoRegister()
{
	return AEyeLever::StaticClass();
}
struct Z_Construct_UClass_AEyeLever_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PuzzleComponents/EyeLever.h" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeLever.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveableObject_MetaData[] = {
		{ "Category", "EyeLever" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeLever.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveableObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeLever>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeLever_Statics::NewProp_MoveableObject = { "MoveableObject", nullptr, (EPropertyFlags)0x0144000000000801, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeLever, MoveableObject), Z_Construct_UClass_AEyeMoveableObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveableObject_MetaData), NewProp_MoveableObject_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeLever_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeLever_Statics::NewProp_MoveableObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeLever_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEyeLever_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeLever_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeLever_Statics::ClassParams = {
	&AEyeLever::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEyeLever_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEyeLever_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeLever_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeLever_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeLever()
{
	if (!Z_Registration_Info_UClass_AEyeLever.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeLever.OuterSingleton, Z_Construct_UClass_AEyeLever_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeLever.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeLever>()
{
	return AEyeLever::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeLever);
AEyeLever::~AEyeLever() {}
// End Class AEyeLever

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeLever_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeLever, AEyeLever::StaticClass, TEXT("AEyeLever"), &Z_Registration_Info_UClass_AEyeLever, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeLever), 2352070009U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeLever_h_3546439529(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeLever_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeLever_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
