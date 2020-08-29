#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Automobile
{
protected:
    int number = 0;
public:
    Automobile();
    Automobile(int number);
    virtual ~Automobile() = 0;
    void setNumber(int number);
    int getNumber()const;
};



