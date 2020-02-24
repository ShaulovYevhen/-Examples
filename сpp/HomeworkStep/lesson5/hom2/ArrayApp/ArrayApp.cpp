//Имеется двумерный массив размером 5х5.
//Написать функцию, которая подсчитывает по выбору пользователя сумму всех элементов,
//произведение всех элементов

#include <iostream>
#include <iomanip>
using namespace std;

void CreateMass(int mass[][5], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mass[i][j] = rand() % 100;
		}
	}
}

void ShowMass(int mass[][5], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(3) << mass[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int SumMass(int mass[][5], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sum += mass[i][j];
		}
	}
	return sum;
}

int MultMass(int mass[][5], int size)
{
	int mult = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mult *= mass[i][j];
		}
	}
	return mult;
}

int input_int()
{
	int i;
	cin >> i;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Wrong input, enter digit pls." << endl;
		cin >> i;
	}
	return i;
}

int main()
{
	srand(time(NULL));
	int const size = 5;
	int mass[size][size];
	CreateMass(mass, size);
	ShowMass(mass, size);
	cout << "Enter 1 if you need to know sum of all elements of array" << endl;
	cout << "Enter 2 if you need to know multiplication of all elements of array" << endl;
	int choice = input_int();
	while (choice != 1 && choice != 2)
	{
		cout << "Wrong input, enter 1 or 2 pls." << endl;
		choice = input_int();
	}
	if (choice==1)
	{
		cout << "Sum = " <<SumMass(mass,size) <<endl;
	}
	else
	{
		cout << "Mult = " << MultMass(mass, size) << endl;
	}
}
