#pragma once
#include "Truck.h"
class FordTruck :
	public Truck
{
public:
	FordTruck();
	void info()const override;
};

