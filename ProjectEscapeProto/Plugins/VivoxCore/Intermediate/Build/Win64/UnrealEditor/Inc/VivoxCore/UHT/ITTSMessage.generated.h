// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ITTSMessage.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_ITTSMessage_generated_h
#error "ITTSMessage.generated.h already included, missing '#pragma once' in ITTSMessage.h"
#endif
#define VIVOXCORE_ITTSMessage_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ITTSMessage_h


#define FOREACH_ENUM_TTSDESTINATION(op) \
	op(TTSDestination::Default) \
	op(TTSDestination::RemoteTransmission) \
	op(TTSDestination::LocalPlayback) \
	op(TTSDestination::RemoteTransmissionWithLocalPlayback) \
	op(TTSDestination::QueuedRemoteTransmission) \
	op(TTSDestination::QueuedLocalPlayback) \
	op(TTSDestination::QueuedRemoteTransmissionWithLocalPlayback) \
	op(TTSDestination::ScreenReader) 

enum class TTSDestination : uint8;
template<> struct TIsUEnumClass<TTSDestination> { enum { Value = true }; };
template<> VIVOXCORE_API UEnum* StaticEnum<TTSDestination>();

#define FOREACH_ENUM_TTSMESSAGESTATE(op) \
	op(TTSMessageState::Playing) \
	op(TTSMessageState::Enqueued) 

enum class TTSMessageState : uint8;
template<> struct TIsUEnumClass<TTSMessageState> { enum { Value = true }; };
template<> VIVOXCORE_API UEnum* StaticEnum<TTSMessageState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
