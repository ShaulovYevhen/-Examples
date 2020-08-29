#pragma once
#include "Car.h"
class FordCar :
	public Car
{
public:
	FordCar();
	void info()const override;
};

