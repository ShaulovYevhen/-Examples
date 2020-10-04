#include "Input_.h"
Input_::Input_()
{
}
Input_::~Input_()
{
}
int Input_::input_int()
{
    int i;
    cin >> i;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "";
        cout << "Wrong input, enter digit pls." << endl;
        cin >> i;
    }
    return i;
}

string Input_::teg_generator()
{
    string teg = "";
    string str1 = "123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    for (int i = 0; i < 6 + rand() % 4; i++)
    {
        teg += str1[rand() % (str1.length() - 25)];
    }
    return teg;
}
