// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eyeball/EyeCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeCharacter() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter();
EYEBALL_API UClass* Z_Construct_UClass_AEyeCharacter_NoRegister();
EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature();
EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature();
EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature();
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
		{ "ModuleRelativePath", "EyeCharacter.h" },
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
		{ "ModuleRelativePath", "EyeCharacter.h" },
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

// Begin Delegate FOnDeath
struct Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Eyeball, nullptr, "OnDeath__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnDeath_DelegateWrapper(const FMulticastScriptDelegate& OnDeath)
{
	OnDeath.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnDeath

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
		{ "ModuleRelativePath", "EyeCharacter.h" },
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
		{ "IncludePath", "EyeCharacter.h" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterChanged_MetaData[] = {
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnEject_MetaData[] = {
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDeath_MetaData[] = {
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDangerChanged_MetaData[] = {
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalMovementSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Movement */" },
#endif
		{ "ModuleRelativePath", "EyeCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxTimeInDanger_MetaData[] = {
		{ "Category", "Danger" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Danger */" },
#endif
		{ "ModuleRelativePath", "EyeCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Danger" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeDilationDanger_MetaData[] = {
		{ "Category", "Danger" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeldJumpThreshold_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Jump */" },
#endif
		{ "ModuleRelativePath", "EyeCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpDirection_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpForce_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxJumpCount_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RadiusFloorCheck_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LengthFloorCheck_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetFloorCheck_MetaData[] = {
		{ "Category", "Jump" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetActorPlacement_MetaData[] = {
		{ "Category", "Positioning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Positioning */" },
#endif
		{ "ModuleRelativePath", "EyeCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Positioning" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SafeZone_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityBody_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "EyeCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Floor_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Would be cool to make a character that can walk on other surfaces.\n// If so, make it protected. \n" },
#endif
		{ "ModuleRelativePath", "EyeCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Would be cool to make a character that can walk on other surfaces.\nIf so, make it protected." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEject;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDeath;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDangerChanged;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalMovementSpeed;
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
		TCppClassTypeTraits<AEyeCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnCharacterChanged = { "OnCharacterChanged", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnCharacterChanged), Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterChanged_MetaData), NewProp_OnCharacterChanged_MetaData) }; // 3869976157
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnEject = { "OnEject", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnEject), Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnEject_MetaData), NewProp_OnEject_MetaData) }; // 4005566352
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnDeath = { "OnDeath", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnDeath), Z_Construct_UDelegateFunction_Eyeball_OnDeath__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDeath_MetaData), NewProp_OnDeath_MetaData) }; // 3967545141
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnDangerChanged = { "OnDangerChanged", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OnDangerChanged), Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDangerChanged_MetaData), NewProp_OnDangerChanged_MetaData) }; // 3079858746
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_NormalMovementSpeed = { "NormalMovementSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, NormalMovementSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalMovementSpeed_MetaData), NewProp_NormalMovementSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_MaxTimeInDanger = { "MaxTimeInDanger", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, MaxTimeInDanger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxTimeInDanger_MetaData), NewProp_MaxTimeInDanger_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_TimeDilationDanger = { "TimeDilationDanger", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, TimeDilationDanger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeDilationDanger_MetaData), NewProp_TimeDilationDanger_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_HeldJumpThreshold = { "HeldJumpThreshold", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, HeldJumpThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeldJumpThreshold_MetaData), NewProp_HeldJumpThreshold_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_JumpDirection = { "JumpDirection", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, JumpDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpDirection_MetaData), NewProp_JumpDirection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_JumpForce = { "JumpForce", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, JumpForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpForce_MetaData), NewProp_JumpForce_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_MaxJumpCount = { "MaxJumpCount", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, MaxJumpCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxJumpCount_MetaData), NewProp_MaxJumpCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_RadiusFloorCheck = { "RadiusFloorCheck", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, RadiusFloorCheck), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RadiusFloorCheck_MetaData), NewProp_RadiusFloorCheck_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_LengthFloorCheck = { "LengthFloorCheck", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, LengthFloorCheck), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LengthFloorCheck_MetaData), NewProp_LengthFloorCheck_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OffsetFloorCheck = { "OffsetFloorCheck", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OffsetFloorCheck), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetFloorCheck_MetaData), NewProp_OffsetFloorCheck_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OffsetActorPlacement = { "OffsetActorPlacement", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, OffsetActorPlacement), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetActorPlacement_MetaData), NewProp_OffsetActorPlacement_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_SafeZone = { "SafeZone", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, SafeZone), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SafeZone_MetaData), NewProp_SafeZone_MetaData) }; // 756624936
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_EntityBody = { "EntityBody", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, EntityBody), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityBody_MetaData), NewProp_EntityBody_MetaData) }; // 756624936
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AEyeCharacter_Statics::NewProp_Floor = { "Floor", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEyeCharacter, Floor), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Floor_MetaData), NewProp_Floor_MetaData) }; // 756624936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEyeCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnCharacterChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnEject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnDeath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OnDangerChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_NormalMovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_MaxTimeInDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_TimeDilationDanger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_HeldJumpThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_JumpDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_JumpForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_MaxJumpCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_RadiusFloorCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_LengthFloorCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OffsetFloorCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_OffsetActorPlacement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_SafeZone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_EntityBody,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEyeCharacter_Statics::NewProp_Floor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEyeCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEyeCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
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
struct Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEyeCharacter, AEyeCharacter::StaticClass, TEXT("AEyeCharacter"), &Z_Registration_Info_UClass_AEyeCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEyeCharacter), 3894295189U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeCharacter_h_1647559852(TEXT("/Script/Eyeball"),
	Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_EyeCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
