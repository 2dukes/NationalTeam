#ifndef NTEAM_NATIONALTEAM_H
#define NTEAM_NATIONALTEAM_H

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "SoccerPlayer.h"
#include "OtherWorker.h"
#include "TechnicalTeam.h"
#include "Call.h"
#include "Game.h"
#include "IndividualStatistics.h"
#include "../NecessaryFunctions_NameSpaces.h"
#include "Exceptions.h"
#include "Coach.h"


#define HASH_TABLE_MAX_SIZE 457  // numero primo

struct StuffHash {
    int operator() (const Staff& staff) const {
        int result = 0;
        for (int i = 0; i < staff.getName().size(); i++)
            result += staff.getName().at(i) * staff.getId() * (i + 3);

        return result % HASH_TABLE_MAX_SIZE;
    }

    bool operator() (const Staff& staff1, const Staff& staff2) const {
        return staff1 == staff2;
    }
};


typedef std::unordered_set<Staff, StuffHash, StuffHash> HashTabStaff;


/**
 * @brief - National Team class. The projects' heartwood. It contains all the information about the other classes
 */
class NationalTeam {
public:
    /**
     * @brief - National Team constructor
     * @param n - National Team name
     */
    NationalTeam(std::string n):name(n), coachList(Coach("", 0, std::list<std::pair<std::string, Interval>>())) { };
    /* Gets */

    /**
     *
     * @return - National Team name
     */
    std::string getName() const;


    /* OtherWorkers Methods */

    /**
     *
     * @return - True upon a successful OtherWorker creation. False otherwise
     */
    bool createOtherWorker();
    /**
     *
     * @return - True upon a successful OtherWorker modification. False otherwise
     */
    bool alterOtherWorker();
    /**
     * @brief - Add a new OtherWorker
     * @param oW - Adds a new OtherWorker to the corresponding vector
     */
    void addOtherWorker(OtherWorker* oW);
    /**
     *
     * @return - True upon a successful OtherWorker removal. False otherwise
     */
    bool deleteOtherWorker();
    /**
     * @brief - Reads Other Workers file
     * @param filename - Path where OtherWorker file is stored
     * @return - True upon a successful read. False otherwise
     */
    bool readOtherWorkersFile(std::string filename);
    /**
     * @brief - Saves info into the Other Workers file
     * @param filename - Path where OtherWorker file is stored
     * @return - True upon a successful save. False otherwise
     */
    bool writeOtherWorkersFile(std::string filename);

    /* Other Methods */

    /**
     * Displays Other Workers
     */
    void displayOtherWorkers() const;
    /**
     * Displays Soccer Players
     */
    void displaySoccerPlayers() const;
    /**
     * Displays Games
     */
    void displayGames() const;
    /**
     * Displays Technical Team members
     */
    void displayTechnicalTeamMembers() const;
    /**
     * Displays players summoned for the respective calls
     */
    void displayCallsPlayers() const;
    /**
     * Displays Games inside of the respective calls
     */
    void displayCallsGames() const;

    /* Other Methods (templates) */

    /**
     * @brief - Template method used to search for a SoccerPlayer, OtherWorker or a TechnicalTeam member.
     * @tparam Type - SoccerPlayer*, OtherWorker* or TechnicalTeam*
     * @param workers - Respective vector.
     * @return - SoccerPlayer, OtherWorker or a TechnicalTeam* that points to the selected 'person'
     */
    template <class Type>
    Type workerLookUp(std::vector<Type> &workers);
    /**
     * @brief - Gets an 'object' according to a given ID.
     * @tparam Type - Every class that has a getId method included.
     * @param elements - Respective vector.
     * @param id - Searching ID.
     * @return - The searched object.
     */
    template <class Type>
    Type& getByID(std::vector<Type> &elements, int id);
    /**
     * @brief - Gets the ID of the last inserted element.
     * @tparam Type - Every class that has a getId method included.
     * @param elements - Respective vector.
     * @return - Last inserted ID.
     */
    template <class Type>
    unsigned int getLastID(std::vector<Type> & elements);

