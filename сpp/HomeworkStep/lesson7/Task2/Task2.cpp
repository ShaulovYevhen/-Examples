//2.	Написать программу, в которой имеется двумерный массив 5х5.
//      Программа подсчитывает сумму элементов побочной диагонали.
//Если сумма больше 200, то программа создает два динамических массива, в один записывает четные элементы массива, в другой – нечетные.
//Если сумма меньше 200, то создается три динамических массива, в которыe записываются элементы,
// в первый - записываются элементы больше 10 первых двух столбцов, 
//во второй - элементы меньшие 30 последних двух столбцов.
//и в третий динамический массив заполним из элементов среднего столбца, которые больше 50


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
	cout << "\n";
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

void Show(int mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
}

void CountOdd(int mass[][5], int size)
{
	int a=0, b = 0;
	int odd_size = 0;
	int even_size = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mass[i][j] % 2 == 0)
			{
				even_size++;
			}
			else
			{
				odd_size++;
			}
		}
	}
	int* odd_mass = new int[odd_size];
	int* even_mass = new int[even_size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mass[i][j] % 2 == 0)
			{
				even_mass[a] = mass[i][j];
				a++;
			}
			else
			{
				odd_mass[b] = mass[i][j];
				b++;
			}
		}
	}
	cout << "\nEven array: \n";
	Show(even_mass, even_size);
	cout << "\nOdd array: \n";
	Show(odd_mass, odd_size);
	delete[]even_mass;
	delete[]odd_mass;
}

void CountArrays(int mass[][5], int size)
{
	int a=0, b=0, c = 0;
	int first_size = 0;
	int second_size = 0;
	int third_size = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0 || j == 1)   // в первый - записываются элементы больше 10 первых двух столбцов, 
			{
				if (mass[i][j] > 10)
				{
					first_size++;
				}
			}
			else if (j == 4 || j == 3)//во второй - элементы меньшие 30 последних двух столбцов.
			{
				if (mass[i][j] < 30)
				{
					second_size++;
				}
			}
			else //и в третий динамический массив заполним из элементов среднего столбца, которые больше 50
			{
				if (mass[i][j] > 50)
				{
					third_size++;
				}
			}
		}
	}
	int* first_mass = new int[first_size];
	int* second_mass = new int[second_size];
	int* third_mass = new int[third_size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0 || j == 1)   // в первый - записываются элементы больше 10 первых двух столбцов, 
			{
				if (mass[i][j] > 10)
				{
					first_mass[a] = mass[i][j];
					a++;
				}
			}
			else if (j == 4 || j == 3)//во второй - элементы меньшие 30 последних двух столбцов.
			{
				if (mass[i][j] < 30)
				{
					second_mass[b] = mass[i][j];
					b++;
				}
			}
			else //и в третий динамический массив заполним из элементов среднего столбца, которые больше 50
			{
				if (mass[i][j] > 50)
				{
					third_mass[c] = mass[i][j];
					c++;
				}
			}
		}
	}
	cout << "\nfirst array ( >10): \n";
	Show(first_mass, first_size);
	cout << "\nsecond array ( <30): \n";
	Show(second_mass, second_size);
	cout << "\nthid array ( >50): \n";
	Show(third_mass, third_size);
	delete[]first_mass;
	delete[]second_mass;
	delete[]third_mass;
}
int main()
{
	srand(time(NULL));
	int const size = 5;
	int mass[size][size];
	CreateMass(mass, size);
	ShowMass(mass, size);
	if (SumMass(mass, size) > 200)
	{
		CountOdd(mass, size);
	}
	else
	{
		CountArrays(mass, size);
	}
}

