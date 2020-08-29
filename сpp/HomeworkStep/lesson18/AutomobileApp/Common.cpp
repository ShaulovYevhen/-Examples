#include "Common.h"

Common::Common()
{
	color = _strdup("Nocolor");
}

Common::Common(const char* n, int number) :Automobile(number)
{
	this->color = _strdup(n);
}

Common::~Common()
{
}

const char* Common::getColor() const
{
	return color;
}

void Common::setColor(const char* n)
{
	this->color = _strdup(n);
}
