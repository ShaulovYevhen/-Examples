// 2.	Написать программу добавления / удаления строк / 
// столбцов в массив в указанном пользователем месте

#include <iostream>
#include <iomanip>
using namespace std;

void createMatrix(int**& X, int rows, int cols)
{// создание массива
    X = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        X[i] = new int[cols] {0};
    }
}

void displayMatrix(int** X, int rows, int cols)
{//вывод массива
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << X[i][j];
        }
        cout << endl;
    }
}

void deleteMatrix(int**& X, int rows)
{// освобождение памяти
    for (int i = 0; i < rows; i++)
    {
        delete[] X[i];
    }
    delete[] X;
}

void Fill(int** X, int rows, int cols)//заполнение массива случайными значениеями
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            X[i][j] = rand() % 100;
        }
    }
}

void insertRows(int**& X, int& rows, int cols, int posr)
{//вставка строки
    int** buff;
    createMatrix(buff, rows + 1, cols);
    bool shift = 0;
    for (int i = 0; i < rows; i++)
    {
        if (i == posr)
        {
            shift = 1;
        }
        for (int j = 0; j < cols; j++)
        {
            buff[i + shift][j] = X[i][j];
        }
    }
    deleteMatrix(X, rows);
    rows++;
    X = buff;
}

void delRows(int**& X, int& rows, int cols, int posr)
{//удаление строки
    int** buff;
    createMatrix(buff, rows-1, cols);
    for (int i = 0; i < rows-1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != posr) 
            {
                buff[i][j] = X[i][j];
            }
        }
    }
    deleteMatrix(X, rows);
    X = buff;
    rows--;
}

void insertCols(int**& X, int rows, int& cols, int posc)
{//вставка столбца
    int** buff;
    createMatrix(buff, rows, cols + 1);
    bool shift;
    for (int i = 0; i < rows; i++)
    {
        shift = 0;
        for (int j = 0; j < cols; j++)
        {
            if (j == posc)
            {
                shift = 1;
            }
            buff[i][j + shift] = X[i][j];
        }
    }
    deleteMatrix(X, rows);
    cols++;
    X = buff;
}

void delCols(int**& X, int rows, int& cols, int posc)
{//удаление столбца
    int** buff;
    createMatrix(buff, rows, cols - 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols-1; j++)
        {
            if (i != posc)
            {
                buff[i][j] = X[i][j];
            }
        }
    }
    deleteMatrix(X, rows);
    cols--;
    X = buff;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int rows, cols;
    cout << "Введите размеры начальной матрицы: ";
    cin >> rows >> cols;
    int** M;
    createMatrix(M, rows, cols);
    Fill(M, rows, cols);
    displayMatrix(M, rows, cols);
    short choice = 0;
    while (choice != 5)
    {
        cout << "Выберите действие:\n1.Вставить строку\n2.Вставить столбец\n3.Удалить строку\n4.Удалить столбец\n5.Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Введите позицию в строках: ";
            cin >> choice;
            insertRows(M, rows, cols, choice - 1);
            displayMatrix(M, rows, cols);
            break;
        case 2:
            cout << "Введите позицию в столбцах: ";
            cin >> choice;
            insertCols(M, rows, cols, choice - 1);
            displayMatrix(M, rows, cols);
            break;
        case 3:
            cout << "Введите позицию в строках: ";
            cin >> choice;
            delRows(M, rows, cols, choice - 1);
            displayMatrix(M, rows, cols);
            break;
        case 4:
            cout << "Введите позицию в столбцах: ";
            cin >> choice;
            delCols(M, rows, cols, choice - 1);
            displayMatrix(M, rows, cols);
            break;
        default:
            choice = 5;
            break;
        }
        cout << endl;
    }
    cout << "\n\n";
    system("pause");
    return 0;
}

