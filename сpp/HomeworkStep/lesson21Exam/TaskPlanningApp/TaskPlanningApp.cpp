//Реализуйте с использованием паттернов проектирования простейшую систему планирования задач.
//Должна быть возможность создания списка дел, установки приоритетов, установки
//дат выполнения, удаление и изменения дел.
//Каждому делу можно установить тег.Список дел можно загружать и сохранять в файл.
//Необходимо реализовать возможность поиска конкретного дела
//Критерии поиска : по датам, по тегам, по приоритету и так далее.
/*


#include <iostream>
#include "Input_.h"
#include "DealFactory.h"
#include "ToDoList.h"
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
    int ch=0;
    auto list = new ToDoList();
    auto dealFactory = new DealFactory();
    auto urgent = dealFactory->createUrgent();
    auto notUrgent = dealFactory->createNotUrgent();
    auto veryUrgent = dealFactory->createVeryUrgent();
    while (choice != 12)
    {
        cout << "Выберите действие:\n1.Добавить срочное дело\n";
        cout << "2.Добавить обычное дело\n";
        cout << "3.Добавить срочное дело\n";
        cout << "4.Вывести все дела\n";
        cout << "5.Удалить дело\n";
        cout << "6.Найти дело по номеру\n" ;
        cout << "7.Найти дело по названию\n";
        cout << "8.Найти дело по тегу\n";
        cout << "9.Изменить дело\n";
        cout << "10. Сохранить дела в файл\n";
        cout << "11. Открыть список дел из файла\n";
        cout << "12.Выход." << endl;
        choice = myInput.input_int();
        switch (choice)
        {
        case 1:
            cout << "Введите название: \n";
            cin >> s;
            urgent->setName(s);
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
            urgent->setDate(date);
            cout << "Введите что нужно сделать: \n";
            cin >> s;
            urgent->setWhatToDo(s);
            list->addDeal(urgent);
            break;
        case 2:
            notUrgent = dealFactory->createNotUrgent();
            cout << "Введите название: \n";
            cin >> s;
            notUrgent->setName(s);
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
            notUrgent->setDate(date);
            cout << "Введите что нужно сделать: \n";
            cin >> s;
            notUrgent->setWhatToDo(s);
            list->addDeal(notUrgent);
            break;
        case 3:
            veryUrgent = dealFactory->createVeryUrgent();
            cout << "Введите название: \n";
            cin >> s;
            veryUrgent->setName(s);
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
            veryUrgent->setDate(date);
            cout << "Введите что нужно сделать: \n";
            cin >> s;
            veryUrgent->setWhatToDo(s);
            list->addDeal(veryUrgent);
            break;
        case 4:
            list->show();
            break;
        case 5:
            cout << "Введите номер дела которое нужно удалить: \n";
            d = myInput.input_int();
            list->deleteDeal(d);
            break;
        case 6:
            cout << "Введите номер дела которое нужно найти: \n";
            d = myInput.input_int();
            list->find(d);
            break;
        case 7:
            cout << "Введите название дела которое нужно найти: \n";
            cin >> s;
            list->find(s);
            break;
        case 8:
            cout << "Введите тег дела которое нужно найти: \n";
            cin >> s;
            list->findTeg(s);
            break;
        case 9:
            cout << "Введите номер дела кторое нужно изменить: \n";
            d = myInput.input_int();
            list->change(d);
            break;
        case 10:
            
            break;
        case 11:

            break;

        default:
            choice = 12;
            break;
        }
        cout << endl;
    }
}
