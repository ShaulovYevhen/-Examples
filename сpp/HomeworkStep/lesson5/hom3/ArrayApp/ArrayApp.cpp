//3. Написать программу формирования одномерного массива,
//вывода его на экран и замены всех отрицательных элементов
//максимальным значением

#include <iostream>
#include <time.h>
using namespace std;

void CreateMass(int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 100-50;
    }
}

void ShowMass(int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << "\n\n";
}

int FindMax(int mass[], int size)
{
    int max = mass[0];
    for (int i = 0; i < size; i++)
    {
        if (mass[i] > max)
        {
            max = mass[i];
        }
    }
    return max;
}

void ChangeMass (int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
    	if (mass[i]<0)
    	{
            mass[i] = FindMax(mass, size);
    	}
    }
}

int main()
{
    srand(time(NULL));
    int const size = 10;
    int mass[size];
    CreateMass(mass, size);
    ShowMass(mass, size);
    ChangeMass(mass, size);
    ShowMass(mass, size);
}

