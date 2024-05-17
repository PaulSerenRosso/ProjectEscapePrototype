// Fill out your copyright notice in the Description page of Project Settings.


#include "VivoxManager.h"

#include "FirstPersonMapGS.h"
#include "OnlineGameInstance.h"
#include "GameFramework/GameState.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UVivoxManager::UVivoxManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UVivoxManager::BeginPlay()
{
	Super::BeginPlay();

	//InitializeVivox();
	MyGameInstance = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance());
	TryToJoinChannel();
}

void UVivoxManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// MyVoiceClient->Uninitialize();
	// MyLoginSessionPtr->Logout();
}

void UVivoxManager::OnRep_ChannelName()
{
	if(waitResponseFromServerForJoinChannel)
	{
		waitResponseFromServerForJoinChannel = false;
		TryToJoinChannel();
	}
}


// FString UVivoxManager::GetChannelFromServer_Implementation()
// {
// 	return MyGameInstance->ChannelName;
// }


// Called every frame
void UVivoxManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Update3DPosition(GetOwner());
	// float PositionalUpdateRate = 0.02f; // Send position and orientation update every 0.02 seconds.
	// static float NextUpdateTime = UGameplayStatics::GetRealTimeSeconds(GetWorld()) + PositionalUpdateRate;
	// if (UGameplayStatics::GetRealTimeSeconds(GetWorld()) > NextUpdateTime)
	// {
	// 	NextUpdateTime += PositionalUpdateRate;
	// 	
	// }
}

