// Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.
//

#include <iostream>
using namespace  std;

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

template <typename T>
void ShowStars(T stars)
{
	if (stars == 0)
	{
		return;
	}
	ShowStars(stars - 1);
	cout<< " * ";
}

int main()
{
	cout << "Enter number of stars\n";
	int stars = input_int();
	ShowStars(stars);
}
