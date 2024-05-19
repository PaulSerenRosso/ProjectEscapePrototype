// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Channel3DProperties.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChannel3DProperties() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_EAudioFadeModel();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAudioFadeModel;
	static UEnum* EAudioFadeModel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAudioFadeModel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAudioFadeModel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_EAudioFadeModel, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("EAudioFadeModel"));
		}
		return Z_Registration_Info_UEnum_EAudioFadeModel.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<EAudioFadeModel>()
	{
		return EAudioFadeModel_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enumerators[] = {
		{ "EAudioFadeModel::InverseByDistance", (int64)EAudioFadeModel::InverseByDistance },
		{ "EAudioFadeModel::LinearByDistance", (int64)EAudioFadeModel::LinearByDistance },
		{ "EAudioFadeModel::ExponentialByDistance", (int64)EAudioFadeModel::ExponentialByDistance },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n  * \\brief The distance model for a Positional ChannelType, which determines the algorithm to use when computing attenuation.\n  */" },
#endif
		{ "ExponentialByDistance.Comment", "/**\n     * \\brief Makes voice within the conversational distance louder, but fade quickly beyond it.\n     */" },
		{ "ExponentialByDistance.Name", "EAudioFadeModel::ExponentialByDistance" },
		{ "ExponentialByDistance.ToolTip", "\\brief Makes voice within the conversational distance louder, but fade quickly beyond it." },
		{ "InverseByDistance.Comment", "/**\n     * \\brief Fades voice quickly at first, buts slows down as you get further from conversational distance.\n     */" },
		{ "InverseByDistance.Name", "EAudioFadeModel::InverseByDistance" },
		{ "InverseByDistance.ToolTip", "\\brief Fades voice quickly at first, buts slows down as you get further from conversational distance." },
		{ "LinearByDistance.Comment", "/**\n     * \\brief Fades voice slowly at first, but speeds up as you get further from conversational distance.\n     */" },
		{ "LinearByDistance.Name", "EAudioFadeModel::LinearByDistance" },
		{ "LinearByDistance.ToolTip", "\\brief Fades voice slowly at first, but speeds up as you get further from conversational distance." },
		{ "ModuleRelativePath", "Public/Channel3DProperties.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The distance model for a Positional ChannelType, which determines the algorithm to use when computing attenuation." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"EAudioFadeModel",
		"EAudioFadeModel",
		Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_EAudioFadeModel()
	{
		if (!Z_Registration_Info_UEnum_EAudioFadeModel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAudioFadeModel.InnerSingleton, Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAudioFadeModel.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics::EnumInfo[] = {
		{ EAudioFadeModel_StaticEnum, TEXT("EAudioFadeModel"), &Z_Registration_Info_UEnum_EAudioFadeModel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1390945056U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_2167630576(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
