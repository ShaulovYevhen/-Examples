#include "FordTruck.h"

FordTruck::FordTruck() : Truck(150)
{
}

void FordTruck::info() const
{
    cout << "Ford Truck" << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}