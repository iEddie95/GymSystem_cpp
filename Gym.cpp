#include "Gym.h"


Gym::Gym(int id, char* name, char* address, int maxMachines, int maxTrainees, GymLicense& license) : license(license)
{
    this->id = id;
    setName(name);
    setAddress(address);
    setMaxMachineNum(maxMachines);
    setMaxTraineeNum(maxTrainees);

    this->currentTraineesNum = 0;
    this->currentMachinesNum = 0;

    this->allTrainees = new Trainee*[maxTrainees];
    this->allMachines = new ExerciseMachine*[maxMachines];
    this->instructor = nullptr;
}

Gym::Gym(Gym&& otherGym) : license(otherGym.license)
{
    *this = std::move(otherGym);
}

Gym::~Gym()
{
    for (int i = 0; i < currentTraineesNum; ++i)
        delete allTrainees[i];

    for (int i = 0; i < currentMachinesNum; ++i)
        delete allMachines[i];

    delete []this->allMachines;
    delete []this->allTrainees;
    delete []name;
    delete []address;
    delete instructor;
}

const Gym& Gym::operator=(Gym&& other)
{
    if (this != &other)
    {
        this->id = other.id;
        swap(name, other.name);
        swap(address, other.address);
        setMaxTraineeNum(other.maxTraineesNum);
        setMaxMachineNum(other.maxMachinesNum);
        this->currentTraineesNum = other.currentTraineesNum;
        this->currentMachinesNum = other.currentMachinesNum;
        swap(allMachines, other.allMachines);
        swap(allTrainees, other.allTrainees);
        swap(instructor, other.instructor);
    }
    return *this;
}

GymLicense Gym::getLicense() const
{
	return license;
}

int Gym::getId() const
{
	return id;
}

char* Gym::getName() const
{
	return name;
}

bool Gym::setName(const char* name)
{
    this->name = strdup(name);
	return true;
}

char* Gym::getAddress() const
{
	return address;
}

bool Gym::setAddress(const char* address)
{
    this->address = strdup(address);
	return true;
}

int Gym::getCurrentMachineNum() const
{
	return currentMachinesNum;
}

int Gym::getMaxMachineNum() const
{
	return maxMachinesNum;
}

bool Gym::setMaxMachineNum(const int machineNum)
{
    this->maxMachinesNum = machineNum;
	return true;
}

int Gym::getCurrentTraineesNum() const
{
	return currentTraineesNum;
}

int Gym::getMaxTraineeNum() const
{
	return maxTraineesNum;
}

bool Gym::setMaxTraineeNum(const int traineeNum)
{
    this->maxTraineesNum = traineeNum;
	return true;
}

ExerciseMachine** Gym::getAllMachines() const
{
	return allMachines;
}

Trainee** Gym::getAllTrainees() const
{
	return allTrainees;
}

bool Gym::addTrainee(char* name, char* familyName, int phoneNumber, Date& dateOfBirth, int favoriteMachine)
{
    cout << "working\n";
    this->allTrainees[currentTraineesNum] = new Trainee(name, familyName, phoneNumber, dateOfBirth, favoriteMachine);
    cout << "added\n";
    currentTraineesNum++;
    return true;
}

Instructor* Gym::getInstructor() const
{
	return instructor;
}

bool Gym::setInstructor(const Person& base, double salary, int machine,  int numExpYears)
{
    if (!this->instructor)
    {
        this->instructor = new Instructor(base, salary, machine ,numExpYears);
        cout << "added instructor" << endl;
        return true;
    }
    cout << "exict instructor" << endl;
	return false;
}

bool Gym::setInstructor(Instructor* instructor)
{
    this->instructor = instructor;
    return true;
}


bool Gym::resizeMaxTrainees(int num)
{
    if (num <= maxTraineesNum)
        return false;
    Trainee** newTrainee = new Trainee*[num];
    setMaxTraineeNum(num);
    for (int i = 0; i < currentTraineesNum; ++i)
        newTrainee[i] = allTrainees[i];

    delete[] allTrainees;
    allTrainees = newTrainee;
    return true;
}

bool Gym::addMachine(int type, double weight, int numOfDates, Date* maintenancesDates)
{
    allMachines[currentMachinesNum] = new ExerciseMachine(ExerciseMachine::eName(type), weight, numOfDates, maintenancesDates);
    currentMachinesNum++;
    return true;
}

void Gym::showMachines() const
{
    for (int i = 0; i < this->currentMachinesNum; ++i)
        cout << *(this->allMachines[i]) << endl;
}

void Gym::showTrainees() const
{
    for (int i = 0; i < this->currentTraineesNum; ++i)
        cout << *(this->allTrainees[i]) << endl;
}

ostream& operator<<(ostream& os, const Gym& gym)
{
    os << "GYM DETAILS: Name: " << gym.name << " Address: " << gym.address <<  " ID: " << gym.id << endl;
    return os;
}