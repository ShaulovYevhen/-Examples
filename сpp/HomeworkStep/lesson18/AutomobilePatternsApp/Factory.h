#pragma once

#include "Bus.h"
#include "Car.h"
#include "Truck.h"

class Factory
{
    virtual Bus* createBus()const = 0;
    virtual Car* createCar()const = 0;
    virtual Truck* createTruck()const = 0;
    virtual ~Factory();
};

