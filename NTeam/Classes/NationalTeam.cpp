
#include "NationalTeam.h"
#include "TechnicalTeam.h"
#include "../NecessaryFunctions_NameSpaces.h"
#include <iostream>
#include <new>
#include <limits>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include <chrono>
#include <ratio>
#include <ctime>
#include <time.h>
#include <random>

using namespace std;

/* Gets */

string NationalTeam::getName() const
{
    return name;
}


/* OtherWorker Methods */

bool NationalTeam::createOtherWorker()
{
    string auxName = readOperations::readString("Name:");

    Date birth = readOperations::readDate("Birth Date (DD/MM/YYYY):");

    string auxRole = readOperations::readString("Role:");

    unsigned int auxSalary = readOperations::readNumber<unsigned int>("Salary:");

    unsigned int id = getLastID(otherWorkers);

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    OtherWorker *oW = new OtherWorker(id, auxRole, auxSalary, auxName, birth);
    oW->header();
    oW->info();
    cout << endl << endl;
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
                Date birth = readOperations::readDate("New Birth Date (DD/MM/YYYY):");
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

void NationalTeam::displayOtherWorkers() const {
    OtherWorker::header();
    for(auto &worker: otherWorkers)
    {
        worker->info();
        cout << endl;
    }
}

void NationalTeam::displaySoccerPlayers() const
{
    SoccerPlayer::header();
    for(auto &player: players)
    {
        player->info();
        cout << endl;
    }

}

void NationalTeam::displayGames() const
{
    for(auto &game: games)
    {
        Game::header();
        game->info();
        cout << endl;
    }
}

void NationalTeam::displayTechnicalTeamMembers() const {
    TechnicalTeam::header();
    for(auto &member: technicalTeam) {
        member->info();
        cout << endl;
    }
}

void NationalTeam::displayCallsPlayers() const
{
    for(auto &x: calls)
    {
        x->infoPlayers();
        cout << endl << endl << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    }
}

void NationalTeam::displayCallsGames() const
{
    for(auto &x: calls)
    {
        x->infoGames();
        cout << endl << endl <<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    }
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
    Date birth = readOperations::readDate("Birth Date (DD/MM/YYYY):");
    string auxPosition = readOperations::readString("Position:");
    string auxClub = readOperations::readString("Club:");
    unsigned short auxWeight =  readOperations::readNumber<unsigned short>("Weight (KG):");
    unsigned short auxHeight = readOperations::readNumber<unsigned short>("Height (CM):");
    unsigned long marketPrice = readOperations::readNumber<unsigned long>("Market Price:");
    unsigned int daysActive = readOperations::readNumber<unsigned int>("Days Active:");

    unsigned int id = getLastID(players);

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    SoccerPlayer *sP = new SoccerPlayer(id, auxName, birth, auxPosition, auxClub, auxWeight, auxHeight, marketPrice, daysActive);
    sP->header();
    sP->info();
    cout << endl << endl;
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
                Date birth = readOperations::readDate("New Birth Date (DD/MM/YYYY):");
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
    if(sP == NULL || sP->getDaysActive() != 0)
    {
        cout << endl << "Soccer Player not removed! Either because didn't exist... Or because has already games where it participated!" << endl << endl;
        return false;
    }
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

bool NationalTeam::alterGameGlobalOpposite(Game* game)
{
    bool toggle = true;
    int repetition = 0, option;
    GameStats* stats = game->getGameStats();
    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    while (toggle)
    {
        if (repetition == 0)
        {
            cout << endl << "What do you want to change?\n";
            repetition++;
        }
        else
            cout << "Do you want to change anything else?\n";

        cout << "1. Opposition Goals\n2. Opposition Shots\n3. Opposition Shots on Target\n"
                "4. Opposition Passes\n5. Opposition Pass Accuracy\n6. Opposition Fouls\n"
                "7. Opposition Offsides\n8. Opposition Corners\n9. Opposition Yellow Cards\n10. Opposition Red Cards\n"
                "11. Opposition Injuries\n0. Back\n\n";
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
                cout << "Opposition Goals: " << stats->getOppositionGoals() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Goals:");
                stats->setOppositionGoals(aux);
                break;
            }
            case 2:
            {
                cout << "Opposition Shots: " << stats->getOppositionShots() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Shots:");
                stats->setOppositionShots(aux);
                break;
            }
            case 3:
            {
                cout << "Opposition Shots on Target: " << stats->getOppositionShotsTarget() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Shots on Target:");
                stats->setOppositionShotsTarget(aux);
                break;
            }
            case 4:
            {
                cout << "Opposition Passes: " << stats->getOppositionPasses() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Passes:");
                stats->setOppositionPasses(aux);
                break;
            }
            case 5:
            {
                cout << "Opposition Pass Accuracy: " << stats->getOppositionPassAccuracy() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Pass Accuracy:");
                stats->setOppositionPassAccuracy(aux);
                break;
            }
            case 6:
            {
                cout << "Opposition Fouls: " << stats->getOppositionFouls() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Fouls:");
                stats->setOppositionFouls(aux);
                break;
            }
            case 7:
            {
                cout << "Opposition Offsides: " << stats->getOppositionOffsides() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Offsides:");
                stats->setOppositionOffsides(aux);
                break;
            }
            case 8:
            {
                cout << "Opposition Corners: " << stats->getOppositionCorners() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Corners:");
                stats->setOppositionCorners(aux);
                break;
            }
            case 9:
            {
                cout << "Opposition Yellow Cards: " << stats->getOppositionYellowCards() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Yellow Cards:");
                stats->setOppositionYellowCards(aux);
                break;
            }
            case 10:
            {
                cout << "Opposition Red Cards: " << stats->getOppositionRedCards() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Red Cards:");
                stats->setOppositionRedCards(aux);
                break;
            }
            case 11:
            {
                cout << "Opposition Injuries: " << stats->getOppositionInjuries() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Opposition Injuries:");
                stats->setOppositionInjuries(aux);
                break;
            }
        }
        if (toggle)
        {
            cout << endl << "Game Statistics successfully altered!" << endl;
        }
    }
    return true;
}

bool NationalTeam::alterGameGlobal(Game* game)
{
    bool toggle = true;
    int repetition = 0, option;
    GameStats* stats = game->getGameStats();
    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    while (toggle)
    {
        if (repetition == 0)
        {
            cout << endl << "What do you want to change?\n";
            repetition++;
        }
        else
            cout << "Do you want to change anything else?\n";

        cout << "1. Goals\n2. Shots\n3. Shots on Target\n4. Possession\n"
                "5. Passes\n6.  Pass Accuracy\n7. Fouls\n8. Offsides\n"
                "9. Corners\n10. Yellow Cards\n11. Red Cards\n"
                "12. Injuries\n0. Back\n\n";
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
                cout << "Goals: " << stats->getGoals() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Goals:");
                stats->setGoals(aux);
                break;
            }
            case 2:
            {
                cout << "Shots: " << stats->getShots() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Shots:");
                stats->setShots(aux);
                break;
            }
            case 3:
            {
                cout << "Shots on Target: " << stats->getShotsTarget() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Shots on Target:");
                stats->setShotsTarget(aux);
                break;
            }
            case 4:
            {
                cout << "Possession: " << stats->getPossession() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Possession:");
                stats->setPossession(aux);
                break;
            }
            case 5:
            {
                cout << "Passes: " << stats->getPasses() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Passes:");
                stats->setPasses(aux);
                break;
            }
            case 6:
            {
                cout << "Pass Accuracy: " << stats->getPassAccuracy() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Pass Accuracy:");
                stats->setPassAccuracy(aux);
                break;
            }
            case 7:
            {
                cout << "Fouls: " << stats->getFouls() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Fouls:");
                stats->setFouls(aux);
                break;
            }
            case 8:
            {
                cout << "Offsides: " << stats->getOffsides() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Offsides:");
                stats->setOffsides(aux);
                break;
            }
            case 9:
            {
                cout << "Corners: " << stats->getCorners() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Corners:");
                stats->setCorners(aux);
                break;
            }
            case 10:
            {
                cout << "Yellow Cards: " << stats->getYellowCards() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Yellow Cards:");
                stats->setYellowCards(aux);
                break;
            }
            case 11:
            {
                cout << "Red Cards: " << stats->getRedCards() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Red Cards:");
                stats->setRedCards(aux);
                break;
            }
            case 12:
            {
                cout << "Injuries: " << stats->getInjuries() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Injuries:");
                stats->setInjuries(aux);
                break;
            }
        }
        if (toggle)
        {
            cout << endl << "Game Statistics successfully altered!" << endl;
        }
    }
    return true;
}

bool NationalTeam::alterPlayerStats(vector<IndividualStatistics*> stats, unsigned int playerID)
{
    bool toggle = true;
    int repetition = 0, option;

    IndividualStatistics* st;
    for(auto &x: stats)
    {
        if(x->getSoccerPlayerID() == playerID)
        {
            st = x;
            break;
        }
    }

    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    while (toggle)
    {
        if (repetition == 0)
        {
            cout << endl << "What do you want to change?\n";
            repetition++;
        }
        else
            cout << "Do you want to change anything else?\n";

        cout << "1. Goals\n2. Assists\n3. Passes\n4. Shots\n5. Shots on Target\n6. Travelled Distance\n7. Played Minutes\n"
                "8. Yellow Cards\n9. Red Cards\n10. Fouls\n11. Injured\n0. Back\n\n";
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
                cout << "Goals: " << st->getGoals() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Goals:");
                st->setGoals(aux);
                break;
            }
            case 2:
            {
                cout << "Assists: " << st->getAssists() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Assists:");
                st->setAssists(aux);
                break;
            }
            case 3:
            {
                cout << "Passes: " << st->getPasses() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Passes:");
                st->setPasses(aux);
                break;
            }
            case 4:
            {
                cout << "Shots: " << st->getShots() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Shots:");
                st->setShots(aux);
                break;
            }
            case 5:
            {
                cout << "Shots on Target: " << st->getShotsTarget() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Shots on Target:");
                st->setShotsTarget(aux);
                break;
            }
            case 6:
            {
                cout << "Travelled Distance: " << st->getTravelledDistance() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Travelled Distance:");
                st->setTravelledDistance(aux);
                break;
            }
            case 7:
            {
                cout << "Played Minutes: " << st->getPlayedMinutes() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Played Minutes:");
                st->setPlayedMinutes(aux);
                break;
            }
            case 8:
            {
                cout << "Yellow Cards: " << st->getYellowCards() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Yellow Cards:");
                st->setYellowCards(aux);
                break;
            }
            case 9:
            {
                cout << "Red Cards: " << st->getRedCards() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Red Cards:");
                st->setRedCards(aux);
                break;
            }
            case 10:
            {
                cout << "Fouls: " << st->getFouls() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Fouls:");
                st->setFouls(aux);
                break;
            }
            case 11:
            {
                cout << "Injured: " << st->getInjured() << endl;
                unsigned short aux = readOperations::readNumber<unsigned short>("New Injured:");
                st->setInjured(aux);
                break;
            }
        }
        if (toggle)
        {
            cout << endl << "Individual Statistics successfully altered!" << endl;
        }
    }
    return true;
}

