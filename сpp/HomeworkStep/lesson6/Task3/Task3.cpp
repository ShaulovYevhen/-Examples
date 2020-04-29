// Необходимо отсортировать первые две трети массива в порядке возрастания, если среднее
//арифметическое всех элементов больше нуля;
//иначе - лишь первую треть
//

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

template <typename T>
void Show(T mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << round(mass[i] * 100) / 100 << " ";
    }
}

template <typename T>
void Create(T mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 100 - 50;
    }
    Show(mass, size);
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

template <typename T>
double average(const T* mass, const size_t size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += mass[i];
    }
    return sum / size;
}

int main()
{
    srand(time(NULL));
    int const size = 10;
    int mass[size];
    float arr[size];
    Create(mass, size);
    cout << "\n\n";
    cout << average(mass, size) << endl;
	if (average(mass, size)>=0)
	{
        Sort(mass, size*(2/3));
	}
	else
	{
        Sort(mass, size / 3);
	}
}


