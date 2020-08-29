#pragma once
#include "Factory.h"
#include "FordBus.h"
#include "FordCar.h"
#include "FordTruck.h"
class FordFactory :
	public Factory
{
public:
	Bus* createBus()const override;
	Car* createCar()const override;
	Truck* createTruck()const override;
};

