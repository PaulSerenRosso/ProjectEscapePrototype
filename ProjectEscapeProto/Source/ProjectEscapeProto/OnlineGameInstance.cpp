// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"
#include "OnlineSubsystem.h"

void UOnlineGameInstance::OnFindSessionsComplete(bool bArg)
{
	UE_LOG(LogTemp, Warning, TEXT("OnFindSessionsComplete: %d"), bArg);
	int nbLobbies = SessionSearch->SearchResults.Num();
	UE_LOG(LogTemp, Warning, TEXT("nbLobbies: %d"), nbLobbies);
	for (int i = 0; i < nbLobbies; i++)
	{
		FOnlineSessionSearchResult Lobby = SessionSearch->SearchResults[i];
		UE_LOG(LogTemp, Warning, TEXT("Lobby %d: %s"), i, *Lobby.GetSessionIdStr());
	}
	if (nbLobbies > 0)
	{
		JoinFirstSession();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No lobbies found"));
	}
}

void UOnlineGameInstance::FindAllSessions()
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem)
	{
		IOnlineSessionPtr Session = OnlineSubsystem->GetSessionInterface();

		if (Session.IsValid())
		{
			SessionSearch = MakeShareable(new FOnlineSessionSearch());
			SessionSearch->bIsLanQuery = false;
			SessionSearch->MaxSearchResults = 100;

			FOnFindSessionsCompleteDelegate OnJoinSessionCompleteDelegateHandle;
			OnJoinSessionCompleteDelegateHandle.BindUObject(this, &UOnlineGameInstance::OnFindSessionsComplete);

			Session->AddOnFindSessionsCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
			ULocalPlayer* LocalPlayer = GetFirstGamePlayer();

			Session->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Session is not valid"));
		}
	}
}

void UOnlineGameInstance::OnJoinSessionComplete(FName Name, EOnJoinSessionCompleteResult::Type Arg)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Join Session Complete")));
	// Get the OnlineSubsystem we want to work with
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		IOnlineSessionPtr Sessions = Subsystem->GetSessionInterface();

		if (Sessions.IsValid())
		{
			APlayerController* const PlayerController = GetWorld()->GetFirstPlayerController();

			FString TravelURL;

			if (PlayerController && Sessions->GetResolvedConnectString(Name, TravelURL))
			{
				PlayerController->ClientTravel(TravelURL, ETravelType::TRAVEL_Absolute);
			}
		}
	}
}

void UOnlineGameInstance::JoinFirstSession()
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem)
	{
		IOnlineSessionPtr Session = OnlineSubsystem->GetSessionInterface();

		if (Session.IsValid())
		{
			if (SessionSearch->SearchResults.Num() > 0)
			{
				FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegateHandle;
				OnJoinSessionCompleteDelegateHandle.BindUObject(this, &UOnlineGameInstance::OnJoinSessionComplete);
				Session->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);

				FString SessionName = SessionSearch->SearchResults[0].Session.OwningUserName;


				Session->JoinSession(*GetFirstGamePlayer()->GetPreferredUniqueNetId(), FName(*SessionName),
				                     SessionSearch->SearchResults[0]);
			}
		}
	}
}
