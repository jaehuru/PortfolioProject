// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SoundManagerSubsystem.h"
#include "Engine/GameInstance.h"
#include "PPGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class PORTFOLIOPROJECT_API UPPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init();

public:
	UFUNCTION(Exec, BlueprintCallable, Category = "Sound")
	void TemplateTest(double a, double b);

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Subsystem")
	USoundManagerSubsystem* SoundSubsystem;
	
};
