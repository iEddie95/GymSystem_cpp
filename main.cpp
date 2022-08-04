#include <iostream>
#include "Gym.h"

using namespace std;

constexpr int NUM_OF_OPTIONS = 9;
constexpr int EXIT = 10;
constexpr int BUFFER_SIZE = 256;

const char* options[NUM_OF_OPTIONS] = {"Change max number of trainees in a gym", "Add a trainee",
                                       "Add an instructor", "Add an exercise machine", "Show all trainees",
                                       "Show license validation",
                                       "Show all exercise machines", "Show gym info", "Fire instructor"};


void addTrainee(Gym& gym);

bool addInstructor(Gym& gym);

Gym initGym();
void addExerciseMachine(Gym& gym);
void printMachineTypes();
int pickFavMachine(Gym& gym);
void cleanBuffer();

int menu();

int main()
{
    int option;
    int stop = 0;

/*    HARD CODED GYM
 * MinistryOfHealthLicense mLicense(3, true);
    FireDepartmentLicense fLicense(5, true);
    GymLicense license(mLicense, fLicense);
    Gym gym = Gym(5678, "ICON", "Hod HaSharon", 5, 5, license);
    */

    Gym gym = initGym();


    do {
        option = menu();
        switch (option) {
            case 1:
                int num;
                cout << "Enter new max num" << endl;
                cin >> num;
                if (!gym.resizeMaxTrainees(num))
                    cout << "cannot resize number of trainess" << endl;
                break;

            case 2:
                try{
                    addTrainee(gym);
                }
                catch(std::invalid_argument& e){
                    cout << "Invalid_argument: " << e.what() << endl;
                }
                break;

            case 3: {
                try{
                    addInstructor(gym);
                }
                catch(std::invalid_argument& e) {
                    cout << "Invalid_argument: " << e.what() << endl;
                }
                break;
            }
            case 4:
                try{
                    addExerciseMachine(gym);
                }
                catch(std::invalid_argument& e)
                {
                    cout << "Invalid_argument: " << e.what() << endl;
                }
                break;

            case 5:
                gym.showTrainees();
                break;

            case 6:
                if (gym.getLicense().getIsValid())
                    cout << "License is valid" << endl;
                else
                    cout << "License is invalid" << endl;
                break;

            case 7:
                gym.showMachines();
                break;

            case 8:
                cout << gym << endl;
                break;

            case 9:
                if (gym.getInstructor())
                    gym.setInstructor(nullptr);
                else
                    cout << "no instructor set" << endl;
                    break;
            case 10:
                cout << "Bye bye" << endl;
                stop = 1;
                break;

            default:
                cout << "Wrong option" << endl;
                break;
        }
    } while (!stop);

    return 0;
}


int menu()
{
    int option;
    cout << "" << endl;
    cout << "Please choose one of the following options :" << endl;

    for (int i = 0; i < NUM_OF_OPTIONS; i++)
        cout << i + 1 << " - " << options[i] << endl;

    cout << EXIT << " - Quit" << endl;
    cin >> option;

    return option;
}

Gym initGym() noexcept(false)
{
    char name[BUFFER_SIZE], address[BUFFER_SIZE];
    int id, maxMachines, maxTrainees, numOfDefibrillators, numOfEmergencySigns;
    bool isSignsVisible, isDefibrillatorsVisible;
    int valid;
    cout << "CREATING GYM" << endl;
    cout << "Enter gym ID: ";
    cin >> id;
    cleanBuffer();
    cout << "Enter gym name: ";
    cin.getline(name,BUFFER_SIZE);
    cout << "Enter gym address: ";
    cin.getline(address,BUFFER_SIZE);
    cout << "Enter max trainees: ";
    cin >> maxTrainees;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    cout << "Enter max machines: ";
    cin >> maxMachines;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    cout << "Enter num of Defibrillators: ";
    cin >> numOfDefibrillators;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    cout << "Is the Defibrillators visible[0-false, 1-true]? ";
    cin >> valid;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    isDefibrillatorsVisible = true ? valid = 1 : false;
    cout << "Enter num of Emergency Signs: ";
    cin >> numOfEmergencySigns;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    cout << "Is the Emergency Signs visible[0-false, 1-true]? ";
    cin >> valid;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    isSignsVisible =  true ? valid = 1 : false;

    FireDepartmentLicense fLicense(numOfEmergencySigns, isSignsVisible);
    MinistryOfHealthLicense mLicense(numOfDefibrillators, isDefibrillatorsVisible);

    GymLicense license(mLicense, fLicense);
    Gym gym(id, name, address, maxMachines, maxTrainees, license);
    // gym must have at least 1 exercise machine when created
    addExerciseMachine(gym);
    return gym;
}

