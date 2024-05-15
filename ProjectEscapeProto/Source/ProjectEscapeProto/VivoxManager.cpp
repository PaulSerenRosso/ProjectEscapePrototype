// Fill out your copyright notice in the Description page of Project Settings.


#include "VivoxManager.h"

#include "FirstPersonMapGS.h"
#include "OnlineGameInstance.h"
#include "GameFramework/GameState.h"

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

	InitializeVivox();
}

void UVivoxManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	MyLoginSessionPtr->Logout();
	MyVoiceClient->Uninitialize();
}


// Called every frame
void UVivoxManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UVivoxManager::InitializeVivox()
{
	UOnlineGameInstance* MyGameInstance = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance());
	FVivoxCoreModule* MyVoiceModule = MyGameInstance->MyVoiceModule;
	if (MyVoiceModule == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Vivox Module is null"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vivox Module is null"));
		return;
	}
	MyVoiceClient = &MyVoiceModule->VoiceClient();
	MyVoiceClient->Initialize();

	///
	AccountId Account = AccountId(MyGameInstance->kDefaultIssuer, "example_user", MyGameInstance->kDefaultDomain);
	ILoginSession& MyLoginSession(MyVoiceClient->GetLoginSession(Account));
	MyLoginSessionPtr = &MyLoginSession;
	bool IsLoggedIn = false;
	// Setup the delegate to execute when login completes
	ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleted;
	OnBeginLoginCompleted.BindLambda([this, &IsLoggedIn, &MyLoginSession](VivoxCoreError Error)
	{
		if (VxErrorSuccess == Error)
		{
			// This bool is only illustrative. The user is now logged in.
			IsLoggedIn = true;
			GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, TEXT("LoginSession Logged In :)"));
			UE_LOG(LogTemp, Log, TEXT("LoginSession Logged In\n"));

//IF IM FIRST I CREATE THE CHANNEL
			if (GetOwner()->HasAuthority())
			{
				AFirstPersonMapGS* MyGameState = Cast<AFirstPersonMapGS>(GetWorld()->GetGameState());
				MyGameState->CreateChannel();
				GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, TEXT("Channel Created :)"));
				UE_LOG(LogTemp, Log, TEXT("Channel Created\n"));
			}

			
			JoinChannel();
		}
	});
	// Request the user to login to Vivox
	MyLoginSession.BeginLogin(MyGameInstance->kDefaultServer,
	                          MyLoginSession.GetLoginToken(MyGameInstance->kDefaultKey,
	                                                       MyGameInstance->kDefaultExpiration), OnBeginLoginCompleted);
	MyLoginSession.EventStateChanged.AddUObject(this, &UVivoxManager::OnLoginSessionStateChanged);
}

void UVivoxManager::OnChannelStateChanged(const IChannelConnectionState& ChannelConnectionState)
{
	FString ChannelName(ChannelConnectionState.ChannelSession().Channel().Name());

	if (ConnectionState::Connected == ChannelConnectionState.State())
	{
		UE_LOG(LogTemp, Log, TEXT("Channel %s  fully connected\n"), *ChannelName);
		FString Message = FString::Printf(TEXT("Channel %s  fully connected\n"), *ChannelName);
		GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, *Message);
	}
	else if (ConnectionState::Disconnected == ChannelConnectionState.State())
	{
		UE_LOG(LogTemp, Log, TEXT("Channel %s fully disconnected\n"), *ChannelName);
		FString MessageD = FString::Printf(TEXT("Channel %s fully disconnected\n"),
		                                   *ChannelName);
		GEngine->AddOnScreenDebugMessage(-1, 2500.f, FColor::Green, *MessageD);
	}
}

void UVivoxManager::JoinChannel()
{
	AFirstPersonMapGS* MyGameState = Cast<AFirstPersonMapGS>(GetWorld()->GetGameState());
	if (MyGameState == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("GameState is null"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GameState is null"));
		return;
	}
	IChannelSession& MyChannelSession = MyGameState->JoinChannel(MyLoginSessionPtr);
	MyChannelSession.EventChannelStateChanged.AddUObject(this, &UVivoxManager::OnChannelStateChanged);


	MyChannelSession.EventAfterParticipantUpdated.AddLambda([](const IParticipant& Participant)
	{
		FString Message = FString::Printf(
			TEXT("Speech Detected %f"), Participant.AudioEnergy());
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, *Message);
	});
}

void UVivoxManager::OnLoginSessionStateChanged(LoginState State)
{
	if (LoginState::LoggedOut == State)
	{
		UE_LOG(LogTemp, Error, TEXT("LoginSession Logged Out Unexpectedly\n"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LoginSession Logged Out Unexpectedly"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LoginSession Logged In\n"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LoginSession Logged In"));
	}
}
