#ifndef _GYM_H
#define _GYM_H
#include "GymLicense.h"
#include "ExerciseMachine.h"
#include "Trainee.h"
#include "Instructor.h"


class Gym
{
private:
	int id;
	char* name;
	char* address;
	int maxMachinesNum;
	int currentMachinesNum;
	int maxTraineesNum;
	int currentTraineesNum;
	ExerciseMachine** allMachines;
	Trainee** allTrainees;
	GymLicense license;
	Instructor* instructor;

public:
    Gym(int id, char* name, char* address, int maxMachines, int maxTrainees, GymLicense& license);
	Gym(const Gym& other) = delete;													//copy constructor
	Gym(Gym&& otherGym);														//move constructor
	~Gym();																		//destructor

    const Gym& operator=(Gym&& other);

	GymLicense getLicense() const;
	int getId() const;
	char* getName() const;
	bool setName(const char* name);
	char* getAddress() const;
	bool setAddress(const char* address);
	int getCurrentMachineNum() const;
	int getMaxMachineNum() const;
	bool setCurrentMachineNum(const int machineNum);
	bool setMaxMachineNum(const int machineNum);
	int getCurrentTraineesNum() const;
	int getMaxTraineeNum() const;
	bool setCurrentTraineeNum(const int traineeNum);
	bool setMaxTraineeNum(const int traineeNum);
    Instructor* getInstructor() const;
    bool setInstructor(const Person& base, double salary, int machine,  int numExpYears);
    bool setInstructor(Instructor* instructor);
    ExerciseMachine** getAllMachines() const;
	Trainee** getAllTrainees() const;
    bool addTrainee(char* name, char* familyName, int phoneNumber, Date& dateOfBirth, int favoriteMachine);
	bool addMachine(int type, double weight, int numOfDates, Date* maintenancesDates);
    bool resizeMaxTrainees(int num);
	void showMachines() const;
	void showTrainees() const;

    friend ostream& operator<<(ostream& os, const Gym& gym);

};

#endif