#include "Special.h"

Special::Special()
{
	organization = _strdup("noOrganization");
}

Special::Special(const char* n, int number) : Automobile(number)
{
	organization = _strdup("n");
}

Special::~Special()
{
}

const char* Special::getOrganization() const
{
	return organization;
}

void Special::setOrganization(const char* n)
{
	organization = _strdup("n");
}
