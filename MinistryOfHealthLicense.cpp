#include "MinistryOfHealthLicense.h"


MinistryOfHealthLicense::MinistryOfHealthLicense(int numOfDefibrillators, bool allDefibrillatorsVisible)
{
    this->numOfDefibrillators = numOfDefibrillators;
    this->allDefibrillatorsVisible = allDefibrillatorsVisible;
}

bool MinistryOfHealthLicense::setNumOfDefibrillators(const int num)
{
    this->numOfDefibrillators = num;
	return true;
}

bool MinistryOfHealthLicense::setAllDefibrillatorsVisible(const bool isVisible)
{
    this->allDefibrillatorsVisible = isVisible;
	return true;
}

int MinistryOfHealthLicense::getNumOfDefibrillators() const
{
	return this->numOfDefibrillators;
}

bool MinistryOfHealthLicense::getAllDefibrillatorsVisible() const
{
	return this->allDefibrillatorsVisible;
}
bool MinistryOfHealthLicense::getLicenseValid() const
{
    if(this->getAllDefibrillatorsVisible() && this->numOfDefibrillators >= NUM_OF_AED){
        return true;
    }
    return false;
}