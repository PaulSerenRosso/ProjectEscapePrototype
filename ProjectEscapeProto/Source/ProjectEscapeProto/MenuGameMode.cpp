// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"



bool AMenuGameMode::CreateSession(FString SessionName, bool bIsLAN, int32 MaxNumPlayers)
{
	FOnlineSessionSettings* SessionSettings = new FOnlineSessionSettings();
	// SessionSettings->bIsLANMatch = bIsLAN;
	SessionSettings->NumPublicConnections = MaxNumPlayers;
	// SessionSettings->NumPrivateConnections = MaxNumPlayers;
	SessionSettings->bShouldAdvertise = false;
	// SessionSettings->bAllowJoinInProgress = true;
	// SessionSettings->bAllowInvites = true;
	SessionSettings->bUsesPresence = true;
	// SessionSettings->bAllowJoinViaPresence = true;
	// SessionSettings->bAllowJoinViaPresenceFriendsOnly = false;
	// SessionSettings->bAntiCheatProtected = false;
	// SessionSettings->bIsDedicated = false;
	// SessionSettings->bUsesStats = false;

	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
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
			

			return SessionInterface->CreateSession(0, FName(*SessionName), *SessionSettings);
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
			SessionSearch->PingBucketSize = 50;

			FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
			FindSessionsCompleteDelegate.BindUObject(this, &AMenuGameMode::OnFindSessionComplete);
			return SessionInterface->FindSessions(0, SessionSearch);
		}
	}
	return false;
}

bool AMenuGameMode::JoinSession(FName SessionName)
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{			
			return SessionInterface->JoinSession(0, SessionName, FOnlineSessionSearchResult());
		}
	}
	return false;
}

bool AMenuGameMode::DestroySession(FName SessionName)
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			return SessionInterface->DestroySession(SessionName);
		}
	}
	return false;
}
