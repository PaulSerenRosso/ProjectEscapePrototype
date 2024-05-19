// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VivoxCore.h"
#include "GameFramework/Actor.h"
#include "ProximityChatManager.generated.h"

USTRUCT(BlueprintType)
struct FMyChannel3DProperties
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, DisplayName = "Audible Distance", Category = "3D Properties")
	int32 audibleDistance = 2700;

	UPROPERTY(BlueprintReadWrite, DisplayName = "Conversational Distance", Category = "3D Properties")
	int32 conversationalDistance = 90;

	UPROPERTY(BlueprintReadWrite, DisplayName = "Audio Fade Intensity By Distance", Category = "3D Properties")
	double audioFadeIntensityByDistance = 1.0;

	UPROPERTY(BlueprintReadWrite, DisplayName = "Audio Fade Mode", Category = "3D Properties")
	EAudioFadeModel audioFadeMode = EAudioFadeModel::InverseByDistance;

	
	FMyChannel3DProperties()
		
	{}
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(F_Escape_OnLoginStateChanged, FString, Username, LoginState,
                                             LoginStateStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(F_Escape_OnBeginLoginCompleted, FString, Username, LoginState, LoginStateStatus);

UCLASS()
class PROJECTESCAPEPROTO_API AProximityChatManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProximityChatManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void InitVivox();

	//Client
	bool InitializeClient();
	int32 SignIn(FString InputUsername, FString InputDisplayName, FTimespan Expiration);
	void OnChannelSessionStateChanged(const IChannelConnectionState& ChannelConnectionState, FString String, FString String1);
	void OnChannelSessionTextMessageReceived(const IChannelTextMessage& ChannelTextMessage, FString String, FString String1);
	int32 JoinChannel(FString InputUserName, FString InputChannelName, ChannelType InputChannelType,
					  FMyChannel3DProperties InputChannel3dProperties, bool ConnectAudio, bool ConnectText,
					  bool SwitchTransmition, FTimespan Expiration);
	ChannelId* GetChannelId(FString Channelname);
	void OnLoginSessionStateChanged(LoginState State, FString Username);
	int32 Update3dPositionalChannel(FString InputUsername, FString InputChannelName, FVector SpeakerPosition,
									FVector ListenerPosition, FVector ListenerForwardVector, FVector ListenerUpVector);
public:
	UFUNCTION(BlueprintCallable)
	void TickPosittion(APawn *PlayerPawn);

public:
	FString kDefaultKey = "eyXkpK8qcw3r0YnyISUvA1NkiKLJlseF";
	FString kDefaulEndPoint = "https://unity.vivox.com/appconfig/90719-proje-41231-udash";
	FTimespan kDefaultExpiration = FTimespan::FromDays(10);
	FString kDefaultIssuer = "90719-proje-41231-udash";
	FString kDefaultDomain = "mtu1xp.vivox.com";
	FString ChannelName = "laClasseDePetiteSection";


	//Client
	IClient *MyVoiceClient = nullptr;
	FVivoxCoreModule *MyVoiceModule;
	TMap<FString, AccountId> AccountIds;
	TMap<FString, ChannelId> ChannelIds;
	UPROPERTY(BlueprintAssignable, DisplayName = "On Login State Changed", category="Vivox Subsystem|Account|Deligates")
	F_Escape_OnLoginStateChanged OnLoginStateChanged;
	FString MyInputUsername = "";

};
