// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Presence.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePresence() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_PresenceStatus();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_PresenceStatus;
	static UEnum* PresenceStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_PresenceStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_PresenceStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_PresenceStatus, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("PresenceStatus"));
		}
		return Z_Registration_Info_UEnum_PresenceStatus.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<PresenceStatus>()
	{
		return PresenceStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::Enumerators[] = {
		{ "PresenceStatus::Unavailable", (int64)PresenceStatus::Unavailable },
		{ "PresenceStatus::Available", (int64)PresenceStatus::Available },
		{ "PresenceStatus::Chat", (int64)PresenceStatus::Chat },
		{ "PresenceStatus::DoNotDisturb", (int64)PresenceStatus::DoNotDisturb },
		{ "PresenceStatus::Away", (int64)PresenceStatus::Away },
		{ "PresenceStatus::ExtendedAway", (int64)PresenceStatus::ExtendedAway },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::Enum_MetaDataParams[] = {
		{ "Available.Comment", "/**\n    * \\brief Generally available.\n    */" },
		{ "Available.Name", "PresenceStatus::Available" },
		{ "Available.ToolTip", "\\brief Generally available." },
		{ "Away.Comment", "/**\n    * \\brief Away.\n    */" },
		{ "Away.Name", "PresenceStatus::Away" },
		{ "Away.ToolTip", "\\brief Away." },
		{ "BlueprintType", "true" },
		{ "Chat.Comment", "/**\n    * \\brief Available to chat.\n    */" },
		{ "Chat.Name", "PresenceStatus::Chat" },
		{ "Chat.ToolTip", "\\brief Available to chat." },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n* \\brief The online status of the user.\n*/" },
#endif
		{ "DoNotDisturb.Comment", "/**\n    * \\brief Do Not Disturb.\n    */" },
		{ "DoNotDisturb.Name", "PresenceStatus::DoNotDisturb" },
		{ "DoNotDisturb.ToolTip", "\\brief Do Not Disturb." },
		{ "ExtendedAway.Comment", "/**\n    * \\brief Away for an extended period of time.\n    */" },
		{ "ExtendedAway.Name", "PresenceStatus::ExtendedAway" },
		{ "ExtendedAway.ToolTip", "\\brief Away for an extended period of time." },
		{ "ModuleRelativePath", "Public/Presence.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The online status of the user." },
#endif
		{ "Unavailable.Comment", "/**\n    * \\brief Not available (offline).\n    */" },
		{ "Unavailable.Name", "PresenceStatus::Unavailable" },
		{ "Unavailable.ToolTip", "\\brief Not available (offline)." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"PresenceStatus",
		"PresenceStatus",
		Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_PresenceStatus()
	{
		if (!Z_Registration_Info_UEnum_PresenceStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_PresenceStatus.InnerSingleton, Z_Construct_UEnum_VivoxCore_PresenceStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_PresenceStatus.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Presence_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Presence_h_Statics::EnumInfo[] = {
		{ PresenceStatus_StaticEnum, TEXT("PresenceStatus"), &Z_Registration_Info_UEnum_PresenceStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 756748522U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Presence_h_172448099(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Presence_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_Presence_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
