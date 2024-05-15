// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AudioDeviceImpl.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAudioDeviceImpl() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_DeviceType();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_DeviceType;
	static UEnum* DeviceType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_DeviceType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_DeviceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_DeviceType, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("DeviceType"));
		}
		return Z_Registration_Info_UEnum_DeviceType.OuterSingleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<DeviceType>()
	{
		return DeviceType_StaticEnum();
	}
	struct Z_Construct_UEnum_VivoxCore_DeviceType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VivoxCore_DeviceType_Statics::Enumerators[] = {
		{ "DeviceType::NullDevice", (int64)DeviceType::NullDevice },
		{ "DeviceType::SpecificDevice", (int64)DeviceType::SpecificDevice },
		{ "DeviceType::DefaultSystemDevice", (int64)DeviceType::DefaultSystemDevice },
		{ "DeviceType::DefaultCommunicationDevice", (int64)DeviceType::DefaultCommunicationDevice },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VivoxCore_DeviceType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \\brief The type of device\n */" },
#endif
		{ "DefaultCommunicationDevice.Comment", "/**\n     * This type means to use what ever the system has configured as a default communication device, at the time of the call.\n     * Don't switch devices mid-call if the default communication device changes.\n     */" },
		{ "DefaultCommunicationDevice.Name", "DeviceType::DefaultCommunicationDevice" },
		{ "DefaultCommunicationDevice.ToolTip", "This type means to use what ever the system has configured as a default communication device, at the time of the call.\nDon't switch devices mid-call if the default communication device changes." },
		{ "DefaultSystemDevice.Comment", "/**\n     * This type means to use what ever the system has configured as a default, at the time of the call.\n     * Don't switch devices mid-call if the default system device changes.\n     */" },
		{ "DefaultSystemDevice.Name", "DeviceType::DefaultSystemDevice" },
		{ "DefaultSystemDevice.ToolTip", "This type means to use what ever the system has configured as a default, at the time of the call.\nDon't switch devices mid-call if the default system device changes." },
		{ "ModuleRelativePath", "Public/AudioDeviceImpl.h" },
		{ "NullDevice.Comment", "/**\n     * This is the null device, which means that either input or output from/to that device will not occur.\n     */" },
		{ "NullDevice.Name", "DeviceType::NullDevice" },
		{ "NullDevice.ToolTip", "This is the null device, which means that either input or output from/to that device will not occur." },
		{ "SpecificDevice.Comment", "/**\n     * This type is a specific device.\n     */" },
		{ "SpecificDevice.Name", "DeviceType::SpecificDevice" },
		{ "SpecificDevice.ToolTip", "This type is a specific device." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The type of device" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_DeviceType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
		nullptr,
		"DeviceType",
		"DeviceType",
		Z_Construct_UEnum_VivoxCore_DeviceType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_DeviceType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_DeviceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_DeviceType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VivoxCore_DeviceType()
	{
		if (!Z_Registration_Info_UEnum_DeviceType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_DeviceType.InnerSingleton, Z_Construct_UEnum_VivoxCore_DeviceType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_DeviceType.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_AudioDeviceImpl_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_AudioDeviceImpl_h_Statics::EnumInfo[] = {
		{ DeviceType_StaticEnum, TEXT("DeviceType"), &Z_Registration_Info_UEnum_DeviceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3632981833U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_AudioDeviceImpl_h_951854718(TEXT("/Script/VivoxCore"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_AudioDeviceImpl_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_AudioDeviceImpl_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
