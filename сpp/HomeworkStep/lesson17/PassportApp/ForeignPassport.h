#pragma once
#include "Passport.h"
class ForeignPassport :	public Passport
{
protected:
    string citizenship;
    Date validity;
    int numberVisas;

public:
    ForeignPassport();
    ForeignPassport(string Name, string Patronymic, string Surname, string City_birth, string Issued_by, string series, int number, Date birth, Date date_issue, string citizenship);
    ~ForeignPassport();

    friend ostream& operator<<(ostream& out, ForeignPassport& obj);
};

