#pragma once
#include "Observer.h"
#include "Mail.h"
#include <iostream>
#include <string>
class Desktop :
	public Observer
{
public:
	Desktop(Mail* mail);
	~Desktop();
	void Update();
private:
	Mail* mail;
};