// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonMapGS.h"
#include "OnlineGameInstance.h"

void AFirstPersonMapGS::CreateChannel()
{
	UOnlineGameInstance* MyGameInstance = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance());
	Channel = ChannelId(MyGameInstance->kDefaultIssuer, "example_channel", MyGameInstance->kDefaultDomain,
				  ChannelType::NonPositional);
}

IChannelSession& AFirstPersonMapGS::JoinChannel(ILoginSession *MyLoginSessionPtr)
{
	IChannelSession& MyChannelSession(MyLoginSessionPtr->GetChannelSession(Channel));
	bool IsAsynchronousConnectCompleted = false;
	IChannelSession::FOnBeginConnectCompletedDelegate OnBeginConnectCompleted;

	OnBeginConnectCompleted.BindLambda([this, &IsAsynchronousConnectCompleted, &MyChannelSession](VivoxCoreError Error)
	{
		if (VxErrorSuccess == Error)
		{
			// This bool is only illustrative. The connect call has completed.
			IsAsynchronousConnectCompleted = true;
			GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, TEXT("ChannelSession Connected :)"));
		}
	});

	UOnlineGameInstance* MyGameInstance = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance());
	MyChannelSession.BeginConnect(true, true, true,
								  MyChannelSession.GetConnectToken(MyGameInstance->kDefaultKey,
																   MyGameInstance->kDefaultExpiration),
								  OnBeginConnectCompleted);
	return MyChannelSession;
}

