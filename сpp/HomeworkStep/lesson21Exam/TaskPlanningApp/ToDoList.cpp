#include "ToDoList.h"

ToDoList::ToDoList()
{

}

void ToDoList::addDeal(Deal* _deal)
{
	deals.push_back(_deal);
}

void ToDoList::deleteDeal(Deal* _deal)
{
	vector<Deal*>::iterator pos;
	for (pos = deals.begin();
		pos != deals.end(); ++pos)
	{
		if (*pos == _deal)
		{
			deals.erase(pos);
			break;
		}
	}
}

void ToDoList::deleteDeal(int poz)
{
	if (poz>0&&poz<deals.size())
	deals.erase(deals.begin() + poz);
}

void ToDoList::find(int poz)
{
	if (poz > 0 && poz < deals.size())
		deals[poz]->show();
}

void ToDoList::find(string name)
{
	for (int i = 0; i < deals.size(); i++)
	{
		if (deals[i]->getName() == name)
		{
			deals[i]->show();
		}
	}
}

void ToDoList::findTeg(string teg)
{
	for (int i = 0; i < deals.size(); i++)
	{
		if (deals[i]->getTeg() == teg)
		{
			deals[i]->show();
		}
	}
}

void ToDoList::show()const
{
	for (int i = 0; i < deals.size(); i++)
		deals[i]->show();
}

void ToDoList::change(int poz)
{
	setlocale(LC_ALL, "rus");
	string s;
	int d;
	Input_ myInput;
	Date date;
	if (poz > 0 && poz < deals.size())
	{
		cout << "¬ведите название: \n";
		cin >> s;
		deals[poz]->setName(s);
		cout << "¬ведите дату: \n";
		cout << "¬ведите день: \n";
		d = myInput.input_int();
		date.setDay(d);
		cout << "¬ведите мес€ц: \n";
		d = myInput.input_int();
		date.setMonth(d);
		cout << "¬ведите год: \n";
		d = myInput.input_int();
		date.setYear(d);
		deals[poz]->setDate(date);
		cout << "¬ведите что нужно сделать: \n";
		cin >> s;
		deals[poz]->setWhatToDo(s);
	}
	else
	{
		cout << "ERROR \n";
	}
}