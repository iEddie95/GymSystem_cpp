#ifndef _DATE_H
#define _DATE_H
#include <iostream>

using namespace std;

class Date
{
private:
    static constexpr int DAY_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;

public:
	Date(int day = 1, int month = 1, int year = 2020);
	
	int getDay() const;  
	int getMonth() const; 
	int getYear() const;  
	bool setDay(const int day);
	bool setMonth(const int month);
	bool setYear(const int year);

	friend istream& operator>>(istream& in, Date& d);
    friend ostream& operator<<(ostream& os, const Date& date);
    bool operator==(const Date& other) const;
};

#endif