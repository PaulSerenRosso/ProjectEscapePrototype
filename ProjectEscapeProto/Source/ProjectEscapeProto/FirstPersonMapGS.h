// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChannelId.h"
#include "ILoginSession.h"
#include "GameFramework/GameState.h"
#include "FirstPersonMapGS.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTESCAPEPROTO_API AFirstPersonMapGS : public AGameState
{
	GENERATED_BODY()

public:
	void CreateChannel();
	IChannelSession& JoinChannel(ILoginSession *MyLoginSessionPtr);
	//ChannelId& GetChannel() const { return Channel; }
	
private:
	//UPROPERTY(Replicated, Category = "Vivox")
	ChannelId Channel = ChannelId("90719-proje-41231-udash", "example_channel", "mtu1xp.vivox.com",
	                              ChannelType::NonPositional);
};
