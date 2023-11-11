// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundManagerSubsystem.h"
#include "Sound/SoundCue.h"

bool USoundManagerSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	Super::ShouldCreateSubsystem(Outer);
	return true;
}

void USoundManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InitSounds();
}

void USoundManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	
}

void USoundManagerSubsystem::InitSounds()
{
	SoundStringMap.Add(TEXT("Explosion"),TEXT("ExplosionSound"));
	SoundStringMap.Add(TEXT("Apple"),TEXT("AppleSound"));
	SoundStringMap.Add(TEXT("Banana"),TEXT("BananaSound"));
	SoundStringMap.Add(TEXT("Pickup"),TEXT("PickupSound"));
	SoundStringMap.Add(TEXT("Destroy"),TEXT("DestroySound"));
}

void USoundManagerSubsystem::PushSound(FString FSoundName, FString FSound)
{
	SoundStringMap.Add(FSoundName, FSound);
}

void USoundManagerSubsystem::PlaySound(FString FSoundName)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FSoundName);

	if (GEngine)
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FSoundName);
}

