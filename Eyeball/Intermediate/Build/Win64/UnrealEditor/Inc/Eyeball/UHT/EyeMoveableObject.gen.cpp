// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/PuzzleComponents/EyeMoveableObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeMoveableObject() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeMoveableObject();
EYEBALL_API UClass* Z_Construct_UClass_AEyeMoveableObject_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_UEyeMoveableObjectDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class AEyeMoveableObject
void AEyeMoveableObject::StaticRegisterNativesAEyeMoveableObject()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeMoveableObject);
UClass* Z_Construct_UClass_AEyeMoveableObject_NoRegister()
{
	return AEyeMoveableObject::StaticClass();
}
struct Z_Construct_UClass_AEyeMoveableObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PuzzleComponents/EyeMoveableObject.h" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectData_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY(EditAnywhere)\n// FVector MoveDirection;\n// UPROPERTY(EditAnywhere)\n// float MoveSpeed;\n// UPROPERTY(EditAnywhere)\n// FVector TargetOffset;\n// UPROPERTY(EditAnywhere)\n// bool ReturnToStartLocation;\n" },
#endif
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere)\nFVector MoveDirection;\nUPROPERTY(EditAnywhere)\nfloat MoveSpeed;\nUPROPERTY(EditAnywhere)\nFVector TargetOffset;\nUPROPERTY(EditAnywhere)\nbool ReturnToStartLocation;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionBox_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Box;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionBox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeMoveableObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_ObjectData = { "ObjectData", nullptr, (EPropertyFlags)0x0040000000000801, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, ObjectData), Z_Construct_UClass_UEyeMoveableObjectDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectData_MetaData), NewProp_ObjectData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Box_MetaData), NewProp_Box_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_CollisionBox = { "CollisionBox", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, CollisionBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionBox_MetaData), NewProp_CollisionBox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeMoveableObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_ObjectData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_Box,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_CollisionBox,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeMoveableObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEyeMoveableObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeMoveableObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeMoveableObject_Statics::ClassParams = {
	&AEyeMoveableObject::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEyeMoveableObject_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEyeMoveableObject_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeMoveableObject_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeMoveableObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeMoveableObject()
{
	if (!Z_Registration_Info_UClass_AEyeMoveableObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeMoveableObject.OuterSingleton, Z_Construct_UClass_AEyeMoveableObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeMoveableObject.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeMoveableObject>()
{
	return AEyeMoveableObject::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeMoveableObject);
AEyeMoveableObject::~AEyeMoveableObject() {}
// End Class AEyeMoveableObject

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeMoveableObject, AEyeMoveableObject::StaticClass, TEXT("AEyeMoveableObject"), &Z_Registration_Info_UClass_AEyeMoveableObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeMoveableObject), 3099136130U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_4010654188(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
