#include "Instructor.h"


Instructor::Instructor(const Person& base, double salary, int machine, int numExpYears): Person(base), Trainee(base, machine), Employee(base, salary)
{
    this->numExpYears = numExpYears;
}

int Instructor::getNumExpYears() const
{
	return numExpYears;
}

bool Instructor::setNumExpYears(const int num)
{
    this->numExpYears = num;
	return false;
};

ostream& operator<<(ostream& os, const Instructor& instructor)
{
    os << (Person&)instructor << " Salary is: " << instructor.salary << " Years of experience: " << instructor.numExpYears;
    return os;
}