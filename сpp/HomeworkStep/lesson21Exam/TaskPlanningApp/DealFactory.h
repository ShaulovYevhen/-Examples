#pragma once
#include "Factory.h"
#include "NotUrgentDeal.h"
#include "VeryUrgentDeal.h"
#include "UrgentDeal.h"
class DealFactory :
	public Factory
{
public:
	NotUrgent* createNotUrgent()const override;
	Urgent* createUrgent()const override;
	VeryUrgent* createVeryUrgent()const override;
};

