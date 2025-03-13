// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/Entities/EyeCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter_NoRegister();
EYEBALL_API UClass* Z_Construct_UClass_UEyeCharacterDataAsset_NoRegister();
EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature();
EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature();
EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_Eyeball();
// End Cross Module References

// Begin Delegate FOnCharacterChanged
struct Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics
{
	struct _Script_Eyeball_eventOnCharacterChanged_Parms
	{
		AEyeCharacter* Character;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Eyeball_eventOnCharacterChanged_Parms, Character), Z_Construct_UClass_AEyeCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::NewProp_Character,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Eyeball, nullptr, "OnCharacterChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::_Script_Eyeball_eventOnCharacterChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::_Script_Eyeball_eventOnCharacterChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterChanged_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterChanged, AEyeCharacter* Character)
{
	struct _Script_Eyeball_eventOnCharacterChanged_Parms
	{
		AEyeCharacter* Character;
	};
	_Script_Eyeball_eventOnCharacterChanged_Parms Parms;
	Parms.Character=Character;
	OnCharacterChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnCharacterChanged

// Begin Delegate FOnEject
struct Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Eyeball, nullptr, "OnEject__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnEject_DelegateWrapper(const FMulticastScriptDelegate& OnEject)
{
	OnEject.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnEject

// Begin Delegate FOnDangerChanged
struct Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics
{
	struct _Script_Eyeball_eventOnDangerChanged_Parms
	{
		bool IsInDanger;
		float TimeDilationAmount;
		float MaxDangerTime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
#endif // WITH_METADATA
	static void NewProp_IsInDanger_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsInDanger;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeDilationAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDangerTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_IsInDanger_SetBit(void* Obj)
{
	((_Script_Eyeball_eventOnDangerChanged_Parms*)Obj)->IsInDanger = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_IsInDanger = { "IsInDanger", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Eyeball_eventOnDangerChanged_Parms), &Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_IsInDanger_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_TimeDilationAmount = { "TimeDilationAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Eyeball_eventOnDangerChanged_Parms, TimeDilationAmount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_MaxDangerTime = { "MaxDangerTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Eyeball_eventOnDangerChanged_Parms, MaxDangerTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_IsInDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_TimeDilationAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::NewProp_MaxDangerTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Eyeball, nullptr, "OnDangerChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::_Script_Eyeball_eventOnDangerChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::_Script_Eyeball_eventOnDangerChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnDangerChanged_DelegateWrapper(const FMulticastScriptDelegate& OnDangerChanged, bool IsInDanger, float TimeDilationAmount, float MaxDangerTime)
{
	struct _Script_Eyeball_eventOnDangerChanged_Parms
	{
		bool IsInDanger;
		float TimeDilationAmount;
		float MaxDangerTime;
	};
	_Script_Eyeball_eventOnDangerChanged_Parms Parms;
	Parms.IsInDanger=IsInDanger ? true : false;
	Parms.TimeDilationAmount=TimeDilationAmount;
	Parms.MaxDangerTime=MaxDangerTime;
	OnDangerChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDangerChanged

// Begin Class AEyeCharacter
void AEyeCharacter::StaticRegisterNativesAEyeCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEyeCharacter);
UClass* Z_Construct_UClass_AEyeCharacter_NoRegister()
{
	return AEyeCharacter::StaticClass();
}
struct Z_Construct_UClass_AEyeCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/EyeCharacter.h" },
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterChanged_MetaData[] = {
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnEject_MetaData[] = {
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDangerChanged_MetaData[] = {
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityData_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "DataAsset" },
		{ "ModuleRelativePath", "Entities/EyeCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEject;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDangerChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntityData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEyeCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnCharacterChanged = { "OnCharacterChanged", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnCharacterChanged), Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterChanged_MetaData), NewProp_OnCharacterChanged_MetaData) }; // 3187667202
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnEject = { "OnEject", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnEject), Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnEject_MetaData), NewProp_OnEject_MetaData) }; // 3402013746
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnDangerChanged = { "OnDangerChanged", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnDangerChanged), Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDangerChanged_MetaData), NewProp_OnDangerChanged_MetaData) }; // 1157825587
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_EntityData = { "EntityData", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, EntityData), Z_Construct_UClass_UEyeCharacterDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityData_MetaData), NewProp_EntityData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnCharacterChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnEject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnDangerChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_EntityData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEyeCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Eyeball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEyeCharacter_Statics::ClassParams = {
	&AEyeCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEyeCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEyeCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AEyeCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEyeCharacter()
{
	if (!Z_Registration_Info_UClass_AEyeCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEyeCharacter.OuterSingleton, Z_Construct_UClass_AEyeCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEyeCharacter.OuterSingleton;
}
template<> EYEBALL_API UClass* StaticClass<AEyeCharacter>()
{
	return AEyeCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEyeCharacter);
AEyeCharacter::~AEyeCharacter() {}
// End Class AEyeCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeCharacter, AEyeCharacter::StaticClass, TEXT("AEyeCharacter"), &Z_Registration_Info_UClass_AEyeCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeCharacter), 3170715664U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_2050417412(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
