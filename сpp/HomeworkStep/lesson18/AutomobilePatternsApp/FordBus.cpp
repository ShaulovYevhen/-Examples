#include "FordBus.h"

FordBus::FordBus() : Bus(150)
{
}

void FordBus::info() const
{
    cout << "Ford Bus" << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}
