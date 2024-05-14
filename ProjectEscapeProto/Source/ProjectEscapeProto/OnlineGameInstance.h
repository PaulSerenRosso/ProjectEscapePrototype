// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "OnlineGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTESCAPEPROTO_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

	void OnFindSessionsComplete(bool bArg);
	UFUNCTION(BlueprintCallable)
	void FindAllSessions();
	void OnJoinSessionComplete(FName Name, EOnJoinSessionCompleteResult::Type Arg);
	void JoinFirstSession();

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString pathToLobbyMap = "/Game/FirstPerson/Maps/FirstPersonMap";
	
};
