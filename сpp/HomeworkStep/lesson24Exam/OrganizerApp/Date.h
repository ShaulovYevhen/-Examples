#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Date {
protected:
	int year_;
	int month_;
	int day_;
public:
	Date();
	Date(const int d, const int m, const int y);
	bool valid(void) const;
	int day() const;
	int month() const;
	int year() const;
	void setDay(const int& day);
	void setMonth(const int& month);
	void setYear(const int& year);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void setDateFromString(string dt);
	friend ostream& operator<<(ostream& out, Date& obj);
	Date& operator=(const Date& obj);
};

