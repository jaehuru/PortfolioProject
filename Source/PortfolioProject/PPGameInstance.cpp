// Fill out your copyright notice in the Description page of Project Settings.


#include "PPGameInstance.h"
#include "SoundManagerSubsystem.h"
#include "TemplateTest.h"

void UPPGameInstance::Init()
{
	SoundSubsystem = NewObject<USoundManagerSubsystem>(this, USoundManagerSubsystem::StaticClass(), FName("SoundSubSystem"));
	//TemplateTest();
}

void UPPGameInstance::TemplateTest(double a, double b)
{
	double DoubleMax = TemplateTest::max(a,b);
	int IntMax = TemplateTest::max((int)a, (int)b);
	float FloatMax = TemplateTest::max((float)a, (float)b);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), max);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black,
			FString::Printf(TEXT("DoubleMax %lf IntMax %d FloatMax %f"),DoubleMax,IntMax,FloatMax));
}
