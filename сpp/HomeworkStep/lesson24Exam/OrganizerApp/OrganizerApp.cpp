#include <iostream>
#include "Input_.h"
#include "Deal.h"
#include "Organizer.h"
#include "Date.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    Input_ myInput;
    int d;
    string s;
    Date date;
    int choice = 0;
    int ch = 0;
    auto organizer = new Organizer();
    auto deal = new Deal();
    auto dar = new Date();
    cout << dar->getDay()<<dar->getMonth()<<dar->getYear();
    while (choice != 10)
    {
        cout << "Выберите действие:\n1.Добавить дело\n";
        cout << "2.Вывести все дела\n";
        cout << "3.Удалить дело\n";
        cout << "4.Найти дело по номеру\n";
        cout << "5.Найти дело по названию\n";
        cout << "6.Найти дело по тегу\n";
        cout << "7.Изменить дело\n";
        cout << "8.Сохранить дела в файл\n";
        cout << "9.Открыть список дел из файла\n";
        cout << "10. Выход.\n";
        choice = myInput.input_int();
        switch (choice)
        {
        case 1:
            cout << "Введите название: \n";
            cin >> s;
            deal->setName(s);
            cout << "Введите дату: \n";
            cout << "Введите день: \n";
            d = myInput.input_int();
            date.setDay(d);
            cout << "Введите месяц: \n";
            d = myInput.input_int();
            date.setMonth(d);
            cout << "Введите год: \n";
            d = myInput.input_int();
            date.setYear(d);
            deal->setDate(date);
            cout << "Введите что нужно сделать: \n";
            cin >> s;
            deal->setWhatToDo(s);
            organizer->addDeal(deal);
            break;
        case 2:
            organizer->show();
            break;
        case 3:
            cout << "Введите номер дела которое нужно удалить: \n";
            d = myInput.input_int();
            organizer->deleteDeal(d);
            break;
        case 4:
            cout << "Введите номер дела которое нужно найти: \n";
            d = myInput.input_int();
            organizer->find(d);
            break;
        case 5:
            cout << "Введите название дела которое нужно найти: \n";
            cin >> s;
            organizer->find(s);
            break;
        case 6:
            cout << "Введите тег дела которое нужно найти: \n";
            cin >> s;
            organizer->findTeg(s);
            break;
        case 7:
            cout << "Введите номер дела кторое нужно изменить: \n";
            d = myInput.input_int();
            organizer->change(d);
            
            break;
        case 8:
            cout << "Введите имя файла: \n";
            cin >> s;
            organizer->save(s);
            break;
        case 9:
            cout << "Введите имя файла: \n";
            cin >> s;
            organizer->open(s);
            break;
        case 10:
            choice = 10;
            break;
        default:
            choice = 10;
            break;
        }
        cout << endl;
    }
}


