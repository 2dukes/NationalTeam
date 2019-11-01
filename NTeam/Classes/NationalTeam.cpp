//
// Created by Rui Pinto on 10/11/2019.
//

#include "NationalTeam.h"
#include "TechnicalTeam.h"
#include "../NecessaryFunctions_NameSpaces.h"
#include <iostream>
#include <new>
#include <limits>

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/* Gets */

string NationalTeam::getName() const
{
    return name;
}

/* Sets */

string NationalTeam::setName(string &name)
{
    this->name = name;
    return name;
}

/* Other Methods */

bool NationalTeam::createOtherWorker()
{
    string auxName = readOperations::readString("Name:");

    Date birth = readOperations::readDate();

    string auxRole = readOperations::readString("Role:");

    float auxSalary = 0.0;
    auxSalary = readOperations::readNumber("Salary:", auxSalary);

    unsigned int id;
    if(otherWorkers.size() > 0)
        id = otherWorkers.at(otherWorkers.size() - 1)->getId() + 1; // We suppose all Ids are incremented by 1
    else
        id = 1;

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    Staff *oW = new OtherWorker(id, auxRole, auxName, birth, auxSalary);
    oW->info(cout);
    string answer = readOperations::confirmAnswer();

    if(answer == "Y" || answer == "y")
    {
        addOtherWorker(oW);
        cout << "Data successfully inserted!" << endl;
        return true;
        /* In the future to save all info inside a file */
        //  ofstream out_stream("../Files/OtherWorkers.txt", ios::app);
        //  oW.info(out_stream);
    }
    cout << "Data not inserted." << endl;
    delete oW;
    return false;

    // NATIONALTEAM DESTRUCTOR SHOULD DESTRUCT ALL VECTORS BECAUSE THEY'RE ALLOCATED DYNAMICALLY
}

bool NationalTeam::readOtherWorkersFile(string filename) {
    ifstream f;
    f.open(filename);
    unsigned int id;
    string name, aux;
    char delim = ' ';
    Date birthday;
    string function;
    float salary;
    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, name);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> birthday;
            getline(f, aux, delim);
            getline(f, function);
            getline(f, aux, delim);
            f >> salary;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux); // blank line

            Staff* oW = new OtherWorker(id, function, name, birthday, salary);
            addOtherWorker(oW);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::deleteOtherWorker() {
    Staff *oW = workerLookUp(otherWorkers);
    if(oW == NULL)
        return false;
    for (auto it = otherWorkers.begin(); it != otherWorkers.end(); it++) {
        if (*(*it) == *oW) {
            otherWorkers.erase(it);
            cout << endl << "Other Worker successfully removed!" << endl << endl;
            return true;
        }
    }
    return false;
}

bool NationalTeam::alterOtherWorker()
{
    string reader;
    bool flag = true, toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    Staff *person = workerLookUp(otherWorkers);
    if(person == NULL)
        return false;

    while (toggle)
    {
        if (repetition == 0)
        {
            cout << endl << "What do you want to change?\n";
            repetition++;
        }
        else
            cout << "Do you want to change anything else?\n";

        cout << "1. Name\n2. Role\n3. Birth Date\n4. Salary\n0. Back\n\n";
        cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (option)
        {
            case 0:
            {
                toggle = false;
                break;
            }
            case 1:
            {
                string auxName = readOperations::readString("New Name:");
                person->setName(auxName);
                break;
            }
            case 2:
            {
                string auxRole = readOperations::readString("New Role:");
                person->setRole(auxRole);
                break;
            }
            case 3:
            {
                Date birth = readOperations::readDate();
                person->setDate(birth);
                break;
            }
            case 4:
            {
                float auxSalary = 0.0;
                auxSalary = readOperations::readNumber("New Salary:", auxSalary);
                person->setSalary(auxSalary);
                break;
            }
        }
        if (toggle)
        {
            cout << endl << "Worker successfully altered!" << endl;
            // OtherWorkerInfoHasChanged = true;
        }
    }
    return true;
}

void NationalTeam::addOtherWorker(Staff *oW)
{
    otherWorkers.push_back(oW);
}

vector<Staff*>& NationalTeam::getOtherWorkers()
{
    return otherWorkers;
}

void NationalTeam::displayOtherWorkers() const {
    std::cout << std::endl;
    for(auto &x: otherWorkers)
        x->info(std::cout);
}

bool NationalTeam::readSoccerPlayersFile(string filename) {
    ifstream f;
    f.open(filename);
    unsigned int id, daysActive;
    string name, position, club, isInjuredString, aux;
    char delim = ' ';
    Date birthday;
    float salary, weight, height;
    bool isInjured;
    unsigned long marketPrice, ensurance;
    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, name);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> birthday;
            getline(f, aux, delim);
            getline(f, position);
            getline(f, aux, delim);
            getline(f, club);
            getline(f, aux, delim);
            f >> weight;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> height;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> marketPrice;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> salary;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> daysActive;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, isInjuredString);
            if (isInjuredString == "true")
                isInjured = true;
            else if (isInjuredString == "false")
                isInjured = false;
            else {
                cerr << "Error reading the file " << filename << endl;
                return false;
            }
            getline(f, aux, delim);
            f >> ensurance;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux); // THIS IS THE CALL INFORMATION, WE NEED TO TREAT THIS CASE!!
            getline(f, aux, delim); // blank line

            //SoccerPlayer* sP = new SoccerPlayer(id, name, position, birthday, salary,
                    //position, club, weight, height, marketPrice, daysActive, isInjured);
            //addOtherSoccerPlayer(sP);



        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }

}

void NationalTeam::addOtherSoccerPlayer(SoccerPlayer *sP) {
    players.push_back(sP);
}
