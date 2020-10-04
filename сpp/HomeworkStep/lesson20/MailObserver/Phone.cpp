#include "Phone.h"

Phone::Phone(Mail* mail) : mail(mail)
{
}

Phone::~Phone()
{
}

void Phone::Update()
{
	cout << "Phone get " << mail->GetData() << "\n";
}
