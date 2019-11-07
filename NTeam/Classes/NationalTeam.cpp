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

/* OtherWorker Methods */

bool NationalTeam::createOtherWorker()
{
    string auxName = readOperations::readString("Name:");

    Date birth = readOperations::readDate();

    string auxRole = readOperations::readString("Role:");

    unsigned int auxSalary = readOperations::readNumber<unsigned int>("Salary:");

    unsigned int id = getLastID(otherWorkers);

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    OtherWorker *oW = new OtherWorker(id, auxRole, auxSalary, auxName, birth);
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
    unsigned int id, salary;
    string name, aux;
    char delim = ' ';
    Date birthday;
    string function;
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

            OtherWorker* oW = new OtherWorker(id, function, salary, name, birthday);
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
    OtherWorker *oW = workerLookUp(otherWorkers);
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
    bool toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    OtherWorker *person = workerLookUp(otherWorkers);
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
                cout << "Previous Name: " << person->getName() << endl;
                string auxName = readOperations::readString("New Name:");
                person->setName(auxName);
                break;
            }
            case 2:
            {
                cout << "Previous Role: " << person->getRole() << endl;
                string auxRole = readOperations::readString("New Role:");
                person->setRole(auxRole);
                break;
            }
            case 3:
            {
                cout << "Previous Birth Date: " << person->getDate() << endl;
                Date birth = readOperations::readDate();
                person->setDate(birth);
                break;
            }
            case 4:
            {
                cout << "Previous Salary: " << person->getSalary() << endl;
                float auxSalary = readOperations::readNumber<float>("New Salary:");
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

void NationalTeam::addOtherWorker(OtherWorker *oW)
{
    otherWorkers.push_back(oW);
}

vector<OtherWorker*>& NationalTeam::getOtherWorkers()
{
    return otherWorkers;
}

void NationalTeam::displayOtherWorkers() const {
    std::cout << std::endl;
    for(auto &x: otherWorkers)
        x->info(std::cout);
}

void NationalTeam::displaySoccerPlayers() const
{
    std::cout << std::endl;
    for(auto &x: players)
        x->info(std::cout);
}

/* SoccerPlayer Methods */

bool NationalTeam::readSoccerPlayersFile(string filename) {
    ifstream f;
    f.open(filename);
    unsigned int id, daysActive;
    string name, position, club, aux;
    char delim = ' ';
    Date birthday;
    unsigned short weight, height;
    unsigned long marketPrice;
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
            getline(f, aux, delim);
            f >> marketPrice;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> daysActive;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, '\n');  // blank line

            SoccerPlayer* sP = new SoccerPlayer(id, name, birthday, position,
                    club, weight, height, marketPrice, daysActive);
            addSoccerPlayer(sP);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }

}

void NationalTeam::addSoccerPlayer(SoccerPlayer *sP) {
    players.push_back(sP);
}

bool NationalTeam::createSoccerPlayer()
{
    string auxName = readOperations::readString("Name:");
    Date birth = readOperations::readDate();
    string auxPosition = readOperations::readString("Position:");
    string auxClub = readOperations::readString("Club:");
    unsigned short auxWeight =  readOperations::readNumber<unsigned short>("Weight (KG):");
    unsigned short auxHeight = readOperations::readNumber<unsigned short>("Height (CM):");
    unsigned long marketPrice = readOperations::readNumber<unsigned long>("Market Price:");
    unsigned int daysActive = readOperations::readNumber<unsigned int>("Days Active:");

    unsigned int id = getLastID(players);

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    SoccerPlayer *sP = new SoccerPlayer(id, auxName, birth, auxPosition, auxClub, auxWeight, auxHeight, marketPrice, daysActive);
    sP->info(cout);
    string answer = readOperations::confirmAnswer();

    if(answer == "Y" || answer == "y")
    {
        addSoccerPlayer(sP);
        cout << "Data successfully inserted!" << endl;
        return true;
        /* In the future to save all info inside a file */
        //  ofstream out_stream("../Files/OtherWorkers.txt", ios::app);
        //  oW.info(out_stream);
    }
    cout << "Data not inserted." << endl;
    delete sP;
    return false;

    // NATIONALTEAM DESTRUCTOR SHOULD DESTRUCT ALL VECTORS BECAUSE THEY'RE ALLOCATED DYNAMICALLY
}

