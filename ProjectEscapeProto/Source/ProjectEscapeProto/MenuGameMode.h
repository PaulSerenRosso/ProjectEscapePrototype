// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/OnlineSessionDelegates.h"
#include "MenuGameMode.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTESCAPEPROTO_API AMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Menu")
	void OnCreateSessionComplete(FName Name, bool bArg);
	UFUNCTION(BlueprintImplementableEvent, Category = "Menu")
	void OnFindSessionComplete(bool bArg);

	protected:
	UFUNCTION(BlueprintCallable, Category = "Menu")
	bool CreateSession(FString SessionName, bool bIsLAN, int32 MaxNumPlayers);
	UFUNCTION(BlueprintCallable, Category = "Menu")
	bool FindSession(bool bIsLAN);
	UFUNCTION(BlueprintCallable, Category = "Menu")
	bool JoinSession(FString SessionName);

private:
	/**
	 * 
	 */
	FOnCreateSessionCompleteDelegate *CreateSessionCompleteDelegate = nullptr;
};
