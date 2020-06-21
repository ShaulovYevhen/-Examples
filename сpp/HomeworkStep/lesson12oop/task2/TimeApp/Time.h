#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Time
{
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s);//конструктор класа
	Time();//конструктор по умролчанию
	int getHour()const;//геттер для возвращения значений
	void setHour(int val);//сеттер для установки и проверки значений 
	int getMin()const;
	void setMin(int val);
	int getSec()const;
	void setSec(int val);
	void Show()const;
	int timeToSeconds(Time& t);//перевести время в секунды
	int timeToSeconds(int h, int m, int s);
	Time secondsToTime(int sec);// перевести секунды в время
	Time operator +(Time obj);
	Time operator +(int val);
	Time operator -(Time obj);
	Time operator -(int val);
	void operator ++();
	void operator ++(int);
	void operator --();
	void operator --(int);
	bool operator <(Time obj);
	bool operator >(Time obj);
	bool operator <=(Time obj);
	bool operator >=(Time obj);
	bool operator ==(Time obj);
	bool operator !=(Time obj);
};

