/*Haписать программу, которая записывает в файл телефонную книгу.
Фамилия / Имя / Отчество.И номер телефона*/

#include <stdlib.h> 
#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

struct PhoneBook
{
	string name;
	int phone;
};

PhoneBook* Add(PhoneBook* MyPhoneBook, int const count) 
{
	if (count == 0)
	{
		MyPhoneBook = new PhoneBook[1];
	}
	else
	{
		PhoneBook* temp = new PhoneBook[count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = MyPhoneBook[i];
		}
		delete[] MyPhoneBook;
		MyPhoneBook = temp;
	}
	return MyPhoneBook;
}

void SetData(PhoneBook PhoneBook[], int const size)
{
    string s;

    cout << "Enter Name\n"; getline(cin, PhoneBook[size].name);
    cout << "Enter ID\n"; cin >> PhoneBook[size].phone;
}

void ShowData(PhoneBook PhoneBook[], int const size)
{
    cout << "#\tName\tPhone\n";
    for (int i = 0; i < size; i++)
    {
        cout << PhoneBook[i].name << "\t" << PhoneBook[i].phone << "\n";
    }
}

void Write(PhoneBook PhoneBook[], int const size, const char* filename)
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Файла не существует\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        file << PhoneBook[i].name << "\t" << PhoneBook[i].phone << "\n";
    }
    file.close();
}

void main()
{
    setlocale(LC_ALL, "rus");
	PhoneBook* PhoneBook = 0;
	int size = 0;
  
    short choice = 0;
    while (choice != 4)
    {
        cout << "Выберите действие:\n1.Добавить контакт\n2.Вывести контактын\n3.Записать в файл\n4.Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            PhoneBook = Add(PhoneBook, size);
            SetData(PhoneBook, size);
            size++;
            break;
        case 2:
            ShowData(PhoneBook, size);
            break;
        case 3:
            Write(PhoneBook, size, "D:\\file.txt");
            break;
        default:
            choice = 4;
            break;
        }
        cout << endl;
    }
    delete[] PhoneBook;
}

