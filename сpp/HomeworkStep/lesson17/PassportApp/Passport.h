#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Passport
{
protected:
    string Name;
    string Patronymic;
    string Surname;
    string Ñity_birth;
    Date birth;
    string Issued_by;
    Date date_issue;
    string series;
    int number;
public:
    Passport();
    Passport(string Name, string Patronymic, string Surname, string City_birth, string Issued_by, string series, int number, Date birth, Date date_issue);
    ~Passport();
    string getName();
    string getSurname();
    string getPatronymic();
    string getCity_birth();
    string getIssued_by();
    string getSeries();
    Date getBirth();
    Date getDate_issue();
    int getNumber();
    void setName(const string& Name);
    void setSurname(const string& Surname);
    void setPatronymic(const string& Patronymic);
    void setCity_birth(const string& City_birth);
    void setIssued_by(const string& Issued_by);
    void setSeries(const string& series);
    void setNumber(const int& number);
    void setBirth(const Date& birth);
    void setDate_issue(const Date& date_issue);

    friend ostream& operator<<(ostream& out, Passport& obj);
};