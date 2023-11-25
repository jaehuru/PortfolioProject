// Fill out your copyright notice in the Description page of Project Settings.


#include "TMapEx.h"

// Sets default values
ATMapEx::ATMapEx()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATMapEx::BeginPlay()
{
	Super::BeginPlay();

	TestTmap();
}

// Called every frame
void ATMapEx::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATMapEx::TestTmap()
{
	TMap<int32, FString> FruitMap;
    
	FruitMap.Add(5, TEXT("Banana"));
	FruitMap.Add(2, TEXT("GrapeFruit"));
	FruitMap.Add(7, TEXT("Pineapple"));
	
	//for(int i=0; i< FruitMap.Num(); ++i)

	/*for (auto Fruit : FruitMap)
	{
	    if (GEngine)
	        GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Black, FString::Printf(TEXT("%s"), *(Fruit.Value)));
	}*/
    
	FruitMap.Add(2, TEXT("Pear"));

	/*for (auto Fruit : FruitMap)
	{
	    if (GEngine)
	        GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, FString::Printf(TEXT("Add Pear%s"), *(Fruit.Value)));
	}*/

	FruitMap.Add(4);

	/*for (auto Fruit : FruitMap)
	{
	    if (GEngine)
	        GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Blue, FString::Printf(TEXT("Add 4 %s"), *(Fruit.Value)));
	}*/

	FruitMap.Emplace(3,TEXT("Orange"));
	
	/*for (auto Fruit : FruitMap)
	{
	    if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Orange, FString::Printf(TEXT("Add Orange %s"), *(Fruit.Value)));
	}*/

	TMap<int32, FString> FruitMap2;
	FruitMap2.Emplace(4, TEXT("Kiwi"));
	FruitMap2.Emplace(9, TEXT("Melon"));
	FruitMap2.Emplace(5, TEXT("Mango"));
	FruitMap.Append(FruitMap2);

	/*for (auto Fruit : FruitMap)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Emerald, FString::Printf(TEXT("AllFruitsMap Key %d , Value %s"),Fruit.Key, *(Fruit.Value)));
	}

	for (auto It = FruitMap.CreateConstIterator(); It; ++It)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, FString::Printf(TEXT("AllFruitsMap Key %d , Value %s"), It.Key(), *
			(It.Value())));
	}*/

	/*int32 Count = FruitMap.Num(); //과일사전에 과일 몇개나 있는지.
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, FString::Printf(TEXT("FruitNum %d"), Count));

	//과일사전에 7이 있는지 여부
	bool bHas7 = FruitMap.Contains(7);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Yellow, FString::Printf(TEXT("Has7 %s"), bHas7 ? TEXT("true") : TEXT("false")));

	//과일사전에 8이 있는지 여부
	bool bHas8 = FruitMap.Contains(8);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, FString::Printf(TEXT("Has8 %s"), bHas8 ? TEXT("true") : TEXT("false")));*/


	// Find 함수
	FString Ptr7 = *FruitMap.Find(7);
	FString Ptr8 = *FruitMap.FindOrAdd(9);

	auto autoPtr = *FruitMap.Find(7);

	/*if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, FString::Printf(TEXT("Ptr7 %s"), *Ptr7));
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Blue, FString::Printf(TEXT("Ptr8 %s"), *Ptr8));
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Blue, FString::Printf(TEXT("autoPtr %s"), *autoPtr));*/

	// 7 삭제
	FruitMap.Remove(7);
	for (auto Fruit : FruitMap)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Emerald, FString::Printf(TEXT("FruitMap 7 remove Key %d , Value %s"),Fruit.Key, *(Fruit.Value)));
	}
	
	// 내용 전부 삭제
	/*FruitMap.Empty();
	for (auto Fruit : FruitMap)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Emerald, FString::Printf(TEXT("All remove Key %d , Value %s"),Fruit.Key, *(Fruit.Value)));
	}*/

	// 내용 소팅
	FruitMap.KeySort([](int32 A, int32 B)
	{
		return A > B;
	});
	
	for (auto Fruit : FruitMap)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Blue, FString::Printf(TEXT("All sort FruitMap Key %d , Value %s"),Fruit
			.Key, *(Fruit.Value)));
	}

	FruitMap.ValueSort([](const FString& A, const FString& B)
	{
		return A.Len() < B.Len();
	});

	for (auto Fruit : FruitMap)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, FString::Printf(TEXT("All Value Sort FruitMap Key %d , Value %s"),
			Fruit.Key, *(Fruit.Value)));
	}
	
	/*FString& Ref7 = FruitMap.FindOrAdd(7);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, FString::Printf(TEXT("Ref7 %s"), Ref7));*/
	
}

