//1. Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.
//Пользователь вводит a и b.Проиллюстрируйте работу функции примером.

#include <iostream>

using namespace  std;

template <typename T> T Sum(T a, T b)
{
	if (a - b == 1)
		return 0;
	return b + Sum(a, b - 1);
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
	cout << "Enter first number" << endl;
	int first = input_int();
	cout << "Enter second number" << endl;
	int second = input_int();
	cout << "Sum = " << Sum(first, second)<< endl;
}

