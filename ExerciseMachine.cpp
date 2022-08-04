#include "ExerciseMachine.h"
int ExerciseMachine::counter;

ExerciseMachine::ExerciseMachine(eName name, double weight, int maintenancesNum, Date* maintenancesDates)
{
    this->id = counter++;
    this->name = name;
    this->weight = weight;
    this->maintenancesNum = maintenancesNum;
    this->maintenancesDates = maintenancesDates;
}

ExerciseMachine::ExerciseMachine(const ExerciseMachine& otherMachine)
{
    *this = otherMachine;
}

ExerciseMachine::ExerciseMachine(ExerciseMachine&& otherMachine)
{
    *this = std::move(otherMachine);
}

ExerciseMachine::~ExerciseMachine()
{
    delete [] maintenancesDates;
}

int ExerciseMachine::getId() const
{
	return id;
}

ExerciseMachine::eName ExerciseMachine::getName() const
{
	return name;
}

bool ExerciseMachine::setName(const eName name)
{
    this->name = name;
	return true;
}

double ExerciseMachine::getWeight() const
{
	return weight;
}

bool ExerciseMachine::setWeight(const double weight)
{
    this->weight = weight;
	return true;
}

int ExerciseMachine::getMaintenancesNum() const
{
	return maintenancesNum;
}

bool ExerciseMachine::setMaintenancesNum(const int num)
{
    maintenancesNum = num;
	return true;
}

Date* ExerciseMachine::getMaintenancesDates() const
{
	return maintenancesDates;
}

bool ExerciseMachine::setMaintenancesDates(Date* dates)
{
    maintenancesDates = dates;
	return true;
}

const char* ExerciseMachine::getMachineName() const
{
    return machinesName[name];
}

const ExerciseMachine& ExerciseMachine::operator=(const ExerciseMachine& other)
{
    if (this != &other)
    {
        this->id = other.id;
        setName(other.name);
        setWeight(other.weight);
        setMaintenancesNum(other.maintenancesNum);
        setMaintenancesDates(other.maintenancesDates);
    }
    return *this;
}

const ExerciseMachine& ExerciseMachine::operator=(ExerciseMachine& other)
{
    if (this != &other)
    {
        this->id = other.id;
        setName(other.name);
        setWeight(other.weight);
        setMaintenancesNum(other.maintenancesNum);
        std::swap(this->maintenancesDates, other.maintenancesDates);
    }

    return *this;
}

ostream& operator<<(ostream& os, const ExerciseMachine& machine)
{
    os << "Machine Id: " << machine.id << " ,Name: " << machine.getMachineName() << " ,Weight: " << machine.weight << endl;

    return os;
}

ostream& operator<<(ostream& os, const ExerciseMachine::eName eMachine)
{
    os <<  ExerciseMachine::machinesName[eMachine];
    return os;
}