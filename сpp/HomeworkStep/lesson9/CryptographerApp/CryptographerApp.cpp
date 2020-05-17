//
//1.	Написать программу - шифровальщик.Пользователь вводит строку, программа переводит ее в числовом формате.
//Допустим а это 10, b это 11, c это 12, d это 13 и тд.Тогда слово “bad” числовой форме 111013

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    string password;
    char letters[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    cout << "Enter password\n";
    cin >> password;
    char* chPass = new char[password.size() + 1];
    strcpy(chPass, password.c_str());
    for (int i = 0; i < strlen(chPass); i++)
    {
        for (int j = 0; j < strlen(letters); j++)
        {
            if (chPass[i] == letters[j])
            {
                cout << 10 + j;
            }
        }
    }
}
