#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Input_
{
public:
    Input_();
    ~Input_();
    int input_int();
    string input_phone_number();
};

