#include "Deal.h"

Deal::Deal()
{
	Input_ myInput;
	teg = myInput.teg_generator();
}

Deal::~Deal()
{
}

string Deal::getTeg() const
{
	return teg;
}

string Deal::getName() const
{
	return string();
}

void Deal::setName(string _name)
{
	name = _name;
}

Date Deal::getDate() const
{
	return date;
}

void Deal::setDate(Date _date)
{
	date = _date;
}

string Deal::getWhatToDo() const
{
	return whatToDo;
}

void Deal::setWhatToDo(string _whatToDo)
{
	whatToDo = _whatToDo;
}

void Deal::show() const
{
	cout << "Deal name: " << name << "\n";
	cout << "Deal date: " << date.getDay() << "." << date.getMonth() << "." << date.getYear() << "\n";
	cout << "What to do: " << whatToDo<<"\n";
	cout << "Teg: "<< teg << "\n";	
}

