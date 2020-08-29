#include "MersedesBus.h"
MersedesBus::MersedesBus() :Bus(115)
{
}

void MersedesBus::info() const
{
    cout << "Mersedes Bus" << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}