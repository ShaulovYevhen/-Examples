//1.	Написать программу, в которой будут реализованы следующие функции :
//a.Создание динамического массива
//b.Сортировка массива
//c.Функция, которая считает кол - во элементов больших 50 и из них формируется еще один динамический массив
//d.Удаления массива

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 100;
    }
}

void Show(int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
}

template <typename T> void Sort(T mass[], int size)
{
    T temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
    Show(mass, size);
}

void Count(int mass[], int size)
{
    int j = 0;
    int second_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (mass[i] > 50)
        {
            second_size++;
        }
    }
    int* second_mass = new int[second_size];
    for (int i = 0; i < size; i++)
    {
        if (mass[i] > 50)
        {
            second_mass[j] = mass[i];
            j++;
        }
    }
    Show(second_mass, second_size);
    delete[]second_mass;
}

int main()
{
    srand(time(NULL));
    int size;
    cout << "Enter size of array\n";
    cin >> size;
    int* mass = new int[size];
    Create(mass, size);
    cout << "\nFirst Array\n";
    Show(mass, size);
    cout << "\nSort Array\n";
    Sort(mass, size);
    cout << "\nSecond Array\n";
    Count(mass, size);
    cout << "\n\n";
}

