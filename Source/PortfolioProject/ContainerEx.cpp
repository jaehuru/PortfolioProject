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
	//TestStringArray();
	//AddUniqueArray();
	//IterArray();
	SortArray();
}

void AContainerEx::TestStringArray()
{
	TArray<FString> StrArray;
	StrArray.Add(TEXT("Hello"));
	StrArray.Emplace(TEXT("World")); 

	//StrArray = ["Hello","World"]

	FString Arr[] = { TEXT("of"),TEXT("Tomorrow") };
	StrArray.Append(Arr, UE_ARRAY_COUNT(Arr));

	for (auto Iter : Arr)
	{
		if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf
		(TEXT("String Array Acess %s"), *Iter));
	}
}

void AContainerEx::AddUniqueArray()
{
	//Add Unique를 통해 배열 요소를 유니크 하게 (중복 없도록) 추가 할수 있는 함수 기능 실습
	TArray<FString> StrArray;
	StrArray.Add(TEXT("Hello"));
	StrArray.Emplace(TEXT("World"));

	FString Arr[] = { TEXT("of"),TEXT("Tomorrow") };

	StrArray.Append(Arr, UE_ARRAY_COUNT(Arr));
	StrArray.AddUnique(TEXT("!"));

}

void AContainerEx::IterArray()
{
	//기존 for문 (i를 활용해 순회하는 기능과 다르게) Auto Iterator를 써서 순회 하는 기능 
	FString JoinedStr;
	TArray<FString> StrArray;

	StrArray.Add(TEXT("Hello"));				
	StrArray.Emplace(TEXT("World"));

	FString Arr[] = { TEXT("of"),TEXT("Tomorrow") };

	StrArray.Append(Arr, UE_ARRAY_COUNT(Arr));
	StrArray.AddUnique(TEXT("!"));


	for (int i = 0; i < StrArray.Num(); ++i)
	{
		StrArray[i];
	}

	for (auto& Str : StrArray)
	{
		JoinedStr += Str;
		JoinedStr += TEXT(" ");
	}

	PrintTArrayString(TEXT("+=Str"), StrArray, FColor::Green);

	for (int32 Index = 0; Index != StrArray.Num(); ++Index)
	{
		JoinedStr += StrArray[Index];
		JoinedStr += TEXT(" ");
	}
	PrintTArrayString(TEXT("Index"), StrArray , FColor::Blue);

	for (auto It = StrArray.CreateConstIterator(); It; ++It)
	{
		JoinedStr += *It;
		JoinedStr += TEXT(" ");
	}

	PrintTArrayString(TEXT("Iterator"), StrArray, FColor::Cyan);
}
void AContainerEx::PrintTArrayString(FString NoticeMent, TArray<FString> const& TargetArray, FColor Color = FColor::Black) const
{
	//TArray 요소 모두 출력하기 위해서 쓰는 함수
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, Color, FString::Printf
		(TEXT("%s"),*NoticeMent));

	for (auto Iter : TargetArray)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, Color, FString::Printf
			(TEXT("%s"), *Iter));
	}
}

void AContainerEx::PrintTArrayString(FString NoticeMent, TArray<int> const& TargetArray, FColor Color = FColor::Black) const
{
	//TArray 요소 모두 출력하기 위해서 쓰는 함수
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, Color, FString::Printf
		(TEXT("%s"), *NoticeMent));

	for (auto Iter : TargetArray)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, Color, FString::Printf
			(TEXT("%d"), Iter));
	}
}

void AContainerEx::SortArray()
{
	TArray<int> IntArray;
	
	IntArray.Add(999);
	IntArray.Add(123);
	IntArray.Add(9);
	IntArray.Add(3);
	IntArray.Add(1);
	IntArray.Add(17);
	IntArray.Add(2);

	IntArray.Sort([](int A, int B)
	{
		return A < B;
	});
	//람다.
	
	PrintTArrayString("Sort TArray", IntArray, FColor::Cyan);

	IntArray.Sort([](int A, int B)
	{
		return A > B;
	});
	
	PrintTArrayString("Reverse Sort TArray", IntArray, FColor::Magenta);

	
}
