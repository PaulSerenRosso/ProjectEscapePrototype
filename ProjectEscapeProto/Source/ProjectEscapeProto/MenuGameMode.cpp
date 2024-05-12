// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"



bool AMenuGameMode::CreateSession(FString SessionName, bool bIsLAN, int32 MaxNumPlayers)
{
	FOnlineSessionSettings* SessionSettings = new FOnlineSessionSettings();
	SessionSettings->bIsLANMatch = bIsLAN;
	SessionSettings->bUseLobbiesVoiceChatIfAvailable = true;
	SessionSettings->NumPublicConnections = MaxNumPlayers;
	SessionSettings->NumPrivateConnections = MaxNumPlayers;
	SessionSettings->bShouldAdvertise = true;
	SessionSettings->bAllowJoinInProgress = true;
	SessionSettings->bAllowInvites = true;
	SessionSettings->bUsesPresence = true;
	SessionSettings->bAllowJoinViaPresence = true;
	SessionSettings->bAllowJoinViaPresenceFriendsOnly = false;
	SessionSettings->bAntiCheatProtected = false;
	SessionSettings->bIsDedicated = false;
	SessionSettings->bUsesStats = false;

	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	UE_LOG(LogTemp, Warning, TEXT("The name is: %s"), *Subsystem->GetSubsystemName().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Current Online Subsystem: %s"), *Subsystem->GetSubsystemName().ToString()));
	if (Subsystem)
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			if (!CreateSessionCompleteDelegate)
			{
				CreateSessionCompleteDelegate = new FOnCreateSessionCompleteDelegate();
				CreateSessionCompleteDelegate->BindUObject(this, &AMenuGameMode::OnCreateSessionComplete);// Clear the delegate before adding it
				SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(*CreateSessionCompleteDelegate);
			}
			ULocalPlayer* const Player = GetWorld()->GetFirstLocalPlayerFromController();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Player Server: %s"), *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString()));
			UE_LOG(LogTemp, Warning, TEXT("Player Server: %s"), *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString());

			return SessionInterface->CreateSession(*Player->GetPreferredUniqueNetId().GetUniqueNetId(), FName(*SessionName), *SessionSettings);
		}
	}
	return false;
}

bool AMenuGameMode::FindSession(bool bIsLAN)
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	
	if (Subsystem)
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			TSharedRef<FOnlineSessionSearch> SessionSearch = MakeShared<FOnlineSessionSearch>();
			SessionSearch->bIsLanQuery = bIsLAN;
			SessionSearch->MaxSearchResults = 100;

			FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
			FindSessionsCompleteDelegate.BindUObject(this, &AMenuGameMode::OnFindSessionComplete);
			SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionsCompleteDelegate);
			ULocalPlayer* const Player = GetWorld()->GetFirstLocalPlayerFromController();
			return SessionInterface->FindSessions(*Player->GetPreferredUniqueNetId().GetUniqueNetId(), SessionSearch);
		}
	}
	return false;
}

bool AMenuGameMode::JoinSession(FString SessionName)
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			ULocalPlayer* const Player = GetWorld()->GetFirstLocalPlayerFromController();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Player Client: %s"), *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString()));
UE_LOG(LogTemp, Warning, TEXT("Player Client: %s"), *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString());
			return SessionInterface->JoinSession(*Player->GetPreferredUniqueNetId().GetUniqueNetId(), FName(*SessionName), FOnlineSessionSearchResult());
		}
	}
	return false;
}
