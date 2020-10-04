#pragma once
#include <string>
#include <iostream>
#include "Input_.h"
#include "Date.h"
#include <fstream>
using namespace std;
class Deal
{
protected:
    string teg = "";
    string name = "";
    Date date;
    string whatToDo = "";
public:
    Deal();
    virtual ~Deal();
    string getTeg()const;
    string getName()const;
    void setName(string _name);
    Date getDate()const;
    void setDate(Date _date);
    string getWhatToDo()const;
    void setWhatToDo(string _whatToDo);
    void show()const;
    void save(string filename);
    void open(string filename);
};


