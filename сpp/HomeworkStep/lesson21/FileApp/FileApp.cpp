//1. Создать текстовый файл и записать в него фразу «Здесь был,
//<Ваше_имя>!».
//2. Записать массив строк в файл, расположив каждый элемент массива на
//отдельной строке с сохранением порядка.
//3. Дан текстовый файл.Необходимо переписать его строки в другой
//файл.Порядок строк во втором файле должен совпадать с порядком
//строк в заданном файле.
//4. Дан текстовый файл.Необходимо переписать его строки в другой
//файл.Порядок строк во втором файле должен быть обратным по
//отношению к порядку строк в заданном файле.
//5. Дан текстовый файл.Необходимо создать новый файл, в который
//переписать из исходного файла все слова, состоящие не менее чем из
//семи букв.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream out;
    out.open("1.txt");
    if (out.is_open())
    {
        out << "«Здесь был, Женя!»" << endl;
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    out.close();

    out.open("2.txt");
    if (out.is_open())
    {
        string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Saturday" };
        for (int i = 0; i < 7; i++)
        {
            out << daysOfWeek[i] << endl;
        }
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    out.close();

    system("copy 2.txt 3.txt");
    
    ifstream in("2.txt");
    out.open("3.1.txt");
      
    if (out.is_open() && in.is_open())
    {
        out << in.rdbuf();
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    in.close();
    out.close();

    string str;
    in.open("2.txt");
    out.open("3.2.txt");
    if (out.is_open() && in.is_open())
    {
        while (getline(in, str))
        {
           out << str << endl;
        }
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    in.close();
    out.close();

    
    in.open("2.txt");
    out.open("4.txt");
    int filesize = 0;
    if (!in)
    {
        cout << "File not open\n";
    }
    else
    {
        string buff;
        while (!in.eof())
        {
            getline(in, buff);
            filesize++;
        }
    }
    in.clear();
    in.seekg(0);
    string * mas = new string[filesize];
    int i = 0;
    if (out.is_open() && in.is_open())
    {
        while (getline(in, str))
        {
            mas[i] = str;
            i++;
        }
        for (int j = i; j >= 0; j--)
        {
            out << mas[j] << endl;
        }
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    in.close();
    out.close();

    in.open("2.txt");
    out.open("5.txt");
    if (in.is_open())
    {
        while (getline(in, str))
        {
            if (str.size() >= 7) 
            {
                out << str << endl;
            }
        }
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    in.close();
    out.close();

    return 0;
}

