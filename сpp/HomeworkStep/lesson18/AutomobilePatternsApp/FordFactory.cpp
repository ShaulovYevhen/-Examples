#include "FordFactory.h"
Bus* FordFactory::createBus() const
{
	return new FordBus;
}

Car* FordFactory::createCar() const
{
	return new FordCar;
}

Truck* FordFactory::createTruck() const
{
	return new FordTruck;
}