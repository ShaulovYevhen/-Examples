/*
3. Пользователь вводит 10 чисел, программа считает сумму первых 5
и сумму вторых 5 чисел. Программа сравнивает полученные суммы и выводит
сообщение - равные ли они или сумма первых больше суммы вторых 5
*/

#include <iostream>

using namespace std;
int main()
{
	setlocale(0, "rus");
	int sum1 = 0, sum2 = 0, num;
	cout << "Вдедите 10 чисел" << endl;
	for (int i = 1; i <= 10; i++)
	{
		if (i <= 5)
		{
			cout << "Введите число номер " << i << endl;
			cin >> num;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Неправильный ввод" << endl;
				cout << "Введите число номер " << i << endl;
				cin >> num;
			}
			sum1 += num;
		}
		else
		{
			cout << "Введите число номер " << i << endl;
			cin >> num;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Неправильный ввод" << endl;
				cout << "Введите число номер " << i << endl;
				cin >> num;
			}
			sum2 += num;
		}
	}
	if (sum1 == sum2)
	{
		cout << "Cуммы равные " << sum1 << " = " << sum2 << endl;
	}
	else if (sum1 > sum2)
	{
		cout << "Cумма первой половины больше суммы второй " << sum1 << " > " << sum2 << endl;
	}
	else
	{
		cout << "Cумма второй половины больше суммы первой " << sum1 << " < " << sum2 << endl;
	}
}
