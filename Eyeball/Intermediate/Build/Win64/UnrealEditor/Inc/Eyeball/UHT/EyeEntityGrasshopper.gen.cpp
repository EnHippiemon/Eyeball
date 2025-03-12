// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/Entities/EyeEntityGrasshopper.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeEntityGrasshopper() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter();
EYEBALL_API UClass* Z_Construct_UClass_AEyeEntityGrasshopper();
EYEBALL_API UClass* Z_Construct_UClass_AEyeEntityGrasshopper_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class AEyeEntityGrasshopper
void AEyeEntityGrasshopper::StaticRegisterNativesAEyeEntityGrasshopper()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeEntityGrasshopper);
UClass* Z_Construct_UClass_AEyeEntityGrasshopper_NoRegister()
{
	return AEyeEntityGrasshopper::StaticClass();
}
struct Z_Construct_UClass_AEyeEntityGrasshopper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/EyeEntityGrasshopper.h" },
		{ "ModuleRelativePath", "Entities/EyeEntityGrasshopper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[] = {
		{ "Category", "EyeEntityGrasshopper" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Entities/EyeEntityGrasshopper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Box;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeEntityGrasshopper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeEntityGrasshopper_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeEntityGrasshopper, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Box_MetaData), NewProp_Box_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeEntityGrasshopper_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeEntityGrasshopper_Statics::NewProp_Box,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityGrasshopper_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEyeEntityGrasshopper_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEyeCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityGrasshopper_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeEntityGrasshopper_Statics::ClassParams = {
	&AEyeEntityGrasshopper::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEyeEntityGrasshopper_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityGrasshopper_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityGrasshopper_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeEntityGrasshopper_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeEntityGrasshopper()
{
	if (!Z_Registration_Info_UClass_AEyeEntityGrasshopper.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeEntityGrasshopper.OuterSingleton, Z_Construct_UClass_AEyeEntityGrasshopper_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeEntityGrasshopper.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeEntityGrasshopper>()
{
	return AEyeEntityGrasshopper::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeEntityGrasshopper);
AEyeEntityGrasshopper::~AEyeEntityGrasshopper() {}
// End Class AEyeEntityGrasshopper

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeEntityGrasshopper, AEyeEntityGrasshopper::StaticClass, TEXT("AEyeEntityGrasshopper"), &Z_Registration_Info_UClass_AEyeEntityGrasshopper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeEntityGrasshopper), 336426669U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_872018757(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
