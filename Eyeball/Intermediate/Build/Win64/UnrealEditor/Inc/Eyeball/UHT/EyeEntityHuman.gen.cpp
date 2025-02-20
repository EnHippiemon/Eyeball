// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/EyeEntityHuman.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeEntityHuman() {}

// Begin Cross Module References
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter();
EYEBALL_API UClass* Z_Construct_UClass_AEyeEntityHuman();
EYEBALL_API UClass* Z_Construct_UClass_AEyeEntityHuman_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class AEyeEntityHuman
void AEyeEntityHuman::StaticRegisterNativesAEyeEntityHuman()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeEntityHuman);
UClass* Z_Construct_UClass_AEyeEntityHuman_NoRegister()
{
	return AEyeEntityHuman::StaticClass();
}
struct Z_Construct_UClass_AEyeEntityHuman_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EyeEntityHuman.h" },
		{ "ModuleRelativePath", "EyeEntityHuman.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeEntityHuman>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEyeEntityHuman_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEyeCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityHuman_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeEntityHuman_Statics::ClassParams = {
	&AEyeEntityHuman::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityHuman_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeEntityHuman_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeEntityHuman()
{
	if (!Z_Registration_Info_UClass_AEyeEntityHuman.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeEntityHuman.OuterSingleton, Z_Construct_UClass_AEyeEntityHuman_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeEntityHuman.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeEntityHuman>()
{
	return AEyeEntityHuman::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeEntityHuman);
AEyeEntityHuman::~AEyeEntityHuman() {}
// End Class AEyeEntityHuman

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityHuman_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeEntityHuman, AEyeEntityHuman::StaticClass, TEXT("AEyeEntityHuman"), &Z_Registration_Info_UClass_AEyeEntityHuman, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeEntityHuman), 1920349058U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityHuman_h_2403503912(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityHuman_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityHuman_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
