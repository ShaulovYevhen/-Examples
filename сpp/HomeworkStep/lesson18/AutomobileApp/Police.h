#pragma once
#include "Emergency.h"
class Police :
	public Emergency
{
	void signal()override;
};

