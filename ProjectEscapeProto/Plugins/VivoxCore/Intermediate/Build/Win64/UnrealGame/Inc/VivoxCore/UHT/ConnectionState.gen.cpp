// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConnectionState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConnectionState() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_ConnectionState();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ConnectionState;
	static UEnum* ConnectionState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ConnectionState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ConnectionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_ConnectionState, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("ConnectionState"));
		}
		return Z_Registration_Info_UEnum_ConnectionState.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<ConnectionState>()
	{
		return ConnectionState_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_ConnectionState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::Enumerators[] = {
		{ "ConnectionState::Disconnected", (int64)ConnectionState::Disconnected },
		{ "ConnectionState::Connecting", (int64)ConnectionState::Connecting },
		{ "ConnectionState::Connected", (int64)ConnectionState::Connected },
		{ "ConnectionState::Disconnecting", (int64)ConnectionState::Disconnecting },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief The state of any resource with connection semantics.\n */" },
#endif
		{ "Connected.Comment", "/**\n     * \\brief The resource is connected.\n     */" },
		{ "Connected.Name", "ConnectionState::Connected" },
		{ "Connected.ToolTip", "\\brief The resource is connected." },
		{ "Connecting.Comment", "/**\n     * \\brief The resource is in the process of connecting.\n     */" },
		{ "Connecting.Name", "ConnectionState::Connecting" },
		{ "Connecting.ToolTip", "\\brief The resource is in the process of connecting." },
		{ "Disconnected.Comment", "/**\n     *\\brief The resource is disconnected.\n     */" },
		{ "Disconnected.Name", "ConnectionState::Disconnected" },
		{ "Disconnected.ToolTip", "\\brief The resource is disconnected." },
		{ "Disconnecting.Comment", "/**\n     * \\brief The resource is in the process of disconnecting.\n     */" },
		{ "Disconnecting.Name", "ConnectionState::Disconnecting" },
		{ "Disconnecting.ToolTip", "\\brief The resource is in the process of disconnecting." },
		{ "ModuleRelativePath", "Public/ConnectionState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The state of any resource with connection semantics." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"ConnectionState",
		"ConnectionState",
		Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_ConnectionState()
	{
		if (!Z_Registration_Info_UEnum_ConnectionState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ConnectionState.InnerSingleton, Z_Construct_UEnum_VivoxCore_ConnectionState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ConnectionState.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ConnectionState_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ConnectionState_h_Statics::EnumInfo[] = {
		{ ConnectionState_StaticEnum, TEXT("ConnectionState"), &Z_Registration_Info_UEnum_ConnectionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2885889123U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ConnectionState_h_4212799409(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ConnectionState_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ConnectionState_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
