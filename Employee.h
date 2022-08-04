#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include "Person.h"

class Employee : virtual public Person
{
protected:
	double salary;
public:
	Employee(char* name, char* familyName, int phoneNumber, Date& dateOfBirth, double salary);
    Employee(const Person& base, double salary);

	double getSalary() const;
	bool setSalary(const double salary);
};

#endif