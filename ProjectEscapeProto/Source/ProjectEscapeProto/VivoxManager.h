// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VivoxCore.h"
#include "VivoxManager.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTESCAPEPROTO_API UVivoxManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVivoxManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitializeVivox();
	void OnChannelStateChanged(const IChannelConnectionState& ChannelConnectionState);
	void JoinChannel();
	void OnLoginSessionStateChanged(LoginState State);

protected:
	ILoginSession *MyLoginSessionPtr;
	IClient *MyVoiceClient;
 };
