//2. Пользователь создает одномерный массив.
//Программа считает произведение первого и последнего элемента,
//а также сумму элементов между первым и последним.
#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>

using namespace std;
int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	int array[10];
	int mult = 1, sum = 0;
	cout << " Программа считает произведение первого и последнего элемента массива,\n а также сумму элементов между первым и последним.\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
		cout << setw(3) << array[i] << " ";
	}

	for (int i = 0; i < 10; i++)
	{
		if (i != 0 && i != 9)
		{
			sum += array[i];
		}
		else
		{
			mult *= array[i];
		}
	}
	cout << "\nПроизведение первого и последнего элемента массива - " << mult << endl;
	cout << "Cумма элементов между первым и последним - " << sum << endl;
}
