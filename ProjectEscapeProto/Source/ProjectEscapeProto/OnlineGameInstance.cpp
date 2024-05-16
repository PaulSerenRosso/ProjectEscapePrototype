// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"

void UOnlineGameInstance::Init()
{
	Super::Init();
	//InitVivox();
}

void UOnlineGameInstance::InitVivox()
{
	MyVoiceModule = &FModuleManager::Get().LoadModuleChecked<FVivoxCoreModule>("VivoxCore");
}
