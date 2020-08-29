#pragma once
#include "Truck.h"
class MersedesTruck :
	public Truck
{
public:
	MersedesTruck();
	void info()const override;
};

