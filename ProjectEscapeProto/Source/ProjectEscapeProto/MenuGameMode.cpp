// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"


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
	SessionSettings->bUsesPresence = false;
	SessionSettings->bAllowJoinViaPresence = true;
	SessionSettings->bAllowJoinViaPresenceFriendsOnly = false;
	SessionSettings->bAntiCheatProtected = false;
	SessionSettings->bIsDedicated = false;
	SessionSettings->bUsesStats = false;
	SessionSettings->Set(SETTING_MAPNAME, FString("FirstPersonMap"), EOnlineDataAdvertisementType::ViaOnlineService);

	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	UE_LOG(LogTemp, Warning, TEXT("The name is: %s"), *Subsystem->GetSubsystemName().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
	                                 FString::Printf(
		                                 TEXT("Current Online Subsystem: %s"),
		                                 *Subsystem->GetSubsystemName().ToString()));
	if (Subsystem)
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			if (!CreateSessionCompleteDelegate)
			{
				CreateSessionCompleteDelegate = new FOnCreateSessionCompleteDelegate();
				CreateSessionCompleteDelegate->BindUObject(this, &AMenuGameMode::OnCreateSessionComplete);
				// Clear the delegate before adding it
				SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(*CreateSessionCompleteDelegate);
			}
			ULocalPlayer* const Player = GetWorld()->GetFirstLocalPlayerFromController();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
			                                 FString::Printf(
				                                 TEXT("Player Server: %s"),
				                                 *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString()));
			UE_LOG(LogTemp, Warning, TEXT("Player Server: %s"),
			       *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString());

			return SessionInterface->CreateSession(*Player->GetPreferredUniqueNetId().GetUniqueNetId(),
			                                       FName(*SessionName), *SessionSettings);
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
			SessionSearch = MakeShareable(new FOnlineSessionSearch());
			SessionSearch->bIsLanQuery = bIsLAN;
			SessionSearch->MaxSearchResults = 100;
			SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, false, EOnlineComparisonOp::Equals);

			FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
			FindSessionsCompleteDelegate.BindUObject(this, &AMenuGameMode::OnFindSessionComplete);
			SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionsCompleteDelegate);
			ULocalPlayer* const Player = GetWorld()->GetFirstLocalPlayerFromController();
			return SessionInterface->FindSessions(*Player->GetPreferredUniqueNetId().GetUniqueNetId(),
			                                      SessionSearch.ToSharedRef());
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
			if (SessionSearch->SearchResults.Num() <= 0)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No Sessions Found")));
				UE_LOG(LogTemp, Warning, TEXT("No Sessions Found"));
				return false;
			}
			FOnlineSessionSearchResult SearchResult = SessionSearch->SearchResults[0];
			ULocalPlayer* const Player = GetWorld()->GetFirstLocalPlayerFromController();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
			                                 FString::Printf(
				                                 TEXT("Player Client: %s"),
				                                 *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString()));
			UE_LOG(LogTemp, Warning, TEXT("Player Client: %s"),
			       *Player->GetPreferredUniqueNetId().GetUniqueNetId()->ToString());


			FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegateHandle;
			OnJoinSessionCompleteDelegateHandle.BindUObject(this, &AMenuGameMode::OnJoinSessionComplete);
			SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
			
			return SessionInterface->JoinSession(*Player->GetPreferredUniqueNetId().GetUniqueNetId(),
			                                     FName(*SessionName), SearchResult);
		}
	}
	return false;
}

void AMenuGameMode::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Join Session Complete")));
	// Get the OnlineSubsystem we want to work with
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		// Get SessionInterface from the OnlineSubsystem
		IOnlineSessionPtr Sessions = Subsystem->GetSessionInterface();

		if (Sessions.IsValid())
		{
			// // Clear the Delegate again
			// Sessions->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);

			// Get the first local PlayerController, so we can call "ClientTravel" to get to the Server Map
			// This is something the Blueprint Node "Join Session" does automatically!
			APlayerController * const PlayerController = GetWorld()->GetFirstPlayerController();

			// We need a FString to use ClientTravel and we can let the SessionInterface contruct such a
			// String for us by giving him the SessionName and an empty String. We want to do this, because
			// Every OnlineSubsystem uses different TravelURLs
			FString TravelURL;

			if (PlayerController && Sessions->GetResolvedConnectString(SessionName, TravelURL))
			{
				// Finally call the ClienTravel. If you want, you could print the TravelURL to see
				// how it really looks like
				PlayerController->ClientTravel(TravelURL, ETravelType::TRAVEL_Absolute);
			}
		}
	}
}
