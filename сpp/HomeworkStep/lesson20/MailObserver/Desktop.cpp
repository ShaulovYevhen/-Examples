#include "Desktop.h"

Desktop::Desktop(Mail* mail) : mail(mail)
{
}

Desktop::~Desktop()
{
}

void Desktop::Update()
{
	cout <<"Desktop get "<< mail->GetData() << "\n";
}
