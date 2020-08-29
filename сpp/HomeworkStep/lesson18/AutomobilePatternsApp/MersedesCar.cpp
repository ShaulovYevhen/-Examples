#include "MersedesCar.h"
MersedesCar::MersedesCar() : Car(150)
{
}

void MersedesCar::info() const
{
    cout << "Mersedes Car" << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}