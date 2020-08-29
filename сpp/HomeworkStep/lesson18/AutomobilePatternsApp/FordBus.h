#pragma once
#include "Bus.h"
class FordBus :
	public Bus
{
public:
	FordBus();
	void info()const override;
};

