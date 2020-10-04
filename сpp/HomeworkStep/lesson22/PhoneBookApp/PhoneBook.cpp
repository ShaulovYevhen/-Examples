#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	name = "name";
}

PhoneBook::PhoneBook(string _name)
{
	name = _name;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addPhone(Phone* _phone)
{
	phones.push_back(_phone);
}

void PhoneBook::deletePhone(int poz)
{
	if (poz > 0 && poz < phones.size())
		phones.erase(phones.begin() + poz);
}

void PhoneBook::deletePhone(Phone* _phone)
{
	vector<Phone*>::iterator pos;
	for (pos = phones.begin();
		pos != phones.end(); ++pos)
	{
		if (*pos == _phone)
		{
			phones.erase(pos);
			break;
		}
	}
}

Phone PhoneBook::getPhone(int poz)
{
	if (poz > 0 && poz < phones.size())
	{
		return *phones[poz]; 
	}
}

void PhoneBook::saveBinary(string filename)
{
	ofstream out(filename, ios::binary);
	if (out.is_open())
	{
		out.write((char*)&this->phones, sizeof(phones));
		out.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void PhoneBook::openBinary(string filename)
{
	ifstream in(filename, ios::binary);
	if (in.is_open())
	{
		in.read((char*)&this->phones, sizeof(phones));
		in.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void PhoneBook::save(string filename)
{
	ofstream out;
	out.open(filename);
	if (out.is_open())
	{
		for (int i = 0; i < phones.size(); i++)
		{
			out << phones[i]->getName() << "\n";
			out << phones[i]->getSurname() << "\n";
			out << phones[i]->getPhone() << "\n";
			out << phones[i]->getAdress() << "\n";
			out << phones[i]->getId() << "\n";
		}
		out.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void PhoneBook::open(string filename)
{
	for (int i = 0; i < phones.size(); i++)
		phones[i]->open(filename);
}

void PhoneBook::show()
{
	for (int i = 0; i < phones.size(); i++)
		phones[i]->show();
}
