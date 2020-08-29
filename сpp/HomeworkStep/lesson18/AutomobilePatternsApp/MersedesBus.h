#pragma once
#include "Bus.h"
class MersedesBus :public Bus
{
public:
    MersedesBus();
    void info()const override;
};
