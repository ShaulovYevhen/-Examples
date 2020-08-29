#pragma once
#include "Emergency.h"
class FireEngine :
	public Emergency
{
	void signal()override;
};

