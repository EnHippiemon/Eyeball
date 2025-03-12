// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/EyeGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeGameMode() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_AEyeGameMode();
EYEBALL_API UClass* Z_Construct_UClass_AEyeGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Class AEyeGameMode Function ChangeEntity
struct Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics
{
	struct EyeGameMode_eventChangeEntity_Parms
	{
		AEyeCharacter* Character;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EyeGameMode_eventChangeEntity_Parms, Character), Z_Construct_UClass_AEyeCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::NewProp_Character,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEyeGameMode, nullptr, "ChangeEntity", nullptr, nullptr, Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::EyeGameMode_eventChangeEntity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::EyeGameMode_eventChangeEntity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEyeGameMode_ChangeEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEyeGameMode_ChangeEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEyeGameMode::execChangeEntity)
{
	P_GET_OBJECT(AEyeCharacter,Z_Param_Character);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ChangeEntity(Z_Param_Character);
	P_NATIVE_END;
}
// End Class AEyeGameMode Function ChangeEntity

// Begin Class AEyeGameMode Function EjectCurrentEntity
struct Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEyeGameMode, nullptr, "EjectCurrentEntity", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEyeGameMode::execEjectCurrentEntity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EjectCurrentEntity();
	P_NATIVE_END;
}
// End Class AEyeGameMode Function EjectCurrentEntity

// Begin Class AEyeGameMode Function HandleDangerChange
struct Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics
{
	struct EyeGameMode_eventHandleDangerChange_Parms
	{
		bool bIsInDanger;
		float TimeDilationAmount;
		float MaxDangerTime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsInDanger_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInDanger;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeDilationAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDangerTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_bIsInDanger_SetBit(void* Obj)
{
	((EyeGameMode_eventHandleDangerChange_Parms*)Obj)->bIsInDanger = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_bIsInDanger = { "bIsInDanger", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EyeGameMode_eventHandleDangerChange_Parms), &Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_bIsInDanger_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_TimeDilationAmount = { "TimeDilationAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EyeGameMode_eventHandleDangerChange_Parms, TimeDilationAmount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_MaxDangerTime = { "MaxDangerTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EyeGameMode_eventHandleDangerChange_Parms, MaxDangerTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_bIsInDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_TimeDilationAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::NewProp_MaxDangerTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEyeGameMode, nullptr, "HandleDangerChange", nullptr, nullptr, Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::EyeGameMode_eventHandleDangerChange_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::EyeGameMode_eventHandleDangerChange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEyeGameMode_HandleDangerChange()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEyeGameMode_HandleDangerChange_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEyeGameMode::execHandleDangerChange)
{
	P_GET_UBOOL(Z_Param_bIsInDanger);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TimeDilationAmount);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxDangerTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDangerChange(Z_Param_bIsInDanger,Z_Param_TimeDilationAmount,Z_Param_MaxDangerTime);
	P_NATIVE_END;
}
// End Class AEyeGameMode Function HandleDangerChange

// Begin Class AEyeGameMode Function HandlePlayerDeath
struct Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEyeGameMode, nullptr, "HandlePlayerDeath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEyeGameMode::execHandlePlayerDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePlayerDeath();
	P_NATIVE_END;
}
// End Class AEyeGameMode Function HandlePlayerDeath

// Begin Class AEyeGameMode
void AEyeGameMode::StaticRegisterNativesAEyeGameMode()
{
	UClass* Class = AEyeGameMode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ChangeEntity", &AEyeGameMode::execChangeEntity },
		{ "EjectCurrentEntity", &AEyeGameMode::execEjectCurrentEntity },
		{ "HandleDangerChange", &AEyeGameMode::execHandleDangerChange },
		{ "HandlePlayerDeath", &AEyeGameMode::execHandlePlayerDeath },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeGameMode);
UClass* Z_Construct_UClass_AEyeGameMode_NoRegister()
{
	return AEyeGameMode::StaticClass();
}
struct Z_Construct_UClass_AEyeGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "EyeGameMode.h" },
		{ "ModuleRelativePath", "EyeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeDilationDanger_MetaData[] = {
		{ "Category", "EyeGameMode" },
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityEyeball_MetaData[] = {
		{ "Category", "EyeGameMode" },
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityHuman_MetaData[] = {
		{ "Category", "EyeGameMode" },
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCharacter_MetaData[] = {
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Controller_MetaData[] = {
		{ "ModuleRelativePath", "EyeGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeDilationDanger;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EntityEyeball;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EntityHuman;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Controller;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEyeGameMode_ChangeEntity, "ChangeEntity" }, // 1270892266
		{ &Z_Construct_UFunction_AEyeGameMode_EjectCurrentEntity, "EjectCurrentEntity" }, // 2284524464
		{ &Z_Construct_UFunction_AEyeGameMode_HandleDangerChange, "HandleDangerChange" }, // 2017739732
		{ &Z_Construct_UFunction_AEyeGameMode_HandlePlayerDeath, "HandlePlayerDeath" }, // 1197661568
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeGameMode_Statics::NewProp_TimeDilationDanger = { "TimeDilationDanger", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeGameMode, TimeDilationDanger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeDilationDanger_MetaData), NewProp_TimeDilationDanger_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEyeGameMode_Statics::NewProp_EntityEyeball = { "EntityEyeball", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeGameMode, EntityEyeball), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityEyeball_MetaData), NewProp_EntityEyeball_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEyeGameMode_Statics::NewProp_EntityHuman = { "EntityHuman", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeGameMode, EntityHuman), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityHuman_MetaData), NewProp_EntityHuman_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeGameMode_Statics::NewProp_PlayerCharacter = { "PlayerCharacter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeGameMode, PlayerCharacter), Z_Construct_UClass_AEyeCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCharacter_MetaData), NewProp_PlayerCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeGameMode_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeGameMode, Controller), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Controller_MetaData), NewProp_Controller_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeGameMode_Statics::NewProp_TimeDilationDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeGameMode_Statics::NewProp_EntityEyeball,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeGameMode_Statics::NewProp_EntityHuman,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeGameMode_Statics::NewProp_PlayerCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeGameMode_Statics::NewProp_Controller,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEyeGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeGameMode_Statics::ClassParams = {
	&AEyeGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEyeGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEyeGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeGameMode()
{
	if (!Z_Registration_Info_UClass_AEyeGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeGameMode.OuterSingleton, Z_Construct_UClass_AEyeGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeGameMode.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeGameMode>()
{
	return AEyeGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeGameMode);
AEyeGameMode::~AEyeGameMode() {}
// End Class AEyeGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeGameMode, AEyeGameMode::StaticClass, TEXT("AEyeGameMode"), &Z_Registration_Info_UClass_AEyeGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeGameMode), 3189258037U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeGameMode_h_2131180605(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
