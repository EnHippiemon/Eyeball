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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeEntityGrasshopper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_AEyeEntityGrasshopper, AEyeEntityGrasshopper::StaticClass, TEXT("AEyeEntityGrasshopper"), &Z_Registration_Info_UClass_AEyeEntityGrasshopper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeEntityGrasshopper), 1202903416U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_943669255(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeEntityGrasshopper_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
