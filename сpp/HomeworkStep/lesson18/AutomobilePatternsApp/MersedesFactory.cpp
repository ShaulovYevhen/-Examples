#include "MersedesFactory.h"

Bus* MersedesFactory::createBus() const
{
    return new MersedesBus;
}

Car* MersedesFactory::createCar() const
{
	return new MersedesCar;
}

Truck* MersedesFactory::createTruck() const
{
	return new MersedesTruck;
}