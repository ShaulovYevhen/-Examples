//Разработать приложение, описывающее взаимодействие почтового сервера с
//клиентами.При получении нового письма, сервер должен оповестить об этом
//все клиентские приложения(телефон, десктоп, веб).

#include "Mail.h"
#include "Subscriber.h"
#include "Phone.h"
#include "Web.h"
#include "Desktop.h"

#include <iostream>
int main()
{
    Mail* mail = new Mail();

    Subscriber* phone = new Subscriber(mail);
    Subscriber* desktop = new Subscriber(mail);
    Subscriber* web = new Subscriber(mail);
    mail->Subscribe(phone);
    mail->Subscribe(desktop);
    mail->Subscribe(web);
    mail->Notify();
    mail->SetData(string("My first mail"));
    mail->Notify();
    mail->SetData(string("My second mail"));
    mail->Notify();
    mail->Unsubscribe(phone);
    mail->SetData(string("My Third  mail"));
    mail->Notify();
    
    delete web;
    delete desktop;
    delete phone;
    Phone* phone = new Phone(mail);
    Desktop* desktop = new Desktop(mail);
    Web* web = new Web(mail);
    mail->Subscribe(phone);
    mail->Subscribe(desktop);
    mail->Subscribe(web);
    mail->Notify();
    mail->SetData(string("My first mail"));
    mail->Notify();
    mail->SetData(string("My second mail"));
    mail->Notify();
    mail->Unsubscribe(phone);
    mail->SetData(string("My Third  mail"));
    mail->Notify();
    delete web;
    delete desktop;
    delete phone;
    delete mail;



}


