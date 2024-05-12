// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"

#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

bool UOnlineGameInstance::DestroySession(FName SessionName)
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
