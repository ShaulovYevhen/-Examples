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

string Input_::input_phone_number()
{
    bool flag = false;
    char str[255];
    string phone;
    while (flag == false)
    {
        cin >> phone;
        strcpy(str, phone.c_str());
        if (str[0] == '3' && str[1] == '8' && str[2]=='0' && isdigit(str[3]) && isdigit(str[4]) && (isdigit(str[5])) && isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]) && isdigit(str[10]) && isdigit(str[11]) && !isdigit(str[12]))
        {
            return phone;
            flag = true;
        }
        else
        {
            cout << "\nWhong input enter Ukr phone number for example 380636016011" << endl;
            flag = false;
        }
    }
}
