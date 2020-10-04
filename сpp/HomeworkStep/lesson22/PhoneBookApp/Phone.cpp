#include "Phone.h"

Phone::Phone()
{
    surname = "Ivanov";
    name = "Ivan";
	adress = "";
	phone = "38000000000";
	id = "";
}

Phone::Phone(string _name, string _surname, string _adress, string _phone, string _id )
{
	surname = _name;
	name = _surname;
	adress = _adress;
	phone = _phone;
	id = _id;
}

Phone::~Phone()
{

}

Phone::Phone(const Phone& obj)
{
	surname = obj.surname;
	name = obj.name;
	adress = obj.adress;
	phone = obj.phone;
	id = obj.id;
}

Phone::Phone(Phone&& obj) noexcept
{
	surname = obj.surname;
	name = obj.name;
	adress = obj.adress;
	phone = obj.phone;
	id = obj.id;
	obj.surname = nullptr;
	obj.name = nullptr;
	obj.phone = nullptr;
	obj.adress = nullptr;
	obj.id = nullptr;
}

Phone& Phone::operator=(const Phone& obj)
{
	if (this == &obj)
		return *this;
	surname = obj.surname;
	name = obj.name;
	adress = obj.adress;
	phone = obj.phone;
	id = obj.id;
	return *this;
}

Phone& Phone::operator=(Phone&& obj) noexcept
{
	if (this == &obj)
		return *this;
	surname = obj.surname;
	name = obj.name;
	adress = obj.adress;
	phone = obj.phone;
	id = obj.id;
	obj.surname = nullptr;
	obj.name = nullptr;
	obj.phone = nullptr;
	obj.adress = nullptr;
	obj.id = nullptr;
	return *this;
}

string Phone::getName()const
{
	return name;
}

void Phone::setName(string _name)
{
	name = _name;
}

string Phone::getSurname()const
{
	return surname;
}

void Phone::setSurname(string _surname)
{
	surname = _surname;
}

string Phone::getAdress()const
{
	return adress;
}

void Phone::setAdress(string _adress)
{
	adress = _adress;

}

string Phone::getPhone()const
{
	return phone;
}

void Phone::setPhone(string _phone)
{
	phone = _phone;
}

string Phone::getId() const
{
	return id;
}

void Phone::setId(string _id)
{
	id = _id;
}

void Phone::show() const
{
	cout << "Name: " << getName() << "\n";
	cout << "Surname: " << getSurname() << "\n";
	cout << "Phone: " << getPhone() << "\n";
	cout << "Adress: " << getAdress() << "\n";
	cout << "ID: " << getId() << "\n";
}

void Phone::saveBinary(string filename)
{
	ofstream out(filename, ios::binary);
	if (out.is_open()) 
	{
		out.write((char*)&name, sizeof(name));
		out.write((char*)&surname, sizeof(surname));
		out.write((char*)&phone, sizeof(phone));
		out.write((char*)&adress, sizeof(adress));
		out.write((char*)&id, sizeof(id));
		out.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void Phone::openBinary(string filename)
{
	ifstream in(filename, ios::binary);
	if (in.is_open())
	{
		in.read((char*)&name, sizeof(name));
		in.read((char*)&surname, sizeof(surname));
		in.read((char*)&phone, sizeof(phone));
		in.read((char*)&adress, sizeof(adress));
		in.read((char*)&id, sizeof(id));
	in.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void Phone::save(string filename)
{
	ofstream out;
	if (out.is_open())
	{
		out.open(filename);
		out << name << "\n";
		out << surname << "\n";
		out << phone << "\n";
		out << adress << "\n";
		out << id << "\n";
	out.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}

void Phone::open(string filename)
{
	ifstream in(filename);
	if (in.is_open())
	{
		in >> name;
		in >> surname;
		in >> phone;
		in >> adress;
		in >> id;
		in.close();
	}
	else
		cout << "\nERROR OPEN FILE\n";
}


