#ifndef _MINISTRYOFHEALTHLICENSE_H
#define _MINISTRYOFHEALTHLICENSE_H

class MinistryOfHealthLicense
{
private:
    const int NUM_OF_AED = 2; // num of min defibrillators (AED) for licence to be valid
    int numOfDefibrillators;
	bool allDefibrillatorsVisible;

public:
	MinistryOfHealthLicense(int numOfDefibrillators, bool allDefibrillatorsVisible);
	bool setNumOfDefibrillators(const int num);
	bool setAllDefibrillatorsVisible(const bool isVisible);
	int getNumOfDefibrillators() const;
	bool getAllDefibrillatorsVisible() const;
	bool getLicenseValid() const;

};

#endif