// void UVivoxManager::InitializeVivox()
// {
// 	UOnlineGameInstance* MyGameInstance = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance());
// 	FVivoxCoreModule* MyVoiceModule = MyGameInstance->MyVoiceModule;
// 	if (MyVoiceModule == nullptr)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("Vivox Module is null"));
// 		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vivox Module is null"));
// 		return;
// 	}
// 	MyVoiceClient = &MyVoiceModule->VoiceClient();
// 	MyVoiceClient->Initialize();
//
// 	FString RandomName = GetRandomString(10);
// 	AccountId Account = AccountId(MyGameInstance->kDefaultIssuer, RandomName, MyGameInstance->kDefaultDomain);
// 	ILoginSession& MyLoginSession(MyVoiceClient->GetLoginSession(Account));
// 	MyLoginSessionPtr = &MyLoginSession;
// 	bool IsLoggedIn = false;
// 	// Setup the delegate to execute when login completes
// 	ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleted;
// 	OnBeginLoginCompleted.BindLambda([this, &IsLoggedIn, &MyLoginSession](VivoxCoreError Error)
// 	{
// 		if (VxErrorSuccess == Error)
// 		{
// 			// This bool is only illustrative. The user is now logged in.
// 			IsLoggedIn = true;
// 			GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, TEXT("LoginSession Logged In :)"));
// 			UE_LOG(LogTemp, Log, TEXT("LoginSession Logged In\n"));
//
// 			//IF IM FIRST I CREATE THE CHANNEL
// 			if (GetOwner()->HasAuthority())
// 			{
// 				AFirstPersonMapGS* MyGameState = Cast<AFirstPersonMapGS>(GetWorld()->GetGameState());
// 				MyGameState->CreateChannel();
// 				GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, TEXT("Channel Created :)"));
// 				UE_LOG(LogTemp, Log, TEXT("Channel Created\n"));
// 			}
//
//
// 			JoinChannelOnClient();
// 		}
// 	});
// 	// Request the user to login to Vivox
// 	MyLoginSession.BeginLogin(MyGameInstance->kDefaulEndPoint,
// 	                          MyLoginSession.GetLoginToken(MyGameInstance->kDefaultIssuer,
// 	                                                       MyGameInstance->kDefaultExpiration), OnBeginLoginCompleted);
// 	MyLoginSession.EventStateChanged.AddUObject(this, &UVivoxManager::OnLoginSessionStateChanged);
// }
//
// void UVivoxManager::OnChannelStateChanged(const IChannelConnectionState& ChannelConnectionState)
// {
// 	FString ChannelName(ChannelConnectionState.ChannelSession().Channel().Name());
//
// 	if (ConnectionState::Connected == ChannelConnectionState.State())
// 	{
// 		UE_LOG(LogTemp, Log, TEXT("Channel %s  fully connected\n"), *ChannelName);
// 		FString Message = FString::Printf(TEXT("Channel %s  fully connected\n"), *ChannelName);
// 		GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, *Message);
// 	}
// 	else if (ConnectionState::Disconnected == ChannelConnectionState.State())
// 	{
// 		UE_LOG(LogTemp, Log, TEXT("Channel %s fully disconnected\n"), *ChannelName);
// 		FString MessageD = FString::Printf(TEXT("Channel %s fully disconnected\n"),
// 		                                   *ChannelName);
// 		GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, *MessageD);
// 	}
// }
//
// void UVivoxManager::JoinChannelOnClient()
// {
// 	AFirstPersonMapGS* MyGameState = Cast<AFirstPersonMapGS>(GetWorld()->GetGameState());
// 	if (MyGameState == nullptr)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("GameState is null"));
// 		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GameState is null"));
// 		return;
// 	}
// 	MyChannelSession = &MyGameState->JoinChannel(MyLoginSessionPtr);
// 	ConnectedPositionalChannel = MyChannelSession->Channel();
// 	MyChannelSession->EventChannelStateChanged.AddUObject(this, &UVivoxManager::OnChannelStateChanged);
//
// 	ParticipantSpeakingUpdateRate UpdateRate = ParticipantSpeakingUpdateRate::Update10Hz;
// 	MyLoginSessionPtr->SetParticipantSpeakingUpdateRate(UpdateRate);
// 	MyChannelSession->EventAfterParticipantUpdated.AddLambda([](const IParticipant& Participant)
// 	{
// 		FString Message = FString::Printf(
// 			TEXT("Speech Detected %f"), Participant.AudioEnergy());
// 		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, *Message);
// 	});
// }
//
// void UVivoxManager::OnLoginSessionStateChanged(LoginState State)
// {
// 	if (LoginState::LoggedOut == State)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("LoginSession Logged Out Unexpectedly\n"));
// 		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LoginSession Logged Out Unexpectedly"));
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("LoginSession Logged In\n"));
// 		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LoginSession Logged In"));
// 	}
// }
//
// void UVivoxManager::Update3DPosition(AActor* Actor)
// {
//
// 	/// Return if argument is invalid.
// 	if (NULL == Actor)
// 		return;
//
// 	/// Return if we're not in a positional channel.
// 	if (ConnectedPositionalChannel.IsEmpty())
// 		return;
//
// 	/// Update cached 3D position and orientation.
// 	FVector NewPosition = Actor->GetActorLocation();
// 	FVector NewForwardVector = Actor->GetActorForwardVector();
// 	FVector NewUpVector = Actor->GetActorUpVector();
//
// 	/// Set new position and orientation in connected positional channel.
// 	MyLoginSessionPtr->GetChannelSession(ConnectedPositionalChannel).Set3DPosition(NewPosition, NewPosition, NewForwardVector, NewUpVector);
// /*
// 	if (MyChannelSession == nullptr)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("ChannelSession is null. Not Connected to a channel ?"));
// 		return;
// 	}
// 	FString msg = FString::Printf(
// 		TEXT("Updating 3D Position %f %f %f\n"), Actor->GetActorLocation().X, Actor->GetActorLocation().Y,
// 		Actor->GetActorLocation().Z);
// 	UE_LOG(LogTemp, Log, TEXT("%s"), *msg);
// 	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, *msg);
// 	VivoxCoreError retrunValue = MyChannelSession->Set3DPosition(
// 		Actor->GetActorLocation(),
// 		Actor->GetActorLocation(),
// 		Actor->GetActorForwardVector(),
// 		Actor->GetActorUpVector());
//
// 	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Set3DPosition return %d"), retrunValue));
// 	*/
// }
//
FString UVivoxManager::GetRandomString(int32 Length)
{
	FString RandomString = "";
	const FString Characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	for (int i = 0; i < Length; i++)
	{
		int32 RandomIndex = FMath::RandRange(0, Characters.Len() - 1);
		RandomString.AppendChar(Characters[RandomIndex]);
	}
	return RandomString;
}


void UVivoxManager::TryToJoinChannel()
{
	FMyChannel3DProperties TempChannel3DProperties;
	TempChannel3DProperties.audibleDistance = 2700;
	TempChannel3DProperties.conversationalDistance = 90;
	TempChannel3DProperties.audioFadeIntensityByDistance = 1.0;
	TempChannel3DProperties.audioFadeMode = EAudioFadeModel::InverseByDistance;

	UE_LOG(LogTemp, Warning, TEXT("Try to Joining channel"));
	//GetEngine()->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Try to Joining channel"));
	if(GetOwner()->HasAuthority())
	{
		MyGameInstance->ChannelName = GetRandomString(10);
		ChannelNameRep = MyGameInstance->ChannelName;
	}
	else if (ChannelNameRep.IsEmpty())
	{
		waitResponseFromServerForJoinChannel = true;
		return;
		//Wait for the server to set the channel name :)
	}
	else
	{
		MyGameInstance->ChannelName = ChannelNameRep;
	}
	JoinChannel(MyGameInstance->MyInputUsername,
	            MyGameInstance->ChannelName,
	            ChannelType::Positional,
	            TempChannel3DProperties,
	            true,
	            true,
	            true,
	            FTimespan::FromDays(10)
	);
}


