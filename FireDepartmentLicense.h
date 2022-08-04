#ifndef _FIREDEPARTMENTLICENSE_H
#define _FIREDEPARTMENTLICENSE_H

class FireDepartmentLicense
{
private:
    const int NUM_OF_SIGNS = 5; // num of min signs for licence to be valid
    int numOfEmergencySigns;
	bool allSignsVisible;

public:
    FireDepartmentLicense(int numOfEmergencySigns, bool allSignsVisible);
	bool setNumOfSigns(const int num);
	bool setAllSignsVisible(const bool isVisible);
	int getNumOfSigns()  const;
	bool getAllSignsVisible() const;
	bool getLicenseValid() const;
};

#endif