#pragma once
#include "Special.h"
class Builder :
	public Special
{
	Builder(const char* n, int number);
	virtual void work();
};

