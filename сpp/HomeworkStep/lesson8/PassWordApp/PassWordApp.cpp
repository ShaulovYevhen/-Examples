//Пользователь вводит потенциальный пароль. Проверить его на устойчивость. 
//В нормальном пароле длина не менее 6 символов,
//большие и малые буквы, 
//цифры и / или спецсимволы. 
//Результат сообщить пользователю (подходит / не подходит пароль)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool LetChecker(char chPass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isalpha(chPass[i]))
		{
			return true;
		}
	}
	return false;
}

bool NumChecker(char chPass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isdigit(chPass[i]))
		{
			return true;
		}
	}
	return false;
}

bool LetterCheck(char chPass[], int size)
{
	bool checker = false;
	bool checker1 = false;
	for (int i = 0; i < size; i++)
	{
		if (islower(chPass[i])) // c русскими буквами не работает
		{
			checker = true;
		}
		else
		{
			checker1 = true;
		}
	}
	if (checker && checker1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string password;
	bool checker = true;
	cout << "Enter password\n";
	cin >> password;
	char* chPass = new char[password.size() + 1];
	strcpy(chPass, password.c_str());
	
	if (password.size() < 6)
	{
		cout << "\nToo short password\n";
		checker = false;
	}
	if (!LetterCheck(chPass, password.size()))
	{
		cout<<"\nPassword need uppercase and lovercase letters\n";
		checker = false;
	}
	if (!LetChecker(chPass, password.size()))
	{
		cout << "\nPassword need letters\n";
		checker = false;
	}
	if (!NumChecker(chPass, password.size()))
	{
		cout << "\nPassword need letters\n";
		checker = false;
	}
	if (checker) 
	{
		cout << "\nPassword good\n";
	}
	else
	{
		cout << "\nPassword bad\n";
	}
}