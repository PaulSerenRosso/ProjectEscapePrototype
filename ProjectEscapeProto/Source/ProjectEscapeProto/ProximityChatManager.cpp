// Fill out your copyright notice in the Description page of Project Settings.


#include "ProximityChatManager.h"

#include "OnlineGameInstance.h"
#include "VivoxManager.h"

// Sets default values
AProximityChatManager::AProximityChatManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProximityChatManager::BeginPlay()
{
	Super::BeginPlay();
	InitVivox();
	InitializeClient();
}

// Called every frame
void AProximityChatManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProximityChatManager::InitVivox()
{
	MyVoiceModule = &FModuleManager::Get().LoadModuleChecked<FVivoxCoreModule>("VivoxCore");
}

bool AProximityChatManager::InitializeClient()
{
	if (!MyVoiceModule)
	{
		return false;
	}

	if (kDefaulEndPoint.IsEmpty() || kDefaultDomain.IsEmpty() || kDefaultIssuer.IsEmpty() || kDefaultKey.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Make sure server and Domain and Issuer and SecretKey is set"));
		return false;
	}

	MyVoiceClient = &MyVoiceModule->VoiceClient();
	bool bSuccess = MyVoiceClient->Initialize() == VxErrorSuccess;
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to initialize voice client"));
		return false;
	}
	FString RandomName = UVivoxManager::GetRandomString(10);
	FTimerHandle TimerHandle;
	//GEngine()->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Finish to Initialize Vivox"));
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, RandomName]()
	{
		//GEngine()->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Try to Sign In"));
		SignIn(RandomName, RandomName, kDefaultExpiration);
	}, 0.01f, false);


	return true;
}

int32 AProximityChatManager::SignIn(FString InputUsername, FString InputDisplayName, FTimespan Expiration)
{
	if (InputUsername.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("make sure username is set"));
		return 99;
	}

	if (InputDisplayName.IsEmpty())
	{
		InputDisplayName = InputUsername;
	}

	AccountId TempAccountId = AccountId(*kDefaultIssuer, *InputUsername, *kDefaultDomain, InputDisplayName);

	if (!TempAccountId.IsValid())
	{
		UE_LOG(LogTemp, Warning,
		       TEXT("AccountId id not valid, try again and make sure vivox cridentials and input is good"));
		return 98;
	}

	AccountIds.Add(InputUsername, TempAccountId);

	ILoginSession& MyLoginSession(MyVoiceClient->GetLoginSession(TempAccountId));
	MyLoginSession.EventStateChanged.AddUObject(this, &AProximityChatManager::OnLoginSessionStateChanged,
	                                            TempAccountId.Name());

	AsyncTask(ENamedThreads::GameThread, [this, TempAccountId, Expiration, InputUsername]()
	{
		ILoginSession& MyLoginSession(MyVoiceClient->GetLoginSession(TempAccountId));
		FString VivoxLoginToken = MyLoginSession.GetLoginToken(kDefaultKey, Expiration);

		ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleted;

		OnBeginLoginCompleted.BindLambda([this, &MyLoginSession, InputUsername](VivoxCoreError Error)
		{
			UE_LOG(LogTemp, Warning, TEXT("login error code: %i"), Error);
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, InputUsername]()
			{
				FMyChannel3DProperties TempChannel3DProperties;
				TempChannel3DProperties.audibleDistance = 2700;
				TempChannel3DProperties.conversationalDistance = 90;
				TempChannel3DProperties.audioFadeIntensityByDistance = 1.0;
				TempChannel3DProperties.audioFadeMode = EAudioFadeModel::InverseByDistance;

				UE_LOG(LogTemp, Warning, TEXT("Try to Joining channel"));
				//GEngine()->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Try to Joining channel"));
				JoinChannel(InputUsername,
				            ChannelName,
				            ChannelType::Positional,
				            TempChannel3DProperties,
				            true,
				            true,
				            true,
				            FTimespan::FromDays(10)
				);
			}, 0.01f, false);
		});

		MyLoginSession.BeginLogin(kDefaulEndPoint, VivoxLoginToken, OnBeginLoginCompleted);
	});

	return 0;
}

void AProximityChatManager::OnChannelSessionStateChanged(const IChannelConnectionState& ChannelConnectionState,
                                                       FString String, FString String1)
{
}

void AProximityChatManager::OnChannelSessionTextMessageReceived(const IChannelTextMessage& ChannelTextMessage,
                                                              FString String, FString String1)
{
}

