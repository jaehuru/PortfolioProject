#pragma once

#include "CoreMinimal.h"

template <typename  Type>
class  FSingleton
{
public:
	FSingleton() {}
	virtual ~FSingleton()
	{
		if (Inst)
		{
			Inst->RemoveFromRoot();	
		}
		Inst = nullptr;
	}

	static Type* Instance()
	{
		if (Inst == nullptr)
		{
			Inst = NewObject<Type>();
			Inst->AddToRoot(); //GC 방지
		}
		return Inst;
	}
protected:
	static Type* Inst;
	
};
template<typename Type>
Type* FSingleton<Type>::Inst = nullptr;
