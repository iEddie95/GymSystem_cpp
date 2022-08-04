#include "Trainee.h"


Trainee::Trainee(char* name, char* familyName, int phoneNumber, Date& dateOfBirth, int favoriteMachine) : Person(name, familyName, phoneNumber, dateOfBirth)
{
    this->favMachine = (ExerciseMachine::eName)favoriteMachine;
}

Trainee::Trainee(const Person& base, int favoriteMachine) : Person(base)
{
    this->favMachine = (ExerciseMachine::eName)favoriteMachine;
}

int Trainee::getFavMachineIndex() const
{
    return favMachine;
}

bool Trainee::setFavMachine(int machine)
{
    this->favMachine = (ExerciseMachine::eName)machine;
	return true;
}

ostream& operator<<(ostream& os, const Trainee& trainee)
{
    os <<"Trainee-> " << (Person&)trainee << " Favorite Machine is: " << trainee.favMachine;
    return os;
}