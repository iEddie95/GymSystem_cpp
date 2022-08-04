#include "Employee.h"

Employee::Employee(char* name, char* familyName, int phoneNumber, Date& dateOfBirth, double salary) : Person(name, familyName, phoneNumber, dateOfBirth)
{
    this->salary = salary;
}

Employee::Employee(const Person& base, double salary) :  Person(base)
{
    this->salary = salary;
}

double Employee::getSalary() const
{
	return salary;
}

bool Employee::setSalary(const double salary)
{
    this->salary = salary;
	return true;
}