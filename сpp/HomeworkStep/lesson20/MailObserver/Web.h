#pragma once
#include "Observer.h"
#include "Mail.h"
#include <iostream>
#include <string>
class Web :
	public Observer
{
public:
	Web(Mail* mail);
	~Web();
	void Update();
private:
	Mail* mail;
};