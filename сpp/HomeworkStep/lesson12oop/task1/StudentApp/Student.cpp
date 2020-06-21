#include "Student.h"

Student::Student(const char* n, int y) //конструктор класа
{
	year = y;
	name = _strdup(n); //name = new char[strlen(n + 1)]; strcpy(name, n);
}

Student::Student()//конструктор по умролчанию
{
	name = _strdup("empty");
	year = 0;
}

Student::Student(const Student& obj)//конструктор копирования которыцй принимаетконстантную ссылку на обьект того же тип
{
	year = obj.year;
	name = _strdup(obj.name);
}

Student::Student(Student&& obj) noexcept// конструктор перемещения который принимает ссылку rvalue
{
	year = obj.year;
	name = obj.name;
	obj.name = nullptr;
}

Student::~Student()//деструктор
{
	delete[]name;
}

int Student::getYear()const// геттер для возвращения значений
{
	return year;
}

void Student::setYear(int val) // сеттер для установки и проверки значений 
{
	year = val;
}

const char* Student::getName()const
{
	return name;
}

void Student::setName(const char* val)
{
	delete[]name;
	name = _strdup(val);
}

void Student::Show()const
{
	cout << "Name: " << name << "; Year: " << year << "\n";
}
