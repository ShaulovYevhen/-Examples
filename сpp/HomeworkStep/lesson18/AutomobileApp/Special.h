#pragma once
#include "Automobile.h"
class Special :
	public Automobile
{
protected:
	char* organization = nullptr;
public:
	Special();
	Special(const char* n, int number);
	virtual ~Special() = 0;
	const char* getOrganization() const;
	void setOrganization(const char* n);
};

