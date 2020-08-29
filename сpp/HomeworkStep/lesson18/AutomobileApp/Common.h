#pragma once
#include "Automobile.h"
class Common :
	public Automobile
{
protected:
	char* color = nullptr;
public:
	Common();
	Common(const char* n, int number);
	virtual ~Common() = 0;
	const char* getColor() const;
	void setColor(const char* n);
};



