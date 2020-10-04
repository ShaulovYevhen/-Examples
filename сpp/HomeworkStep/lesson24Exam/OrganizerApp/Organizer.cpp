#include "Organizer.h"

Organizer::Organizer()
{
}

void Organizer::addDeal(Deal* _deal)
{
	deals.push_back(_deal);
}

void Organizer::deleteDeal(Deal* _deal)
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

void Organizer::deleteDeal(int poz)
{
	if (poz > 0 && poz < deals.size())
		deals.erase(deals.begin() + poz);
	else
	{
		cout << "Deal not exist \n";
	}
}

void Organizer::find(int poz)
{
	if (poz > 0 && poz < deals.size())
		deals[poz]->show();
	else
	{
		cout << "Deal not exist \n";
	}
}

void Organizer::find(string name)
{
	for (int i = 0; i < deals.size(); i++)
	{
		if (deals[i]->getName() == name)
		{
			deals[i]->show();
		}
	}
}

void Organizer::findTeg(string teg)
{
	for (int i = 0; i < deals.size(); i++)
	{
		if (deals[i]->getTeg() == teg)
		{
			deals[i]->show();
		}
	}
}

void Organizer::show() const
{
	for (int i = 0; i < deals.size(); i++)
		deals[i]->show();
}

void Organizer::change(int poz)
{
	setlocale(LC_ALL, "rus");
	string s;
	int d;
	Input_ myInput;
	Date date;
	bool flag = true;
	while (flag)
	{
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
			flag = false;
		}
		else
		{
			cout << "ERROR \n";
			flag = true;
		}
	}
}

void Organizer::save(string filename)
{
	ofstream out;
	out.open(filename);
	if (out.is_open())
	{
		for (int i = 0; i < deals.size(); i++)
		{
			out << deals[i]->getName() << "\n";
			out << deals[i]->getDate().getDay() << "." << deals[i]->getDate().getMonth() << "." << deals[i]->getDate().getYear() << "\n";
			out << deals[i]->getWhatToDo() << "\n";
			out << deals[i]->getTeg() << "\n";
		}
		out.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void Organizer::open(string filename)
{
	for (int i = 0; i < deals.size(); i++)
		deals[i]->open(filename);
}
