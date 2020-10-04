#pragma once
#include "DealFactory.h"
#include <vector>
#include "Input_.h"
#include "Date.h"
class ToDoList
{
private:
	vector<Deal*> deals;
public:
	ToDoList();
	void addDeal(Deal *_deal);
	void deleteDeal(Deal* _deal);
	void deleteDeal(int poz);
	void find(int poz);
	void find(string name);
	void findTeg(string teg);
	void show()const;
	void change(int poz);
};

