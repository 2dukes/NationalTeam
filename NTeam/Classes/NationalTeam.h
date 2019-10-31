//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_NATIONALTEAM_H
#define NTEAM_NATIONALTEAM_H

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include "SoccerPlayer.h"
#include "OtherWorker.h"
#include "TechnicalTeam.h"
#include "Call.h"
#include "Game.h"
#include "../NecessaryFunctions_NameSpaces.h"

class NationalTeam {
public:
    NationalTeam() { };

    /* Gets */
    std::string getName() const;
    std::vector<Staff*>& getOtherWorkers(); // Inserted...

    /* Sets */
    std::string setName(std::string &name); /* Returns string because of menu's 1st option */

    /* OtherWorkers Methods */
    bool createOtherWorker();
    bool alterOtherWorker();
    void addOtherWorker(Staff* oW);
    bool deleteOtherWorker();
    bool readOtherWorkersFile(std::string filename);

    /* Other Methods */
    void displayOtherWorkers() const;

    template<class Type>
    Type workerLookUp(std::vector<Type> &workers); // Type varies as: OtherWorker*, TechnicalTeam*, SoccerPlayer*...
    // According to the Internet, it should be defined on the .h
private:
    std::vector<Staff*> otherWorkers; // OtherWorkers
    std::vector<TechnicalTeam*> technicalTeam;
    std::vector<SoccerPlayer*> players;
    std::vector<InfCall*> InfCalls;
    std::vector<Call*> calls;
    std::vector<Game*> games;
    std::string name;
};

template<class Type>
Type NationalTeam::workerLookUp(std::vector<Type> &workers)
{

    bool ct;
    std::string reader;
    int option;
    std::vector<Type> auxPerson;
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
                std::string name = readOperations::readString("Name:");
                std::transform(name.begin(), name.end(), name.begin(), toupper); // Convert to uppercase

                std::string workerName;

                for(auto &x: workers)
                {
                    workerName = x->getName();
                    std::transform(workerName.begin(), workerName.end(), workerName.begin(), toupper); // Convert to uppercase
                    if(workerName.find(name) != std::string::npos)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        x->info(std::cout);
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl;
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
                std::cout << std::endl << "No Corresponding Worker Found..." << std::endl << std::endl;
                break;
            }
            case 2:
            {
                // Role
                std::string role = readOperations::readString("Role:");

                for(auto &x: workers)
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
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl;
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
                std::cout << std::endl << "No Corresponding Worker Found..." << std::endl << std::endl;
                break;
            }
            case 3:
            {
                // Birth Date
                Date dBirth = readOperations::readDate();

                for(auto &x: workers)
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
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl;
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
                std::cout << std::endl << "No Corresponding Worker Found..." << std::endl << std::endl;
                break;

            }
            case 4:
            {
                // Salary
                float salary;
                salary = readOperations::readNumber("Salary:", salary);

                for(auto &x: workers)
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
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl;
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
                std::cout << std::endl << "No Corresponding Worker Found..." << std::endl << std::endl;
                break;
            }
            case 5:
            {
                // ID
                int id;
                id = readOperations::readNumber("ID: ", id);

                for(auto &x: workers)
                {
                    if(x->getId() == id)
                        return x;
                }

                std::cout << std::endl << "No Corresponding Worker Found..." << std::endl << std::endl;
                break;
            }
        }
    }
}

#endif //NTEAM_NATIONALTEAM_H
