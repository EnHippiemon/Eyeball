// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/EyeEntityEyeball.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeEntityEyeball() {}

// Begin Cross Module References
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter();
EYEBALL_API UClass* Z_Construct_UClass_AEyeEntityEyeball();
EYEBALL_API UClass* Z_Construct_UClass_AEyeEntityEyeball_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class AEyeEntityEyeball
void AEyeEntityEyeball::StaticRegisterNativesAEyeEntityEyeball()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeEntityEyeball);
UClass* Z_Construct_UClass_AEyeEntityEyeball_NoRegister()
{
	return AEyeEntityEyeball::StaticClass();
}
struct Z_Construct_UClass_AEyeEntityEyeball_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EyeEntityEyeball.h" },
		{ "ModuleRelativePath", "EyeEntityEyeball.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeEntityEyeball>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEyeEntityEyeball_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEyeCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityEyeball_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeEntityEyeball_Statics::ClassParams = {
	&AEyeEntityEyeball::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityEyeball_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeEntityEyeball_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeEntityEyeball()
{
	if (!Z_Registration_Info_UClass_AEyeEntityEyeball.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeEntityEyeball.OuterSingleton, Z_Construct_UClass_AEyeEntityEyeball_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeEntityEyeball.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeEntityEyeball>()
{
	return AEyeEntityEyeball::StaticClass();
}
AEyeEntityEyeball::AEyeEntityEyeball() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeEntityEyeball);
AEyeEntityEyeball::~AEyeEntityEyeball() {}
// End Class AEyeEntityEyeball

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeEntityEyeball, AEyeEntityEyeball::StaticClass, TEXT("AEyeEntityEyeball"), &Z_Registration_Info_UClass_AEyeEntityEyeball, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeEntityEyeball), 1145724023U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_3501738829(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
