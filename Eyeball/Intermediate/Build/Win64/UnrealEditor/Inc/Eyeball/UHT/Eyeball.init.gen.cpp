// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEyeball_init() {}
	EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature();
	EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature();
	EYEBALL_API UFunction* Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Eyeball;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Eyeball()
	{
		if (!Z_Registration_Info_UPackage__Script_Eyeball.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Eyeball_OnCharacterChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Eyeball_OnDangerChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Eyeball_OnEject__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Eyeball",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xCA4EE0A7,
				0x3052884E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Eyeball.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Eyeball.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Eyeball(Z_Construct_UPackage__Script_Eyeball, TEXT("/Script/Eyeball"), Z_Registration_Info_UPackage__Script_Eyeball, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xCA4EE0A7, 0x3052884E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
