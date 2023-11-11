// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SoundManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIOPROJECT_API USoundManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	virtual bool ShouldCreateSubsystem(UObject* Outer)const; // 무조건 만들어져야 한다
	virtual void Initialize(FSubsystemCollectionBase& Collection); // 초기화
	virtual void Deinitialize(); //소멸

public:
	void InitSounds();

	UFUNCTION(BlueprintCallable, Category = "Sound")
	void PushSound(FString FSoundName, FString FSound);
	
	UFUNCTION(Exec, BlueprintCallable, Category = "Sound")
	void PlaySound(FString FSoundName);

	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SoundManager")
	TMap<FString, class USoundCue*> SoundMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SoundManager")
	TMap<FString, FString> SoundStringMap;
	
};
