// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ConnectionState.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_ConnectionState_generated_h
#error "ConnectionState.generated.h already included, missing '#pragma once' in ConnectionState.h"
#endif
#define VIVOXCORE_ConnectionState_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectEscapeProto_Plugins_VivoxCore_Source_VivoxCore_Public_ConnectionState_h


#define FOREACH_ENUM_CONNECTIONSTATE(op) \
	op(ConnectionState::Disconnected) \
	op(ConnectionState::Connecting) \
	op(ConnectionState::Connected) \
	op(ConnectionState::Disconnecting) 

enum class ConnectionState : uint8;
template<> struct TIsUEnumClass<ConnectionState> { enum { Value = true }; };
template<> VIVOXCORE_API UEnum* StaticEnum<ConnectionState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
