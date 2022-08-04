#include "Person.h"

int Person::counter;

Person::Person(char* name, char* familyName, int phoneNumber, Date& dateOfBirth)
{
    setName(name);
    this->familyName = strdup(familyName);
    this->phoneNumber = phoneNumber;
    this->dateOfBirth = dateOfBirth;
    this->id = counter++;
}

Person::Person(const Person& otherPerson)
{
    *this = otherPerson;
}

Person::Person(Person&& otherPerson)
{
  *this = std::move(otherPerson);
}

Person::~Person()
{
    delete []name;
    delete []familyName;
}

const Person& Person::operator=(const Person& other)
{
    if (this != &other) {
        setName(other.name);
        setFamilyName(other.familyName);
        setPhoneNumber(other.phoneNumber);
        setDateOfBirth(other.dateOfBirth);
        setId(other.id);
    }
    return *this;
}

const Person& Person::operator=(Person&& other)
{
    if (this != &other)
    {
        setPhoneNumber(other.phoneNumber);
        setId(other.id);
        setDateOfBirth(other.dateOfBirth);
        std::swap(name, other.name);
        std::swap(familyName, other.familyName);
    }
    return *this;
}

int Person::getId() const
{
	return id;
}

void Person::setId(const int id)
{
    this->id = id;
}

char* Person::getName() const
{
	return name;
}

bool Person::setName(const char* name)
{
    if (strlen(name) == 0)
        throw "Name cannot be empty";
    else
        this->name = strdup(name);
        return true;
}

char* Person::getFamilyName() const
{
	return familyName;
}

bool Person::setFamilyName(const char* familyName)
{
    this->familyName = strdup(familyName);
	return true;
}

int Person::getPhoneNumber() const
{
	return phoneNumber;
}

bool Person::setPhoneNumber(const int phoneNumber)
{
    this->phoneNumber = phoneNumber;
	return true;
}

Date Person::getDateOfBirth() const
{
	return Date();
}

bool Person::setDateOfBirth(const Date& dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
	return true;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << "Name: " << p.name << " Last name: " << p.familyName << " Phone number: " << p.phoneNumber  << " Birthdate: " << p.dateOfBirth <<
    " ID: " << p.id;

    return os;
}
