#pragma once
#include "Observer.h"
#include "Mail.h"
#include <iostream>
#include <string>
class Subscriber :
	public Observer
{
public:
	Subscriber(Mail* mail);
	~Subscriber();
	void Update();
private:
	Mail* mail;
};

