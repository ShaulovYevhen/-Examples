#include "FordCar.h"

FordCar::FordCar() : Car(150)
{
}

void FordCar::info() const
{
    cout << "Ford Car" << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}