int32 UVivoxManager::JoinChannel(FString InputUserName, FString InputChannelName, ChannelType InputChannelType,
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

	ChannelId TempChannelId(MyGameInstance->kDefaultIssuer, InputChannelName, MyGameInstance->kDefaultDomain,
	                        InputChannelType,
	                        TempChannel3DProperties);
	if (!TempChannelId.IsValid())
	{
		UE_LOG(LogTemp, Warning,
		       TEXT("ChannelId id not valid, try again and make sure vivox cridentials and input is good"));
		return 98;
	}

	ChannelIds.Add(InputChannelName, TempChannelId);

	AccountId* TempAccountId = &MyGameInstance->AccountIds[InputUserName];

	ILoginSession* TempLoginSession = &MyGameInstance->MyVoiceClient->GetLoginSession(*TempAccountId);

	if (TempLoginSession->State() != LoginState::LoggedIn)
	{
		UE_LOG(LogTemp, Warning, TEXT("user its not logged in"));
		return false;
	}

	IChannelSession& MyChannelSession(TempLoginSession->GetChannelSession(TempChannelId));
	MyChannelSession.EventChannelStateChanged.AddUObject(this, &UVivoxManager::OnChannelSessionStateChanged,
	                                                     TempLoginSession->LoginSessionId().Name(),
	                                                     TempChannelId.Name());
	if (ConnectText)
	{
		MyChannelSession.EventTextMessageReceived.AddUObject(
			this, &UVivoxManager::OnChannelSessionTextMessageReceived, TempLoginSession->LoginSessionId().Name(),
			TempChannelId.Name());
	}

	AsyncTask(ENamedThreads::GameThread,
	          [this, TempLoginSession, TempChannelId, Expiration, ConnectAudio, ConnectText, SwitchTransmition,
		          InputUserName]()
	          {
		          IChannelSession& MyChannelSession(TempLoginSession->GetChannelSession(TempChannelId));

		          FString ConnectToken = MyChannelSession.GetConnectToken(MyGameInstance->kDefaultKey, Expiration);
		          IChannelSession::FOnBeginConnectCompletedDelegate OnBeginConnectCompleted;

		          OnBeginConnectCompleted.BindLambda([this, &MyChannelSession, InputUserName](VivoxCoreError Error)
		          {
			          UE_LOG(LogTemp, Warning, TEXT("Join channel completed"));
			          MyGameInstance->MyInputUsername = InputUserName;
		          });

		          MyChannelSession.BeginConnect(ConnectAudio, ConnectText, SwitchTransmition, ConnectToken,
		                                        OnBeginConnectCompleted);
	          });

	return 0;
}

int32 UVivoxManager::Update3dPositionalChannel(FString InputUsername, FString InputChannelName,
                                               FVector SpeakerPosition, FVector ListenerPosition,
                                               FVector ListenerForwardVector, FVector ListenerUpVector)
{
	if (InputUsername.IsEmpty() || InputChannelName.IsEmpty())
	{
		//UE_LOG(LogTemp, Warning, TEXT("please enter username and channelname"));
		return 99;
	}
	if (MyGameInstance == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameInstance is null"));
		return 98;
	}
	AccountId* TempAccountId = &MyGameInstance->AccountIds[InputUsername];

	ILoginSession* TempLoginSession = &MyGameInstance->MyVoiceClient->GetLoginSession(*TempAccountId);
	if (TempLoginSession == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("user its not valid"));
		return 98;
	}

	if (TempLoginSession->State() != LoginState::LoggedIn)
	{
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

	return TempChannelSession->Set3DPosition(SpeakerPosition, ListenerPosition, ListenerForwardVector,
	                                         ListenerUpVector);
}

ChannelId* UVivoxManager::GetChannelId(FString Channelname)
{
	if (!ChannelIds.Contains(Channelname))
	{
		UE_LOG(LogTemp, Warning, TEXT("channel id not found"));
		return nullptr;
	}
	return &ChannelIds[Channelname];
}

void UVivoxManager::OnLoginSessionStateChanged(LoginState State, FString Username)
{
	if (OnLoginStateChanged.IsBound())
	{
	}
}

void UVivoxManager::OnChannelSessionStateChanged(const IChannelConnectionState& ChannelConnectionState,
                                                 FString String, FString String1)
{
}

void UVivoxManager::OnChannelSessionTextMessageReceived(const IChannelTextMessage& ChannelTextMessage,
                                                        FString String, FString String1)
{
}
void UVivoxManager::GetLifetimeReplicatedProps (TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVivoxManager, ChannelNameRep);
}