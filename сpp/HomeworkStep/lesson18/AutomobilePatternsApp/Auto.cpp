#include "Auto.h"

Auto::Auto(int _number)
{
    number = _number;
}

Auto::~Auto() = default;

int Auto::getNumber() const
{
    return number;
}

void Auto::setNumber(int _hp)
{
    number = _hp;
}