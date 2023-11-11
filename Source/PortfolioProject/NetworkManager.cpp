// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkManager.h"
#include "Misc/DateTime.h"

UNetworkManager::UNetworkManager()
{
}

UNetworkManager::~UNetworkManager()
{
}

void UNetworkManager::GetCurrentTime()
{
	FDateTime Now = FDateTime::UtcNow();
	FString TimeString = Now.ToString(TEXT("%H:%M:%S.%f"));
	UE_LOG(LogTemp, Warning, TEXT("Current time with milliseconds : %s"), *TimeString);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("%s"),*TimeString));
}

FDateTime UNetworkManager::GetDateTime()
{
	return  FDateTime::UtcNow();
}

void UNetworkManager::Init()
{
}
