#pragma once
#include "Observer.h"
#include "Mail.h"
#include <iostream>
#include <string>
class Phone :
	public Observer
{
public:
	Phone(Mail* mail);
	~Phone();
	void Update();
private:
	Mail* mail;
};