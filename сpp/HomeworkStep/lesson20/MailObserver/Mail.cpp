#include "Mail.h"

Mail::Mail()
{
}

Mail::~Mail()
{

}

string Mail::GetData()
{
	return data;
}

void Mail::SetData(string _data)
{
	data = _data;
}

void Mail::Subscribe(Observer* observer)
{
	observers.push_back(observer);
}

void Mail::Unsubscribe(Observer* observer)
{
	vector<Observer*>::iterator pos;
	for (pos = observers.begin();
		pos != observers.end(); ++pos)
	{
		if (*pos == observer)
		{
			observers.erase(pos);
			break;
		}
	}
}

void Mail::Notify()
{
	if (data == "") 
	{
		return;
	}
	vector<Observer*>::iterator pos;
	for (pos = observers.begin();
		pos != observers.end(); ++pos)
	{
		Observer* observer = *pos;
		observer->Update();
	}
}
