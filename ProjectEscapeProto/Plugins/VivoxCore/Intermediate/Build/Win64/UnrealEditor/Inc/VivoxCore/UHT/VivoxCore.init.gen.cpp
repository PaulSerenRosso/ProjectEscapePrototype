// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVivoxCore_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VivoxCore;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VivoxCore()
	{
		if (!Z_Registration_Info_UPackage__Script_VivoxCore.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VivoxCore",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x794AB71B,
				0x3989AFEB,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VivoxCore.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VivoxCore.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VivoxCore(Z_Construct_UPackage__Script_VivoxCore, TEXT("/Script/VivoxCore"), Z_Registration_Info_UPackage__Script_VivoxCore, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x794AB71B, 0x3989AFEB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
