//3.	Написать программу, которая создает двумерный массив по размерам пользователя,
//если ков - во столбцов четное, то делит его пополам(см рисунок)

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

int main()
{
    setlocale(LC_ALL, "rus");
    int rows, cols;
    cout << "Введите размеры начальной матрицы: ";
    cin >> rows >> cols;
    if (cols % 2 != 0) 
    {
        int** M;
        createMatrix(M, rows, cols);
        Fill(M, rows, cols);
        displayMatrix(M, rows, cols);
    }
    else
    {
        int** M;
        int** N;
        createMatrix(M, rows, cols);
        Fill(M, rows, cols);
        displayMatrix(M, rows, cols);
        createMatrix(N, rows, cols);
        Fill(N, rows, cols);
        displayMatrix(N, rows, cols);
    }
}


