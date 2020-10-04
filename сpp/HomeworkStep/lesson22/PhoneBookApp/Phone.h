#pragma once
#include<string>
#include <iostream>
#include <fstream>
using namespace std;
class Phone
{
    string name="";
    string surname="";
    string adress="";
    string phone="";
    string id="";
public:
    Phone();
    Phone(string _name, string _surname, string _adress, string _phone, string _id);
    ~Phone();
    Phone(const Phone& obj);
    Phone(Phone&& obj)noexcept;
    Phone& operator=(const Phone& obj);
    Phone& operator=(Phone&& obj)noexcept;
    string getName()const;
    void setName(string _name);
    string getSurname()const;
    void setSurname(string _surname);
    string getAdress()const;
    void setAdress(string _adress);
    string getPhone()const;
    void setPhone(string _phone);
    string getId()const;
    void setId(string _id);
    void show()const;
    void saveBinary(string filename);
    void openBinary(string filename);
    void save(string filename);
    void open(string filename);
};

