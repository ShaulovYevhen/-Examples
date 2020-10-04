#include "Subscriber.h"

Subscriber::Subscriber(Mail* mail) : mail(mail)
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::Update()
{
	cout << mail->GetData() << "\n";
}
