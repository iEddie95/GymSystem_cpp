#ifndef _PERSON_H
#define _PERSON_H
#include "Date.h"

class Person	
{
protected:
	static int counter;
	char* name;
	char* familyName;
	int phoneNumber;
	Date dateOfBirth;
    int id;

public:
	Person(char* name, char* familyName, int phoneNumber, Date& dateOfBirth);
    Person(const Person& otherPerson);
	Person(Person&& otherPerson);												//move constructor
    virtual ~Person();//destructor

	int getId() const;
    void setId(const int id);
	char* getName() const;
	bool setName(const char* name);
	char* getFamilyName() const;
	bool setFamilyName(const char* familyName);
	int  getPhoneNumber() const;
	bool setPhoneNumber(const int phoneNumber);
	Date getDateOfBirth() const;
	bool setDateOfBirth(const Date& dateOfBirth);
    const Person& operator=(const Person& other);
    const Person& operator=(Person&& other);

    friend ostream& operator<<(ostream& os, const Person& p);
};


#endif
