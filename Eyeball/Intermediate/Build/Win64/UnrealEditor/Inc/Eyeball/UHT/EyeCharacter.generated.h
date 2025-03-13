// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Entities/EyeCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AEyeCharacter;
#ifdef EYEBALL_EyeCharacter_generated_h
#error "EyeCharacter.generated.h already included, missing '#pragma once' in EyeCharacter.h"
#endif
#define EYEBALL_EyeCharacter_generated_h

#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_7_DELEGATE \
EYEBALL_API void FOnCharacterChanged_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterChanged, AEyeCharacter* Character);


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_8_DELEGATE \
EYEBALL_API void FOnEject_DelegateWrapper(const FMulticastScriptDelegate& OnEject);


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_9_DELEGATE \
EYEBALL_API void FOnDangerChanged_DelegateWrapper(const FMulticastScriptDelegate& OnDangerChanged, bool IsInDanger, float TimeDilationAmount, float MaxDangerTime);


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_10_DELEGATE \
EYEBALL_API void FOnDeath_DelegateWrapper(const FMulticastScriptDelegate& OnDeath);


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEyeCharacter(); \
	friend struct Z_Construct_UClass_AEyeCharacter_Statics; \
public: \
	DECLARE_CLASS(AEyeCharacter, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Eyeball"), NO_API) \
	DECLARE_SERIALIZER(AEyeCharacter)


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEyeCharacter(AEyeCharacter&&); \
	AEyeCharacter(const AEyeCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEyeCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEyeCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEyeCharacter) \
	NO_API virtual ~AEyeCharacter();


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_15_PROLOG
#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EYEBALL_API UClass* StaticClass<class AEyeCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_Entities_EyeCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
