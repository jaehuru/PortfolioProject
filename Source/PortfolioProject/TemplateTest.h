// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PORTFOLIOPROJECT_API TemplateTest
{
public:
	TemplateTest();
	~TemplateTest();

public:
	static int PPmax(int a, int b)
	{
		return  (a > b ? a : b);
	}

	static double PPmax(double a, double b)
	{
		return (a > b ? a : b);
	}
	
	static short PPmax(short a, short b)
	{
		return (a > b ? a : b);
	}
	
	static char PPmax(char a, char b)
	{
		return (a > b ? a : b);
	}

	template <typename T>
	static T max(T a, T b)
	{
		return (a > b ? a : b);
	}
};


