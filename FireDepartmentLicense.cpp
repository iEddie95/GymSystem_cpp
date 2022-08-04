#include "FireDepartmentLicense.h"


FireDepartmentLicense::FireDepartmentLicense(int numOfEmergencySigns, bool allSignsVisible)
{
    this->numOfEmergencySigns = numOfEmergencySigns;
    this->allSignsVisible = allSignsVisible;
}

bool FireDepartmentLicense::setNumOfSigns(const int num)
{
    this->numOfEmergencySigns = num;
	return true;
}

bool FireDepartmentLicense::setAllSignsVisible(const bool isVisible)
{
    this->allSignsVisible = isVisible;
	return true;
}

int FireDepartmentLicense::getNumOfSigns() const
{
	return this->numOfEmergencySigns;
}
bool FireDepartmentLicense::getAllSignsVisible() const
{
	return this->allSignsVisible;
}

bool FireDepartmentLicense::getLicenseValid() const
{
    if (this->allSignsVisible && this->numOfEmergencySigns >= NUM_OF_SIGNS){
        return true;
    }
	return false;
}