// Cоздать телефонную книгу.
// Поля : ФИО, номер телефона, email.
//- Заполнение из файла и из консоли
//- Сортировка по имени
//- Добавление и удаление элементов
//- Редактирование элементов
//- Поиск элементов
//- Ну и вывод на экран само собой

#include <stdlib.h> 
#include <iostream> 
#include <iomanip>
#include <fstream> 
#include <string>
#include <sstream>

using namespace std;

struct PhoneBook
{
    string name;
    string phone;
    string email;
};

int FileSize(const char* filename)
{
    ifstream fin(filename);
    int i = 0;
    if (!fin)
    {
        cout << "File not open\n";
    }
    else
    {
        string buff;
        while (!fin.eof())
        {
            getline(fin, buff);
            i++;
        }
    }
    return i;
}

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

PhoneBook* Add(PhoneBook* MyPhoneBook, int const count) 
{
    if (count == 0)
    {
        MyPhoneBook = new PhoneBook[1];
    }
    else
    {
        PhoneBook* temp = new PhoneBook[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = MyPhoneBook[i];
        }
        delete[] MyPhoneBook;
        MyPhoneBook = temp;
    }
    return MyPhoneBook;
}
PhoneBook* Del(PhoneBook* MyPhoneBook, int const count, int el) 
{
    PhoneBook* temp = new PhoneBook[count - 1];
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        if (i != el)
        {
            temp[j] = MyPhoneBook[i];
            j++;
        }
    }
    delete[] MyPhoneBook;
    MyPhoneBook = temp;
    return MyPhoneBook;
}

PhoneBook* Read(const char* filename, PhoneBook MyPhoneBook[])
{
    ifstream fin(filename);
    int j = 0;
    if (!fin)
    {
        cout << "File not open\n";
    }
    else
    {
        string buff;
        while (getline(fin, buff))
        {
            MyPhoneBook = Add(MyPhoneBook, j);
            stringstream ss(buff);
            string token;
            string s[3];
            int i = 0;
            while (getline(ss, token, ';'))
            {
                s[i] = token;
                i++;
            }
            MyPhoneBook[j].name = s[0];
            MyPhoneBook[j].phone = s[1];
            MyPhoneBook[j].email = s[2];
            j++;
        }
    }
    return MyPhoneBook;
    fin.close();
}

void Search(PhoneBook* MyPhoneBook, int size, string searchWord)
{
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (MyPhoneBook[i].name.find(searchWord)!=-1|| MyPhoneBook[i].phone.find(searchWord) !=-1 || MyPhoneBook[i].email.find(searchWord) !=-1)
        {
            cout << "Номер ПП\tФИО\t\tНомер телефона\t E-mail\n";
            cout << i + 1 << "\t\t" << MyPhoneBook[i].name << "\t" << MyPhoneBook[i].phone << "\t" << MyPhoneBook[i].email << "\n";
            flag = false;
        }
    }
    if (flag) 
    {
        cout << "Нет таких";
    }
}

void SetData(PhoneBook MyPhoneBook[], int const count)
{
    cout << "Введите имя(англ) и нажмите Enter\n"; 
    cin.ignore();
    getline(cin, MyPhoneBook[count].name);
    
    cout << "Введте номер телефонаи нажмите Enter\n"; 
    cin.ignore();
    getline(cin, MyPhoneBook[count].phone);
    
    cout << "Введите емайли нажмите Enter\n"; 
    cin.ignore();
    getline(cin, MyPhoneBook[count].email);
}

void Edit(PhoneBook MyPhoneBook[], int const count, int el)
{
    cout << "Введите имя(англ) и нажмите Enter\n";
    cin.ignore();
    getline(cin, MyPhoneBook[el].name);

    cout << "Введте номер телефонаи нажмите Enter\n";
    cin.ignore();
    getline(cin, MyPhoneBook[el].phone);

    cout << "Введите емайли нажмите Enter\n";
    cin.ignore();
    getline(cin, MyPhoneBook[el].email);
}

