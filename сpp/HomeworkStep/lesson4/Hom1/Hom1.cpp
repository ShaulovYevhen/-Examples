//1. Пользователь создает массив из 10 элементов.
//Подсчитать кол - во положительных, отрицательных и нулевых элементов

#include <iostream>

using namespace std;
int main()
{
	setlocale(0, "rus");
	int array[10];
	int pozitive = 0, negative = 0;
	cout << "Введите число\nПрограмма считает кол-во положительных, отрицательных и нулевых элементов" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Введите число номер " << i + 1 << endl;
		cin >> array[i];
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Неправильный ввод" << endl;
			cout << "Введите число номер " << i + 1 << endl;
			cin >> array[i];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
		if (array[i] > 0)
		{
			pozitive++;
		}
		else if (array[i] < 0)
		{
			negative++;
		}

	}
	cout << endl;
	cout << "Количество положительных - " << pozitive << endl;
	cout << "Количество отирицательных - " << negative << endl;
	cout << "Нулей - " << 10 - pozitive - negative << endl;
}
