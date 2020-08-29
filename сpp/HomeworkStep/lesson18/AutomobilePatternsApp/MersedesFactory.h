#pragma once
#include "MersedesBus.h"
#include "MersedesCar.h"
#include "MersedesTruck.h"

#include "Factory.h"

class MersedesFactory :public  Factory
{
public:
    Bus* createBus() const override;
	Car* createCar()const override;
	Truck* createTruck()const override;
};