// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ITTSMessage.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeITTSMessage() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_TTSDestination();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_TTSMessageState();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_TTSDestination;
	static UEnum* TTSDestination_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_TTSDestination.OuterSingleton)
		{
			Z_Registration_Info_UEnum_TTSDestination.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_TTSDestination, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("TTSDestination"));
		}
		return Z_Registration_Info_UEnum_TTSDestination.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<TTSDestination>()
	{
		return TTSDestination_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_TTSDestination_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::Enumerators[] = {
		{ "TTSDestination::Default", (int64)TTSDestination::Default },
		{ "TTSDestination::RemoteTransmission", (int64)TTSDestination::RemoteTransmission },
		{ "TTSDestination::LocalPlayback", (int64)TTSDestination::LocalPlayback },
		{ "TTSDestination::RemoteTransmissionWithLocalPlayback", (int64)TTSDestination::RemoteTransmissionWithLocalPlayback },
		{ "TTSDestination::QueuedRemoteTransmission", (int64)TTSDestination::QueuedRemoteTransmission },
		{ "TTSDestination::QueuedLocalPlayback", (int64)TTSDestination::QueuedLocalPlayback },
		{ "TTSDestination::QueuedRemoteTransmissionWithLocalPlayback", (int64)TTSDestination::QueuedRemoteTransmissionWithLocalPlayback },
		{ "TTSDestination::ScreenReader", (int64)TTSDestination::ScreenReader },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief A unified selection of output stream and mechanism for text-to-speech (TTS) injection.\n */" },
#endif
		{ "Default.Comment", "/**\n     * \\brief Do not use. This is only defined to work around a bug in UnrealBuildTool.\n     */" },
		{ "Default.Name", "TTSDestination::Default" },
		{ "Default.ToolTip", "\\brief Do not use. This is only defined to work around a bug in UnrealBuildTool." },
		{ "LocalPlayback.Comment", "/**\n     * \\brief Immediately play back locally on a render device (for example, speaker hardware). Mixes new messages with any other ongoing messages.\n     */" },
		{ "LocalPlayback.Name", "TTSDestination::LocalPlayback" },
		{ "LocalPlayback.ToolTip", "\\brief Immediately play back locally on a render device (for example, speaker hardware). Mixes new messages with any other ongoing messages." },
		{ "ModuleRelativePath", "Public/ITTSMessage.h" },
		{ "QueuedLocalPlayback.Comment", "/**\n     * \\brief Play back locally on a render device (for example, speaker hardware), or enqueue if there is already an ongoing message playing in this destination.\n     */" },
		{ "QueuedLocalPlayback.Name", "TTSDestination::QueuedLocalPlayback" },
		{ "QueuedLocalPlayback.ToolTip", "\\brief Play back locally on a render device (for example, speaker hardware), or enqueue if there is already an ongoing message playing in this destination." },
		{ "QueuedRemoteTransmission.Comment", "/**\n     * \\brief Send to participants in connected sessions, or enqueue if there is already an ongoing message playing in this destination.\n     */" },
		{ "QueuedRemoteTransmission.Name", "TTSDestination::QueuedRemoteTransmission" },
		{ "QueuedRemoteTransmission.ToolTip", "\\brief Send to participants in connected sessions, or enqueue if there is already an ongoing message playing in this destination." },
		{ "QueuedRemoteTransmissionWithLocalPlayback.Comment", "/**\n     * \\brief Play back locally on a render device and send to participants in connected sessions. Enqueue if there is already an ongoing message playing in this destination.\n     */" },
		{ "QueuedRemoteTransmissionWithLocalPlayback.Name", "TTSDestination::QueuedRemoteTransmissionWithLocalPlayback" },
		{ "QueuedRemoteTransmissionWithLocalPlayback.ToolTip", "\\brief Play back locally on a render device and send to participants in connected sessions. Enqueue if there is already an ongoing message playing in this destination." },
		{ "RemoteTransmission.Comment", "/**\n     * \\brief Immediately send to participants in connected sessions. Mixes new messages with any other ongoing messages.\n     */" },
		{ "RemoteTransmission.Name", "TTSDestination::RemoteTransmission" },
		{ "RemoteTransmission.ToolTip", "\\brief Immediately send to participants in connected sessions. Mixes new messages with any other ongoing messages." },
		{ "RemoteTransmissionWithLocalPlayback.Comment", "/**\n     * \\brief Immediately play back locally on a render device and send to participants in connected sessions. Mixes new messages with any other ongoing messages.\n     */" },
		{ "RemoteTransmissionWithLocalPlayback.Name", "TTSDestination::RemoteTransmissionWithLocalPlayback" },
		{ "RemoteTransmissionWithLocalPlayback.ToolTip", "\\brief Immediately play back locally on a render device and send to participants in connected sessions. Mixes new messages with any other ongoing messages." },
		{ "ScreenReader.Comment", "/**\n     * \\brief Immediately play back locally on a render device (for example, speaker hardware). Replaces the currently playing message in this destination.\n     */" },
		{ "ScreenReader.Name", "TTSDestination::ScreenReader" },
		{ "ScreenReader.ToolTip", "\\brief Immediately play back locally on a render device (for example, speaker hardware). Replaces the currently playing message in this destination." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief A unified selection of output stream and mechanism for text-to-speech (TTS) injection." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"TTSDestination",
		"TTSDestination",
		Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_TTSDestination()
	{
		if (!Z_Registration_Info_UEnum_TTSDestination.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_TTSDestination.InnerSingleton, Z_Construct_UEnum_VivoxCore_TTSDestination_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_TTSDestination.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_TTSMessageState;
	static UEnum* TTSMessageState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_TTSMessageState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_TTSMessageState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_TTSMessageState, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("TTSMessageState"));
		}
		return Z_Registration_Info_UEnum_TTSMessageState.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<TTSMessageState>()
	{
		return TTSMessageState_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::Enumerators[] = {
		{ "TTSMessageState::Playing", (int64)TTSMessageState::Playing },
		{ "TTSMessageState::Enqueued", (int64)TTSMessageState::Enqueued },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief The state of the TTSMessage.\n */" },
#endif
		{ "Enqueued.Comment", "/**\n     * \\brief The message is waiting to be played in its destination.\n     */" },
		{ "Enqueued.Name", "TTSMessageState::Enqueued" },
		{ "Enqueued.ToolTip", "\\brief The message is waiting to be played in its destination." },
		{ "ModuleRelativePath", "Public/ITTSMessage.h" },
		{ "Playing.Comment", "/**\n     * \\brief The message is currently being played in its destination.\n     */" },
		{ "Playing.Name", "TTSMessageState::Playing" },
		{ "Playing.ToolTip", "\\brief The message is currently being played in its destination." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The state of the TTSMessage." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"TTSMessageState",
		"TTSMessageState",
		Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_TTSMessageState()
	{
		if (!Z_Registration_Info_UEnum_TTSMessageState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_TTSMessageState.InnerSingleton, Z_Construct_UEnum_VivoxCore_TTSMessageState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_TTSMessageState.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ITTSMessage_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ITTSMessage_h_Statics::EnumInfo[] = {
		{ TTSDestination_StaticEnum, TEXT("TTSDestination"), &Z_Registration_Info_UEnum_TTSDestination, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1969703833U) },
		{ TTSMessageState_StaticEnum, TEXT("TTSMessageState"), &Z_Registration_Info_UEnum_TTSMessageState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1998513066U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ITTSMessage_h_3301072996(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ITTSMessage_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ITTSMessage_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
