// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineGameInstance.generated.h"

UCLASS()
class PROJECTESCAPEPROTO_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

// private:
// 	void InitVivox();
//
// 	//Client
// 	bool InitializeClient();
// 	int32 SignIn(FString InputUsername, FString InputDisplayName, FTimespan Expiration);
// 	void OnChannelSessionStateChanged(const IChannelConnectionState& ChannelConnectionState, FString String, FString String1);
// 	void OnChannelSessionTextMessageReceived(const IChannelTextMessage& ChannelTextMessage, FString String, FString String1);
// 	int32 JoinChannel(FString InputUserName, FString InputChannelName, ChannelType InputChannelType,
// 					  FMyChannel3DProperties InputChannel3dProperties, bool ConnectAudio, bool ConnectText,
// 					  bool SwitchTransmition, FTimespan Expiration);
// 	ChannelId* GetChannelId(FString Channelname);
// 	void OnLoginSessionStateChanged(LoginState State, FString Username);
// 	int32 Update3dPositionalChannel(FString InputUsername, FString InputChannelName, FVector SpeakerPosition,
// 									FVector ListenerPosition, FVector ListenerForwardVector, FVector ListenerUpVector);
// public:
// 	UFUNCTION(BlueprintCallable)
// 	void TickPosittion(APawn *PlayerPawn);
//
// public:
// 	FString kDefaultKey = "eyXkpK8qcw3r0YnyISUvA1NkiKLJlseF";
// 	FString kDefaulEndPoint = "https://unity.vivox.com/appconfig/90719-proje-41231-udash";
// 	FTimespan kDefaultExpiration = FTimespan::FromDays(10);
// 	FString kDefaultIssuer = "90719-proje-41231-udash";
// 	FString kDefaultDomain = "mtu1xp.vivox.com";
// 	FString ChannelName = "pommeDeTerre";
//
//
// 	//Client
// 	IClient *MyVoiceClient = nullptr;
// 	FVivoxCoreModule *MyVoiceModule;
// 	TMap<FString, AccountId> AccountIds;
// 	TMap<FString, ChannelId> ChannelIds;
// 	UPROPERTY(BlueprintAssignable, DisplayName = "On Login State Changed", category="Vivox Subsystem|Account|Deligates")
// 	F_Escape_OnLoginStateChanged OnLoginStateChanged;
// 	FString MyInputUsername = "";
};