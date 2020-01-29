/*
1. Пользователь вводит с клавиатуры числа пока не введет 0.
Программа подсчитывает среднее только тех, что делятся на 4.
*/
#include <iostream>

using namespace std;
int main()
{
    setlocale(0, "rus");
    int number;
    int counter = 0, sum = 0;
    do
    {
        cout << "Введите число\nПрограмма подсчитывает среднее тех цифр, что делятся на 4 пока Вы не введёте 0" << endl;
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Неправильный ввод" << endl;
            cout << "Введите число " << endl;
            cin >> number;
        }
        if (number % 4 == 0)
        {
            counter++;
            sum += number;
        }
    } while (number != 0);

    cout << "Среднее среднее тех цифр, что делятся на 4" << sum/counter << endl;
}

