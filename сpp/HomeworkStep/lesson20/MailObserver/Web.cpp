#include "Web.h"

Web::Web(Mail* mail) : mail(mail)
{
}

Web::~Web()
{
}

void Web::Update()
{
	cout << "Web get " << mail->GetData() << "\n";
}
