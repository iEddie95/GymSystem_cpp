#include "GymLicense.h"

int GymLicense::counter;

GymLicense::GymLicense(MinistryOfHealthLicense& mLicense, FireDepartmentLicense& fLicense): mLicense(mLicense),
                                                                                            fLicense(fLicense)
{
    this->id = counter++;
}

int GymLicense::getId() const
{
	return this->id;
}

bool GymLicense::getIsValid() const
{
	return (fLicense.getLicenseValid() && mLicense.getLicenseValid());
}

ostream& operator<<(ostream& os, const GymLicense& gymLicense)
{
    os << "The gym license ID is: " << gymLicense.id;
    if(gymLicense.getIsValid()){
        os << " The gym license is valid";
    } else{
        os << " The gym license is invalid";
    }
	return os;
}