#pragma once
#include "Emergency.h"
class Ambulance :
	public Emergency
{
	void signal()override;
};

