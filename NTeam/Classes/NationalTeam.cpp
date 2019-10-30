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

string NationalTeam::setName(string name)
{
    this->name = name;
    return name;
}

/* Other Methods */

Staff* NationalTeam::WorkerLookUp()
{

    bool ct;
    std::string reader;
    int option;
    std::vector<Staff*> auxPerson;
    while(true)
    {
        auxPerson.clear();
        ct = false;
        std::cout << "Look for a \'Worker\' using: " << std::endl; std::cout << "1. Name\n2. Role\n3. Birth Date\n4. Salary\n5. ID\n0. Back\n\n";
        std::cin >> option; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cout << std::endl;
        switch(option)
        {
            case 0:
                return NULL;
            case 1:
            {
                // Name
                std::string name;

                do
                {
                    std::cout << "Name:";
                    getline(std::cin, name);
                } while(verifyInputs::verifyString(name));

                for(auto &x: otherWorkers)
                {
                    if((x->getName()).find(name) != std::string::npos)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        x->info(std::cout);
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One: " << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for(auto &x: auxPerson)
                        {
                            if(x->getId() == option)
                                return x;
                        }
                    }
                    catch (...) {

                    }
                }
                std::cout << "No Corresponding Worker Found..." << std::endl;
                break;
            }
            case 2:
            {
                // Role
                std::string role;
                do
                {
                    std::cout << "Role:";
                    getline(std::cin, role);
                } while(verifyInputs::verifyString(role));

                for(auto &x: otherWorkers)
                {
                    if(x->getRole() == role)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        x->info(std::cout);
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One: " << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for(auto &x: auxPerson)
                        {
                            if(x->getId() == option)
                                return x;
                        }
                    }
                    catch (...) {

                    }
                }
                std::cout << "No Corresponding Worker Found..." << std::endl;
                break;
            }
            case 3:
            {
                // Birth Date
                std::string birth;
                do
                {
                    std::cout << "Birth Date (YYYY/MM/DD):";
                    getline(std::cin, birth);

                } while(verifyInputs::verifyDate(birth));
                Date dBirth = Date(birth);

                for(auto &x: otherWorkers)
                {
                    if(x->getDate() == dBirth)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        x->info(std::cout);
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One: " << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for(auto &x: auxPerson)
                        {
                            if(x->getId() == option)
                                return x;
                        }
                    }
                    catch (...) {

                    }
                }
                std::cout << "No Corresponding Worker Found..." << std::endl;
                break;

            }
            case 4:
            {
                // Salary
                float salary;
                do {
                    std::cout << "Salary:";
                    std::cin >> salary;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while(verifyInputs::verifyNumber());

                for(auto &x: otherWorkers)
                {
                    if(x->getSalary() == salary)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        x->info(std::cout);
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One: " << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for(auto &x: auxPerson)
                        {
                            if(x->getId() == option)
                                return x;
                        }
                    }
                    catch (...) {

                    }
                }
                std::cout << "No Corresponding Worker Found..." << std::endl;
                break;
            }
            case 5:
            {
                // Salary
                int id;
                do {
                    std::cout << "ID:";
                    std::cin >> id;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while(verifyInputs::verifyNumber());

                for(auto &x: otherWorkers)
                {
                    if(x->getId() == id)
                        return x;
                }

                std::cout << "No Corresponding Worker Found..." << std::endl;
                break;
            }
        }
    }
}

bool NationalTeam::CreateOtherWorker()
{
    string auxName;
    do
    {
        cout << "Name:";
        getline(cin, auxName);
    } while(verifyInputs::verifyString(auxName));


    string auxBirth;
    do
    {
        cout << "Birth Date (YYYY/MM/DD):";
        getline(cin, auxBirth);

    } while(verifyInputs::verifyDate(auxBirth));
    Date birth = Date(auxBirth);

    string auxRole;
    do
    {
        cout << "Role:";
        getline(cin, auxRole);
    } while(verifyInputs::verifyString(auxRole));

    float auxSalary;
    do {
        cout << "Salary:";
        cin >> auxSalary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(verifyInputs::verifyNumber());

    unsigned int id;
    if(otherWorkers.size() > 0)
        id = otherWorkers.at(otherWorkers.size() - 1)->getId() + 1; // We suppose all Ids are incremented by 1
    else
        id = 1;

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    Staff *oW = new OtherWorker(id, auxRole, auxName, birth, auxSalary);
    oW->info(cout);
    string answer;
    do
    {
        getline(cin, answer);
    } while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");

    if(answer == "Y" || answer == "y")
    {
        addWorker(oW);
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
    unsigned long salary;
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
            getline(f, aux); // linha em branco

            Staff* staff = new OtherWorker(id, function, name, birthday, salary);
            addWorker(staff);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::deleteWorker() {
    Staff *oW = WorkerLookUp();
    for (auto it = otherWorkers.begin(); it != otherWorkers.end(); it++) {
        if ((*it)->getId() == oW->getId()) {
            otherWorkers.erase(it);
            return true;
        }
    }
    return false;
}


bool NationalTeam::AlterOtherWorker()
{
    string reader;
    bool flag = true, toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    Staff *person = WorkerLookUp();
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
                string auxName;
                do
                {
                    cout << "New Name:";
                    getline(cin, auxName);
                } while(verifyInputs::verifyString(auxName));

                person->setName(auxName);
                break;
            }
            case 2:
            {
                string auxRole;
                do
                {
                    cout << "New Role:";
                    getline(cin, auxRole);
                } while(verifyInputs::verifyString(auxRole));

                person->setRole(auxRole);
                break;
            }
            case 3:
            {
                string auxBirth;
                do
                {
                    cout << "Birth Date (YYYY/MM/DD):";
                    getline(cin, auxBirth);

                } while(verifyInputs::verifyDate(auxBirth));
                Date birth = Date(auxBirth);

                person->setDate(birth);
                break;
            }
            case 4:
            {
                float auxSalary;
                do {
                    cout << "Salary:";
                    cin >> auxSalary;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while(verifyInputs::verifyNumber());

                person->setSalary(auxSalary);
                break;
            }
        }
        if (toggle)
        {
            cout << endl << "Worker successfully altered!" << endl << endl << "Press Enter to Continue...";
            cin.get();
            // OtherWorkerInfoHasChanged = true;
        }
    }
    return true;
}

void NationalTeam::addWorker(Staff *oW)
{
    otherWorkers.push_back(oW);
}

const vector<Staff*>& NationalTeam::getWorkers()
{
    return otherWorkers;
}

