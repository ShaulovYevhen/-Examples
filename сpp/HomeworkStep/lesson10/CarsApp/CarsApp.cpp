//1.	Написать динамическую структуру, 
//в которую пользователь может добавить позиции, 
//вывести позиции на экран.
//Вывод на экран всех элементов структуры 
//либо отталкивая от цены(выше / ниже введенной пользователем), 
//вывод по бренду.

#include <stdlib.h> 
#include <iostream> 
#include <string>
using namespace std;

struct Cars
{
    string brand;
    string model;
    int ID;
    float cost;
};

Cars* Add(Cars* MyCar, int const count) //функция увеличения динамического массива структур
{
    if (count == 0)
    {
        MyCar = new Cars[1];
    }
    else
    {
        Cars* temp = new Cars[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = MyCar[i];
        }
        delete[] MyCar;
        MyCar = temp;
    }
    return MyCar;
}

void SetData(Cars MyCars[], int const count)
{
    cout << "Enter brand\n"; getline(cin, MyCars[count].brand);
    cout << "Enter model\n"; getline(cin, MyCars[count].model);
    cout << "Enter price\n"; cin >> MyCars[count].cost;
    cout << "Enter ID\n"; cin >> MyCars[count].ID;
}

void ShowData(Cars* MyCars, int size)
{
    cout << "#\tBrand\tModel\tPrice\tID\n";
    for (int i = 0; i < size; i++)
    {
        cout << MyCars[i].brand << "\t" << MyCars[i].model << "\t" << MyCars[i].cost << "\t" << MyCars[i].ID << "\n";
    }
}

void ShowData(Cars* MyCars, int size, string brand)
{
    cout << "#\tBrand\tModel\tPrice\tID\n";
    for (int i = 0; i < size; i++)
    {
        if (MyCars[i].brand==brand)
        {
        cout << MyCars[i].brand << "\t" << MyCars[i].model << "\t" << MyCars[i].cost << "\t" << MyCars[i].ID << "\n";
        }
        else
        {
        cout << "Запись отсутствует";
        }
    }
}

void ShowData(Cars* MyCars, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (i + 1 == num)
        {
            cout << "#\tBrand\tModel\tPrice\tID\n";
            cout << MyCars[i].brand << "\t" << MyCars[i].model << "\t" << MyCars[i].cost << "\t" << MyCars[i].ID << "\n";
        }
        else
        {
            cout << "Запись отсутствует";
        }
    }
}

void ShowData(Cars* MyCars,int size, int price, int b)
{
    cout << "#\tBrand\tModel\tPrice\tID\n";
    for (int i = 0; i < size; i++)
    {
        if (b == 1)
        {
            if (MyCars[i].cost >= price)
            cout << MyCars[i].brand << "\t" << MyCars[i].model << "\t" << MyCars[i].cost << "\t" << MyCars[i].ID << "\n";
        }
        else if (b==0)
        {
            if (MyCars[i].cost <= price)
            cout << MyCars[i].brand << "\t" << MyCars[i].model << "\t" << MyCars[i].cost << "\t" << MyCars[i].ID << "\n";
        }
    }
}

void main()
{
    
    setlocale(LC_ALL, "rus");
  
    Cars* MyCars = 0;//указатель на массив структур
    int size = 0;//счетчик стукрур в массиве
    string brand;
    short choice = 0;
    while (choice != 6)
    {
        cout << "Выберите действие:\n1.Добавить позиции\n2.Вывести все позиции на экран\n3.Вывести позицию по номеру \n4.Вывести позиции по цене\n5.Вывести по бренду\n6.Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            MyCars = Add(MyCars, size); 
            SetData(MyCars, size); 
            size++; 
            break;
        case 2:
            ShowData(MyCars, size);
            break;
        case 3:
            cout << "Введите номер позиции ";  
            int num;
            cin >> num;
            ShowData(MyCars, size, num);
            break;
        case 4:
            cout << "Введите цену ";
            int price;
            cin >> price;
            cout << "Введите 1 что-бы выести те которые дороже или 0 - вывести те которые дешевле ";
            int b;
            cin >> b;
            ShowData(MyCars, size, price, b);
            break;
        case 5:
            cout << "Введите бренд ";
            getline(cin, brand);
            ShowData(MyCars, size, brand);
            break;
        default:
            choice = 6;
            break;
        }
        cout << endl;
    }
    delete[] MyCars;
}
