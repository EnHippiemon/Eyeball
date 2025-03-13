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
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeMoveableObject();
EYEBALL_API UClass* Z_Construct_UClass_AEyeMoveableObject_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveDirection_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// bool bIsActivated = false;\n" },
#endif
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "bool bIsActivated = false;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetOffset_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnToStartLocation_MetaData[] = {
		{ "Category", "EyeMoveableObject" },
		{ "ModuleRelativePath", "PuzzleComponents/EyeMoveableObject.h" },
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveDirection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetOffset;
	static void NewProp_ReturnToStartLocation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnToStartLocation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Box;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionBox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeMoveableObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_MoveDirection = { "MoveDirection", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, MoveDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveDirection_MetaData), NewProp_MoveDirection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSpeed_MetaData), NewProp_MoveSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_TargetOffset = { "TargetOffset", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, TargetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetOffset_MetaData), NewProp_TargetOffset_MetaData) };
void Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_ReturnToStartLocation_SetBit(void* Obj)
{
	((AEyeMoveableObject*)Obj)->ReturnToStartLocation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_ReturnToStartLocation = { "ReturnToStartLocation", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEyeMoveableObject), &Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_ReturnToStartLocation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnToStartLocation_MetaData), NewProp_ReturnToStartLocation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Box_MetaData), NewProp_Box_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_CollisionBox = { "CollisionBox", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeMoveableObject, CollisionBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionBox_MetaData), NewProp_CollisionBox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeMoveableObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_MoveDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_MoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_TargetOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeMoveableObject_Statics::NewProp_ReturnToStartLocation,
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
		{ Z_Construct_UClass_AEyeMoveableObject, AEyeMoveableObject::StaticClass, TEXT("AEyeMoveableObject"), &Z_Registration_Info_UClass_AEyeMoveableObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeMoveableObject), 4163431170U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_3819781608(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
