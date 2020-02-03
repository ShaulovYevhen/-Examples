/*
2. Компьютер загадывает число от 0 до 10.
Задача игрока угадать число за 3 попытки.
*/

#include <iostream>
#include <time.h>
#include <random>
using namespace std;
int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    int user_choice;
    int pc_choice = rand() % 11;
    cout << "Угадайте число от 0 до 10, у Вас три попытки" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите число от 0 до 10" << endl;
        cin >> user_choice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Неправильный ввод" << endl;
            cout << "Введите число от 0 до 10" << endl;
            cin >> user_choice;
        }

        while (cin.good())
        {
            if (user_choice >= 0 && user_choice <= 10)
            {
                break;
            }
            else
            {
                cout << "Неправильный ввод" << endl;
                cout << "Введите число от 0 до 10" << endl;
                cin >> user_choice;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Неправильный ввод" << endl;
                    cout << "Введите число от 0 до 10" << endl;
                    cin >> user_choice;
                }
            }
        }
        if (user_choice == pc_choice)
        {
            cout << "Вы угадали" << endl;
            cout << "Компьютер загадал число: " << pc_choice << endl;
            break;
        }
        else
        {
            cout << "Вы не угадали" << endl;
            if (i == 2)
            {
                cout << "Компьютер загадал число: " << pc_choice << endl;
            }
        }
    }
}