    /* SoccerPlayer Methods */

    /**
     *
     * @return - True upon a successful creation. False otherwise.
     */
    bool createSoccerPlayer();
    /**
     *
     * @return - True upon a successful modification. False otherwise.
     */
    bool alterSoccerPlayer();
    /**
     * @brief - Add a new SoccerPlayer.
     * @param sP - Adds a new SoccerPlayer.
     */
    void addSoccerPlayer(SoccerPlayer* sP);
    /**
     * @brief - Delete a SoccerPlayer.
     * @return - True upon a successful removal. False otherwise.
     */
    bool deleteSoccerPlayer();
    /**
     * @brief - Reads Soccer Players' file.
     * @param filename - Soccer Player file path.
     * @return - True upon a successful read. False otherwise.
     */
    bool readSoccerPlayersFile(std::string filename);
    /**
     * @brief - Saves Soccer Players' file.
     * @param filename - Soccer Player file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeSoccerPlayersFile(std::string filename);

    /* Game Methods */

    /**
     * @brief - Create a Game.
     * @param soccerPlayers - List of Soccer Players.
     * @param begin - Summon begin date.
     * @param end - Summon end date.
     * @return - Pointer to the new created game.
     */
    Game* createGame(std::vector<SoccerPlayer*> soccerPlayers, Date begin, Date end);
    /**
     * @brief - Adds a new game.
     * @param game - Game.
     */
    void addGame(Game* game);
    /**
     * @brief - Modify game global statistics.
     * @param game - Game.
     * @return - True upon a successful modification. False otherwise.
     */
    bool alterGameGlobal(Game* game);
    /**
     * @brief - Modify opposite team global statistics.
     * @param game - game
     * @return - True upon a successful modification. False otherwise.
     */
    bool alterGameGlobalOpposite(Game* game);
    /**
     * @brief - Modify SoccerPlayer individual statistics.
     * @param stats - Individual statistics.
     * @param playerID - SoccerPlayer ID.
     * @return - True upon a successful modification. False otherwise.
     */
    bool alterPlayerStats(std::vector<IndividualStatistics*> stats, unsigned int playerID);
    /**
     * @brief - Read Games Files.
     * @param filename - Games file path.
     * @return - True upon a successful read. False otherwise.
     */
    bool readGamesFile(std::string filename);
    /**
     * @brief - Save Games file.
     * @param filename - Games file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeGamesFile(std::string filename);

    /* Call Methods */

    /**
     *
     * @return - True upon a successful creation. False otherwise.
     */
    bool createCall();
    /**
     * @brief - Add a Summon.
     * @param call - Summon itself.
     */
    void addCall(Call* call);
    /**
     * @brief - Reads Summons' filename
     * @param filename - Summons' file path.
     * @return - True upon a successful read. False otherwise.
     */
    bool readCallsFile(std::string filename);
    /**
     *
     * @return - True upon a successful Modification. False otherwise.
     */
    bool alterCall();
    /**
     *
     * @return - True upon a successful removal. False otherwise.
     */
    bool removeCall();
    /**
     * @brief - Save Summons' file.
     * @param filename - Summons' file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeCallsFile(std::string filename);
    /**
     *
     * @return - Corresponding searched Summon.
     */
    Call* callLookUp();

    /* GameStats Methods */

    /**
     * @brief - Create a Game Statistic.
     * @param gameID - Game ID = Game Statistic ID
     * @return - Pointer to the created Game Statistic.
     */
    GameStats* createGameStatistics(unsigned int gameID);
    /**
     * @brief - Add a Game Statistic.
     * @param gStats - Game Statistic.
     */
    void addGameStatistics(GameStats* gStats);
    /**
     * @brief - Read Game Statistics file.
     * @param filename - Game Statistics file path.
     * @return - True upon a successful read. False otherwise.
     */
    bool readGameStatisticsFile(std::string filename);
    /**
     * @brief - Save Game Statistics file.
     * @param filename - Game Statistics file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeGamesStatisticsFile(std::string filename);

    /* IndividualStatistics Methods */

