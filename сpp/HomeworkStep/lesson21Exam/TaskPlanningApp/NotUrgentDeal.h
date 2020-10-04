#pragma once
#include "Deal.h"
class NotUrgentDeal :
	public Deal
{
	string priority = "not Urgent";
public:
	NotUrgentDeal();
};

