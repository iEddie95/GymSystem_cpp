#ifndef _GYMLICENSE_H
#define _GYMLICENSE_H
#include "FireDepartmentLicense.h"
#include "MinistryOfHealthLicense.h"
#include <iostream>

using namespace std;

class GymLicense
{
private:
	static int counter;
    int id;
	MinistryOfHealthLicense mLicense;
	FireDepartmentLicense fLicense;

public:
	GymLicense(MinistryOfHealthLicense& mLicense, FireDepartmentLicense& fLicense);
	int getId() const;
	bool getIsValid() const;

	friend ostream& operator<<(ostream& os, const GymLicense& gymLicense);
};

#endif