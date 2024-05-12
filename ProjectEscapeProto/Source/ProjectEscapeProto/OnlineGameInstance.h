// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTESCAPEPROTO_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Menu")
	bool DestroySession(FName SessionName);
};