bool NationalTeam::alterSoccerPlayer()
{
    bool toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    SoccerPlayer *person = workerLookUp(players);
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

        cout << "1. Name\n2. Birth Date\n3. Position\n4. Club\n5. Weight\n6. Height\n7. Market Price\n8. Days Active\n0. Back\n\n";
        cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (option)
        {
            case 0:
            {
                toggle = false;
                break;
            }
            case 1: /* Name */
            {
                cout << "Previous Name: " << person->getName() << endl;
                string auxName = readOperations::readString("New Name:");
                person->setName(auxName);
                break;
            }
            case 2: /* Birth Date */
            {
                cout << "Previous Birth Date: " << person->getDate() << endl;
                Date birth = readOperations::readDate();
                person->setDate(birth);
                break;
            }
            case 3: /* Position */
            {
                cout << "Previous Position: " << person->getPosition() << endl;
                string auxPosition = readOperations::readString("New Position:");
                person->setPosition(auxPosition);
                break;
            }
            case 4: /* Club */
            {
                cout << "Previous Club: " << person->getClub() << endl;
                string auxClub = readOperations::readString("New Club:");
                person->setClub(auxClub);
                break;
            }
            case 5: /* Weight */
            {
                cout << "Previous Weight: " << person->getWeight() << endl;
                unsigned short auxWeight = readOperations::readNumber<unsigned short>("New Weight (KG):");
                person->setWeight(auxWeight);
                break;
            }
            case 6: /* Height */
            {
                cout << "Previous Height: " << person->getHeight() << endl;
                unsigned short auxHeight = readOperations::readNumber<unsigned short>("New Height (CM):");
                person->setHeight(auxHeight);
                break;
            }
            case 7: /* MarketPrice */
            {
                cout << "Previous Market Price: " << person->getMarketPrice() << endl;
                unsigned long auxMarketPrice = readOperations::readNumber<unsigned long>("New Market Price:");
                person->setMarketPrice(auxMarketPrice);
                break;
            }
            case 8: /* Days Active */
            {
                cout << "Previous Days Active: " << person->getDaysActive() << endl;
                unsigned int auxDaysActive = readOperations::readNumber<unsigned int>("New Days Active:");
                person->setDaysActive(auxDaysActive);
                break;
            }
        }
        if (toggle)
        {
            cout << endl << "Player successfully altered!" << endl;
            // OtherWorkerInfoHasChanged = true;
        }
    }
    return true;
}

bool NationalTeam::deleteSoccerPlayer(){
    SoccerPlayer *sP = workerLookUp(players);
    if(sP == NULL)
        return false;
    for (auto it = players.begin(); it != players.end(); it++) {
        if (*(*it) == *sP) {
            players.erase(it);
            cout << endl << "Soccer Player successfully removed!" << endl << endl;
            return true;
        }
    }
    return false;
}

/* Games */

void NationalTeam::addGame(Game* game) {
    games.push_back(game);
}

// NOT TESTED YET!!!
bool NationalTeam::readGamesFile(std::string filename) {
    ifstream f;
    f.open(filename);
    string aux, city, country, stadium, oppositeTeam;
    char delim = ' ';
    unsigned int id, gameStatisticsId;
    Date date;
    vector<string> oppositeTeamParticipants;
    vector<string> refereeingTeam;
    GameStats* gameStatsPtr;
    vector<string> individualStatsVectorString;
    vector<int> individualStatsVectorInt;
    vector<IndividualStatistics *> individualStatistics;

    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> date;
            getline(f, aux, delim);
            getline(f, country);
            getline(f, aux, delim);
            getline(f, stadium);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, oppositeTeam);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux);
            oppositeTeamParticipants = generalFunctions::separate_string(aux, ',');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux);
            refereeingTeam = generalFunctions::separate_string(aux, ',');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> gameStatisticsId;
            f.clear();
            f.ignore(1000, '\n');
            gameStatsPtr = getByID(gameStats, gameStatisticsId);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux);
            individualStatsVectorString = generalFunctions::separate_string(aux, ',');
            individualStatsVectorInt = generalFunctions::convert_vector_str_to_int(individualStatsVectorString);
            for (auto &x: individualStatsVectorInt) {
                individualStatistics.push_back(getByID(individualStatistics, x));
            }

            Game* game = new Game(id, date, city, country, stadium, oppositeTeam, oppositeTeamParticipants,
                              refereeingTeam, gameStatsPtr, individualStatistics);
            addGame(game);

            }
            f.close();
            return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }

}

