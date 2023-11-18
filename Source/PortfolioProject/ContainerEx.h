// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContainerEx.generated.h"

UCLASS()
class PORTFOLIOPROJECT_API AContainerEx : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContainerEx();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	void TestStringArray(); //String Array 출력 테스트 하는 함수
	
	void AddUniqueArray();  // Array Unique하게 넣어주는 기능 테스트
	
	void IterArray();   // Iterator 를 활용하여 For문을 순회하는 기능
	
	void PrintTArrayString(FString NoticeMent, TArray<FString>const& TargetArray, FColor Color)const; // Array 내부의 요소를 프린트 해주는 함수
	
	void PrintTArrayString(FString NoticeMent, TArray<int>const& TargetArray, FColor Color)const; // Array 내부의 요소를 프린트 해주는 함수
	
	void SortArray();
	
};
