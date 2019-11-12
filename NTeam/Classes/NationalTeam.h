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
    NationalTeam(std::string n):name(n) { };

    /* Gets */
    std::string getName() const;
    std::vector<OtherWorker*>& getOtherWorkers(); // Inserted...

    /* Sets */
    std::string setName(std::string &name); /* Returns string because of menu's 1st option */

    /* OtherWorkers Methods */
    bool createOtherWorker();
    bool alterOtherWorker();
    void addOtherWorker(OtherWorker* oW);
    bool deleteOtherWorker();
    bool readOtherWorkersFile(std::string filename);
    bool writeOtherWorkersFile(std::string filename);

    /* Other Methods */
    void displayOtherWorkers() const;
    void displaySoccerPlayers() const;
    void displayGames() const;
    void displayTechnicalTeamMembers() const;
    void displayCallsPlayers() const;
    void displayCallsGames() const;

    /* Other Methods (templates) */
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
    bool writeSoccerPlayersFile(std::string filename);

    /* Game Methods */
    Game* createGame(std::vector<SoccerPlayer*> soccerPlayers, Date begin, Date end);
    void addGame(Game* game);
    bool alterGameGlobal(Game* game);
    bool alterGameGlobalOpposite(Game* game);
    bool alterPlayerStats(std::vector<IndividualStatistics*> stats, unsigned int playerID);
    bool readGamesFile(std::string filename);
    bool writeGamesFile(std::string filename);

    /* Call Methods */
    bool createCall();
    void addCall(Call* call);
    bool readCallsFile(std::string filename);
    bool alterCall();
    bool removeCall();
    bool writeCallsFile(std::string filename);
    Call* callLookUp();

    /* GameStats Methods */
    GameStats* createGameStatistics(unsigned int gameID);
    void addGameStatistics(GameStats* gStats);
    bool readGameStatisticsFile(std::string filename);
    bool writeGamesStatisticsFile(std::string filename);

    /* IndividualStatistics Methods */
    IndividualStatistics* createIndividualStatistics(unsigned int playerID);
    void addIndividualStatistic(IndividualStatistics* iStat);
    bool readIndividualStatisticsFile(std::string filename);
    bool writeIndividualStatisticsFile(std::string filename);

    /* InfCalls */
    bool readInfCalls(std::string filename);
    InfCall* createInfCalls(unsigned int sPId);
    void addInfCall(InfCall* inf);
    bool writeInfCallsFile(std::string filename);

    /* TechnicalTeam Methods */
    void addTechnicalTeamMember(TechnicalTeam* tTeam);
    bool readTechnicalTeamFile(std::string filename);
    bool createTechnicalTeamMember();
    bool alterTechnicalTeamMember();
    bool deleteTechnicalTeamMember();
    bool writeTechnicalTeamFile(std::string filename);

    /* Features */
    std::vector<Call*> playerCalls(SoccerPlayer* sP); // Calls em que o jogador participou
    void playerCallsForMenu();
    std::vector<Game*> playerGames(SoccerPlayer* sP, Call* call); // Jogos em que o jogador participou numa determinada call
    void playerGamesForMenu();
    void topScorer();
    void showNumberOfVictoriesDrawsLoses();

    /* Costs */
    void getPlayerTotalCost();
    unsigned int getTeamTotalCost();
    void getNationalTeamTotalCost();
    void getMonthlyPlayerTotalCost();
    void getMonthlyTeamTotalCost();
    void getMonthlyNationalTeamTotalCost();

    void showCallStats();
    void showGlobalStats();

    void showPlayerGlobalStats();
    void showPlayerCallStats();

    ~NationalTeam();

    template<class Type>
    void auxiliaryDestructor(std::vector<Type> &elements);

private:
    std::vector<OtherWorker*> otherWorkers; // OtherWorkers
    std::vector<TechnicalTeam*> technicalTeam;
    std::vector<SoccerPlayer*> players;
    std::vector<InfCall*> infCalls;
    std::vector<Call*> calls;
    std::vector<Game*> games;
    std::vector<GameStats*> gameStats;
    std::vector<IndividualStatistics*> individualStats;
    std::string name;
};

template<class Type>
void NationalTeam::auxiliaryDestructor(std::vector<Type> &elements)
{
    for(auto &x: elements)
        delete x;
}

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
        throw NoObjectFound("ID Not Valid..."); // IDs smaller than 1 are not allowed
    else
    {
        for (auto &x: elements) {
            if (x->getId() == id)
                return x;
        }
    }
    throw NoObjectFound("No Corresponding Person Found...");
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
        std::cout << std::endl << "Look for a \'Person\' using: " << std::endl; std::cout << "1. Name\n2. Birth Date\n3. Salary\n4. ID\n0. Back\n\n";
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
                    }
                }
                if(!auxPerson.empty())
                {
                    auxPerson.at(0)->header(); // Print corresponding header
                    for(auto &x: auxPerson)
                    {
                        x->info();
                        std::cout << std::endl;
                    }
                }


                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return getByID(auxPerson, option);
                    }
                    catch (NoObjectFound &e) {
                        std::cout << std::endl << e.getError() << std::endl << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Person Found..." << std::endl << std::endl;
                break;
            }
            case 2:
            {
                // Birth Date
                Date dBirth1, dBirth2;
                do
                {
                    dBirth1 = readOperations::readDate("Smaller birth Date (DD/MM/YYYY):");
                    dBirth2 = readOperations::readDate("Bigger birth Date (DD/MM/YYYY):");
                    if(dBirth2 <= dBirth1)
                        std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl << std::endl;
                    else
                        break;
                } while(!(dBirth1 <= dBirth2));


                for(auto &x: workers)
                {
                    if(generalFunctions::checkBetweenDates(dBirth1, x->getDate(), dBirth2))
                    {
                        auxPerson.push_back(x);
                        ct = true;
                    }
                }

                if(!auxPerson.empty())
                {
                    auxPerson.at(0)->header(); // Print corresponding header
                    for(auto &x: auxPerson)
                    {
                        x->info();
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return getByID(auxPerson, option);
                    }
                    catch (NoObjectFound &e) {
                        std::cout << std::endl << e.getError() << std::endl << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Person Found..." << std::endl << std::endl;
                break;

            }
            case 3:
            {
                // Salary
                float smallerSalary, biggerSalary;
                do
                {
                    smallerSalary = readOperations::readNumber<float>("Smaller Salary:");
                    biggerSalary = readOperations::readNumber<float>("Bigger Salary:");
                    if(smallerSalary > biggerSalary)
                        std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl << std::endl;
                } while(smallerSalary > biggerSalary);


                for(auto &x: workers)
                {
                    if(x->getSalary() >= smallerSalary && x->getSalary() <= biggerSalary)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                    }
                }

                if(!auxPerson.empty())
                {
                    auxPerson.at(0)->header(); // Print corresponding header
                    for(auto &x: auxPerson)
                    {
                        x->info();
                        std::cout << std::endl;
                    }
                }

                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return getByID(auxPerson, option);
                    }
                    catch (NoObjectFound &e) {
                        std::cout << std::endl << e.getError() << std::endl << std::endl;
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
                catch (NoObjectFound &e) {
                    std::cout << std::endl << e.getError() << std::endl << std::endl;
                }

                break;
            }
        }
    }
}

#endif //NTEAM_NATIONALTEAM_H
