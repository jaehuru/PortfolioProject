// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerEx.h"

// Sets default values
AContainerEx::AContainerEx()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AContainerEx::BeginPlay()
{
	Super::BeginPlay();
	AddUniqueArray();
	//TestStringArray();
	
	//Init 함수로 Tarray 요소 채우기
	// IntArray.Init(10, 5); //InitArray = {10,10,10,10,10}
	//
	// for(auto Iter: IntArray)
	// {
	// 	if (GEngine)
	// 		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Iterator Acess %d"), Iter));
	// }
	//
	// for(int i = 0; i < IntArray.Num(); ++i)
	// {
	// 	if (GEngine)
	// 		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Iterator Acess %d"), IntArray[i]));
	// }
}

// Called every frame
void AContainerEx::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AContainerEx::TestStringArray()
{
	TArray<FString> StrArray;
	StrArray.Add(TEXT("Hello"));
	StrArray.Emplace(TEXT("World"));

	//StrArray = ["Hello", "World]

	FString Arr[] = { TEXT("of"), TEXT("Tomorrow") };
	StrArray.Append(Arr, UE_ARRAY_COUNT(Arr));

	for(auto Iter: Arr)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("String Array Acess %s"), *Iter));
	}
}

void AContainerEx::AddUniqueArray()
{
	TArray<FString> StrArray;
	StrArray.Add(TEXT("Hello"));
	StrArray.Emplace(TEXT("World"));

	FString Arr[] = { TEXT("of"),TEXT("Tomorrow") };

	StrArray.Append(Arr, UE_ARRAY_COUNT(Arr));
	StrArray.AddUnique(TEXT("!"));

	for (auto Iter : StrArray)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf
			(TEXT("String Array Acess %s"), *Iter));
	}
    
	StrArray.AddUnique(TEXT("!"));
	//추가 되지않는다.

	for (auto Iter : StrArray)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf
			(TEXT("String Array Acess %s"), *Iter));
	}

}

