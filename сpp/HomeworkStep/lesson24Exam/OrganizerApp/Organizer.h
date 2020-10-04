#pragma once
#include <vector>
#include "Deal.h"
#include "Input_.h"
#include "Date.h"
class Organizer
{
private:
	vector<Deal*> deals;
public:
	Organizer();
	void addDeal(Deal* _deal);
	void deleteDeal(Deal* _deal);
	void deleteDeal(int poz);
	void find(int poz);
	void find(string name);
	void findTeg(string teg);
	void show()const;
	void change(int poz);
	void save(string filename);
	void open(string filename);
};