    /**
     * @brief - Create Soccer Player Individual Statistics.
     * @param playerID - SoccerPlayer ID.
     * @return - Pointer to the created IndividualStatistic.
     */
    IndividualStatistics* createIndividualStatistics(unsigned int playerID);
    /**
     * @brief - Add a Individual Statistic.
     * @param iStat - Individual Statistic itself.
     */
    void addIndividualStatistic(IndividualStatistics* iStat);
    /**
     * @brief - Read Individual Statistics file.
     * @param filename - Individual Statistics file path.
     * @return - True upon a successful read. False otherwise.
     */
    bool readIndividualStatisticsFile(std::string filename);
    /**
     * @brief - Svae Individual Statistics file.
     * @param filename - Individual Statistics file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeIndividualStatisticsFile(std::string filename);

    /* InfCalls */

    /**
     * @brief - Read InfCalls file.
     * @param filename - InfCalls file path.
     * @return - True upon a successful red. False otherwise.
     */
    bool readInfCalls(std::string filename);
    /**
     * @brief - Create InfCall.
     * @param sPId - SoccerPlayer ID.
     * @return - Pointer to the Created InfCall.
     */
    InfCall* createInfCalls(unsigned int sPId);
    /**
     * @brief - Add and InfCall.
     * @param inf - InfCall itself.
     */
    void addInfCall(InfCall* inf);
    /**
     * @brief - Save InfCalls.
     * @param filename - InfCalls file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeInfCallsFile(std::string filename);

    /* TechnicalTeam Methods */

    /**
     * @brief - Add a TechnicalTeam member.
     * @param tTeam - TechnicalTeam member itself.
     */
    void addTechnicalTeamMember(TechnicalTeam* tTeam);
    /**
     * @brief - Read TechnicalTeam file.
     * @param filename - Technical Team file path.
     * @return - True upon a successful read. False otherwise.
     */
    bool readTechnicalTeamFile(std::string filename);
    /**
     *
     * @return - True upon a successful creation. False otherwise.
     */
    bool createTechnicalTeamMember();
    /**
     *
     * @return - True upon a successful modification. False otherwise.
     */
    bool alterTechnicalTeamMember();
    /**
     *
     * @return - True upon a successful removal. False otherwise.
     */
    bool deleteTechnicalTeamMember();
    /**
     * @brief - Save TechnicalTeam file.
     * @param filename - TechnicalTeam file path.
     * @return - True upon a successful save. False otherwise.
     */
    bool writeTechnicalTeamFile(std::string filename);

    /* Features */

    /**
     * @brief - Get Calls in which a player has participated.
     * @param sP - SoccerPlayer pointer.
     * @return - Summons vector.
     */
    std::vector<Call*> playerCalls(SoccerPlayer* sP);
    /**
     * Displays Summons in which a SoccerPlayer participated.
     */
    void playerCallsForMenu();
    /**
     * @brief - Games in a Call in which a give player participated.
     * @param sP - Soccer Player itself.
     * @param call - Call itself.
     * @return - Games vector.
     */
    std::vector<Game*> playerGames(SoccerPlayer* sP, Call* call); // Jogos em que o jogador participou numa determinada call
    /**
     * Displays Games in which a SoccerPlayer participated after selecting a certain Summon.
     */
    void playerGamesForMenu();
    /**
     * Displays the Top Scorer ever.
     */
    void topScorer();
    /**
     * Displays number of victories, draws and Losses.
     */
    void showNumberOfVictoriesDrawsLoses();

    /* Costs */

    /**
     * Get total SoccerPlayer cost.
     */
    void getPlayerTotalCost();
    /**
     *
     * @return - Total team Cost.
     */
    unsigned int getTeamTotalCost();
    /**
     * Get National Team total cost.
     */
    void getNationalTeamTotalCost();
    /**
     * Get SoccerPlayer cost in a given month.
     */
    void getMonthlyPlayerTotalCost();
    /**
     * Get Team cost in a given month.
     */
    void getMonthlyTeamTotalCost();
    /**
     * Get National Team cost in a given month.
     */
    void getMonthlyNationalTeamTotalCost();

