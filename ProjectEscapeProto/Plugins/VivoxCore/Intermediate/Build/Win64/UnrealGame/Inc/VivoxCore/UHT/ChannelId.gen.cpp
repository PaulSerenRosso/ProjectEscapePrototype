// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChannelId.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChannelId() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_ChannelType();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ChannelType;
	static UEnum* ChannelType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ChannelType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ChannelType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_ChannelType, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("ChannelType"));
		}
		return Z_Registration_Info_UEnum_ChannelType.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<ChannelType>()
	{
		return ChannelType_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_ChannelType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_ChannelType_Statics::Enumerators[] = {
		{ "ChannelType::NonPositional", (int64)ChannelType::NonPositional },
		{ "ChannelType::Positional", (int64)ChannelType::Positional },
		{ "ChannelType::Echo", (int64)ChannelType::Echo },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_ChannelType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief The type of channel.\n */" },
#endif
		{ "Echo.Comment", "/**\n     * \\brief A conferencing channel where the user's text and audio is echoed back to that user.\n     */" },
		{ "Echo.Name", "ChannelType::Echo" },
		{ "Echo.ToolTip", "\\brief A conferencing channel where the user's text and audio is echoed back to that user." },
		{ "ModuleRelativePath", "Public/ChannelId.h" },
		{ "NonPositional.Comment", "/**\n     * \\brief A typical conferencing channel.\n     */" },
		{ "NonPositional.Name", "ChannelType::NonPositional" },
		{ "NonPositional.ToolTip", "\\brief A typical conferencing channel." },
		{ "Positional.Comment", "/**\n     * \\brief A conferencing channel where user voices are rendered with 3D positional effects.\n     */" },
		{ "Positional.Name", "ChannelType::Positional" },
		{ "Positional.ToolTip", "\\brief A conferencing channel where user voices are rendered with 3D positional effects." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The type of channel." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_ChannelType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"ChannelType",
		"ChannelType",
		Z_Construct_UEnum_VivoxCore_ChannelType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_ChannelType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_ChannelType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_ChannelType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_ChannelType()
	{
		if (!Z_Registration_Info_UEnum_ChannelType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ChannelType.InnerSingleton, Z_Construct_UEnum_VivoxCore_ChannelType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ChannelType.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ChannelId_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ChannelId_h_Statics::EnumInfo[] = {
		{ ChannelType_StaticEnum, TEXT("ChannelType"), &Z_Registration_Info_UEnum_ChannelType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2993731626U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ChannelId_h_229738542(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ChannelId_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ChannelId_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
