#pragma once
#include <string>
#include <vector>
#include "Observer.h"
using namespace std;
class Mail
{
	string data="";
	vector<Observer*> observers;
public:
	Mail();
	~Mail();
	string GetData();
	void SetData(string data);
	void Subscribe(Observer* observer);
	void Unsubscribe(Observer* observer);
	void Notify();
};

