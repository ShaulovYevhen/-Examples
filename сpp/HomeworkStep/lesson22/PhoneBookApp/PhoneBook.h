#pragma once
#include "Phone.h"
#include "Input_.h"
#include <vector>

class PhoneBook
{
private: 
	string name;
	vector <Phone*> phones;
public:
	PhoneBook();
	PhoneBook(string _name);
	~PhoneBook();
	void addPhone(Phone * _phone);
	void deletePhone(int poz);
	void deletePhone(Phone* _phone);
	Phone getPhone(int poz);
	void saveBinary(string filename);
	void openBinary(string filename);
	void save(string filename);
	void open(string filename);
	void show();
};