void Sort(PhoneBook MyPhoneBook[], int const count)
{
    string temp;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(MyPhoneBook[i].name.c_str(), MyPhoneBook[j].name.c_str()) > 0)
            {
                temp = MyPhoneBook[i].name;
                MyPhoneBook[i].name = MyPhoneBook[j].name;
                MyPhoneBook[j].name = temp;
                temp = MyPhoneBook[i].email;
                MyPhoneBook[i].email = MyPhoneBook[j].email;
                MyPhoneBook[j].email = temp;
                temp = MyPhoneBook[i].phone;
                MyPhoneBook[i].phone = MyPhoneBook[j].phone;
                MyPhoneBook[j].phone = temp;
            }
        }
    }
}

void Save(PhoneBook PhoneBook[], int const size, const char* filename)
{
    ofstream file(filename, ios::out);
    if (!file)
    {
        cout << "Файла не существует\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            file << PhoneBook[i].name << ";" << PhoneBook[i].phone << ";" << PhoneBook[i].email << "\n";
        }
        else
        {
            file << PhoneBook[i].name << ";" << PhoneBook[i].phone << ";" << PhoneBook[i].email;
        }
    }
    file.close();
}

void ShowData(PhoneBook* MyPhoneBook, int size)
{
    cout << "__________________________________________________________________________\n";
    cout << "| " << left << setw(4)  << "ПН";
    cout << "| " << left << setw(25) << "ФИО";
    cout << "| " << left << setw(15) << "Номер телефона";
    cout << "| " << left << setw(20) << "E-mail" <<" |"<< endl;
    cout << "__________________________________________________________________________\n";
    for (int i = 0; i < size; i++)
    {
        cout << "| " << left << setw(4)  << i + 1;
        cout << "| " << left << setw(25) << MyPhoneBook[i].name ;
        cout << "| " << left << setw(15) << MyPhoneBook[i].phone ;
        cout << "| " << left << setw(20) << MyPhoneBook[i].email << " |" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    PhoneBook* MyPhoneBook = 0;
    int size = FileSize("PhoneBook.txt");
    MyPhoneBook = Read("PhoneBook.txt", MyPhoneBook);
    ShowData(MyPhoneBook, size);
    string searchWord;
    int el;
    int choice = 0;
    while (choice != 9)
    {
        cout << "Выберите действие:\n1.Открыть\n2.Добавить\n3.Удалить\n4.Отсортировать ФИО\n5.Редактировать\n6.Поиск\n7.Вывести на экран.\n8.Сохранить\n9.Выход." << endl;
        choice = input_int();
        switch (choice)
        {
        case 1:
            MyPhoneBook = Read("PhoneBook.txt", MyPhoneBook);
            ShowData(MyPhoneBook, size);
            break;
        case 2:
            MyPhoneBook = Add(MyPhoneBook, size);
            SetData(MyPhoneBook, size);
            size++;
            break;
        case 3:
            cout << "Введите номер елемента который нужно удалить: ";
            el = input_int();
            MyPhoneBook = Del(MyPhoneBook, size, el-1);
            size--;
            ShowData(MyPhoneBook, size);
            break;
        case 4:
            Sort(MyPhoneBook, size);
            ShowData(MyPhoneBook, size);
            break;
        case 5:
            cout << "Введите номер елемента который нужно отредактировать: ";
            el = input_int();
            Edit(MyPhoneBook, size, el - 1);
            ShowData(MyPhoneBook, size);
            break;
        case 6:
            cout << "Введите что нужно найти: ";
            cin.ignore();
            getline(cin, searchWord);
            Search(MyPhoneBook, size, searchWord);
            break;
        case 7:
            ShowData(MyPhoneBook, size);
            break;
        case 8:
            Save(MyPhoneBook, size, "PhoneBook.txt");
            break;
        default:
            choice = 9;
            break;
        }
        cout << endl;
    }
}











