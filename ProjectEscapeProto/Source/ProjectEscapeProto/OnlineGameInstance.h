// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VivoxCore.h"
#include "OnlineGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTESCAPEPROTO_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
private:
	void InitVivox();

public:
	FVivoxCoreModule *MyVoiceModule;
	FString kDefaultKey = "eyXkpK8qcw3r0YnyISUvA1NkiKLJlseF";
	FString kDefaultServer = "https://unity.vivox.com/appconfig/90719-proje-41231-udash";
	FTimespan kDefaultExpiration = FTimespan::FromSeconds(3600);
	FString kDefaultIssuer = "90719-proje-41231-udash";
	FString kDefaultDomain = "mtu1xp.vivox.com";
};
