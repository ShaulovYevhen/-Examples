#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct students
{
	string FIO;
	int phone;
	string email;
};

void Read(const char* filename, students* stud, int size)
{
	ifstream fin(filename);
	if (!fin)
	{
		cout << "File not open\n";
	}
	else
	{
		string buff;
		string name;
		string ini;
		int i = 0;
		while (!fin.eof())//пока не вычитали все до конца файла
		{
			getline(fin, buff);//считываем строку
			stringstream ss(buff);//передаем ее в объект класса ss
			ss >> name;//записываем в name фамилию
			ss >> ini;//записываем в ini инициалы
			stud[i].FIO = name + " " + ini;//записываем в поле FIO фамилию и инициалы
			ss >> stud[i].phone;//заполняем поля оценками
			ss >> stud[i].email;

			i++;
		}
	}
	fin.close();
}

void Show(students* stud, int size)//функция вывода на экран
{
	cout << "#\tFIO\t\tMath\tPhis\t\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "\t" << stud[i].FIO << "\t" << stud[i].phone << "\t" << stud[i].email <<  "\n";
	}
}

int main()
{
	int const size = 3;
	students stud[size];
	Read("PhoneBook.txt", stud, size);
	Show(stud, size);
}
