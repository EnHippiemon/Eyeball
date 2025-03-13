// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PuzzleComponents/EyeMoveableObject.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef EYEBALL_EyeMoveableObject_generated_h
#error "EyeMoveableObject.generated.h already included, missing '#pragma once' in EyeMoveableObject.h"
#endif
#define EYEBALL_EyeMoveableObject_generated_h

#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleEndOverlap); \
	DECLARE_FUNCTION(execHandleBeginOverlap);


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEyeMoveableObject(); \
	friend struct Z_Construct_UClass_AEyeMoveableObject_Statics; \
public: \
	DECLARE_CLASS(AEyeMoveableObject, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Eyeball"), NO_API) \
	DECLARE_SERIALIZER(AEyeMoveableObject)


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEyeMoveableObject(AEyeMoveableObject&&); \
	AEyeMoveableObject(const AEyeMoveableObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEyeMoveableObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEyeMoveableObject); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEyeMoveableObject) \
	NO_API virtual ~AEyeMoveableObject();


#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_10_PROLOG
#define FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EYEBALL_API UClass* StaticClass<class AEyeMoveableObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_albin_samuelsson_Desktop_GitHub_Eyeball_Eyeball_Source_Eyeball_PuzzleComponents_EyeMoveableObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