Game* NationalTeam::createGame(vector<SoccerPlayer*> soccerPlayers, Date begin, Date end) {

    vector<string> oppositeTeamParticipants;
    vector<string> refereeTeam;
    cout << endl;
    Date date;
    unsigned int id = getLastID(games);
    while(true)
    {
        date = readOperations::readDate("Game date (DD/MM/YYYY):");
        if(!generalFunctions::checkBetweenDates(begin, date, end))
            std::cout << "Inserted date has to be between" << " " << begin.getDate() << " and " << end.getDate() << " !" << std::endl << std::endl;
        else
            break;
    }

    string city = readOperations::readString("City:");
    string country = readOperations::readString("Country:");
    string stadium = readOperations::readString("Stadium:");
    string oppositeTeam = readOperations::readString("Opposite Team:");

    unsigned int oTparticipants;
    while(true)
    {
        oTparticipants = readOperations::readNumber<unsigned int>("Number of Opposite Team Participants (11 - 14) :");
        if(oTparticipants < 11 || oTparticipants > 14)
            cout << "\nPlease Enter a Value Between 11 and 14." << endl;
        else break;
    }

    unsigned int ct = 0;
    while(ct != oTparticipants)
    {
        oppositeTeamParticipants.push_back(readOperations::readString("\nOpposite Team Participant " + to_string(ct) + ":"));
        ct++;
    }

    unsigned int numReferees = readOperations::readNumber<unsigned int>("\nNumber of Referees:");
    ct = 0;
    while(ct != numReferees)
    {
        refereeTeam.push_back(readOperations::readString("Referee " + to_string(ct) + ":"));
        ct++;
    }

    GameStats* gameStatsAux;
    while(true)
    {
        gameStatsAux = createGameStatistics(id);
        gameStats.push_back(gameStatsAux);
        if(gameStatsAux != NULL)
            break;
    }

    vector<IndividualStatistics*> individualStatistics;
    IndividualStatistics* AuxStats;
    ct = 0;

    unsigned int goals;
    unsigned short shots, shotsTarget, passes, fouls, yellowCards, redCards, injuries;

    while(ct != soccerPlayers.size())
    {
        goals = 0, shots = 0, shotsTarget = 0, passes = 0, fouls = 0, yellowCards = 0, redCards = 0, injuries = 0;
        cout << endl << endl;
        soccerPlayers.at(ct)->header();
        soccerPlayers.at(ct)->info();
        cout << endl << endl;
        try {

            AuxStats = createIndividualStatistics(soccerPlayers.at(ct)->getId());

            for(auto &x: individualStatistics)
            {
                goals += x->getGoals();
                shots += x->getShots();
                shotsTarget += x->getShotsTarget();
                passes += x->getPasses();
                fouls += x->getFouls();
                yellowCards += x->getYellowCards();
                redCards += x->getRedCards();
                injuries += x->getInjured();
            }
            goals += AuxStats->getGoals();
            shots += AuxStats->getShots();
            shotsTarget += AuxStats->getShotsTarget();
            passes += AuxStats->getPasses();
            fouls += AuxStats->getFouls();
            yellowCards += AuxStats->getYellowCards();
            redCards += AuxStats->getRedCards();
            injuries += AuxStats->getInjured();

            if(goals != gameStatsAux->getGoals() || shots != gameStatsAux->getShots()
            || shotsTarget != gameStatsAux->getShotsTarget() || passes != gameStatsAux->getPasses()
            || fouls != gameStatsAux->getFouls() || yellowCards != gameStatsAux->getYellowCards() || redCards != gameStatsAux->getRedCards() || injuries != gameStatsAux->getInjuries())
                throw WrongStatistic("Incorrect Statistic! Try again...");

            individualStatistics.push_back(AuxStats);
            individualStats.push_back(AuxStats);
        }
        catch(WrongStatistic &e) {
            cout << endl << e.getError() << endl << endl;
            continue;
        }
        ct++;
    }

    Game* game = new  Game(id, date, city, country, stadium, oppositeTeam, oppositeTeamParticipants, refereeTeam,
                           gameStatsAux, individualStatistics);
    games.push_back(game);

    return game;
}

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
            getline(f, city);
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
            for (auto &x: individualStatsVectorInt)
                individualStatistics.push_back(getByID(individualStats, x));
            cout << id << "..\n";
            Game* game = new Game(id, date, city, country, stadium, oppositeTeam, oppositeTeamParticipants,
                              refereeingTeam, gameStatsPtr, individualStatistics);
            addGame(game);
            individualStatsVectorString.clear();
            individualStatsVectorInt.clear();
            individualStatistics.clear();
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

Call *NationalTeam::callLookUp() {
    bool ct;
    int option;
    vector<Call *> auxCall;
    while (true) {
        ct = false;
        auxCall.clear();
        std::cout << std::endl << "Look for a Call using: " << std::endl;
        std::cout << "1. ID\n2. Date\n0. Back\n\n";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        switch (option) {
            case 0:
                return NULL;
            case 1: {
                // ID
                int id = readOperations::readNumber<int>("ID: ");

                try {
                    return getByID(calls, id);
                }
                catch (NoObjectFound &e) {
                    std::cout << std::endl << e.getError() << std::endl << std::endl;
                }

                break;

            }
            case 2: {
                // Date
                Date d1, d2;
                do {
                    d1 = readOperations::readDate("Smaller Date (DD/MM/YYYY):");
                    d2 = readOperations::readDate("Bigger Date (DD/MM/YYYY):");
                    if (d2 <= d1)
                        std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl
                                  << std::endl;
                    else
                        break;
                } while (!(d1 <= d2));


                for (auto &x: calls) {
                    if (generalFunctions::checkBetweenDates(d1, x->getBeginDate(), d2) ||
                        generalFunctions::checkBetweenDates(d1, x->getEndDate(), d2)) {
                        auxCall.push_back(x);
                        ct = true;
                    }
                }

                if (!auxCall.empty()) {
                    for (auto &x: auxCall) {
                        x->info();
                        std::cout << std::endl;
                    }
                }

                if (ct) {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return getByID(auxCall, option);
                    }
                    catch (NoObjectFound &e) {
                        std::cout << std::endl << e.getError() << std::endl << std::endl;
                    }
                } else
                    std::cout << std::endl << "No Corresponding Call Found..." << std::endl << std::endl;
                break;


            }
        }
    }
}

bool NationalTeam::removeCall()
{
    unsigned int callId;
    Call* call;

    /* Call Search */
    while(true)
    {
        try {
            callId = readOperations::readNumber<unsigned int>("Call ID:");
            call = getByID(calls, callId);
            break;
        }
        catch(NoObjectFound &e) {
            cout << endl << e.getError() << endl << endl;
        }
    }
//    cout << "STEP 0" << endl;
    vector<InfCall*> auxInfCalls = call->getInfs();
    vector<InfCall*>::iterator iTr1;
    for(auto &x: auxInfCalls)
    {
//        cout << "ENTERED" << endl;
        for(iTr1 = infCalls.begin(); iTr1 != infCalls.end(); iTr1++)
        {
            if(x->getId() == (*iTr1)->getId())
            {
                iTr1 = infCalls.erase(iTr1);
                break;
            }
        }
        delete x;
//        cout << "LEFT" << endl;
    }
//    cout << "STEP 1" << endl;
    vector<Game*> auxGames = call->getGames();
    vector<Game*>::iterator iTr2;
    vector<IndividualStatistics*>::iterator iTr3;
    vector<GameStats*>::iterator iTr4;
    for(auto &x: auxGames)
    {
//        cout << "ENTERED" << endl;
        for(iTr2 = games.begin(); iTr2 != games.end(); iTr2++)
        {
            if((*iTr2)->getId() == x->getId())
            {
                iTr2 = games.erase(iTr2);
                break;
            }
        }
//        cout << "P1" << endl;
        for(auto &w: x->getIndividualStatistics())
        {
            for(iTr3 = individualStats.begin(); iTr3 != individualStats.end(); iTr3++)
            {
                if(w->getId() == (*iTr3)->getId())
                {
                    iTr3 = individualStats.erase(iTr3);
                    break;
                }
            }
            delete w;
        }
//        cout << "P2" << endl;
        for(iTr4 = gameStats.begin(); iTr4 != gameStats.end(); iTr4++)
        {
            if(x->getGameStats()->getId() == (*iTr4)->getId())
            {
                iTr4 = gameStats.erase(iTr4);
                break;
            }
        }
//        cout << "P3" << endl;
        delete x->getGameStats();
        delete x;
//        cout << "LEFT" << endl;
    }
//    cout << "STEP 2" << endl;
    vector<Call*>::iterator iTr5;

    for(iTr5 = calls.begin(); iTr5 != calls.end(); iTr5++)
    {
        if(call->getId() == (*iTr5)->getId())
        {
            iTr5 = calls.erase(iTr5);
            break;
        }
    }
    delete call;

    cout << "Call Successfully Deleted!" << endl;

    return true;
}

bool NationalTeam::alterCall()
{
    unsigned int callId, gameId;
    Call* call;
    Game* game;

    /* Call Search */
    while(true)
    {
        try{
            callId = readOperations::readNumber<unsigned int>("Call ID:");
            call = getByID(calls, callId);
            break;
        }
        catch(NoObjectFound &e) {
            cout << endl << e.getError() << endl << endl;
        }
    }

    /* Game Search */
    while(true)
    {
        try{
            gameId = readOperations::readNumber<unsigned int>("Game ID:");
            game = getByID(call->getGames(), gameId);
            break;
        }
        catch(NoObjectFound &e) {
            cout << endl << e.getError() << endl << endl;
        }
    }

    cout << "Update Opposite Team Game Statistics? (Y | N = Global and Player Individual Game Statistic)" << endl;
    string answer = readOperations::confirmAnswer();

    if(answer == "Y" || answer == "y")
        alterGameGlobalOpposite(game);
    else
    {
        /* Any Flimsy Info is At your Own Risk */
        alterGameGlobal(game);
        SoccerPlayer* player = workerLookUp(call->getPlayers());
        alterPlayerStats(game->getIndividualStatistics(), player->getId());
    }
    return true;
}

bool NationalTeam::readCallsFile(std::string filename){
    ifstream f;
    f.open(filename);
    string aux, competition;
    char delim = ' ';
    unsigned int id, housing_food;
    Date bDate, eDate;

    vector<string> auxIds;
    vector<int> auxInts;

    vector<Game*> gamesVec;
    vector<InfCall*> infsVec;
    vector<SoccerPlayer*> playersVec;

    if (f.is_open()) {
        while(!f.eof()) {

            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, competition);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> bDate;
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> eDate;
            getline(f, aux, delim);
            f >> housing_food;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux);
            // Games
            auxIds = generalFunctions::separate_string(aux, ',');
            auxInts = generalFunctions::convert_vector_str_to_int(auxIds);
            for (auto &x: auxInts)
                gamesVec.push_back(getByID(games, x));

            getline(f, aux, delim);
            getline(f, aux);
            // Players Ids
            auxIds = generalFunctions::separate_string(aux, ',');
            auxInts = generalFunctions::convert_vector_str_to_int(auxIds);
            for (auto &x: auxInts)
                playersVec.push_back(getByID(players, x));

            getline(f, aux, delim);
            getline(f, aux);
            // Inf Calls
            auxIds = generalFunctions::separate_string(aux, ',');
            auxInts = generalFunctions::convert_vector_str_to_int(auxIds);
            for (auto &x: auxInts)
                infsVec.push_back(getByID(infCalls, x));
            getline(f, aux);

            Call* call = new Call(id, competition, gamesVec, infsVec, playersVec, bDate, eDate, housing_food);
            addCall(call);
            gamesVec.clear();
            infsVec.clear();
            playersVec.clear();
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }

}

void NationalTeam::addCall(Call *call)
{
    calls.push_back(call);
}

bool sortPlayers(const SoccerPlayer* player1, const SoccerPlayer* player2)
{
    return player1->getId() < player2->getId();
}


bool NationalTeam::createCall()
{

//    if(players.size() < 11)
//    {
//        cout << endl << "Not enough Players To Assign To The Call..." << endl << endl;
//        return;
//    }
    unsigned int counter = 0;
    vector<SoccerPlayer*> auxSoccerPlayers;
    vector<InfCall*> infs;
    unsigned int numPlayers = 0;

    string competition = readOperations::readString("Competition:");
    Date begDate, endDate;
    do
    {
        while(true)
        {
            begDate = readOperations::readDate("Beggining Date (DD/MM/YYYY):");
            bool flag = false;
            for(auto &x: calls)
            {
                Date d1 = x->getBeginDate();
                Date d2 = x->getEndDate();
                if(generalFunctions::checkBetweenDates(d1, begDate, d2))
                    flag = true;
            }
            if(flag)
               cout << endl << endl << "There\'s a another Summon created in the same Period..." << endl << endl;
            else
                break;
        }

        endDate = readOperations::readDate("End Date (DD/MM/YYYY):");
        if(!(begDate <= endDate))
            std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl << std::endl;
    } while(!(begDate <= endDate));
    int housing_food = readOperations::readNumber<int>("Housing and Food Costs (Per Player):");

    unsigned int days = generalFunctions::getDays(begDate, endDate);

    while(true)
    {
        numPlayers = readOperations::readNumber<unsigned int>("\nNumber of Players to Insert (11 - 24):");
//        if(numPlayers < 11 || numPlayers > 24)
//            cout << "Please Insert a Value Between 12 and 24." << endl;
//        else
            break;
    }

    cout << endl << endl << "1 - Player Selection:" << endl;
    unsigned int callID = getLastID(calls);
    while(counter != numPlayers)
    {
        SoccerPlayer* player = workerLookUp(players);
        if(player == NULL)
            return false;



        sort(auxSoccerPlayers.begin(), auxSoccerPlayers.end(), sortPlayers);
        if(binary_search(auxSoccerPlayers.begin(), auxSoccerPlayers.end(), player, sortPlayers))
        {
            cout << endl << "Player Already Inserted! Try again..." << endl;
            continue;
        }
        else
        {
            auxSoccerPlayers.push_back(player);
            player->header();
            for(auto &x: auxSoccerPlayers)
            {
                x->info();
                cout << endl;
            }
            player->setDaysActive(player->getDaysActive() + days);
        }

        InfCall* inf = createInfCalls(player->getId());
        if(inf->getDateArrived().getDate() == "0/0/0" && inf->getDateLeft().getDate() == "0/0/0")
        {
            inf->setDateArrived(begDate);
            inf->setDateLeft(endDate);
        }
        infs.push_back(inf);

        counter++;
        cout << endl << "Players Remaining [ " << (numPlayers - counter) << " ]: " <<  endl << endl;
    }

    /* Games Creation */
    unsigned int numGames;
    while(true)
    {
        numGames = readOperations::readNumber<unsigned int>("Number of Games to Insert (1 - 8):");
        if(numGames > 8 || numPlayers < 1)
            cout << "Please Insert a Value Between 1 and 8." << endl;
        else
            break;
    }

    vector<Game*> gamesAux;
    counter = 0;
    while(counter != numGames)
    {
        gamesAux.push_back(createGame(auxSoccerPlayers, begDate, endDate));
        counter++;
    }

    Call* call = new Call(callID, competition, gamesAux, infs, auxSoccerPlayers, begDate, endDate, housing_food);
    addCall(call);

    // Still need to add Days Active to players!

    cout << "Summon successfully created!" << endl;
    return true;

}


