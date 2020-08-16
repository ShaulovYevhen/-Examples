#include "Passport.h"
Passport::Passport()
{
    Surname = "Ivanov";
    Name = "Ivan";
    Patronymic = "Ivanovich";
    Ñity_birth = "Kyiv";
    Issued_by = "Migration Service 6311";
    series = "BM";
    number = 691152;
    birth = Date(30, 5, 2001);
    date_issue = Date(2, 10, 2017);
}

Passport::Passport(string Name, string Patronymic, string Surname, string City_birth, string Issued_by, string series, int number, Date birth, Date date_issue)
{
    this->Name = Name;
    this->Patronymic = Patronymic;
    this->Surname = Surname;
    this->Ñity_birth = City_birth;
    this->Issued_by = Issued_by;
    this->series = series;
    this->number = number;
    this->birth = birth;
    this->date_issue = date_issue;
}

Passport::~Passport() {}

string Passport::getName()
{
    return Name;
}

string Passport::getSurname()
{
    return Surname;
}

string Passport::getPatronymic()
{
    return Patronymic;
}

string Passport::getCity_birth()
{
    return Ñity_birth;
}

string Passport::getIssued_by()
{
    return Issued_by;
}

string Passport::getSeries()
{
    return series;
}

Date Passport::getBirth()
{
    return birth;
}

Date Passport::getDate_issue()
{
    return date_issue;
}

int Passport::getNumber()
{
    return number;
}

void Passport::setName(const string& Name)
{
    this->Name = Name;
}

void Passport::setSurname(const string& Surname)
{
    this->Surname = Surname;
}

void Passport::setPatronymic(const string& Patronymic)
{
    this->Patronymic = Patronymic;
}

void Passport::setCity_birth(const string& City_birth)
{
    this->Ñity_birth = City_birth;
}

void Passport::setIssued_by(const string& Issued_by)
{
    this->Issued_by = Issued_by;
}

void Passport::setSeries(const string& series)
{
    this->series = series;
}

void Passport::setNumber(const int& number)
{
    this->number = number;
}

void Passport::setBirth(const Date& birth)
{
    this->birth = birth;
}

void Passport::setDate_issue(const Date& date_issue)
{
    this->date_issue = date_issue;
}

ostream& operator<<(ostream& out, Passport& obj)
{
    out << "    My Passport" << endl
        << " Surname: " << obj.getSurname() << endl
        << " Name: " << obj.Name << endl
        << " Patronymic: " << obj.Patronymic << endl

        << " City_birth: " << obj.Ñity_birth << endl
        << " Birthday: " << obj.birth << endl

        << " Issued_by: " << obj.Issued_by << endl
        << " Date of issue: " << obj.date_issue << endl

        << " Series: " << obj.series << endl
        << " Number: " << obj.number << endl;
    return out;
}
