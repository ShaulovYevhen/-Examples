#include "MersedesTruck.h"
MersedesTruck::MersedesTruck() : Truck(180)
{
}

void MersedesTruck::info() const
{
    cout << "Mersedes Truck" << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}