void addTrainee(Gym& gym) noexcept(false)
{
    char name[BUFFER_SIZE];
    char lastName[BUFFER_SIZE];
    int phoneNumber, favMachine;
    Date dateOfBirth;

    cout << "ADDING NEW TRAINEE TO THE GYM" << endl;
    cout << "Enter Trainee's first name: ";
    cin >> name;
    if (strcmp(name, "")==0)
        throw std::invalid_argument("Name cannot be empty");

    cout << "Enter Trainee's last name: ";
    cin >> lastName;
    if (strcmp(lastName, "")==0)
        throw std::invalid_argument("Name cannot be empty");

    cout << "Enter Birth Date dd mm yyyy: ";
    cin >> dateOfBirth;
    if (cin.fail())
        throw std::invalid_argument("Invalid date input");

    cout << "Enter Trainee's phone number: ";
    cin >> phoneNumber;
    if (cin.fail()){
        cin.clear();
        cin.ignore(BUFFER_SIZE,'\n');
        throw std::invalid_argument("Invalid phoneNumber input");
    }
    cout << endl;
    cout << "Pick your favourite machine" << endl;
    favMachine = pickFavMachine(gym);

    gym.addTrainee(name, lastName, phoneNumber, dateOfBirth, favMachine);
}

bool addInstructor(Gym& gym) noexcept(false)
{
    if (gym.getInstructor())
        return false;

    char name[BUFFER_SIZE], lastName[BUFFER_SIZE];
    int phoneNumber, numOfExperience, favMachine;
    Date dateOfBirth;
    double salary;

    cout << "ADDING NEW Instructor TO THE GYM" << endl;
    cout << "Enter Instructor's first name: ";
    cin >> name;
    if (strcmp(name, "")==0)
        throw std::invalid_argument("Name cannot be empty");
    cout << "Enter Instructor's last name: ";
    cin >> lastName;
    if (strcmp(name, "")==0)
        throw std::invalid_argument("Last name cannot be empty");

    cout << "Enter Birth Date dd mm yyyy: ";
    cin >> dateOfBirth;
    if (cin.fail())
        throw std::invalid_argument("Invalid date input");
    cout << "Enter Instructor's phone number: ";
    cin >> phoneNumber;
    if (cin.fail()){
        cleanBuffer();
        throw std::invalid_argument("Invalid phoneNumber input");
    }

    cout << "Pick your favourite machine" << endl;
    favMachine = pickFavMachine(gym);

    cout << "Enter Instructor salary: ";
    cin >> salary;
    cout << "Enter Instructor years of experience: ";
    cin >> numOfExperience;
    cout << endl;

    return gym.setInstructor(Person(name, lastName, phoneNumber, dateOfBirth), salary, favMachine, numOfExperience);

}

void addExerciseMachine(Gym& gym) noexcept(false)
{
    int type, numOfDates;
    double weight;
    Date* maintenancesDates;
    cout << "ADDING NEW EXERCISE MACHINE TO THE GYM" << endl;
    cout << "Pick exercise machine type: " << endl;
    printMachineTypes();
    cin >> type;
    if (cin.fail())
        throw std::invalid_argument("Invalid type input");
    cout << "Enter machine weight: ";
    cin >> weight;
    if (cin.fail())
        throw std::invalid_argument("Invalid weight input");
    cout << "Enter number of maintenances dates: ";
    cin >> numOfDates;
    if (cin.fail())
        throw std::invalid_argument("Invalid int input");
    maintenancesDates = new Date[numOfDates];

    for (int i = 0; i < numOfDates; ++i)
    {
        cout << "Enter date dd mm yyyy: ";
        cin >> maintenancesDates[i];
        if (cin.fail())
            throw std::invalid_argument("Invalid date input");
    }

    gym.addMachine(type, weight, numOfDates, maintenancesDates);
}

void printMachineTypes()
{
    cout << "0: Bicycle\n1: Rowing machine\n2: Leg press\n3: Lat pull down\n4: Chest press\n";
}

int pickFavMachine(Gym& gym)
{
    int select;
    printMachineTypes();
    cout << "\n";
    cout << "Your choice: ";
    cleanBuffer();
    cin >> select;

    return select;;
}

void cleanBuffer()
{
    cin.clear();
    cin.ignore(BUFFER_SIZE,'\n');
}

