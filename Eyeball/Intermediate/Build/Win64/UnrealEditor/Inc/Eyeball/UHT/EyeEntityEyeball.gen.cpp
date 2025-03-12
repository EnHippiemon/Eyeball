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
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FoundActor_MetaData[] = {
		{ "ModuleRelativePath", "EyeEntityEyeball.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FoundEntity_MetaData[] = {
		{ "ModuleRelativePath", "EyeEntityEyeball.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereComponent_MetaData[] = {
		{ "Category", "EyeEntityEyeball" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EyeEntityEyeball.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FoundActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FoundEntity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeEntityEyeball>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeEntityEyeball_Statics::NewProp_FoundActor = { "FoundActor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeEntityEyeball, FoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FoundActor_MetaData), NewProp_FoundActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeEntityEyeball_Statics::NewProp_FoundEntity = { "FoundEntity", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeEntityEyeball, FoundEntity), Z_Construct_UClass_AEyeCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FoundEntity_MetaData), NewProp_FoundEntity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeEntityEyeball_Statics::NewProp_SphereComponent = { "SphereComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeEntityEyeball, SphereComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereComponent_MetaData), NewProp_SphereComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeEntityEyeball_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeEntityEyeball_Statics::NewProp_FoundActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeEntityEyeball_Statics::NewProp_FoundEntity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeEntityEyeball_Statics::NewProp_SphereComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityEyeball_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AEyeEntityEyeball_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEyeEntityEyeball_Statics::PropPointers),
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
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeEntityEyeball);
AEyeEntityEyeball::~AEyeEntityEyeball() {}
// End Class AEyeEntityEyeball

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeEntityEyeball, AEyeEntityEyeball::StaticClass, TEXT("AEyeEntityEyeball"), &Z_Registration_Info_UClass_AEyeEntityEyeball, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeEntityEyeball), 2265951291U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_3751830128(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeEntityEyeball_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
