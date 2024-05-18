// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineGameInstance.h"
#include "Components/ActorComponent.h"
#include "VivoxCore.h"
#include "VivoxManager.generated.h"


class UOnlineGameInstance;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTESCAPEPROTO_API UVivoxManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVivoxManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UFUNCTION()
	void OnRep_ChannelName();
	//UFUNCTION(Server, Reliable)
	//FString GetChannelFromServer();
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	static FString GetRandomString(int32 Length);
	UFUNCTION(BlueprintCallable)
	void TryToJoinChannel();
	int32 JoinChannel(FString InputUserName, FString InputChannelName, ChannelType InputChannelType,
					  FMyChannel3DProperties InputChannel3dProperties, bool ConnectAudio, bool ConnectText,
					  bool SwitchTransmition, FTimespan Expiration);
	int32 Update3dPositionalChannel(FString InputUsername, FString InputChannelName, FVector SpeakerPosition,
									FVector ListenerPosition, FVector ListenerForwardVector, FVector ListenerUpVector);
	ChannelId* GetChannelId(FString Channelname);
	void OnLoginSessionStateChanged(LoginState State, FString Username);
	void OnChannelSessionStateChanged(const IChannelConnectionState& ChannelConnectionState, FString String,
	                                  FString String1);
	void OnChannelSessionTextMessageReceived(const IChannelTextMessage& ChannelTextMessage, FString String,
	                                         FString String1);
	UFUNCTION(BlueprintCallable)
	void isReady() { waiting = false; }

protected:
	//Client
	TMap<FString, ChannelId> ChannelIds;
	UPROPERTY(BlueprintAssignable, DisplayName = "On Login State Changed", category="Vivox Subsystem|Account|Deligates")
	F_Escape_OnLoginStateChanged OnLoginStateChanged;
	UOnlineGameInstance* MyGameInstance;
	UPROPERTY(ReplicatedUsing= OnRep_ChannelName)
	FString ChannelNameRep = "";
	bool waitResponseFromServerForJoinChannel = false;
	UPROPERTY(BlueprintReadWrite, DisplayName = "Channel Name", category="Vivox Subsystem|Channel")
	bool waiting = true;
	
 };
