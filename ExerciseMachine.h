#ifndef _EXERCISEMACHINE_H
#define _EXERCISEMACHINE_H
#include "Date.h"

class ExerciseMachine
{
public:
    enum eName { BICYCLE, ROWING_MACHINE, LEG_PRESS, LAT_PULLDOWN, CHEST_PRESS };
    static constexpr char* machinesName[] = {"Bicycle", "Rowing machine", "Leg press", "Lat pull down", "Chest press"};

private:
    static int counter;
    int id;
    eName name;
    double weight;
    int maintenancesNum;
    Date* maintenancesDates;

public:
	ExerciseMachine(eName name, double weight, int maintenancesNum, Date* maintenancesDates);
	ExerciseMachine(const ExerciseMachine& otherMachine);
	ExerciseMachine(ExerciseMachine&& otherMachine);
	~ExerciseMachine();

	int getId() const;
	eName getName() const;
	bool setName(const eName name);
	double getWeight() const;
	bool setWeight(const double weight);
	int getMaintenancesNum() const;
	bool setMaintenancesNum(const int num);
	Date* getMaintenancesDates() const;
    const char* getMachineName() const;
	bool setMaintenancesDates(Date* dates);
	const ExerciseMachine& operator=(const ExerciseMachine& other);
    const ExerciseMachine& operator=(ExerciseMachine& other);
    friend ostream& operator<<(ostream& os, const ExerciseMachine& machine);
    friend ostream& operator<<(ostream& os, const eName eMachine);

};


#endif