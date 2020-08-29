#include "Automobile.h"

Automobile::Automobile()
{
	number = 0;
}

Automobile::Automobile(int number)
{
	this->number = number;
}

Automobile::~Automobile()
{

}

void Automobile::setNumber(int number)
{
	this->number = number;
}

int Automobile::getNumber() const
{
	return number;
}