/* Game Statistics */

void NationalTeam::addGameStatistics(GameStats* gStats) {
    gameStats.push_back(gStats);
}

GameStats* NationalTeam::createGameStatistics(unsigned int gameID) {
    cout << "======================================================================================== National Team ========================================================================================" << endl;
    unsigned short goals = readOperations::readNumber<unsigned short>("\nGoals:");
    unsigned short shots = readOperations::readNumber<unsigned short>("\nShots:");

    unsigned short shotsTarget;
    while(true)
    {
        shotsTarget = readOperations::readNumber<unsigned short>("\nShots on Target:");
        if(shotsTarget > shots)
            cout << "Shots on Target need to be Smaller than \'Shots\'!" << endl;
        else
            break;
    }

    unsigned short possession;
    while(true)
    {
        possession = readOperations::readNumber<unsigned short>("\nPossession (%):");
        if(possession < 0 || possession > 100)
            cout << "Possession has to be Between 0 an 100!" << endl;
        else
            break;
    }

    unsigned short passes = readOperations::readNumber<unsigned short>("\nPasses:");
    unsigned short passAccuracy;
    while(true)
    {
        passAccuracy = readOperations::readNumber<unsigned short>("\nPass Accuracy (%):");
        if(passAccuracy < 0 || passAccuracy > 100)
            cout << "Pass Accuracy has to be Between 0 an 100!" << endl;
        else
            break;
    }
    unsigned short fouls = readOperations::readNumber<unsigned short>("\nFouls:");
    unsigned short yellowCards = readOperations::readNumber<unsigned short>("\nYellow Cards:");
    unsigned short redCards = readOperations::readNumber<unsigned short>("\nRed Cards:");
    unsigned short offsides = readOperations::readNumber<unsigned short>("\nOffsides:");
    unsigned short corners = readOperations::readNumber<unsigned short>("\nCorners:");
    unsigned short injuries = readOperations::readNumber<unsigned short>("\nInjuries:");

    cout << endl << endl << "======================================================================================== Opposite Team ========================================================================================" << endl;
    unsigned short oppositionGoals = readOperations::readNumber<unsigned short>("\nOpposing Team Goals:");
    unsigned short oppositionShots = readOperations::readNumber<unsigned short>("\nOpposing Team shots:");

    unsigned short oppositionShotsTarget;
    while(true)
    {
        oppositionShotsTarget = readOperations::readNumber<unsigned short>("\nShots on Target:");
        if(oppositionShotsTarget > oppositionShots)
            cout << "Shots on Target need to be Smaller than \'Shots\'!" << endl;
        else
            break;
    }

    unsigned short oppositionPasses = readOperations::readNumber<unsigned short>("\nOpposing Team passes:");
    unsigned short oppositionPassAccuracy = readOperations::readNumber<unsigned short>("\nOpposing Team Pass Accuracy:");
    unsigned short oppositionFouls = readOperations::readNumber<unsigned short>("\nOpposing Team Fouls:");
    unsigned short oppositionYellowCards = readOperations::readNumber<unsigned short>("\nOpposing Yellow Cards:");
    unsigned short oppositionRedCards = readOperations::readNumber<unsigned short>("\nOpposing Team Red Cards:");
    unsigned short oppositionOffsides = readOperations::readNumber<unsigned short>("\nOpposing Team Offsides:");
    unsigned short oppositionCorners = readOperations::readNumber<unsigned short>("\nOpposing Team Corners:");
    unsigned short oppositionInjuries = readOperations::readNumber<unsigned short>("\nOpposing Team Injuries:");

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    GameStats *gStats = new GameStats(gameID, goals, oppositionGoals, shots, oppositionShots, shotsTarget, oppositionShotsTarget,
                                      possession, passes, oppositionPasses, passAccuracy, oppositionPassAccuracy, fouls, oppositionFouls, offsides, oppositionOffsides,
                                      corners, oppositionCorners, yellowCards, oppositionYellowCards, redCards, oppositionRedCards, injuries, oppositionInjuries);
    gStats->info(cout);
    string answer = readOperations::confirmAnswer();

    if(answer == "Y" || answer == "y")
    {
        cout << "Data successfully inserted!" << endl;
        return gStats;
    }
    cout << "Data not inserted." << endl;
    delete gStats;
    return NULL;
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
            f >> oppositionCorners;
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

IndividualStatistics *NationalTeam::createIndividualStatistics(unsigned int playerID) {
    unsigned int id = getLastID(individualStats);

    cout << endl << "Player above participated in the game? (Y|N)" << endl << endl;
    string answer = readOperations::confirmAnswer();
    IndividualStatistics* iStat;

    if(answer == "N" || answer == "n")
    {
        cout << endl << "Did It Got Injured? (Y|N)" << endl << endl;
        answer = readOperations::confirmAnswer();
        if(answer == "Y" || answer == "y")
            iStat = new IndividualStatistics(id, playerID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
        else
            iStat = new IndividualStatistics(id, playerID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        return iStat;
    }

    unsigned short goals = readOperations::readNumber<unsigned short>("\nGoals:");
    unsigned short assists = readOperations::readNumber<unsigned short>("\nAssists:");
    unsigned short shots = readOperations::readNumber<unsigned short>("\nShots:");

    unsigned short shotsTarget;
    while(true)
    {
        shotsTarget = readOperations::readNumber<unsigned short>("\nShots on Target:");
        if(shotsTarget > shots)
            cout << "Shots on Target need to be Smaller than \'Shots\'!" << endl;
        else
            break;
    }

    unsigned short passes = readOperations::readNumber<unsigned short>("\nPasses:");
    unsigned short travelledDistance = readOperations::readNumber<unsigned short>("\nTravelled Distance (in Km):");

    unsigned short playedMinutes;
    while(true)
    {
        playedMinutes = readOperations::readNumber<unsigned short>("\nPlayed Minutes:");
        if(playedMinutes > 120 || playedMinutes < 0)
            cout << "Invalid number..." << endl;
        else
            break;
    }

    unsigned short yellowCards = readOperations::readNumber<unsigned short>("\nYellow Cards:");
    unsigned short redCards = readOperations::readNumber<unsigned short>("\nRed Cards:");
    unsigned short fouls = readOperations::readNumber<unsigned short>("\nFouls:");
    bool injured = false;

    cout << "Injured? (Y | N)" << endl;
    string injuredString = readOperations::confirmAnswer();

    if(injuredString == "Y" || injuredString == "y")
        injured = true;

    iStat = new IndividualStatistics(id, playerID, goals, assists, passes, shots,
                                                               shotsTarget, travelledDistance, playedMinutes, yellowCards, redCards, fouls, injured);

    return iStat;

}

bool NationalTeam::readIndividualStatisticsFile(std::string filename) {
    ifstream f;
    f.open(filename);
    string aux, injuredString;
    char delim = ' ';
    unsigned int id, playerID;
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
            f >> travelledDistance;
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

            IndividualStatistics* iStats = new IndividualStatistics(id, playerID, goals, assists,
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


/* InfCalls */

bool NationalTeam::readInfCalls(std::string filename)
{
    ifstream f;
    f.open(filename);
    string aux;
    char delim = ' ';
    unsigned int id, playerId;
    Date bDate, eDate;

    if (f.is_open()) {
        while (!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> playerId;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> bDate;
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> eDate;
            getline(f, aux, '\n');  // blank line

            InfCall* inf = new InfCall(id, playerId, bDate, eDate);
            addInfCall(inf);
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

InfCall* NationalTeam::createInfCalls(unsigned int sPId)
{
    cout << endl;
    Date arriveDate, leftDate;
    cout << "\nSame Beggining and End Date as the Summon? (Y|N)\n";
    string sameDate = readOperations::confirmAnswer();

    unsigned int id = getLastID(infCalls);

    if(sameDate == "Y" || sameDate == "y")
    {
        InfCall* inf = new InfCall(id, sPId, arriveDate, leftDate);
        addInfCall(inf);
        return inf;
    }

    do
    {
        arriveDate = readOperations::readDate("Arrive Date (DD/MM/YYYY):");
        leftDate = readOperations::readDate("Left Date (DD/MM/YYYY):");
        if(!(leftDate <= arriveDate))
            std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl << std::endl;
    } while(!(arriveDate <= leftDate));


    InfCall* inf = new InfCall(id, sPId, arriveDate, leftDate);
    addInfCall(inf);

    return inf;
}

void NationalTeam::addInfCall(InfCall *inf)
{
    infCalls.push_back(inf);
}


/* TechnicalTeam Methods */

void NationalTeam::addTechnicalTeamMember(TechnicalTeam* tTeam) {
    technicalTeam.push_back(tTeam);
}

bool NationalTeam::readTechnicalTeamFile(std::string filename) {
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

            TechnicalTeam* tTeam = new TechnicalTeam(id, function, salary, name, birthday);
            addTechnicalTeamMember(tTeam);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::createTechnicalTeamMember() {
    string auxName = readOperations::readString("Name:");

    Date birth = readOperations::readDate("Birth Date (DD/MM/YYYY):");

    string auxRole = readOperations::readString("Role:");

    unsigned int auxSalary = readOperations::readNumber<unsigned int>("Salary:");

    unsigned int id = getLastID(technicalTeam);

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    TechnicalTeam *tTeam = new TechnicalTeam(id, auxRole, auxSalary, auxName, birth);
    tTeam->header();
    tTeam->info();
    cout << endl << endl;
    string answer = readOperations::confirmAnswer();

    if(answer == "Y" || answer == "y")
    {
        addTechnicalTeamMember(tTeam);
        cout << "Data successfully inserted!" << endl;
        return true;
        /* In the future to save all info inside a file */
        //  ofstream out_stream("../Files/TechnicalTeam.txt", ios::app);
        //  oW.info(out_stream);
    }
    cout << "Data not inserted." << endl;
    delete tTeam;
    return false;
}

bool NationalTeam::alterTechnicalTeamMember() {
    bool toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n');
//    cout << explorer << endl << endl;

    TechnicalTeam *person = workerLookUp(technicalTeam);
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
                Date birth = readOperations::readDate("New Birth Date (DD/MM/YYYY):");
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

bool NationalTeam::deleteTechnicalTeamMember() {
    TechnicalTeam *tTeam = workerLookUp(technicalTeam);
    if(tTeam == NULL)
        return false;
    for (auto it = technicalTeam.begin(); it != technicalTeam.end(); it++) {
        if (*(*it) == *tTeam) {
            technicalTeam.erase(it);
            cout << endl << "Technical Team member successfully removed!" << endl << endl;
            return true;
        }
    }
    return false;
}

/* Save to Files */

bool NationalTeam::writeOtherWorkersFile(string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = otherWorkers.begin(); it != otherWorkers.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Name: " << (*it)->getName() << endl;
            f << "Birth Date: " << (*it)->getDate() << endl;
            f << "Function: " << (*it)->getRole() << endl;
            f << "Salary: " << (*it)->getSalary();
            if (it != otherWorkers.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeSoccerPlayersFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = players.begin(); it != players.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Name: " << (*it)->getName() << endl;
            f << "Birth Date: " << (*it)->getDate() << endl;
            f << "Position: " << (*it)->getPosition() << endl;
            f << "Club: " << (*it)->getClub() << endl;
            f << "Weight: " << (*it)->getWeight() << endl;
            f << "Height: " << (*it)->getHeight() << endl;
            f << "Market Price: " << (*it)->getMarketPrice() << endl;
            f << "Days Active: " << (*it)->getDaysActive();

            if (it != players.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeIndividualStatisticsFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = individualStats.begin(); it != individualStats.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Player ID: " << (*it)->getSoccerPlayerID() << endl;
            f << "Goals: " << (*it)->getGoals() << endl;
            f << "Assists: " << (*it)->getAssists() << endl;
            f << "Shots: " << (*it)->getShots() << endl;
            f << "Shots on Target: " << (*it)->getShotsTarget() << endl;
            f << "Passes: " << (*it)->getPasses() << endl;
            f << "Travelled Distance: " << (*it)->getTravelledDistance() << endl;
            f << "Played Minutes: " << (*it)->getPlayedMinutes() << endl;
            f << "Yellow Cards: " << (*it)->getYellowCards() << endl;
            f << "Red Cards: " << (*it)->getRedCards() << endl;
            f << "Injured: " << boolalpha << (*it)->getInjured() << endl; // boolalpha to display the bool value in the string format
            f << "Fouls: " << (*it)->getFouls();

            if (it != individualStats.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeGamesStatisticsFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = gameStats.begin(); it != gameStats.end(); it++) {
            f << "Game ID: " << (*it)->getId() << endl;
            f << "Goals: " << (*it)->getGoals() << endl;
            f << "Opposing team goals: " << (*it)->getOppositionGoals() << endl;
            f << "Shots: " << (*it)->getShots() << endl;
            f << "Opposing team shots: " << (*it)->getOppositionShots() << endl;
            f << "Shots on target: " << (*it)->getShotsTarget() << endl;
            f << "Opposing team shots on target: " << (*it)->getOppositionShotsTarget() << endl;
            f << "Possession: " << (*it)->getPossession() << endl;
            f << "Passes: " << (*it)->getPasses() << endl;
            f << "Opposing team passes: " << (*it)->getOppositionPasses() << endl;
            f << "Pass accuracy: " << (*it)->getPassAccuracy() << endl;
            f << "Opposing team pass accuracy: " << (*it)->getOppositionPassAccuracy() << endl;
            f << "Fouls: " << (*it)->getFouls() << endl;
            f << "Opposing team fouls: " << (*it)->getOppositionFouls() << endl;
            f << "Yellow cards: " << (*it)->getYellowCards() << endl;
            f << "Opposing team yellow cards: " << (*it)->getOppositionYellowCards() << endl;
            f << "Red cards: " << (*it)->getRedCards() << endl;
            f << "Opposing team red cards: " << (*it)->getOppositionRedCards() << endl;
            f << "Offsides: " << (*it)->getOffsides() << endl;
            f << "Opposing team offsides: " << (*it)->getOppositionOffsides() << endl;
            f << "Corners: " << (*it)->getCorners() << endl;
            f << "Opposing team corners: " << (*it)->getOppositionCorners() << endl;
            f << "Injuries: " << (*it)->getInjuries() << endl;
            f << "Opposing team injuries: " << (*it)->getOppositionInjuries();

            if (it != gameStats.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeGamesFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = games.begin(); it != games.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Date: " << (*it)->getDate() << endl;
            f << "City: " << (*it)->getCity() << endl;
            f << "Country: " << (*it)->getCountry() << endl;
            f << "Stadium: " << (*it)->getStadium() << endl;
            f << "Opposite Team: " << (*it)->getOppositeTeam() << endl;
            f << "Opposite Team Participants: " << generalFunctions::coutVectorString((*it)->getOppositeTeamParticipants()) << endl;
            f << "Refereeing Team: " << generalFunctions::coutVectorString((*it)->getRefereeTeam()) << endl;
            f << "Game Statistics: " << (*it)->getGameStats()->getId() << endl;
            f << "Individual Statistics: ";
            vector<string> individualStatsVectorString;
            vector<IndividualStatistics*> individualStatistics = (*it)->getIndividualStatistics();
            for (auto it = individualStatistics.begin(); it != individualStatistics.end(); it++) {
                individualStatsVectorString.push_back(to_string((*it)->getId()));
            }
            f << generalFunctions::coutVectorString(individualStatsVectorString);
            individualStatistics.clear();
            individualStatsVectorString.clear();

            if (it != games.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeTechnicalTeamFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = technicalTeam.begin(); it != technicalTeam.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Name: " << (*it)->getName() << endl;
            f << "Birth Date: " << (*it)->getDate() << endl;
            f << "Function: " << (*it)->getRole() << endl;
            f << "Salary: " << (*it)->getSalary();
            if (it != technicalTeam.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeCallsFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = calls.begin(); it != calls.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Competition: " << (*it)->getCompetition() << endl;
            f << "Begin Date: " << (*it)->getBeginDate() << endl;
            f << "End Date: " << (*it)->getEndDate() << endl;
            f << "House-Food: " << (*it)->getHousingFood() << endl;
            f << "Games: ";
            vector<Game*> gamesVector = (*it)->getGames();
            vector<string> gamesVectorString;
            for (auto it = gamesVector.begin(); it != gamesVector.end(); it++) {
                gamesVectorString.push_back(to_string((*it)->getId()));
            }
            f << generalFunctions::coutVectorString(gamesVectorString);
            gamesVector.clear();
            gamesVectorString.clear();
            f << endl << "PlayersID: ";
            vector<SoccerPlayer*> soccerPlayersVector = (*it)->getPlayers();
            vector<string> soccerPlayersVectorString;
            for (auto it = soccerPlayersVector.begin(); it != soccerPlayersVector.end(); it++) {
                soccerPlayersVectorString.push_back(to_string((*it)->getId()));
            }
            f << generalFunctions::coutVectorString(soccerPlayersVectorString);
            soccerPlayersVector.clear();
            soccerPlayersVectorString.clear();
            f << endl << "InfCalls: ";
            vector<InfCall*> infCallsVector = (*it)->getInfs();
            vector<string> infCallsVectorString;
            for (auto it = infCallsVector.begin(); it != infCallsVector.end(); it++) {
                infCallsVectorString.push_back(to_string((*it)->getId()));
            }
            f << generalFunctions::coutVectorString(infCallsVectorString);
            infCallsVector.clear();
            infCallsVectorString.clear();

            if (it != calls.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeInfCallsFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    if (f.is_open()) {
        for (auto it = infCalls.begin(); it != infCalls.end(); it++) {
            f << "ID: " << (*it)->getId() << endl;
            f << "Player ID: " << (*it)->getSoccerPlayerId() << endl;
            f << "Arrived Date: " << (*it)->getDateArrived() << endl;
            f << "Left Date: " << (*it)->getDateLeft();
            if (it != infCalls.end() - 1)
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

vector<Call*> NationalTeam::playerCalls(SoccerPlayer* sP) {
    vector<Call*> result;
    for (auto it = calls.begin(); it!= calls.end(); it++) {
        if (generalFunctions::inVector((*it)->getPlayers(), sP))
            result.push_back(*it);
    }
    return result;
}

void NationalTeam::playerCallsForMenu() {
    SoccerPlayer* sP = workerLookUp(players);
    if(sP == NULL)
        return;
    vector<Call*> playerCallsVector = playerCalls(sP);
    if(playerCallsVector.empty())
    {
        cout << "Player didn't Participated in any Summon\\'s." << endl;
        return;
    }
    cout << endl << endl << "Calls: " << endl << endl;
    for (auto it = playerCallsVector.begin(); it != playerCallsVector.end(); it++) {
        (*it)->info();
    }
}


vector<Game *> NationalTeam::playerGames(SoccerPlayer* sP, Call* call) {
    vector<Game*> result;
    vector<Game*> callGames = call->getGames();
    vector<IndividualStatistics*> indStats;
    for (auto it = callGames.begin(); it != callGames.end(); it++) {
        indStats = (*it)->getIndividualStatistics();
        for (auto itr = indStats.begin(); itr != indStats.end(); itr++) {
            if ((*itr)->getSoccerPlayerID() == sP->getId()) {
                result.push_back(*it);
                break;
            }
        }
        indStats.clear();
    }
    return result;
}

void NationalTeam::playerGamesForMenu() {
    SoccerPlayer* sP = workerLookUp(players);
    if(sP == NULL)
        return;
    cout << endl << endl;
    Call* call = callLookUp();
    if(call == NULL)
        return;
    cout << endl << endl << "Games:" << endl << endl;
    vector<Game*> gamesVector = playerGames(sP, call);
    if(gamesVector.empty())
    {
        cout << "Player didn't Participated in this Summon." << endl;
        return;
    }
    for (auto it = gamesVector.begin(); it != gamesVector.end(); it++) {
        (*it)->info(cout);
    }
}

void NationalTeam::showCallStats() {
    Call* call = callLookUp();
    if(call == NULL)
        return;
    vector<Game*> callGames = call->getGames();
    unsigned short goals = 0, shots = 0, shotsTarget = 0, possession = 0, passes = 0, passAccuracy = 0, fouls = 0,
    offsides = 0, corners = 0, yellowCards = 0, redCards = 0, injuries = 0;
    GameStats* stat;
    for (auto it = callGames.begin(); it != callGames.end(); it++) {
        stat = (*it)->getGameStats();
        goals += stat->getGoals();
        shots += stat->getShots();
        shotsTarget += stat->getShotsTarget();
        possession += stat->getPossession();
        passes += stat->getPasses();
        passAccuracy += stat->getPassAccuracy();
        fouls += stat->getFouls();
        offsides += stat->getOffsides();
        corners += stat->getCorners();
        yellowCards += stat->getYellowCards();
        redCards += stat->getRedCards();
        injuries += stat->getInjuries();
    }
    possession /= callGames.size();
    passAccuracy /= callGames.size();

    cout << endl << endl << "Statistics of the call:" << endl << endl;
    cout << "Goals: " << goals << endl;
    cout << "Shots: " << shots << endl;
    cout << "Shots on Target: " << shotsTarget << endl;
    cout << "Average Possession: " << possession << endl;
    cout << "Passes: " << passes << endl;
    cout << "Average Passe Accuracy: " << passAccuracy << endl;
    cout << "Fouls: " << fouls << endl;
    cout << "Offsides: " << offsides << endl;
    cout << "Corners: " << corners << endl;
    cout << "Yellow Cards: " << yellowCards << endl;
    cout << "Red Cards: " << redCards << endl;
    cout << "Injuries: " << injuries << endl << endl;
}

void NationalTeam::showGlobalStats() {

    vector<Game*> callGames;
    unsigned short goals = 0, shots = 0, shotsTarget = 0, possession = 0, passes = 0, passAccuracy = 0, fouls = 0,
            offsides = 0, corners = 0, yellowCards = 0, redCards = 0, injuries = 0;
    GameStats* stat;
    unsigned int countGames = 0;
    for (auto itr = calls.begin(); itr != calls.end(); itr++) {
        callGames = (*itr)->getGames();
        countGames += callGames.size();
        for (auto it = callGames.begin(); it != callGames.end(); it++) {
            stat = (*it)->getGameStats();
            goals += stat->getGoals();
            shots += stat->getShots();
            shotsTarget += stat->getShotsTarget();
            possession += stat->getPossession();
            passes += stat->getPasses();
            passAccuracy += stat->getPassAccuracy();
            fouls += stat->getFouls();
            offsides += stat->getOffsides();
            corners += stat->getCorners();
            yellowCards += stat->getYellowCards();
            redCards += stat->getRedCards();
            injuries += stat->getInjuries();
        }
        callGames.clear();
    }

    possession /= countGames;
    passAccuracy /= countGames;

    cout << endl << endl << "Global Statiscs:" << endl << endl;
    cout << "Goals: " << goals << endl;
    cout << "Shots: " << shots << endl;
    cout << "Shots on Target: " << shotsTarget << endl;
    cout << "Average Possession: " << possession << endl;
    cout << "Passes: " << passes << endl;
    cout << "Average Passe Accuracy: " << passAccuracy << endl;
    cout << "Fouls: " << fouls << endl;
    cout << "Offsides: " << offsides << endl;
    cout << "Corners: " << corners << endl;
    cout << "Yellow Cards: " << yellowCards << endl;
    cout << "Red Cards: " << redCards << endl;
    cout << "Injuries: " << injuries << endl << endl;
}


/* Costs */


bool sortPerDate(const Call* call1, const Call* call2)
{
    Date d1 = call1->getBeginDate();
    Date d2 = call2->getBeginDate();
    return !(d1 <= d2);
}

void NationalTeam::getPlayerTotalCost()
{
    SoccerPlayer* sP = workerLookUp(players);
    unsigned int daysActive = sP->getDaysActive();
    unsigned int salary = 0, days;
    bool flagInjured;
    sort(calls.begin(), calls.end(), sortPerDate); /* Order Calls from the last to the first */
    for(auto &call: calls)
    {
        sort(call->getPlayers().begin(), call->getPlayers().end(), sortPlayers);
        if(binary_search(call->getPlayers().begin(), call->getPlayers().end(), sP, sortPlayers))
        {
            flagInjured = false;
            days = generalFunctions::getDays(call->getBeginDate(), call->getEndDate());
            sP->setDaysActive(sP->getDaysActive() - days);
            salary += sP->getSalary() * days;
            for(auto &game: call->getGames())
            {
                for(auto stats: game->getIndividualStatistics())
                {
                    if(stats->getSoccerPlayerID() == sP->getId())
                    {
                        flagInjured = stats->getInjured();
                        if(flagInjured)
                        {
                            salary *= 3; /* Triplica o valor */
                            break;
                        }
                    }
                }
                if(flagInjured)
                    break;
            }
            salary += call->getHousingFood();
        }
    }
    sP->setDaysActive(daysActive); // Repõem os DaysActive
    cout << endl << "Global Costs of " << sP->getName() << " Was " << salary << " euros" << endl;
}

unsigned int NationalTeam::getTeamTotalCost()
{

    unsigned int salary = 0, days, daysActive, totalSalaries = 0;
    bool flagInjured;
    sort(calls.begin(), calls.end(), sortPerDate); /* Order Calls from the last to the first */
    for(auto &sP: players)
    {
        daysActive = sP->getDaysActive();
        salary = 0;
        for(auto &call: calls)
        {
            sort(call->getPlayers().begin(), call->getPlayers().end(), sortPlayers);
            if(binary_search(call->getPlayers().begin(), call->getPlayers().end(), sP, sortPlayers))
            {
                flagInjured = false;
                days = generalFunctions::getDays(call->getBeginDate(), call->getEndDate());
                sP->setDaysActive(sP->getDaysActive() - days);
                salary += sP->getSalary() * days;
                for(auto &game: call->getGames())
                {
                    for(auto stats: game->getIndividualStatistics())
                    {
                        if(stats->getSoccerPlayerID() == sP->getId())
                        {
                            flagInjured = stats->getInjured();
                            if(flagInjured)
                            {
                                salary *= 3; /* Triplica o valor */
                                break;
                            }
                        }
                    }
                    if(flagInjured)
                        break;
                }
                salary += call->getHousingFood();
            }
        }
        sP->setDaysActive(daysActive); // Repõem os DaysActive
        totalSalaries += salary;
    }

//    cout << endl << "Global Costs of the Entire Team Was " << totalSalaries << " euros" << endl;
    return totalSalaries;
}

void NationalTeam::getNationalTeamTotalCost()
{
    unsigned int totalCosts = getTeamTotalCost();
    /* Calls already ordered */
    Date firstCall = calls.at(calls.size() - 1)->getBeginDate();
    Date lastCall = calls.at(0)->getEndDate();
    unsigned int yearDiff = lastCall.getYear() - firstCall.getYear();
    unsigned int monthsPassed;
    if(yearDiff == 0)
        monthsPassed = lastCall.getMonth() - firstCall.getMonth() + 1; // Including the first month
    else
        monthsPassed = 12 - firstCall.getMonth() + lastCall.getMonth() + 1; // Including the first month
//    cout << endl << monthsPassed << endl;
    for(auto &x: otherWorkers)
        totalCosts += monthsPassed * x->getSalary();
    for(auto &x: technicalTeam)
        totalCosts += monthsPassed * x->getSalary();
    cout << endl << "Total Money Spent Was " << totalCosts << " euros" << endl;
}

void NationalTeam::getMonthlyPlayerTotalCost()
{
    unsigned int year = readOperations::readNumber<unsigned int>("Year:");
    unsigned int month;
    while(true)
    {
        month = readOperations::readNumber<unsigned int>("Month (1 - 12):");
        if(month < 1 || month > 12)
            cout << endl << "Month Should Be Between 1 and 12." << endl;
        else
            break;
    }
    SoccerPlayer* sP = workerLookUp(players);
    unsigned int daysActive = sP->getDaysActive();
    unsigned int salary = 0, days;
    bool flagInjured;
    sort(calls.begin(), calls.end(), sortPerDate); /* Order Calls from the last to the first */
    for(auto &call: calls)
    {
        sort(call->getPlayers().begin(), call->getPlayers().end(), sortPlayers);
        if(binary_search(call->getPlayers().begin(), call->getPlayers().end(), sP, sortPlayers))
        {
            flagInjured = false;
            days = generalFunctions::getDays(call->getBeginDate(), call->getEndDate());
            sP->setDaysActive(sP->getDaysActive() - days);

            if(call->getBeginDate().getMonth() == month && call->getBeginDate().getYear() == year)
            {
                salary += sP->getSalary() * days;
                for(auto &game: call->getGames())
                {
                    for(auto stats: game->getIndividualStatistics())
                    {
                        if(stats->getSoccerPlayerID() == sP->getId())
                        {
                            flagInjured = stats->getInjured();
                            if(flagInjured)
                            {
                                salary *= 3; /* Triplica o valor */
                                break;
                            }
                        }
                    }
                    if(flagInjured)
                        break;
                }
                salary += call->getHousingFood();
            }
        }
    }
    sP->setDaysActive(daysActive); // Repõem os DaysActive
    cout << endl << "Global Costs of " << sP->getName() << " Was " << salary << " euros" << endl;

}

void NationalTeam::getMonthlyTeamTotalCost()
{
    unsigned int year = readOperations::readNumber<unsigned int>("Year:");
    unsigned int month;
    while(true)
    {
        month = readOperations::readNumber<unsigned int>("Month (1 - 12):");
        if(month < 1 || month > 12)
            cout << endl << "Month Should Be Between 1 and 12." << endl;
        else
            break;
    }
    unsigned int salary = 0, days, daysActive, totalSalaries = 0;
    bool flagInjured;
    sort(calls.begin(), calls.end(), sortPerDate); /* Order Calls from the last to the first */
    for(auto &sP: players)
    {
        daysActive = sP->getDaysActive();
        salary = 0;
        for(auto &call: calls)
        {
            sort(call->getPlayers().begin(), call->getPlayers().end(), sortPlayers);
            if(binary_search(call->getPlayers().begin(), call->getPlayers().end(), sP, sortPlayers))
            {
                flagInjured = false;
                days = generalFunctions::getDays(call->getBeginDate(), call->getEndDate());
                sP->setDaysActive(sP->getDaysActive() - days);
                if(call->getBeginDate().getMonth() == month && call->getBeginDate().getYear() == year)
                {
                    salary += sP->getSalary() * days;
                    for(auto &game: call->getGames())
                    {
                        for(auto stats: game->getIndividualStatistics())
                        {
                            if(stats->getSoccerPlayerID() == sP->getId())
                            {
                                flagInjured = stats->getInjured();
                                if(flagInjured)
                                {
                                    salary *= 3; /* Triplica o valor */
                                    break;
                                }
                            }
                        }
                        if(flagInjured)
                            break;
                    }
                    salary += call->getHousingFood();
                }
            }
        }
        sP->setDaysActive(daysActive); // Repõem os DaysActive
        totalSalaries += salary;
    }

    cout << endl << "Global Costs of the Entire Team Was " << totalSalaries << " euros" << endl;
}

void NationalTeam::getMonthlyNationalTeamTotalCost()
{
    unsigned int year = readOperations::readNumber<unsigned int>("Year:");
    unsigned int month;
    while(true)
    {
        month = readOperations::readNumber<unsigned int>("Month (1 - 12):");
        if(month < 1 || month > 12)
            cout << endl << "Month Should Be Between 1 and 12." << endl;
        else
            break;
    }
    unsigned int salary = 0, days, daysActive, totalSalaries = 0;
    bool flagInjured;
    sort(calls.begin(), calls.end(), sortPerDate); /* Order Calls from the last to the first */
    for(auto &sP: players)
    {
        daysActive = sP->getDaysActive();
        salary = 0;
        for(auto &call: calls)
        {
            sort(call->getPlayers().begin(), call->getPlayers().end(), sortPlayers);
            if(binary_search(call->getPlayers().begin(), call->getPlayers().end(), sP, sortPlayers))
            {
                flagInjured = false;
                days = generalFunctions::getDays(call->getBeginDate(), call->getEndDate());
                sP->setDaysActive(sP->getDaysActive() - days);
                if(call->getBeginDate().getMonth() == month && call->getBeginDate().getYear() == year)
                {
                    salary += sP->getSalary() * days;
                    for(auto &game: call->getGames())
                    {
                        for(auto stats: game->getIndividualStatistics())
                        {
                            if(stats->getSoccerPlayerID() == sP->getId())
                            {
                                flagInjured = stats->getInjured();
                                if(flagInjured)
                                {
                                    salary *= 3; /* Triplica o valor */
                                    break;
                                }
                            }
                        }
                        if(flagInjured)
                            break;
                    }
                    salary += call->getHousingFood();
                }
            }
        }
        sP->setDaysActive(daysActive); // Repõem os DaysActive
        totalSalaries += salary;
    }
    cout << totalSalaries << endl;
    /* 1 Month each */
    for(auto &x: otherWorkers)
        totalSalaries += x->getSalary();
    for(auto &x: technicalTeam)
        totalSalaries += x->getSalary();
    cout << endl << "Total Money Spent Was " << totalSalaries << " euros" << endl;
}

void NationalTeam::showPlayerGlobalStats() {
    SoccerPlayer* sP = workerLookUp(players);
    if(sP == NULL)
        return;
    unsigned short goals = 0, assists = 0, shots = 0, shotsTarget = 0, passes = 0, travelledDistance = 0, playedMinutes = 0,
            yellowCards = 0, redCards = 0, injuries = 0, fouls = 0;
    for (auto it = individualStats.begin(); it != individualStats.end(); it++) {
        if ((*it)->getSoccerPlayerID() == sP->getId()) {
            goals += (*it)->getGoals();
            assists += (*it)->getAssists();
            shots += (*it)->getShots();
            shotsTarget += (*it)->getShotsTarget();
            passes += (*it)->getPasses();
            travelledDistance += (*it)->getTravelledDistance();
            playedMinutes += (*it)->getPlayedMinutes();
            yellowCards += (*it)->getYellowCards();
            redCards += (*it)->getRedCards();
            fouls += (*it)->getFouls();
            if ((*it)->getInjured())
                injuries++;
        }
    }
    cout << endl << endl;
    cout << "Goals: " << goals << endl;
    cout << "Assists: " << assists << endl;
    cout << "Shots: " << shots << endl;
    cout << "Shots on Target: " << shotsTarget << endl;
    cout << "Passes: " << passes << endl;
    cout << "Travelled Distance: " << travelledDistance << endl;
    cout << "Played Minutes: " << playedMinutes << endl;
    cout << "Yellow Cards: " << yellowCards << endl;
    cout << "Red Cards: " << redCards << endl;
    cout << "Fouls: " << fouls << endl;
    cout << "Injuries: " << injuries << endl << endl;
}

void NationalTeam::showPlayerCallStats() {
    SoccerPlayer* sP = workerLookUp(players);
    if(sP == NULL)
        return;
    Call* call = callLookUp();
    if(call == NULL)
        return;
    if(call->getGames().empty())
    {
        cout << endl << "No Statistics to Show..." << endl << endl;
        return;
    }
    vector<Game*> callGames = call->getGames();
    vector<IndividualStatistics*> individualStatsVector;
    unsigned short goals = 0, assists = 0, shots = 0, shotsTarget = 0, passes = 0, travelledDistance = 0, playedMinutes = 0,
            yellowCards = 0, redCards = 0, injuries = 0, fouls = 0;
    for (auto it = callGames.begin(); it != callGames.end(); it++) {
        individualStatsVector = (*it)->getIndividualStatistics();
        for (auto itr = individualStatsVector.begin(); itr != individualStatsVector.end(); itr++) {
            if ((*itr)->getSoccerPlayerID() == (sP)->getId()) {
                goals += (*itr)->getGoals();
                assists += (*itr)->getAssists();
                shots += (*itr)->getShots();
                shotsTarget += (*itr)->getShotsTarget();
                passes += (*itr)->getPasses();
                travelledDistance += (*itr)->getTravelledDistance();
                playedMinutes += (*itr)->getPlayedMinutes();
                yellowCards += (*itr)->getYellowCards();
                redCards += (*itr)->getRedCards();
                fouls += (*itr)->getFouls();
                if ((*itr)->getInjured())
                    injuries++;
            }
        }
        individualStatsVector.clear();
    }
    cout << endl << endl;
    cout << "Goals: " << goals << endl;
    cout << "Assists: " << assists << endl;
    cout << "Shots: " << shots << endl;
    cout << "Shots on Target: " << shotsTarget << endl;
    cout << "Passes: " << passes << endl;
    cout << "Travelled Distance: " << travelledDistance << endl;
    cout << "Played Minutes: " << playedMinutes << endl;
    cout << "Yellow Cards: " << yellowCards << endl;
    cout << "Red Cards: " << redCards << endl;
    cout << "Fouls: " << fouls << endl;
    cout << "Injuries: " << injuries << endl << endl;
}



NationalTeam::~NationalTeam()
{
    writeCoachesFile("../Files/Coaches.txt");
    writeTechnicalTeamFile("../Files/TechnicalTeam.txt");
    writeOtherWorkersFile("../Files/OtherWorkers.txt");
    writeSoccerPlayersFile("../Files/SoccerPlayers.txt");
    writeGamesStatisticsFile("../Files/GameStatistics.txt");
    writeIndividualStatisticsFile("../Files/IndividualStatistics.txt");
    writeGamesFile("../Files/Games.txt");
    writeInfCallsFile("../Files/InfCalls.txt");
    writeCallsFile("../Files/Calls.txt");
    writeStaffHashTableFile("../Files/StaffHashTable.txt");
    //writeProviderFile("../Files/Providers.txt");
    writeEquipmentsFile("../Files/Equipment.txt");

    /* Vector Destruction */
    auxiliaryDestructor(technicalTeam);
    auxiliaryDestructor(otherWorkers);
    auxiliaryDestructor(players);
    auxiliaryDestructor(gameStats);
    auxiliaryDestructor(individualStats);
    auxiliaryDestructor(games);
    auxiliaryDestructor(infCalls);
    auxiliaryDestructor(calls);
}

void NationalTeam::showNumberOfVictoriesDrawsLoses() {
    unsigned int victories = 0, draws = 0, loses = 0;
    for (auto it = gameStats.begin(); it != gameStats.end(); it++) {
        if ((*it)->getGoals() > (*it)->getOppositionGoals())
            victories++;
        else if ((*it)->getGoals() < (*it)->getOppositionGoals())
            loses++;
        else
            draws++;
    }
    cout << endl << endl << "Victories: " << victories << endl;
    cout << "Draws: " << draws << endl;
    cout << "Losses: " << loses << endl << endl;
}

void NationalTeam::topScorer() {
    unsigned int goals = 0;
    SoccerPlayer* sP = players.at(0);
    vector<pair<SoccerPlayer*,unsigned int>> v;
    pair<SoccerPlayer*,unsigned int> p;
    for (auto it = players.begin(); it != players.end(); it++) {
        goals = 0;
        for (auto itr = individualStats.begin(); itr != individualStats.end(); itr++) {
            if ((*it)->getId() == (*itr)->getSoccerPlayerID())
                goals += (*itr)->getGoals();
        }
        p.first = (*it);
        p.second = goals;
        v.push_back(p);
    }
    unsigned int topGoals = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if ((*it).second > topGoals)
            topGoals = (*it).second;
    }
    for (auto it = v.begin(); it != v.end(); it++) {
        if ((*it).second == topGoals)
            sP = (*it).first;
    }

    cout << endl << endl << "The top scorer is: " << sP->getName() << endl <<
        endl << "Goals: " << topGoals << endl << endl;
}

// HASH TABLE

void NationalTeam::addStaffToHashTable(const Staff &staff) {
    allTimeStaff.insert(staff);
}

void NationalTeam::addTechnicalTeamMemberToHashTable(TechnicalTeam member) {
    Staff staff(member.getId(), member.getName(), member.getDate(), member.getSalary(), member.getRole());
    addStaffToHashTable(staff);
}

void NationalTeam::addOtherWorkerToHashTable(OtherWorker otherWorker) {
    Staff staff(otherWorker.getId(), otherWorker.getName(), otherWorker.getDate(), otherWorker.getSalary(), otherWorker.getRole());
    addStaffToHashTable(staff);
}

void NationalTeam::addAllTheStaffToHashTable() { // com exceção de SoccerPlayers
    for (auto it = otherWorkers.begin(); it != otherWorkers.end(); it++) {
        addOtherWorkerToHashTable(**it);
    }
    for (auto it = technicalTeam.begin(); it != technicalTeam.end(); it++) {
        addTechnicalTeamMemberToHashTable(**it);
    }
}

bool NationalTeam::writeStaffHashTableFile(string filename) {
    ofstream f;
    f.open(filename, ios::out);
    int counter = 0;
    if (f.is_open()) {
        for (auto it = allTimeStaff.begin(); it != allTimeStaff.end(); it++) {
            counter++;
            f << "ID: " << it->getId() << endl;
            f << "Name: " << it->getName() << endl;
            f << "Birth Date: " << it->getDate() << endl;
            f << "Function: " << it->getRole() << endl;
            f << "Salary: " << it->getSalary();
            if (counter != allTimeStaff.size())
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::readStaffHashTableFile(string filename) {
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

            Staff staff(id, name, birthday, salary, function);
            addStaffToHashTable(staff);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

bool staffInOtherWorkersVector(const Staff &staff, vector<OtherWorker*> otherWorkers) {
    for (auto it = otherWorkers.begin(); it != otherWorkers.end(); it++) {
        if ((*it)->getId() == staff.getId())
            return true;
    }
    return false;
}

bool staffInTechnicalTeamVector(const Staff &staff, vector<TechnicalTeam*> technicalTeam) {
    for (auto it = technicalTeam.begin(); it != technicalTeam.end(); it++) {
        if ((*it)->getId() == staff.getId())
            return true;
    }
    return false;
}

vector<Staff> NationalTeam::getOldStaff() const {
    vector<Staff> result;
    for (auto it = allTimeStaff.begin(); it != allTimeStaff.end(); it++) {
        if (it->getId() >= 200 && it->getId() < 1500) { // otherWorker
            if (!staffInOtherWorkersVector(*it, otherWorkers))
                result.push_back(*it);
        }
        else if (it->getId() >= 1500) { // technicalTeam
            if (!staffInTechnicalTeamVector(*it, technicalTeam))
                result.push_back(*it);
        }
    }
    return result;
}

void NationalTeam::displayOldStaff() const {
    vector<Staff> staffVector = getOldStaff();
    int counter = 0;
    for (auto it = staffVector.begin(); it != staffVector.end(); it++) {
        counter++;
        cout << "ID: " << it->getId() << endl;
        cout << "Name: " << it->getName() << endl;
        cout << "Birth Date: " << it->getDate() << endl;
        cout << "Function: " << it->getRole() << endl;
        cout << "Salary: " << it->getSalary();
        if (counter != staffVector.size())
            cout << endl << endl << "::::::::::" << endl << endl;
    }
}

Staff NationalTeam::searchOldStaff() const {

    vector<Staff> oldStaffVector = getOldStaff();
    vector<Staff> technicalTeamStaff;
    vector<Staff> otherWorkersStaff;

    for (auto it = oldStaffVector.begin(); it != oldStaffVector.end(); it++) {
        if (it->getId() >= 200 && it->getId() < 1500)
            otherWorkersStaff.push_back(*it);
        else if (it->getId() >= 1500)
            technicalTeamStaff.push_back(*it);
    }

    int option = 0;
    Date auxDate(1,1,1);
    Staff auxStaff(0, "", auxDate, 0, "");

    vector<Staff> auxPerson;
    bool ct = false;

    while (true) {
        string type = readOperations::readString(
                "Do you want to look for a technical team member or other worker? (tt / ow) ");
        std::transform(type.begin(), type.end(), type.begin(), ::toupper); // Convert to uppercase
        if (type == "TT") {
            auxPerson.clear();
            ct = false;
            cout << endl << "Look for a Technical Team member using: " << endl;
            cout << "1. Name\n2. Birth Date\n3. Function\n4. Salary\n5. ID\n0. Back\n\n";
            cin >> option;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << endl;
            switch (option) {
                case 0:
                    return auxStaff;

                case 1: {
                    // Name
                    std::string name = readOperations::readString("Name:");
                    std::transform(name.begin(), name.end(), name.begin(), ::toupper); // Convert to uppercase

                    std::string memberName;

                    for (auto &x: technicalTeamStaff) {
                        memberName = x.getName();
                        std::transform(memberName.begin(), memberName.end(), memberName.begin(), ::toupper); // Convert to uppercase
                        if (memberName.find(name) != std::string::npos) {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }
                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }


                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: technicalTeamStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 2: {
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

                    for(auto &x: technicalTeamStaff)
                    {
                        if(generalFunctions::checkBetweenDates(dBirth1, x.getDate(), dBirth2))
                        {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }
                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }


                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: technicalTeamStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 3: {
                    // Function
                    std::string function = readOperations::readString("Function:");
                    std::transform(function.begin(), function.end(), function.begin(), ::toupper); // Convert to uppercase

                    std::string memberFunction;

                    for (auto &x: technicalTeamStaff) {
                        memberFunction = x.getRole();
                        std::transform(memberFunction.begin(), memberFunction.end(), memberFunction.begin(), ::toupper); // Convert to uppercase
                        if (memberFunction.find(function) != std::string::npos) {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }
                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }


                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: technicalTeamStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 4: {
                    // Salary
                    float smallerSalary, biggerSalary;
                    do
                    {
                        smallerSalary = readOperations::readNumber<float>("Smaller Salary:");
                        biggerSalary = readOperations::readNumber<float>("Bigger Salary:");
                        if(smallerSalary > biggerSalary)
                            std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl << std::endl;
                    } while(smallerSalary > biggerSalary);


                    for(auto &x: technicalTeamStaff)
                    {
                        if(x.getSalary() >= smallerSalary && x.getSalary() <= biggerSalary)
                        {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }

                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }

                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: technicalTeamStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 5: {
                    // ID
                    int id = readOperations::readNumber<int>("ID: ");

                    try {
                        cin >> id;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for (auto &x: technicalTeamStaff) {
                            if (x.getId() == id)
                                return x;
                        }
                        throw NoObjectFound("No Corresponding Person Found...");
                    }
                    catch (NoObjectFound &e) {
                        cout << endl << e.getError() << endl << endl;
                    }

                    break;
                }


            }


            break;
        }
        if (type == "OW") {
            auxPerson.clear();
            ct = false;
            cout << endl << "Look for Other Worker member using: " << endl;
            cout << "1. Name\n2. Birth Date\n3. Function\n4. Salary\n5. ID\n0. Back\n\n";
            cin >> option;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << endl;
            switch (option) {
                case 0:
                    return auxStaff;

                case 1: {
                    // Name
                    std::string name = readOperations::readString("Name:");
                    std::transform(name.begin(), name.end(), name.begin(), ::toupper); // Convert to uppercase

                    std::string memberName;

                    for (auto &x: otherWorkersStaff) {
                        memberName = x.getName();
                        std::transform(memberName.begin(), memberName.end(), memberName.begin(), ::toupper); // Convert to uppercase
                        if (memberName.find(name) != std::string::npos) {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }
                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }


                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: otherWorkersStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 2: {
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

                    for(auto &x: otherWorkersStaff)
                    {
                        if(generalFunctions::checkBetweenDates(dBirth1, x.getDate(), dBirth2))
                        {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }
                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }


                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: otherWorkersStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 3: {
                    // Function
                    std::string function = readOperations::readString("Function:");
                    std::transform(function.begin(), function.end(), function.begin(), ::toupper); // Convert to uppercase

                    std::string memberFunction;

                    for (auto &x: otherWorkersStaff) {
                        memberFunction = x.getRole();
                        std::transform(memberFunction.begin(), memberFunction.end(), memberFunction.begin(), ::toupper); // Convert to uppercase
                        if (memberFunction.find(function) != std::string::npos) {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }
                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }


                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: otherWorkersStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 4: {
                    // Salary
                    float smallerSalary, biggerSalary;
                    do
                    {
                        smallerSalary = readOperations::readNumber<float>("Smaller Salary:");
                        biggerSalary = readOperations::readNumber<float>("Bigger Salary:");
                        if(smallerSalary > biggerSalary)
                            std::cout << "First Date Has To Be Less Than or Equal To The Second! Try again..." << std::endl << std::endl;
                    } while(smallerSalary > biggerSalary);


                    for(auto &x: otherWorkersStaff)
                    {
                        if(x.getSalary() >= smallerSalary && x.getSalary() <= biggerSalary)
                        {
                            auxPerson.push_back(x);
                            ct = true;
                        }
                    }

                    if (!auxPerson.empty()) {
                        for (auto &x: auxPerson) {
                            cout << "ID: " << x.getId() << endl;
                            cout << "Name: " << x.getName() << endl;
                            cout << "Birth Date: " << x.getDate() << endl;
                            cout << "Function: " << x.getRole() << endl;
                            cout << "Salary: " << x.getSalary();
                            cout << endl << endl;
                        }
                    }

                    if (ct) {
                        cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << endl << endl;
                        try {
                            cin >> option;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            for (auto &x: otherWorkersStaff) {
                                if (x.getId() == option)
                                    return x;
                            }
                            throw NoObjectFound("No Corresponding Person Found...");
                        }
                        catch (NoObjectFound &e) {
                            cout << endl << e.getError() << endl << endl;
                        }
                    } else
                        cout << endl << "No Corresponding Person Found..." << endl << endl;
                    break;
                }
                case 5: {
                    // ID
                    int id = readOperations::readNumber<int>("ID: ");

                    try {
                        cin >> id;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for (auto &x: otherWorkersStaff) {
                            if (x.getId() == id)
                                return x;
                        }
                        throw NoObjectFound("No Corresponding Person Found...");
                    }
                    catch (NoObjectFound &e) {
                        cout << endl << e.getError() << endl << endl;
                    }

                    break;
                }


            }



            break;
        }
        cout << "\nOption not valid!\n";
    }
    return auxStaff;

}

void NationalTeam::hireOldStaff() {
    Staff hiredMember = searchOldStaff();
    if (hiredMember.getId() == 0)
        return;

    if (hiredMember.getId() > 1500) { // technical team member
        TechnicalTeam* hiredTechnicalTeamMemer = new TechnicalTeam(hiredMember.getId(), hiredMember.getRole(), hiredMember.getSalary(), hiredMember.getName(), hiredMember.getDate());
        addTechnicalTeamMember(hiredTechnicalTeamMemer);
        cout << "\n\nTechnical Team Member hired successfully!\n\n";
        return;

    }
    else if (hiredMember.getId() >= 200 && hiredMember.getId() < 1500) {
        OtherWorker* hiredWorker = new OtherWorker(hiredMember.getId(), hiredMember.getRole(), hiredMember.getSalary(), hiredMember.getName(), hiredMember.getDate());
        addOtherWorker(hiredWorker);
        cout << "\n\nOther Worker hired successfully!\n\n";
        return;
    }

    cerr << "\n\nUnable to hire the employee!\n\n";
}

void NationalTeam::addCoach()
{
    cout << endl;
    string auxName = readOperations::readString("Coach Name:");
    unsigned int auxCupsWon = readOperations::readNumber<unsigned int>("Cups Won:");
    Coach toAdd(auxName, auxCupsWon, std::list<std::pair<std::string, Interval>>());

    unsigned int numTrain = readOperations::readNumber<unsigned int>("Number of Trained Teams:");

    for(int i = 0; i < numTrain; i++)
    {
        string team = readOperations::readString("Team:");
        Date begin;
        Date end;
        while(true)
        {
            begin = readOperations::readDate("Begin Date:");
            end = readOperations::readDate("End Date:");
            if(begin <= end)
                break;
        }
        toAdd.addTrainedTeam(pair<string, Interval>(team, Interval(begin, end)));
    }

    if(coachList.insert(toAdd))
        cout << "Coach successfully inserted." << endl;
    else
        cout << "Info not added. We have located data conflits!" << endl;
}

void NationalTeam::deleteCoach()
{
    cout << endl;
    string auxName = readOperations::readString("Coach Name:");
    unsigned int auxCupsWon = readOperations::readNumber<unsigned int>("Cups Won:");
    Coach toSearch(auxName, auxCupsWon, std::list<std::pair<std::string, Interval>>());
    Coach toDelete = coachList.find(toSearch);
    if(toDelete.getName() == "" && toDelete.getCupsWon() == 0)
    {
        cout << "Coach doesn\'t exist..." << endl;
        return;
    }
    coachList.remove(toDelete);
    cout << "Coach successfully deleted!" << endl;
}

void NationalTeam::alterCoach()
{
    bool toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n') << endl;

    string auxName = readOperations::readString("Coach Name:");
    unsigned int auxCupsWon = readOperations::readNumber<unsigned int>("Cups Won:");
    Coach toSearch(auxName, auxCupsWon, std::list<std::pair<std::string, Interval>>());
    Coach toAlter = coachList.find(toSearch);
    if(toAlter.getName() == "" && toAlter.getCupsWon() == 0)
    {
        cout << "Coach doesn\'t exist..." << endl;
        return;
    }

    while (toggle)
    {
        if (repetition == 0)
        {
            cout << endl << "What do you want to change?\n";
            repetition++;
        }
        else
            cout << "Do you want to change anything else?\n";

        cout << "1. Name\n2. Cups Won\n3. Add Trained Team\n4. Remove Trained Team\n0. Back\n\n";
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
                cout << "Previous Name: " << toAlter.getName() << endl;
                coachList.remove(toAlter);
                string auxName = readOperations::readString("New Name:");
                toAlter.setName(auxName);
                coachList.insert(toAlter);

                cout << endl << "Coach successfully altered!" << endl;
                break;
            }
            case 2:
            {
                cout << "Previous Cups: " << toAlter.getCupsWon() << endl;
                coachList.remove(toAlter);
                unsigned int auxCupsWon = readOperations::readNumber<unsigned int>("New Cups:");
                toAlter.setCupsWon(auxCupsWon);
                coachList.insert(toAlter);

                cout << endl << "Coach successfully altered!" << endl;
                break;
            }
            case 3:
            {
                unsigned int numTrain = readOperations::readNumber<unsigned int>("Number of Trained Teams to Add:");
                coachList.remove(toAlter);
                for(int i = 0; i < numTrain; i++)
                {
                    string team = readOperations::readString("Team:");
                    Date begin;
                    Date end;
                    while(true)
                    {
                        begin = readOperations::readDate("Begin Date:");
                        end = readOperations::readDate("End Date:");
                        if(begin <= end)
                            break;
                    }
                    toAlter.addTrainedTeam(pair<string, Interval>(team, Interval(begin, end)));
                }

                coachList.insert(toAlter);
                break;
            }
            case 4:
            {
                coachList.remove(toAlter);

                string team = readOperations::readString("Team:");
                Date begin;
                Date end;
                while(true)
                {
                    begin = readOperations::readDate("Begin Date:");
                    end = readOperations::readDate("End Date:");
                    if(begin <= end)
                        break;
                }
                toAlter.removeTrainedTeam(pair<string, Interval>(team, Interval(begin, end)));

                coachList.insert(toAlter);
                break;
            }
        }
    }
}

bool NationalTeam::readCoachesFile(std::string filename)
{
    ifstream f;
    f.open(filename);
    unsigned int cups;
    string name, teams, dates;
    char delimiter = ',';

    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, name);
            if(name == "")
                break;
            f >> cups;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, teams);
            vector<string> teamsTrained = generalFunctions::separate_string(teams, delimiter);
            getline(f, dates);
            vector<string> datesTrained = generalFunctions::separate_string(dates, delimiter);
            unsigned int ct = 0;
            list<pair<string, Interval>> trainedTeams;
            for(auto &x: teamsTrained)
            {
                pair<string, Interval> toAdd(x, Interval(Date(datesTrained[ct]), Date(datesTrained[ct + 1])));
                trainedTeams.push_back(toAdd);
                ct += 2;
            }

            Coach newCoach(name, cups, trainedTeams);
            coachList.insert(newCoach);

            getline(f, name); // blank line
            getline(f, name); // blank line
            getline(f, name); // blank line

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

void NationalTeam::displayCoachesByCupsWon()
{
    BSTItrIn<Coach> iTr(coachList);
    cout << endl;
    int numCoaches;
    do
    {
        numCoaches = readOperations::readNumber<int>("Number of Coaches to Display:");
    } while(numCoaches < 0);

    unsigned int counter = 0;

    cout << endl;
    while(!iTr.isAtEnd() && counter < numCoaches)
    {
        Coach::header();
        Coach coachObj = iTr.retrieve();
        cout << left << setw(50) << coachObj.getName() << left << setw(10) << coachObj.getCupsWon() << endl << endl;
        for(auto &x: coachObj.getTeamsTrained())
            cout << "Team: " << left << setw(20) << x.first << " | " << x.second.getBeginDate().getDate() << "  -  " << x.second.getEndDate().getDate() << endl;

        cout << endl << endl;
        iTr.advance();
        counter++;
    }
}

void NationalTeam::displayCoachesThatTrainedNTeam()
{
    BSTItrIn<Coach> iTr(coachList);

    while(!iTr.isAtEnd())
    {
        bool hasParticipated = false;
        Coach coachObj = iTr.retrieve();
        for(auto &x: coachObj.getTeamsTrained())
        {
            string t = x.first;
            std::transform(t.begin(), t.end(), t.begin(), ::toupper); // Convert to uppercase
            if(t == "PORTUGAL" || t == "POR" || t == "PORT")
                hasParticipated = true;
        }

        if (hasParticipated)
        {
            Coach::header();
            cout << left << setw(50) << coachObj.getName() << left << setw(10) << coachObj.getCupsWon() << endl << endl;
            for (auto &x: coachObj.getTeamsTrained()) {
                cout << "Team: " << left << setw(20) << x.first << " | " << x.second.getBeginDate().getDate() << "  -  "
                     << x.second.getEndDate().getDate() << endl;
            }
        }
        cout << endl << endl;
        iTr.advance();
    }
}

bool NationalTeam::writeCoachesFile(string filename)
{
    ofstream f;
    f.open(filename, ios::out);
    BSTItrPre<Coach> iTr(coachList);
    if (f.is_open()) {
        while(!iTr.isAtEnd())
        {
            Coach toPick = iTr.retrieve();
            f << toPick.getName() << endl;
            f << toPick.getCupsWon() << endl;
            string teams, dates;
            std::list<std::pair<std::string, Interval>> teamsTrained = toPick.getTeamsTrained();
            std::list<std::pair<std::string, Interval>>::iterator iTER;
            for(iTER = teamsTrained.begin(); iTER != teamsTrained.end(); iTER++)
            {
                if(++iTER != teamsTrained.end())
                {
                    iTER--;
                    teams += iTER->first + ", ";
                    dates += iTER->second.getBeginDate().getDate() + ", " + iTER->second.getEndDate().getDate() + ", ";
                }
                else
                {
                    iTER--;
                    teams += iTER->first;
                    dates += iTER->second.getBeginDate().getDate() + ", " + iTER->second.getEndDate().getDate();
                }
            }

            f << teams << endl;
            f << dates << endl;
            f << endl  << "::::::::::" << endl << endl;
            iTr.advance();
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

void NationalTeam::displayCoach()
{
    cout << endl;
    string auxName = readOperations::readString("Coach Name:");
    std::transform(auxName.begin(), auxName.end(), auxName.begin(), ::toupper); // Convert to uppercase
    BSTItrIn<Coach> iTr(coachList);
    bool found = false;

    while(!iTr.isAtEnd())
    {
        string playerName = iTr.retrieve().getName();
        std::transform(playerName.begin(), playerName.end(), playerName.begin(), ::toupper); // Convert to uppercase
        if(playerName == auxName)
        {
            found = true;
            Coach::header();
            cout << left << setw(50) << iTr.retrieve().getName() << left << setw(10) << iTr.retrieve().getCupsWon() << endl << endl;
            for (auto &x: iTr.retrieve().getTeamsTrained()) {
                cout << "Team: " << left << setw(20) << x.first << " | " << x.second.getBeginDate().getDate() << "  -  "
                     << x.second.getEndDate().getDate() << endl;
            }
        }
        iTr.advance();
    }
    if(!found)
        cout << "Coach NOT Found!" << endl << endl;
}

void NationalTeam::addProvider(const Provider &pro) {
    providerList.push(pro);
}


bool NationalTeam::readProviderFile(string filename) {
    ifstream f;
    f.open(filename);
    unsigned int id, made_purchases, quantity;
    string name, aux, type, availableString;
    bool available;
    char delim = ' ';
    unsigned short reputation;
    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, name);
            getline(f, aux, delim);
            getline(f, type);
            getline(f, aux, delim);
            f >> reputation;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            f >> made_purchases;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, availableString);
            if (availableString == "true")
                available = true;
            else
                available = false;
            getline(f, aux, delim);
            f >> quantity;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, '\n'); // blank line

            Provider pro(id, name, type, reputation, made_purchases, available, quantity);
            addProvider(pro);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::writeProviderFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    int counter = 0;
    vector<Provider> proV;
    priority_queue<Provider> aux = providerList;
    while(!aux.empty()){
        proV.push_back(aux.top());
        aux.pop();
    }
    if (f.is_open()) {
        for (auto &x : proV) {
            counter++;
            f << "ID: " << x.getId() << endl;
            f << "Name: " << x.getName() << endl;
            f << "Type: " << x.getEquipmentType() << endl;
            f << "Reputation: " << x.getReputation() << endl;
            f << "Purchases: " << x.getMade_Purchases() << endl;
            if (x.getAvailability())
                f << "Availability: true" << endl;
            else
                f << "Availability: false" << endl;
            f << "Quantity: " << x.getQuantity();
            if (counter != providerList.size())
                f << endl << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}


bool NationalTeam::readEquipmentsFile(string filename) {
    ifstream f;
    f.open(filename);
    unsigned int id, quantity;
    string aux, type;
    char delim = ' ';
    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, type);
            getline(f, aux, delim);
            f >> quantity;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux); // blank line

            Equipment equipment(id, type, quantity);
            addEquipment(equipment);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

void NationalTeam::addEquipment(const Equipment &equipment) {
    for (auto &x: equipments) {
        if (x.getType() == equipment.getType()) {
            x.setQuantity(x.getQuantity() + equipment.getQuantity());
            return;
        }
    }
    equipments.push_back(equipment);
}

bool NationalTeam::writeEquipmentsFile(std::string filename) {
    ofstream f;
    f.open(filename, ios::out);
    int counter = 0;

    if (f.is_open()) {
        for (auto &x : equipments) {
            counter++;
            f << "ID: " << x.getID() << endl;
            f << "Type: " << x.getType() << endl;
            f << "Quantity: " << x.getQuantity();
            if (counter != equipments.size())
                f << endl  << endl << "::::::::::" << endl << endl;
        }
        f.close();
        return true;
    }
    else {
        cerr << "Error opening the file " << filename << endl;
        return false;
    }
}

unsigned int NationalTeam::getEquipmentVectorLastID() const {
    return equipments.at(equipments.size() - 1).getID();
}


bool NationalTeam::typeOfEquipmentIsAvailable(string type) const {
    std::transform(type.begin(), type.end(), type.begin(), ::toupper); // Convert to uppercase
    priority_queue<Provider> aux = providerList;
    while(!aux.empty()) {
        string currentType = aux.top().getEquipmentType();
        std::transform(currentType.begin(), currentType.end(), currentType.begin(), ::toupper); // Convert to uppercase
        if (currentType == type && aux.top().getAvailability()) {
            return true;
        }
        aux.pop();
    }
    return false;
}


bool NationalTeam::quantityOfEquipmentIsAvailable(string type, unsigned int quantity) const {
    std::transform(type.begin(), type.end(), type.begin(), ::toupper); // Convert to uppercase
    if (!typeOfEquipmentIsAvailable(type))
        return false;

    priority_queue<Provider> aux = providerList;
    while(!aux.empty()) {
        string currentType = aux.top().getEquipmentType();
        std::transform(currentType.begin(), currentType.end(), currentType.begin(), ::toupper); // Convert to uppercase
        if (currentType == type) {
            if (aux.top().getQuantity() >= quantity)
                return true;
        }
        aux.pop();
    }
    return false;
}

void NationalTeam::updateReputation(unsigned int id, unsigned short rate) {
    vector<Provider> auxVector;
    priority_queue<Provider> aux = providerList;
    while (!aux.empty()) {
        if (aux.top().getId() == id) {
            unsigned short reputation = aux.top().getReputation();
            if (rate < 3 && reputation < 3) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(0);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if (rate < 3 && reputation >= 3) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(reputation - 2);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if ((rate == 3 || rate == 4) && reputation < 2) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(0);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if ((rate == 3 || rate == 4) && reputation >= 2) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(reputation - 1);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if (rate == 5) {
                auxVector.push_back(aux.top());
                aux.pop();
                break;
            }
            if ((rate == 6 || rate == 7) && reputation > 8) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(10);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if ((rate == 6 || rate == 7) && reputation <= 8) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(reputation + 1);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if (rate > 7 && reputation > 7) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(10);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
            if (rate > 7 && reputation <= 7) {
                Provider updatedProvider = aux.top();
                updatedProvider.setReputation(reputation + 2);
                auxVector.push_back(updatedProvider);
                aux.pop();
                break;
            }
        }
        auxVector.push_back(aux.top());
        aux.pop();
    }

    for (int i = 0; i < auxVector.size(); i++) {
        aux.push(auxVector.at(i));
    }

    providerList = aux;

}

void NationalTeam::purchaseEquipment() {

    unsigned int quantity = 0;

    string type = readOperations::readString("What type of equipment fo you want to buy?");
    std::transform(type.begin(), type.end(), type.begin(), ::toupper); // Convert to uppercase
    if (!typeOfEquipmentIsAvailable(type)) {
        cout << "\nEquipment is not available in the moment!\n";
        return;
    }

    cout << "Enter the quantity:";
    cin >> quantity;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << endl;

    if (!quantityOfEquipmentIsAvailable(type, quantity)) {
        cout << "\nThe quantity of equipment available is not enough!\n";
        return;
    }

    unsigned int idProvider = 0;
    vector<Provider> auxVector;
    priority_queue<Provider> aux = providerList;
    while(!aux.empty()) {
        string currentType = aux.top().getEquipmentType();
        std::transform(currentType.begin(), currentType.end(), currentType.begin(), ::toupper); // Convert to uppercase
        if (currentType == type) {
            Equipment equipment(getEquipmentVectorLastID() + 1, aux.top().getEquipmentType(), quantity);
            addEquipment(equipment);
            Provider updatedProvider = aux.top();
            updatedProvider.setMade_Purchases(updatedProvider.getMade_Purchases() + 1);
            updatedProvider.setQuantity(updatedProvider.getQuantity() - quantity);
            idProvider = updatedProvider.getId();
            auxVector.push_back(updatedProvider);
            aux.pop();
            break;
        }
        auxVector.push_back(aux.top());
        aux.pop();
    }

    for (int i = 0; i < auxVector.size(); i++) {
        aux.push(auxVector.at(i));
    }

    providerList = aux;

    cout << "\n\nPurchase done!\n\n";

    int rate = 0;
    while (true) {
        string answer = readOperations::readString("Do you want to rate the purchase in a scale form 0 to 10? (yes / no)");
        std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
        if (answer == "YES" or answer == "Y") {
            while (true) {
                cout << "Enter the rate from 0 to 10:";
                cin >> rate;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << endl;
                if (rate >= 0 && rate <= 10) {
                    updateReputation(idProvider, rate);
                    break;
                }
                cout << "\nInvalid rate!\n";
            }
            cout << "\nThanks for your feedback!\n";
            break;
        }
        if (answer == "NO" or answer == "N") {

            return;
        }
    }

}

bool NationalTeam::createProvider() {
    string name = readOperations::readString("Name:");
    string type = readOperations::readString("Type:");
    unsigned short reputation;
    while (true) {
        reputation = readOperations::readNumber<unsigned short>("Reputation (0-10):");
        if (reputation >= 0 && reputation <= 10)
            break;
        cout << "\nInvalid reputation!\n";
    }
    unsigned int purchases = readOperations::readNumber<unsigned int>("Purchases:");
    bool available;
    while (true) {
        string auxAvailability = readOperations::readString("Availability (true / false):");
        std::transform(auxAvailability.begin(), auxAvailability.end(), auxAvailability.begin(), ::toupper); // Convert to uppercase
        if (auxAvailability == "TRUE" || auxAvailability == "T") {
            available = true;
            break;
        }
        if (auxAvailability == "FALSE" || auxAvailability == "F") {
            available = false;
            break;
        }
        cout << "\nInvalid option!\n";
    }
    unsigned int quantity = readOperations::readNumber<unsigned int>("Quantity:");

    unsigned int id = getProvidersLastID() + 1;

    Provider provider(id, name, type, reputation, purchases, available, quantity);

    cout << endl << "Are you sure you wnat to insert the following data? (Y|N)" << endl << endl;
    provider.info(cout);
    cout << endl << endl;
    string answer = readOperations::confirmAnswer();

    if(answer == "Y" || answer == "y")
    {
        addProvider(provider);
        cout << "Data successfully inserted!" << endl;
        return true;
    }
    cout << "Data not inserted." << endl;
    return false;

}

unsigned int NationalTeam::getProvidersLastID() const {
    unsigned int lastID = 0;
    priority_queue<Provider> aux = providerList;
    while (!aux.empty()) {
        if (aux.top().getId() > lastID) {
            lastID = aux.top().getId();
        }
        aux.pop();
    }
    return lastID;
}

bool NationalTeam::deleteProvider() {
    Provider providerToDelete = providerLookUp();

    if (providerToDelete.getId() == 0)
        return false;

    vector<Provider> auxVector;
    priority_queue<Provider> aux = providerList;
    while (!aux.empty()) {
        if (providerToDelete == aux.top()) {
            aux.pop();
            for (int i = 0; i < auxVector.size(); i++) {
                aux.push(auxVector.at(i));
            }
            providerList = aux;
            cout << "Provider successfully removed!" << endl << endl;
            return true;
        }
        auxVector.push_back(aux.top());
        aux.pop();
    }
    return false;
}

Provider NationalTeam::providerLookUp() {
    vector<Provider> providersVector;
    priority_queue<Provider> aux = providerList;
    while (!aux.empty()) {
        providersVector.push_back(aux.top());
        aux.pop();
    }


    bool ct;
    std::string reader;
    int option;
    std::vector<Provider> auxPerson;
    Provider auxProvider(0, "", "", 0, 0, false, 0);
    while(true)
    {
        auxPerson.clear();
        ct = false;
        std::cout << std::endl << "Look for a Provider using: " << std::endl; std::cout << "1. Name\n2. Type\n3. ID\n0. Back\n\n";
        std::cin >> option; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cout << std::endl;
        switch(option)
        {
            case 0:
                return auxProvider;
            case 1:
            {
                // Name
                std::string name = readOperations::readString("Name:");
                std::transform(name.begin(), name.end(), name.begin(), ::toupper); // Convert to uppercase

                std::string providerName;

                for(auto &x: providersVector)
                {
                    providerName = x.getName();
                    std::transform(providerName.begin(), providerName.end(), providerName.begin(), ::toupper); // Convert to uppercase
                    if(providerName.find(name) != std::string::npos)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                    }
                }
                if(!auxPerson.empty())
                {
                    for(auto &x: auxPerson)
                    {
                        x.info(cout);
                        cout << endl << endl;
                    }
                }


                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for (auto &x: providersVector) {
                            if (x.getId() == option)
                                return x;
                        }
                        throw NoObjectFound("No Corresponding Provider Found.");
                    }
                    catch (NoObjectFound &e) {
                        std::cout << std::endl << e.getError() << std::endl << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Provider Found..." << std::endl << std::endl;
                break;
            }
            case 2:
            {
                // Type
                std::string type = readOperations::readString("Type:");
                std::transform(type.begin(), type.end(), type.begin(), ::toupper); // Convert to uppercase

                std::string providerType;

                for(auto &x: providersVector)
                {
                    providerType = x.getEquipmentType();
                    std::transform(providerType.begin(), providerType.end(), providerType.begin(), ::toupper); // Convert to uppercase
                    if(providerType.find(type) != std::string::npos)
                    {
                        auxPerson.push_back(x);
                        ct = true;
                    }
                }
                if(!auxPerson.empty())
                {
                    for(auto &x: auxPerson)
                    {
                        x.info(cout);
                        cout << endl << endl;
                    }
                }


                if(ct)
                {
                    std::cout << "Enter the ID of The Choosen One (!ID => [Go Back]): " << std::endl << std::endl;
                    try {
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        for (auto &x: providersVector) {
                            if (x.getId() == option)
                                return x;
                        }
                        throw NoObjectFound("No Corresponding Provider Found.");
                    }
                    catch (NoObjectFound &e) {
                        std::cout << std::endl << e.getError() << std::endl << std::endl;
                    }
                }
                else
                    std::cout << std::endl << "No Corresponding Provider Found..." << std::endl << std::endl;
                break;

            }
            case 3:
            {
                // ID
                unsigned int id = readOperations::readNumber<unsigned int>("ID:");

                try {
                    cin >> id;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    for (auto &x: providersVector) {
                        if (x.getId() == id)
                            return x;
                    }
                    throw NoObjectFound("No Corresponding provider Found...");
                }
                catch (NoObjectFound &e) {
                    cout << endl << e.getError() << endl << endl;
                }

                break;
            }
        }
    }
}

bool NationalTeam::alterProvider() {
    bool toggle = true;
    int repetition = 0, option;

    cout << string(100, '\n');
    Provider providerToAlter = providerLookUp();
    if (providerToAlter.getId() == 0)
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

        cout << "1. Name\n2. Type\n3. Reputation\n4. Purchases\n5. Availability\n6. Quantity\n0. Back\n\n";
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
                cout << "Previous Name: " << providerToAlter.getName() << endl;
                string auxName = readOperations::readString("New Name:");
                providerToAlter.setName(auxName);
                break;
            }
            case 2:
            {
                cout << "Previous Type: " << providerToAlter.getEquipmentType() << endl;
                string auxType = readOperations::readString("New Type:");
                providerToAlter.setEquipmentType(auxType);
                break;
            }
            case 3:
            {
                cout << "Previous Reputation: " << providerToAlter.getReputation() << endl;
                unsigned short auxReputation = readOperations::readNumber<unsigned short>("New Reputation:");
                providerToAlter.setReputation(auxReputation);
                break;
            }
            case 4:
            {
                cout << "Previous Purchases: " << providerToAlter.getMade_Purchases() << endl;
                unsigned int auxPurchases = readOperations::readNumber<unsigned int>("New Purchases:");
                providerToAlter.setMade_Purchases(auxPurchases);
                break;
            }
            case 5:
            {
                if (providerToAlter.getAvailability() == true) {
                    cout << "Previous Availability: true" << endl;
                }
                else {
                    cout << "Previous Availability: false" << endl;
                }
                string auxAvailability;
                while (true) {
                    auxAvailability = readOperations::readString("New Availability (true / false):");
                    if (auxAvailability == "true" || auxAvailability == "t") {
                        providerToAlter.setAvailability(true);
                        break;
                    }
                    if (auxAvailability == "false" || auxAvailability == "f") {
                        providerToAlter.setAvailability(false);
                        break;
                    }
                    cout << "\nInvalid option!\n";
                }
                break;
            }
            case 6:
            {
                cout << "Previous Quantity: " << providerToAlter.getQuantity() << endl;
                unsigned int auxQuantity = readOperations::readNumber<unsigned int>("New Quantity:");
                providerToAlter.setQuantity(auxQuantity);
                break;
            }
        }
        if (toggle)
        {
            vector<Provider> auxVector;
            priority_queue<Provider> aux = providerList;
            while (!aux.empty()) {
                if (aux.top().getId() == providerToAlter.getId()) {
                    aux.pop();
                    aux.push(providerToAlter);
                    for (int i = 0; i < auxVector.size(); i++) {
                        aux.push(auxVector.at(i));
                    }
                    providerList = aux;
                    cout << "Provider successfully altered!" << endl << endl;
                    break;
                }
                auxVector.push_back(aux.top());
                aux.pop();
            }
        }
    }
    return true;
}

void NationalTeam::displayAllProviders() const {
    cout << endl << endl;
    priority_queue<Provider> aux = providerList;
    while (!aux.empty()) {
        cout << "ID: " << aux.top().getId() << endl;
        cout << "Name: " << aux.top().getName() << endl;
        cout << "Type: " << aux.top().getEquipmentType() << endl;
        cout << "Reputation: " << aux.top().getReputation() << endl;
        cout << "Purchases: " << aux.top().getMade_Purchases() << endl;
        if (aux.top().getAvailability())
            cout << "Available: true" << endl;
        else
            cout << "Available: false" << endl;
        cout << "Quantity: " << aux.top().getQuantity() << endl << endl;
        aux.pop();
    }
}

void NationalTeam::displaySpecificProvider() {
    providerLookUp();
}

void NationalTeam::displayAllEquipment() const {
    cout << endl << endl;
    for (auto it = equipments.begin(); it != equipments.end(); it++) {
        cout << "ID: " << it->getID() << endl;
        cout << "Type: " << it->getType() << endl;
        cout << "Quantity: " << it->getQuantity() << endl << endl;
    }
}