    /**
     * Displays calls Statistics.
     */
    void showCallStats();
    /**
     * Displays Global Statistics.
     */
    void showGlobalStats();

    /**
     * Shows SoccerPlayer global Statistics.
     */
    void showPlayerGlobalStats();
    /**
     * Shows Player Summon Statistics.
     */
    void showPlayerCallStats();

    /**
     * National Team destructor. Used to destroy dinamically allocated memory and save the files content.
     */
    ~NationalTeam();

    /**
     * @brief - Destroys dinamically allcoated vectors.
     * @tparam Type - National Team vector types.
     * @param elements - Vectors.
     */
    template<class Type>
    void auxiliaryDestructor(std::vector<Type> &elements);

    // BST:

    void addCoach();

    void alterCoach();

    void deleteCoach();

    bool readCoachesFile(std::string filename);

    void displayCoachesByCupsWon();

    void displayCoachesThatTrainedNTeam();

    bool writeCoachesFile(std::string filename);

    // HASH TABLE:

    void addStaffToHashTable(const Staff &staff);
    void addTechnicalTeamMemberToHashTable(TechnicalTeam member);
    void addOtherWorkerToHashTable(OtherWorker otherWorker);
    void addAllTheStaffToHashTable();
    bool writeStaffHashTableFile(std::string filename);
    bool readStaffHashTableFile(std::string filename);
    std::vector<Staff> getOldStaff() const;
    void displayOldStaff() const;
    Staff searchOldStaff() const;
    void hireOldStaff();





private:
    /**
     * Other Workers' vector.
     */
    std::vector<OtherWorker*> otherWorkers;
    /**
     * Technical Team's vector.
     */
    std::vector<TechnicalTeam*> technicalTeam;
    /**
     * Soccer Players' vector.
     */
    std::vector<SoccerPlayer*> players;
    /**
     * InfCalls' vector.
     */
    std::vector<InfCall*> infCalls;
    /**
     * Summons' vector.
     */
    std::vector<Call*> calls;
    /**
     * Games' vector.
     */
    std::vector<Game*> games;
    /**
     * Game Statistics' vector.
     */
    std::vector<GameStats*> gameStats;
    /**
     * Individual Statistics' vector.
     */
    std::vector<IndividualStatistics*> individualStats;
    /**
     * National Team name.
     */
    std::string name;

    HashTabStaff allTimeStaff;

    BST<Coach> coachList;

};

template<class Type>
void NationalTeam::auxiliaryDestructor(std::vector<Type> &elements)
{
    for(auto &x: elements)
        delete x;
}


// NÃO TESTADO!!
template<class Type>
unsigned int NationalTeam::getLastID(std::vector<Type> &elements)
{
    if (elements.size() > 0) {
        if (elements.at(0)->getId() >= 200) { // se não for soccer player, então procurar o último ID na tabela de dispersão
            unsigned int lastId = 0;
            if (elements.at(0)->getId() >= 200 && elements.at(0)->getId() < 1500) { // se for technical team member
                for (auto it = allTimeStaff.begin(); it != allTimeStaff.end(); it++) {
                    if (it->getId() > lastId && it->getId() >= 200 && it->getId() < 1500)
                        lastId = it->getId();
                }
                return lastId + 1;
            }
            else if (elements.at(0)->getId() >= 1500) {
                for (auto it = allTimeStaff.begin(); it != allTimeStaff.end(); it++) {
                    if (it->getId() > lastId && it->getId() >= 1500)
                        lastId = it->getId();
                }
                return lastId + 1;
            }

        }
        else return elements.at(elements.size() - 1)->getId() + 1; // se for soccer player

    }
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
                std::transform(name.begin(), name.end(), name.begin(), ::toupper); // Convert to uppercase

                std::string workerName;

                for(auto &x: workers)
                {
                    workerName = x->getName();
                    std::transform(workerName.begin(), workerName.end(), workerName.begin(), ::toupper); // Convert to uppercase
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
