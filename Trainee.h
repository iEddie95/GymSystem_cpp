#ifndef _TRAINEE_H
#define _TRAINEE_H
#include "Person.h"
#include "ExerciseMachine.h"

class Trainee : virtual public Person
{
protected:
    ExerciseMachine::eName favMachine;
public:
	Trainee(char* name, char* familyName, int phoneNumber, Date& dateOfBirth, int favoriteMachine);
    Trainee(const Person& base, int favoriteMachine);

	int getFavMachineIndex() const;
	bool setFavMachine(int machine);
    friend ostream& operator<<(ostream& os, const Trainee& trainee);
};

#endif