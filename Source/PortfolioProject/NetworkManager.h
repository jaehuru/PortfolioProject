// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Singleton.h"
#include "UObject/NoExportTypes.h"
#include "NetworkManager.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIOPROJECT_API UNetworkManager : public UObject, public FSingleton<UNetworkManager>
{
	GENERATED_BODY()

public:
	UNetworkManager();
	virtual ~UNetworkManager();

	void GetCurrentTime();
	FDateTime GetDateTime();

	void Init();
};
