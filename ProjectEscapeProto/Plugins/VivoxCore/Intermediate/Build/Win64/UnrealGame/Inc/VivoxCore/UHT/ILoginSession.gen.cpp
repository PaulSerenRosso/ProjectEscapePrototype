// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ILoginSession.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeILoginSession() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_LoginState();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_SubscriptionMode();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_SubscriptionReply();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_TransmissionMode();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_LoginState;
	static UEnum* LoginState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_LoginState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_LoginState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_LoginState, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("LoginState"));
		}
		return Z_Registration_Info_UEnum_LoginState.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<LoginState>()
	{
		return LoginState_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_LoginState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_LoginState_Statics::Enumerators[] = {
		{ "LoginState::LoggedOut", (int64)LoginState::LoggedOut },
		{ "LoginState::LoggingIn", (int64)LoginState::LoggingIn },
		{ "LoginState::LoggedIn", (int64)LoginState::LoggedIn },
		{ "LoginState::LoggingOut", (int64)LoginState::LoggingOut },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_LoginState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief The state of the login session.\n */" },
#endif
		{ "LoggedIn.Comment", "/**\n     * \\brief The login session is signed in.\n     */" },
		{ "LoggedIn.Name", "LoginState::LoggedIn" },
		{ "LoggedIn.ToolTip", "\\brief The login session is signed in." },
		{ "LoggedOut.Comment", "/**\n     * \\brief The login session is signed out.\n     */" },
		{ "LoggedOut.Name", "LoginState::LoggedOut" },
		{ "LoggedOut.ToolTip", "\\brief The login session is signed out." },
		{ "LoggingIn.Comment", "/**\n     * \\brief The login session is in the process of signing in.\n     */" },
		{ "LoggingIn.Name", "LoginState::LoggingIn" },
		{ "LoggingIn.ToolTip", "\\brief The login session is in the process of signing in." },
		{ "LoggingOut.Comment", "/**\n     * \\brief The login Session is in the process of signing out.\n     */" },
		{ "LoggingOut.Name", "LoginState::LoggingOut" },
		{ "LoggingOut.ToolTip", "\\brief The login Session is in the process of signing out." },
		{ "ModuleRelativePath", "Public/ILoginSession.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The state of the login session." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_LoginState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"LoginState",
		"LoginState",
		Z_Construct_UEnum_VivoxCore_LoginState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_LoginState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_LoginState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_LoginState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_LoginState()
	{
		if (!Z_Registration_Info_UEnum_LoginState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_LoginState.InnerSingleton, Z_Construct_UEnum_VivoxCore_LoginState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_LoginState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_SubscriptionMode;
	static UEnum* SubscriptionMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_SubscriptionMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_SubscriptionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_SubscriptionMode, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("SubscriptionMode"));
		}
		return Z_Registration_Info_UEnum_SubscriptionMode.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<SubscriptionMode>()
	{
		return SubscriptionMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::Enumerators[] = {
		{ "SubscriptionMode::Accept", (int64)SubscriptionMode::Accept },
		{ "SubscriptionMode::Block", (int64)SubscriptionMode::Block },
		{ "SubscriptionMode::Defer", (int64)SubscriptionMode::Defer },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::Enum_MetaDataParams[] = {
		{ "Accept.Comment", "/**\n     * \\brief Automatically accept all incoming subscription requests.\n     */" },
		{ "Accept.Name", "SubscriptionMode::Accept" },
		{ "Accept.ToolTip", "\\brief Automatically accept all incoming subscription requests." },
		{ "Block.Comment", "/**\n     * \\brief Automatically block all incoming subscription requests.\n     */" },
		{ "Block.Name", "SubscriptionMode::Block" },
		{ "Block.ToolTip", "\\brief Automatically block all incoming subscription requests." },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief Determine how to handle incoming subscriptions (friend/follower requests).\n */" },
#endif
		{ "Defer.Comment", "/**\n     * \\brief Defer incoming subscription request handling to the application.\n     * This results in EventSubscriptionRequestReceived firing.\n     */" },
		{ "Defer.Name", "SubscriptionMode::Defer" },
		{ "Defer.ToolTip", "\\brief Defer incoming subscription request handling to the application.\nThis results in EventSubscriptionRequestReceived firing." },
		{ "ModuleRelativePath", "Public/ILoginSession.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Determine how to handle incoming subscriptions (friend/follower requests)." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"SubscriptionMode",
		"SubscriptionMode",
		Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_SubscriptionMode()
	{
		if (!Z_Registration_Info_UEnum_SubscriptionMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_SubscriptionMode.InnerSingleton, Z_Construct_UEnum_VivoxCore_SubscriptionMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_SubscriptionMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_SubscriptionReply;
	static UEnum* SubscriptionReply_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_SubscriptionReply.OuterSingleton)
		{
			Z_Registration_Info_UEnum_SubscriptionReply.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_SubscriptionReply, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("SubscriptionReply"));
		}
		return Z_Registration_Info_UEnum_SubscriptionReply.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<SubscriptionReply>()
	{
		return SubscriptionReply_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::Enumerators[] = {
		{ "SubscriptionReply::Allow", (int64)SubscriptionReply::Allow },
		{ "SubscriptionReply::Block", (int64)SubscriptionReply::Block },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::Enum_MetaDataParams[] = {
		{ "Allow.Comment", "/**\n     * \\brief Allow the incoming subscription.\n     */" },
		{ "Allow.Name", "SubscriptionReply::Allow" },
		{ "Allow.ToolTip", "\\brief Allow the incoming subscription." },
		{ "Block.Comment", "/**\n     * \\brief Block the incoming subscription.\n     */" },
		{ "Block.Name", "SubscriptionReply::Block" },
		{ "Block.ToolTip", "\\brief Block the incoming subscription." },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ILoginSession.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"SubscriptionReply",
		"SubscriptionReply",
		Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_SubscriptionReply()
	{
		if (!Z_Registration_Info_UEnum_SubscriptionReply.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_SubscriptionReply.InnerSingleton, Z_Construct_UEnum_VivoxCore_SubscriptionReply_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_SubscriptionReply.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_TransmissionMode;
	static UEnum* TransmissionMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_TransmissionMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_TransmissionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_TransmissionMode, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("TransmissionMode"));
		}
		return Z_Registration_Info_UEnum_TransmissionMode.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<TransmissionMode>()
	{
		return TransmissionMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::Enumerators[] = {
		{ "TransmissionMode::None", (int64)TransmissionMode::None },
		{ "TransmissionMode::Single", (int64)TransmissionMode::Single },
		{ "TransmissionMode::All", (int64)TransmissionMode::All },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::Enum_MetaDataParams[] = {
		{ "All.Comment", "/**\n     * \\brief Adopt a policy of transmission into all channels simultaneously.\n     */" },
		{ "All.Name", "TransmissionMode::All" },
		{ "All.ToolTip", "\\brief Adopt a policy of transmission into all channels simultaneously." },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief Define the policy of where microphone audio and injected audio get broadcast to.\n */" },
#endif
		{ "ModuleRelativePath", "Public/ILoginSession.h" },
		{ "None.Comment", "/**\n     * \\brief Adopt a policy of transmission into no channels.\n     */" },
		{ "None.Name", "TransmissionMode::None" },
		{ "None.ToolTip", "\\brief Adopt a policy of transmission into no channels." },
		{ "Single.Comment", "/**\n     * \\brief Adopt a policy of transmission into one channel at a time.\n     */" },
		{ "Single.Name", "TransmissionMode::Single" },
		{ "Single.ToolTip", "\\brief Adopt a policy of transmission into one channel at a time." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Define the policy of where microphone audio and injected audio get broadcast to." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"TransmissionMode",
		"TransmissionMode",
		Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_TransmissionMode()
	{
		if (!Z_Registration_Info_UEnum_TransmissionMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_TransmissionMode.InnerSingleton, Z_Construct_UEnum_VivoxCore_TransmissionMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_TransmissionMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate;
	static UEnum* ParticipantSpeakingUpdateRate_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("ParticipantSpeakingUpdateRate"));
		}
		return Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<ParticipantSpeakingUpdateRate>()
	{
		return ParticipantSpeakingUpdateRate_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::Enumerators[] = {
		{ "ParticipantSpeakingUpdateRate::StateChange", (int64)ParticipantSpeakingUpdateRate::StateChange },
		{ "ParticipantSpeakingUpdateRate::Never", (int64)ParticipantSpeakingUpdateRate::Never },
		{ "ParticipantSpeakingUpdateRate::Update1Hz", (int64)ParticipantSpeakingUpdateRate::Update1Hz },
		{ "ParticipantSpeakingUpdateRate::Update5Hz", (int64)ParticipantSpeakingUpdateRate::Update5Hz },
		{ "ParticipantSpeakingUpdateRate::Update10Hz", (int64)ParticipantSpeakingUpdateRate::Update10Hz },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief Define how often the SDK raises speech-related IChannelSession::EventAfterParticipantUpdated events while in channel.\n * \\remarks Use a per second rate (at the fidelity of your choice) when implementing a real-time audio energy meter.\n * This only controls participant update events due to changes in speech detection or changes in audio energy.\n * Other participant property state change events (for example, active media or muted state) occur regardless of setting.\n */" },
#endif
		{ "ModuleRelativePath", "Public/ILoginSession.h" },
		{ "Never.Comment", "/**\n     * \\brief Do not raise events for changes in participant speech detection or audio energy (use with caution).\n     */" },
		{ "Never.Name", "ParticipantSpeakingUpdateRate::Never" },
		{ "Never.ToolTip", "\\brief Do not raise events for changes in participant speech detection or audio energy (use with caution)." },
		{ "StateChange.Comment", "/**\n     * \\brief On participant state change in speech detection only (excludes audio energy).\n     */" },
		{ "StateChange.Name", "ParticipantSpeakingUpdateRate::StateChange" },
		{ "StateChange.ToolTip", "\\brief On participant state change in speech detection only (excludes audio energy)." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Define how often the SDK raises speech-related IChannelSession::EventAfterParticipantUpdated events while in channel.\n\\remarks Use a per second rate (at the fidelity of your choice) when implementing a real-time audio energy meter.\nThis only controls participant update events due to changes in speech detection or changes in audio energy.\nOther participant property state change events (for example, active media or muted state) occur regardless of setting." },
#endif
		{ "Update10Hz.Comment", "/**\n     * \\brief Update participant properties up to 10 times per second (includes audio energy).\n     */" },
		{ "Update10Hz.Name", "ParticipantSpeakingUpdateRate::Update10Hz" },
		{ "Update10Hz.ToolTip", "\\brief Update participant properties up to 10 times per second (includes audio energy)." },
		{ "Update1Hz.Comment", "/**\n     * \\brief Update participant properties up to 1 time per second (includes audio energy).\n     */" },
		{ "Update1Hz.Name", "ParticipantSpeakingUpdateRate::Update1Hz" },
		{ "Update1Hz.ToolTip", "\\brief Update participant properties up to 1 time per second (includes audio energy)." },
		{ "Update5Hz.Comment", "/**\n     * \\brief Update participant properties up to 5 times per second (includes audio energy).\n     */" },
		{ "Update5Hz.Name", "ParticipantSpeakingUpdateRate::Update5Hz" },
		{ "Update5Hz.ToolTip", "\\brief Update participant properties up to 5 times per second (includes audio energy)." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"ParticipantSpeakingUpdateRate",
		"ParticipantSpeakingUpdateRate",
		Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate()
	{
		if (!Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate.InnerSingleton, Z_Construct_UEnum_VivoxCore_ParticipantSpeakingUpdateRate_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ILoginSession_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ILoginSession_h_Statics::EnumInfo[] = {
		{ LoginState_StaticEnum, TEXT("LoginState"), &Z_Registration_Info_UEnum_LoginState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 780192043U) },
		{ SubscriptionMode_StaticEnum, TEXT("SubscriptionMode"), &Z_Registration_Info_UEnum_SubscriptionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 824457172U) },
		{ SubscriptionReply_StaticEnum, TEXT("SubscriptionReply"), &Z_Registration_Info_UEnum_SubscriptionReply, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3852786640U) },
		{ TransmissionMode_StaticEnum, TEXT("TransmissionMode"), &Z_Registration_Info_UEnum_TransmissionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1045563251U) },
		{ ParticipantSpeakingUpdateRate_StaticEnum, TEXT("ParticipantSpeakingUpdateRate"), &Z_Registration_Info_UEnum_ParticipantSpeakingUpdateRate, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2046933256U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ILoginSession_h_3267339712(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ILoginSession_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ILoginSession_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
