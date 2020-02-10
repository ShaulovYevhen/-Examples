//3. Пользователь создает двумерный массив с размерностью 5 х 5 и заполняет его случайными числами.
//Программа считает сумму по главной или вспомогательной диагонали или по указанному пользователем
//столбцу либо по указанной строке.Общение с пользователем реализовать при помощи меню.

#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>

using namespace std;
int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	int array[5][5];
	int sum = 0;
	cout << " \nМассив с размерностью 5 х 5 : \n" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			array[i][j] = rand() % 100;
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
	int choice;
	do
	{
		cout << "\nВыберите действие : " << endl;
		cout << " Введите 1 что-бы посчитать сумму елементов главной диагонали" << endl;
		cout << " Введите 2 что-бы посчитать сумму елементов вспомогательной диагонали" << endl;
		cout << " Введите 3 что-бы указать номер строки сумму которой нужно подсчитать" << endl;
		cout << " Введите 4 что-бы указать номер столбца сумму которго нужно подсчитать" << endl;
		cout << " Введите любую другую цыфру для выхода" << endl;
		cin >> choice;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Неправильный ввод" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			sum = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (i == j)
					{
						sum += array[i][j];
					}
				}
			}
			cout << " Cумма елементов главной диагонали: " << sum << endl;
		}
		break;

		case 2:
		{
			sum = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (i + j == 4)
					{
						sum += array[i][j];
					}
				}
			}
			cout << " Cумма елементов вспомогательной диагонали: " << sum << endl;
		}
		break;

		case 3:
		{
			sum = 0;
			cout << " Укажите номер строки сумму элементов которой нужно посчитать (1-5)" << endl;
			int s;
			cin >> s;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Неправильный ввод" << endl;
				cin >> s;
			}
			if (s == 1 || s == 2 || s == 3 || s == 5)
			{
				for (int i = 0; i < 5; i++)
				{
					sum += array[s - 1][i];
				}
			}
			else
			{
				cout << "Нет такой строки"; break;
			}
			cout << "Сумма элементов строки под номером " << s << " - " << sum;
		}
		break;

		case 4:
		{
			sum = 0;
			cout << " Укажите номер столбца сумму элементов которого нужно посчитать (1-5)" << endl;
			int s;
			cin >> s;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Неправильный ввод" << endl;
				cin >> s;
			}
			if (s == 1 || s == 2 || s == 3 || s == 5)
			{
				for (int i = 0; i < 5; i++)
				{
					sum += array[i][s - 1];
				}
			}
			else
			{
				cout << "Нет такого столбца"; break;
			}
			cout << "Сумма элементов столбца под номером " << s << " - " << sum;
		}
		break;

		default:  return 0;
		}
	} while (choice != 0);
}
