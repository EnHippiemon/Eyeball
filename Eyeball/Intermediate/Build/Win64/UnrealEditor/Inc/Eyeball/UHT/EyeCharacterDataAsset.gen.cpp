// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/DataAssets/EyeCharacterDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeCharacterDataAsset() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
EYEBALL_API UClass* Z_Construct_UClass_UEyeCharacterDataAsset();
EYEBALL_API UClass* Z_Construct_UClass_UEyeCharacterDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class UEyeCharacterDataAsset
void UEyeCharacterDataAsset::StaticRegisterNativesUEyeCharacterDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEyeCharacterDataAsset);
UClass* Z_Construct_UClass_UEyeCharacterDataAsset_NoRegister()
{
	return UEyeCharacterDataAsset::StaticClass();
}
struct Z_Construct_UClass_UEyeCharacterDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DataAssets/EyeCharacterDataAsset.h" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalMovementSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Movement */" },
#endif
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighMovementSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxTimeInDanger_MetaData[] = {
		{ "Category", "Danger" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Danger */" },
#endif
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Danger" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeDilationDanger_MetaData[] = {
		{ "Category", "Danger" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeldJumpThreshold_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Jump */" },
#endif
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpDirection_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpForce_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxJumpCount_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RadiusFloorCheck_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LengthFloorCheck_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetFloorCheck_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetActorPlacement_MetaData[] = {
		{ "Category", "Positioning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Positioning */" },
#endif
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Positioning" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SafeZone_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Collisions */" },
#endif
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collisions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityBody_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Floor_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "DataAssets/EyeCharacterDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalMovementSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HighMovementSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxTimeInDanger;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeDilationDanger;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HeldJumpThreshold;
	static const UECodeGen_Private::FStructPropertyParams NewProp_JumpDirection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpForce;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxJumpCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RadiusFloorCheck;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LengthFloorCheck;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OffsetFloorCheck;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OffsetActorPlacement;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SafeZone;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EntityBody;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Floor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEyeCharacterDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_NormalMovementSpeed = { "NormalMovementSpeed", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, NormalMovementSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalMovementSpeed_MetaData), NewProp_NormalMovementSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_HighMovementSpeed = { "HighMovementSpeed", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, HighMovementSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighMovementSpeed_MetaData), NewProp_HighMovementSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_MaxTimeInDanger = { "MaxTimeInDanger", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, MaxTimeInDanger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxTimeInDanger_MetaData), NewProp_MaxTimeInDanger_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_TimeDilationDanger = { "TimeDilationDanger", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, TimeDilationDanger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeDilationDanger_MetaData), NewProp_TimeDilationDanger_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_HeldJumpThreshold = { "HeldJumpThreshold", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, HeldJumpThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeldJumpThreshold_MetaData), NewProp_HeldJumpThreshold_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_JumpDirection = { "JumpDirection", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, JumpDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpDirection_MetaData), NewProp_JumpDirection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_JumpForce = { "JumpForce", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, JumpForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpForce_MetaData), NewProp_JumpForce_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_MaxJumpCount = { "MaxJumpCount", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, MaxJumpCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxJumpCount_MetaData), NewProp_MaxJumpCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_RadiusFloorCheck = { "RadiusFloorCheck", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, RadiusFloorCheck), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RadiusFloorCheck_MetaData), NewProp_RadiusFloorCheck_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_LengthFloorCheck = { "LengthFloorCheck", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, LengthFloorCheck), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LengthFloorCheck_MetaData), NewProp_LengthFloorCheck_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_OffsetFloorCheck = { "OffsetFloorCheck", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, OffsetFloorCheck), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetFloorCheck_MetaData), NewProp_OffsetFloorCheck_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_OffsetActorPlacement = { "OffsetActorPlacement", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, OffsetActorPlacement), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetActorPlacement_MetaData), NewProp_OffsetActorPlacement_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_SafeZone = { "SafeZone", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, SafeZone), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SafeZone_MetaData), NewProp_SafeZone_MetaData) }; // 756624936
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_EntityBody = { "EntityBody", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, EntityBody), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityBody_MetaData), NewProp_EntityBody_MetaData) }; // 756624936
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_Floor = { "Floor", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEyeCharacterDataAsset, Floor), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Floor_MetaData), NewProp_Floor_MetaData) }; // 756624936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEyeCharacterDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_NormalMovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_HighMovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_MaxTimeInDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_TimeDilationDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_HeldJumpThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_JumpDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_JumpForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_MaxJumpCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_RadiusFloorCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_LengthFloorCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_OffsetFloorCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_OffsetActorPlacement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_SafeZone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_EntityBody,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEyeCharacterDataAsset_Statics::NewProp_Floor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEyeCharacterDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEyeCharacterDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEyeCharacterDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEyeCharacterDataAsset_Statics::ClassParams = {
	&UEyeCharacterDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEyeCharacterDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEyeCharacterDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEyeCharacterDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UEyeCharacterDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEyeCharacterDataAsset()
{
	if (!Z_Registration_Info_UClass_UEyeCharacterDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEyeCharacterDataAsset.OuterSingleton, Z_Construct_UClass_UEyeCharacterDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEyeCharacterDataAsset.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<UEyeCharacterDataAsset>()
{
	return UEyeCharacterDataAsset::StaticClass();
}
UEyeCharacterDataAsset::UEyeCharacterDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEyeCharacterDataAsset);
UEyeCharacterDataAsset::~UEyeCharacterDataAsset() {}
// End Class UEyeCharacterDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeCharacterDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEyeCharacterDataAsset, UEyeCharacterDataAsset::StaticClass, TEXT("UEyeCharacterDataAsset"), &Z_Registration_Info_UClass_UEyeCharacterDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEyeCharacterDataAsset), 2073074116U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeCharacterDataAsset_h_2650511470(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeCharacterDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_DataAssets_EyeCharacterDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
