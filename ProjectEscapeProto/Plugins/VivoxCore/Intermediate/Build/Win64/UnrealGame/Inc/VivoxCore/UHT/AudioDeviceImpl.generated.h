// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AudioDeviceImpl.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_AudioDeviceImpl_generated_h
#error "AudioDeviceImpl.generated.h already included, missing '#pragma once' in AudioDeviceImpl.h"
#endif
#define VIVOXCORE_AudioDeviceImpl_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_AudioDeviceImpl_h


#define FOREACH_ENUM_DEVICETYPE(op) \
	op(DeviceType::NullDevice) \
	op(DeviceType::SpecificDevice) \
	op(DeviceType::DefaultSystemDevice) \
	op(DeviceType::DefaultCommunicationDevice) 

enum class DeviceType : uint8;
template<> struct TIsUEnumClass<DeviceType> { enum { Value = true }; };
template<> VIVOXCORE_API UEnum* StaticEnum<DeviceType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
