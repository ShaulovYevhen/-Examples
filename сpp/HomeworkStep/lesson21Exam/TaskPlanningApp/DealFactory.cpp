#include "DealFactory.h"

NotUrgent* DealFactory::createNotUrgent() const
{
	return new NotUrgent;
}

Urgent* DealFactory::createUrgent() const
{
	return new Urgent;
}

VeryUrgent* DealFactory::createVeryUrgent() const
{
	return new VeryUrgent;
}