int32 AProximityChatManager::JoinChannel(FString InputUserName, FString InputChannelName, ChannelType InputChannelType,
                                       FMyChannel3DProperties InputChannel3dProperties, bool ConnectAudio,
                                       bool ConnectText, bool SwitchTransmition, FTimespan Expiration)
{
	if (InputUserName.IsEmpty() || InputChannelName.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("make sure user name and channel name is set"));
		return 99;
	}

	Channel3DProperties TempChannel3DProperties(InputChannel3dProperties.audibleDistance,
	                                            InputChannel3dProperties.conversationalDistance,
	                                            InputChannel3dProperties.audioFadeIntensityByDistance,
	                                            InputChannel3dProperties.audioFadeMode);

	ChannelId TempChannelId(kDefaultIssuer, InputChannelName, kDefaultDomain, InputChannelType,
	                        TempChannel3DProperties);
	if (!TempChannelId.IsValid())
	{
		UE_LOG(LogTemp, Warning,
		       TEXT("ChannelId id not valid, try again and make sure vivox cridentials and input is good"));
		return 98;
	}

	ChannelIds.Add(InputChannelName, TempChannelId);

	AccountId* TempAccountId = &AccountIds[InputUserName];

	ILoginSession* TempLoginSession = &MyVoiceClient->GetLoginSession(*TempAccountId);

	if (TempLoginSession->State() != LoginState::LoggedIn)
	{
		UE_LOG(LogTemp, Warning, TEXT("user its not logged in"));
		return false;
	}

	IChannelSession& MyChannelSession(TempLoginSession->GetChannelSession(TempChannelId));
	MyChannelSession.EventChannelStateChanged.AddUObject(this, &AProximityChatManager::OnChannelSessionStateChanged,
	                                                     TempLoginSession->LoginSessionId().Name(),
	                                                     TempChannelId.Name());
	if (ConnectText)
	{
		MyChannelSession.EventTextMessageReceived.AddUObject(
			this, &AProximityChatManager::OnChannelSessionTextMessageReceived, TempLoginSession->LoginSessionId().Name(),
			TempChannelId.Name());
	}

	AsyncTask(ENamedThreads::GameThread,
	          [this, TempLoginSession, TempChannelId, Expiration, ConnectAudio, ConnectText, SwitchTransmition, InputUserName]()
	          {
		          IChannelSession& MyChannelSession(TempLoginSession->GetChannelSession(TempChannelId));

		          FString ConnectToken = MyChannelSession.GetConnectToken(kDefaultKey, Expiration);
		          IChannelSession::FOnBeginConnectCompletedDelegate OnBeginConnectCompleted;

		          OnBeginConnectCompleted.BindLambda([this, &MyChannelSession, InputUserName](VivoxCoreError Error)
		          {
			          UE_LOG(LogTemp, Warning, TEXT("Join channel completed"));
		          	MyInputUsername = InputUserName;
		          });

		          MyChannelSession.BeginConnect(ConnectAudio, ConnectText, SwitchTransmition, ConnectToken,
		                                        OnBeginConnectCompleted);
	          });

	return 0;
}

int32 AProximityChatManager::Update3dPositionalChannel(FString InputUsername, FString InputChannelName,
	FVector SpeakerPosition, FVector ListenerPosition, FVector ListenerForwardVector, FVector ListenerUpVector)
{
	if (InputUsername.IsEmpty() || InputChannelName.IsEmpty())
	{
		//UE_LOG(LogTemp, Warning, TEXT("please enter username and channelname"));
		return 99;
	}
	
	AccountId* TempAccountId = &AccountIds[InputUsername];

	ILoginSession* TempLoginSession = &MyVoiceClient->GetLoginSession(*TempAccountId);
	if (TempLoginSession == nullptr){
		UE_LOG(LogTemp, Warning, TEXT("user its not valid"));
		return 98;
	}
	
	if (TempLoginSession->State() != LoginState::LoggedIn){
		UE_LOG(LogTemp, Warning, TEXT("user its not logged in"));
		return 97;
	}

	ChannelId* TempChannelId = GetChannelId(InputChannelName);
	if (TempChannelId == nullptr)
	{
		return 96;
	}

	IChannelSession* TempChannelSession = &TempLoginSession->GetChannelSession(*TempChannelId);
	if (TempChannelSession == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Channel session not found or not valid"));
		return 95;
	}

	if (TempChannelSession == nullptr)
	{
		return 96;
	}
	
	if (TempChannelSession->Channel().Type() != ChannelType::Positional)
	{
		UE_LOG(LogTemp, Warning, TEXT("selected channel is not positional"));
		return 95;
	}
	
	return TempChannelSession->Set3DPosition(SpeakerPosition, ListenerPosition, ListenerForwardVector, ListenerUpVector);
}

void AProximityChatManager::TickPosittion(APawn* PlayerPawn)
{
	
	Update3dPositionalChannel(MyInputUsername, ChannelName, PlayerPawn->GetActorLocation(), PlayerPawn->GetActorLocation(), PlayerPawn->GetActorForwardVector(), PlayerPawn->GetActorUpVector());
}

ChannelId* AProximityChatManager::GetChannelId(FString Channelname)
{
	if (!ChannelIds.Contains(Channelname))
	{
		UE_LOG(LogTemp, Warning, TEXT("channel id not found"));
		return nullptr;
	}
	return &ChannelIds[Channelname];
}

void AProximityChatManager::OnLoginSessionStateChanged(LoginState State, FString Username)
{
	if (OnLoginStateChanged.IsBound())
	{
		
	}
}

