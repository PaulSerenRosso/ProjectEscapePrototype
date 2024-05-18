// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"

#include "DummyViewport.h"
#include "VivoxManager.h"

void UOnlineGameInstance::Init()
{
	Super::Init();
	/*InitVivox();
	InitializeClient();*/
}

void UOnlineGameInstance::InitVivox()
{
	MyVoiceModule = &FModuleManager::Get().LoadModuleChecked<FVivoxCoreModule>("VivoxCore");
}

bool UOnlineGameInstance::InitializeClient()
{
	if (!MyVoiceModule)
	{
		return false;
	}

	if (kDefaulEndPoint.IsEmpty() || kDefaultDomain.IsEmpty() || kDefaultIssuer.IsEmpty() || kDefaultKey.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Make sure server and Domain and Issuer and SecretKey is set"));
		return false;
	}

	MyVoiceClient = &MyVoiceModule->VoiceClient();
	bool bSuccess = MyVoiceClient->Initialize() == VxErrorSuccess;
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to initialize voice client"));
		return false;
	}
	FString RandomName = UVivoxManager::GetRandomString(10);
	GetEngine()->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Finish to Initialize Vivox"));
	GetEngine()->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Try to Sign In"));
	SignIn(RandomName, RandomName, kDefaultExpiration);


	return true;
}

int32 UOnlineGameInstance::SignIn(FString InputUsername, FString InputDisplayName, FTimespan Expiration)
{
	if (InputUsername.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("make sure username is set"));
		return 99;
	}

	if (InputDisplayName.IsEmpty())
	{
		InputDisplayName = InputUsername;
	}

	AccountId TempAccountId = AccountId(*kDefaultIssuer, *InputUsername, *kDefaultDomain, InputDisplayName);

	if (!TempAccountId.IsValid())
	{
		UE_LOG(LogTemp, Warning,
		       TEXT("AccountId id not valid, try again and make sure vivox cridentials and input is good"));
		return 98;
	}

	AccountIds.Add(InputUsername, TempAccountId);

	ILoginSession& MyLoginSession(MyVoiceClient->GetLoginSession(TempAccountId));
	// MyLoginSession.EventStateChanged.AddUObject(this, &UOnlineGameInstance::OnLoginSessionStateChanged,
	//                                             TempAccountId.Name());

	AsyncTask(ENamedThreads::GameThread, [this, TempAccountId, Expiration, InputUsername]()
	{
		ILoginSession& MyLoginSession(MyVoiceClient->GetLoginSession(TempAccountId));
		FString VivoxLoginToken = MyLoginSession.GetLoginToken(kDefaultKey, Expiration);

		ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleted;

		OnBeginLoginCompleted.BindLambda([this, &MyLoginSession, InputUsername](VivoxCoreError Error)
		{
			UE_LOG(LogTemp, Warning, TEXT("login error code: %i"), Error);
			MyInputUsername = InputUsername;
		});

		MyLoginSession.BeginLogin(kDefaulEndPoint, VivoxLoginToken, OnBeginLoginCompleted);
	});

	return 0;
}


// void UOnlineGameInstance::TickPosittion(APawn* PlayerPawn)
// {
// 	Update3dPositionalChannel(MyInputUsername, ChannelName, PlayerPawn->GetActorLocation(),
// 	                          PlayerPawn->GetActorLocation(), PlayerPawn->GetActorForwardVector(),
// 	                          PlayerPawn->GetActorUpVector());
// }
