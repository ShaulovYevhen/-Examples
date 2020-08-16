#include "ForeignPassport.h"

ForeignPassport::ForeignPassport()
{
    citizenship = "Ukraine";
    validity = Date(27, 5, 2021);
    numberVisas = 2;
}

ForeignPassport::ForeignPassport(string Name, string Patronymic, string Surname, string City_birth, string Issued_by, string series, int number, Date birth, Date date_issue, string citizenship)
    : Passport(Name, Patronymic, Surname, City_birth, Issued_by, series, number, birth, date_issue)
{
    this->citizenship = citizenship;
}

ForeignPassport::~ForeignPassport() {}

ostream& operator<<(ostream& out, ForeignPassport& obj)
{
    out << " My ForeignPassport" << endl
        << " Surname: " << obj.getSurname() << endl
        << " Name: " << obj.Name << endl
        << " Patronymic: " << obj.Patronymic << endl

        << " Citizenship: " << obj.citizenship << endl
        << " Birthday: " << obj.birth << endl

        << " Validity: " << obj.validity << endl
        << " Number of Visas: " << obj.numberVisas << endl;

    return out;
}
