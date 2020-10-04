#pragma once
#include "NotUrgent.h"
#include "Urgent.h"
#include "VeryUrgent.h"
class Factory
{
public:
    virtual NotUrgent* createNotUrgent()const = 0;
    virtual Urgent* createUrgent()const = 0;
    virtual VeryUrgent* createVeryUrgent()const = 0;
    virtual ~Factory();
};

