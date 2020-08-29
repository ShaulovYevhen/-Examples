#pragma once

#include <string>
#include <iostream>
using namespace std;
class Auto
{
    int number;
public:
    Auto(int _number);
    virtual void info()const = 0;
    virtual ~Auto();
    int getNumber()const;
    void setNumber(int _hp);
};