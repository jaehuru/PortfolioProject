// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnWithCnt(20);
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnManager::SpawnWithCnt(int cnt)
{
	if (MonsterClass)
	{
		for (int i = 0; i < cnt; ++i)
		{
			FTransform MonsterTransform;
			MonsterTransform.SetLocation(FVector(i * 200, i * 200, 120));
			GetWorld()->SpawnActor<AActor>(MonsterClass, MonsterTransform);
		}
	}
}

void ASpawnManager::SpawnWithRandom()
{
	if (MonsterClass)
	{
		FTransform MonsterTransform;
		float RandomX = UKismetMathLibrary::RandomFloatInRange(0, 2000.f);
		float RandomY = UKismetMathLibrary::RandomFloatInRange(0, 2000.f);
	
		MonsterTransform.SetLocation(FVector(RandomX, RandomY, 120));
		GetWorld()->SpawnActor<AActor>(MonsterClass, MonsterTransform);
	}
	
}

void ASpawnManager::BindSpawn()
{
	FTimerHandle SpawnTimerHandle;
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::SpawnWithRandom, SpawnDuration, true);
}

