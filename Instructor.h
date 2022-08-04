#ifndef _CONSTRUCTOR_H
#define _CONSTRUCTOR_H

#include "Employee.h"
#include "Trainee.h"
#include "Person.h"

class Instructor : public Trainee, public Employee
{
private:
	int numExpYears;
public:
    Instructor(const Person& base, double salary, int machine, int numExpYears);

	int getNumExpYears() const;
	bool setNumExpYears(const int num);
    friend ostream& operator<<(ostream& os, const Instructor& instructor);
};

#endif