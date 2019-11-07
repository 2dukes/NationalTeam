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
#include "IndividualStatistics.h"
#include "../NecessaryFunctions_NameSpaces.h"
#include "Exceptions.h"

class NationalTeam {
public:
    NationalTeam() { };

    /* Gets */
    std::string getName() const;
    std::vector<OtherWorker*>& getOtherWorkers(); // Inserted...

    /* Sets */
    std::string setName(std::string &name); /* Returns string because of menu's 1st option */

    /* OtherWorkers Methods */
    unsigned int OtherWorkersgetLastID();
    bool createOtherWorker();
    bool alterOtherWorker();
    void addOtherWorker(OtherWorker* oW);
    bool deleteOtherWorker();
    bool readOtherWorkersFile(std::string filename);

    /* Other Methods */
    void displayOtherWorkers() const;
    void displaySoccerPlayers() const;

    template <class Type>
    Type workerLookUp(std::vector<Type> &workers); // Type varies as: OtherWorker*, TechnicalTeam*, SoccerPlayer*...
    template <class Type>
    Type& getByID(std::vector<Type> &elements, int id);
    template <class Type>
    unsigned int getLastID(std::vector<Type> & elements);
    // According to the Internet, it should be defined on the .h

    /* SoccerPlayer Methods */
    bool createSoccerPlayer();
    bool alterSoccerPlayer();
    void addSoccerPlayer(SoccerPlayer* sP);
    bool deleteSoccerPlayer();
    bool readSoccerPlayersFile(std::string filename);

    /* Game Methods */
    void addGame(Game* game);
    bool readGamesFile(std::string filename);

    /* Call Methods */
    bool createCall();

    /* GameStats Methods */
    void addGameStatistics(GameStats* gStats);
    bool readGameStatisticsFile(std::string filename);

    /* IndividualStatistics Methods */
    void addIndividualStatistic(IndividualStatistics* iStat);
    bool readIndividualStatisticsFile(std::string filename);


private:
    std::vector<OtherWorker*> otherWorkers; // OtherWorkers
    std::vector<TechnicalTeam*> technicalTeam;
    std::vector<SoccerPlayer*> players;
    std::vector<InfCall*> InfCalls;
    std::vector<Call*> calls;
    std::vector<Game*> games;
    std::vector<GameStats*> gameStats;
    std::vector<IndividualStatistics*> individualStats;
    std::string name;
};

template<class Type>
unsigned int NationalTeam::getLastID(std::vector<Type> &elements)
{
    if(elements.size() > 0)
        return elements.at(elements.size() - 1)->getId() + 1; // We suppose all Ids are incremented by 1
    else
        return 1;
}

template<class Type>
Type& NationalTeam::getByID(std::vector<Type> &elements, int id)
{
    if(id < 1)
        throw NoPersonFound("ID Not Valid..."); // IDs smaller than 1 are not allowed
    else
    {
        for (auto &x: elements) {
            if (x->getId() == id)
                return x;
        }
    }
    throw NoPersonFound("No Corresponding Person Found...");
}

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
        std::cout << "Look for a \'Person\' using: " << std::endl; std::cout << "1. Name\n2. Birth Date\n3. Salary\n4. ID\n0. Back\n\n";
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
                        std::cout << std::endl;
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
                        return getByID(auxPerson, option);
                    }
                    catch (NoPersonFound &e) {
                        std::cout << e.getError() << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Person Found..." << std::endl << std::endl;
                break;
            }
            case 2:
            {
                // Birth Date
                Date dBirth = readOperations::readDate();

                for(auto &x: workers)
                {
                    if(x->getDate() == dBirth)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        std::cout << std::endl;
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
                        return getByID(auxPerson, option);
                    }
                    catch (NoPersonFound &e) {
                        std::cout << e.getError() << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Person Found..." << std::endl << std::endl;
                break;

            }
            case 3:
            {
                // Salary
                float salary = readOperations::readNumber<float>("Salary:");

                for(auto &x: workers)
                {
                    if(x->getSalary() == salary)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                        std::cout << std::endl;
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
                        return getByID(auxPerson, option);
                    }
                    catch (NoPersonFound &e) {
                        std::cout << e.getError() << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Person Found..." << std::endl << std::endl;
                break;
            }
            case 4:
            {
                // ID
                int id = readOperations::readNumber<int>("ID: ");

                try {
                    return getByID(workers, id);
                }
                catch (NoPersonFound &e) {
                    std::cout << e.getError() << std::endl;
                }

                break;
            }
        }
    }
}

#endif //NTEAM_NATIONALTEAM_H