/* Calls */

bool NationalTeam::createCall()
{
    unsigned int counter = 0;
    vector<SoccerPlayer*> auxSoccerPlayers;
    string playerList = "";
    unsigned int numPlayers = readOperations::readNumber<unsigned int>("Number of Players to Insert (12 - 24):");

    cout << endl << endl << "1 - Player Selection:" << endl;
    while(counter != numPlayers)
    {
        SoccerPlayer* player = workerLookUp(players);
        auxSoccerPlayers.push_back(player);
        playerList += player->getName();
        counter++;
        cout << endl << "Players Already Inserted [ " << counter << " ]: " << playerList << endl << endl;
        playerList += ", ";
    }

    // Still to finish...
    return true;

}


/* Game Statistics */

void NationalTeam::addGameStatistics(GameStats* gStats) {
    gameStats.push_back(gStats);
}

bool NationalTeam::readGameStatisticsFile(std::string filename) {
    ifstream f;
    f.open(filename);
    string aux;
    char delim = ' ';
    unsigned int gameId;
    unsigned short goals, oppositionGoals, shots, oppositionShots, shotsTarget, oppositionShotsTarget, possession,
            passes, oppositionPasses, passAccuracy, oppositionPassAccuracy, fouls, oppositionFouls, yellowCards, oppositionYellowCards,
            redCards, oppositionRedCards, offsides, oppositionOffsides, corners, oppositionCorners, injuries, oppositionInjuries;

    if (f.is_open()) {
        while (!f.eof()) {
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> gameId;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> goals;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionGoals;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> shots;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionShots;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> shotsTarget;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionShotsTarget;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> possession;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> passes;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionPasses;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> passAccuracy;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionPassAccuracy;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> fouls;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionFouls;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> yellowCards;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionYellowCards;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> redCards;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionRedCards;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> offsides;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionOffsides;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> corners;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionFouls;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> injuries;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> oppositionInjuries;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, '\n');  // blank line

            GameStats* gStats = new GameStats(gameId, goals, oppositionGoals, shots, oppositionShots, shotsTarget, oppositionShotsTarget,
                    possession, passes, oppositionPasses, passAccuracy, oppositionPassAccuracy,fouls, oppositionFouls, offsides, oppositionOffsides,
                    corners, oppositionCorners, yellowCards, oppositionYellowCards, redCards, oppositionRedCards, injuries, oppositionInjuries);
            addGameStatistics(gStats);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}


/* Individual Statistics */

void NationalTeam::addIndividualStatistic(IndividualStatistics* iStat) {
    individualStats.push_back(iStat);
}

bool NationalTeam::readIndividualStatisticsFile(std::string filename) {
    ifstream f;
    f.open(filename);
    string aux, injuredString;
    char delim = ' ';
    unsigned int id, playerID, gameID;
    unsigned short goals, assists, shots, shotsTarget, passes, travelledDistance, playedMinutes, yellowCards, redCards, injured, fouls;

    if (f.is_open()) {
        while (!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> playerID;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> gameID;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> goals;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> assists;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> shots;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> shotsTarget;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> passes;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> playedMinutes;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> yellowCards;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> redCards;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, injuredString);
            if (injuredString == "false")
                injured = false;
            else
                injured = true;
            getline(f, aux, delim);
            f >> fouls;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, '\n');  // blank line

            IndividualStatistics* iStats = new IndividualStatistics(id, playerID, gameID, goals, assists,
                    passes, shots, shotsTarget, travelledDistance, playedMinutes, yellowCards, redCards,
                    fouls, injured);
            addIndividualStatistic(iStats);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}






