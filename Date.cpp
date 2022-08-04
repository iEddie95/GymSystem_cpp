#include "Date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

bool Date::setDay(const int day)
{
    if (DAY_MONTH[month-1] < day)
        return false;

    this->day = day;
	return true;
}

bool Date::setMonth(const int month)
{
    if (month < 1 || month > 12)
        return false;
    this->month = month;
	return true;
}

bool Date::setYear(const int year)
{
    this->year = year;
	return true;
}

bool Date::operator==(const Date& other) const
{
    return (day == other.day && month == other.month && year == other.year);
}
istream& operator>>(istream& in, Date& d) noexcept(false)
{
    int day, month, year;

    in >> day >> month >> year;

    d.setYear(year);
    if (!d.setMonth(month))
        throw std::invalid_argument("Wrong month input");

    if(!d.setDay(day))
        throw std::invalid_argument("Wrong day input");

	return in;
}

ostream& operator<<(ostream& os, const Date& date)
{
    os << date.day << "/" << date.month << "/" << date.year;

    return os;
}
