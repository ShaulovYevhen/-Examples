#pragma once
#include "Deal.h"
class NotUrgent :
	public Deal
{
	string priority = "not Urgent";
public:
	NotUrgent();
};

