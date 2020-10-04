//1. Написать программу, которая инициализирует элементы вектора
//нечетными целыми числами от 0 до 20. Вывести содержимое
//вектора с нумерацией элементов.Пример:
//0 -> 1
//1 -> 3
//2 -> 5
//3 -> 7
//4 -> 9
//5 -> 11
//6 -> 13
//7 -> 15
//8 -> 17
//9 -> 19
//2. Написать программу, которая выводит содержимое вектора
//наоборот.Входными данными является вектор из 10 элементов,
//заполненный случайными числами в диапазоне(12, 35).
//3. Написать программу, в которой список и з 10 элементов
//заполняется случайными числами в диапазоне(-10, 10).
//Найти:
//a.произведение всех элементов списка.
//b.максимальный элемент.
//c.количество элементов равных нулю.
//4. Написать программу, в которой список из 10 элементов
//заполняется случайными числами в диапазоне(-10, 10).Вывести
//на экран сначала все положительные его элементы, а затем все
//отрицательные.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <time.h>
using namespace std;

int main()
{
    //1//////////
    vector<int> numbers = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    for (int i = 0; i < numbers.size(); ++i) 
    {
        cout <<i<<" -> "<< numbers[i] << '\n';
    }
    cout << "\n\n";
    //2/////////
    int min = 12;
    int max = 35;
    vector<int> numbers1;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) 
    {
        numbers1.push_back(min + rand() % (max - min));
    }
    for (int i = 0; i < numbers1.size(); ++i)
    {
        cout << numbers1.size() - i - 1 << " -> " << numbers1[numbers1.size()-i-1] << '\n';
    }
    cout << "\n";
    int j = numbers1.size();
    vector<int>::const_reverse_iterator it;
    for (it = numbers1.rbegin(); it != numbers1.rend(); ++it)
    {
        j--;
        cout<< j << " -> " << *it << '\n';
    }
    cout << "\n\n";
    //3/////////
    min = -10;
    max = 10;
    list<int> list_numbers;
    for (int i = 0; i < 10; ++i)
    {
        list_numbers.push_back(min + rand() % (max - min));
    }
    int mult = 1;
    int list_max=list_numbers.front();
    int zero_el=0;
    for (int n : list_numbers)
    {
        cout << n << "\n";
        mult *= n;
        if (list_max < n)
            list_max = n;
        if (n == 0)
            zero_el++;
    }
    cout << "List multiplication = " << mult << "\n";
    cout << "Max element of List = " << list_max << "\n";
    cout << "Zero elements of List = " << zero_el << "\n";
    cout << "\n\n";
    //4/////////
    min = -10;
    max = 10;
    list<int> list_numbers1;
    for (int i = 0; i < 10; ++i)
    {
        list_numbers1.push_back(min + rand() % (max - min));
    }
    for (int n : list_numbers1)
    {
        if (n>=0)
        cout << n << "\n";
    }
    for (int n : list_numbers1)
    {
        if (n < 0)
            cout << n << "\n";
    }
}

