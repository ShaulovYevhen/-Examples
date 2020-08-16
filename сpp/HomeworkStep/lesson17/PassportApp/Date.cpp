#include "Date.h"
Date::Date() { year_ = 0; month_ = 0; day_ = 0; };

Date::Date(const int d, const int m, const int y)
{
	day_ = d;
	month_ = m;
	year_ = y;
}

int Date::day() const { return day_; }
int Date::month() const { return month_; }
int Date::year() const { return year_; }

void Date::setDay(const int& day) { Date::day_ = day; }
void Date::setMonth(const int& month) { Date::month_ = month; }
void Date::setYear(const int& year) { Date::year_ = year; }

int Date::getDay() const
{
	return day_;
}
int Date::getMonth() const
{
	return month_;
}
int Date::getYear() const
{
	return year_;
}

Date& Date::operator=(const Date& obj)
{
	if (this == &obj)
		return *this;
	this->day_ = obj.day_;
	this->month_ = obj.month_;
	this->year_ = obj.year_;
	return *this;
}

bool Date::valid() const 
{
	if (year_ < 0) return false;
	if (month_ > 12 || month_ < 1) return false;
	if (day_ > 31 || day_ < 1) return false;
	if ((day_ == 31 &&
		(month_ == 2 || month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)))
		return false;
	if (day_ == 30 && month_ == 2) return false;
	if (year_ < 2000) {
		if ((day_ == 29 && month_ == 2) && !((year_ -1900) % 4 == 0)) return false;
	}
	if (year_ > 2000) {
		if ((day_ == 29 && month_ == 2) && !((year_ -2000) % 4 == 0)) return false;
	}
	return true;
}

ostream& operator<<(ostream& out, Date& obj)
{
	out << obj.day() << "." << obj.month() << "." << +obj.year();
	return out;
}