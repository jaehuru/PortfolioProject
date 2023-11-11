// Fill out your copyright notice in the Description page of Project Settings.


#include "PPGameInstance.h"
#include "SoundManagerSubsystem.h"

void UPPGameInstance::Init()
{
	SoundSubsystem = NewObject<USoundManagerSubsystem>(this, USoundManagerSubsystem::StaticClass(), FName("SoundSubSystem"));
}
