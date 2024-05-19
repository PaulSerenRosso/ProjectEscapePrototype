// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ChannelId.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_ChannelId_generated_h
#error "ChannelId.generated.h already included, missing '#pragma once' in ChannelId.h"
#endif
#define VIVOXCORE_ChannelId_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ChannelId_h


#define FOREACH_ENUM_CHANNELTYPE(op) \
	op(ChannelType::NonPositional) \
	op(ChannelType::Positional) \
	op(ChannelType::Echo) 

enum class ChannelType : uint8;
template<> struct TIsUEnumClass<ChannelType> { enum { Value = true }; };
template<> VIVOXCORE_API UEnum* StaticEnum<ChannelType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
