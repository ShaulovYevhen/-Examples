//Домашнее задание : Конструкторы.Деструкторы.Конструктор копирования.
//Написать класс, описывающий группу студентов.Описание студента
//также реализуется с помощью соответствующего класса.
//Студент : 
//	Поля : 
//	    Имя; 
//      Год рождения. 
//Группа:
//	Поля:
//		Факультет;
//		Курс;
//		Количество студентов;
//		Студенты.
//	Методы:
//		Добавление студента в группу;
//		Удаление студента из группы(по позиции);
//		Вывод на экран всех студентов;

#include "Student.h"
#include "Group.h"

int input_int()
{
    int i;
    cin >> i;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Wrong input, enter digit pls." << endl;
        cin >> i;
    }
    return i;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Group group("Botanics", 3);
    group.AddStudent(Student("Petrov", 1990));
    group.AddStudent(Student("Ivanov", 1900));
    group.AddStudent(Student("Petrov", 2000));
    group.AddStudent(Student("Sidorov", 2010));
    int year = 0;
    int el = 0;
    int choice = 0;
    while (choice != 4)
    {
        cout << "\nВыберите действие:\n1.Вывод на экран;\n2.Добавить студента в группу\n3.Удалить\n4.Выход." << endl;
        choice = input_int();
        switch (choice)
        {
        case 1:
            group.Show();
            break;
        case 2:
            char name[1000];
            cout << "Введите имя(англ) и нажмите Enter\n";
            cin.ignore();
            cin.getline(name, 1000);
            cout << "Введите год рождения и нажмите Enter\n";
            year = input_int();
            group.AddStudent(Student(name, year));
            group.Show();
            break;
        case 3:
            cout << "Введите номер елемента который нужно удалить: ";
            el = input_int();
            group.DelStudent(el);
            group.Show();
            break;
        default:
            choice = 4;
            break;
        }
    }
    return 0;
}